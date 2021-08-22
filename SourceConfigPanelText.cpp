#include "App.h"
#include "ModelConfig.h"
#include "ModelConfigSourceText.h"
#include "ModelSourceConfigConverterObserver.h"
#include "ModelSourceConfigTextObserver.h"
#include <QGridLayout>
#include "SourceConfigPanelText.h"
#include "TextCSVConverter.h"
#include "TextNullConverter.h"

using net::draconia::util::languageimporter::model::ModelConfig;
using net::draconia::util::languageimporter::model::ModelConfigSourceText;
using namespace net::draconia::util::languageimporter::observers;
using namespace net::draconia::util::languageimporter::ui;

void SourceConfigPanelText::conversionSelectionChanged(const int iConversionIndex)
{
    if(iConversionIndex >= 0)
        {
        Converter *converter = qvariant_cast<Converter *>(getConversionField()->currentData());

        static_cast<ModelConfigSourceText &>(getModel()).setConverter(*converter);
        }
    else
        {
        Converter *ptrConverter = ModelConfigSourceText::getConverters()[0];

        static_cast<ModelConfigSourceText &>(getModel()).setConverter(*ptrConverter);
        }
}

void SourceConfigPanelText::textChanged()
{
    ModelConfig &model = getController().getModel().getConfiguration();

    if(model.getSource() == "Text")
        static_cast<ModelConfigSourceText &>(model.getSourceConfig()).setText(getText()->toPlainText());
}

QComboBox *SourceConfigPanelText::getConversionField()
{
    if(mCboConversion == nullptr)
        {
        mCboConversion = new QComboBox(this);
        ModelConfigSourceText &refModel = static_cast<ModelConfigSourceText &>(getModel());
        QList<Converter *> &lstModel = const_cast<QList<Converter *> &>(refModel.getConverters());

        for(Converter *ptrConverter : lstModel)
            {
            QVariant variant;

            variant.setValue(ptrConverter);

            if(variant.isValid())
                mCboConversion->addItem(ptrConverter->toString(), variant);
            }

        connect(mCboConversion, SIGNAL(currentIndexChanged(int)), this, SLOT(conversionSelectionChanged(const int)));
        }

    return(mCboConversion);
}

QLabel *SourceConfigPanelText::getConversionLabel()
{
    if(mLblConversion == nullptr)
        {
        mLblConversion = new QLabel("Con&verter:", this);

        mLblConversion->setAutoFillBackground(false);
        mLblConversion->setBuddy(getConversionField());
        }

    return(mLblConversion);
}

QLabel *SourceConfigPanelText::getTextLabel()
{
    if(mLblText == nullptr)
        {
        mLblText = new QLabel("&Text:", this);

        mLblText->setAutoFillBackground(false);
        mLblText->setBuddy(getText());
        }

    return(mLblText);
}

QTextEdit *SourceConfigPanelText::getText()
{
    if(mTxtText == nullptr)
        {
        mTxtText = new QTextEdit(this);

        connect(mTxtText, &QTextEdit::textChanged, this, &SourceConfigPanelText::textChanged);
        }

    return(mTxtText);
}

void SourceConfigPanelText::initControls()
{
    QGridLayout *layout = new QGridLayout(this);

    layout->addWidget(getConversionLabel(), 0, 0, 1, 1);
    layout->addWidget(getConversionField(), 0, 1, 1, 1);
    layout->addWidget(getTextLabel(), 1, 0, 1, 1, Qt::AlignTop | Qt::AlignLeft);
    layout->addWidget(getText(), 1, 1, 1, 1);

    setLayout(layout);
}

void SourceConfigPanelText::initPanel()
{
    setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));

    initControls();
}

SourceConfigPanelText::SourceConfigPanelText(QWidget *parent)
    :   SourceConfigPanelText(parent, static_cast<App *>(qApp)->getController())
{ }

SourceConfigPanelText::SourceConfigPanelText(QWidget *parent, Controller &refController)
    :   SourceConfigPanel(parent, refController)
    ,   mCboConversion(nullptr)
    ,   mLblConversion(nullptr)
    ,   mLblText(nullptr)
    ,   mTxtText(nullptr)
{
    getModel().addObserver(new ModelSourceConfigConverterObserver(getConversionField()));
    getModel().addObserver(new ModelSourceConfigTextObserver(getText()));

    initPanel();
}

bool SourceConfigPanelText::isOkAble()
{
    ModelConfigSourceText &refModel = static_cast<ModelConfigSourceText &>(getModel());

    if(refModel.getConverters().indexOf(&(refModel.getConverter())) > 0)
        return(!refModel.getText().isEmpty());
    else
        return(false);
}

void SourceConfigPanelText::reject()
{
    ModelConfigSourceText &refModel = static_cast<ModelConfigSourceText &>(getModel());

    refModel.setText("");
}
