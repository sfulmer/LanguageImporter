#include "App.h"
#include "ModelConfig.h"
#include "ModelConfigSourceURL.h"
#include <QGridLayout>
#include "SourceConfigPanelURL.h"

using net::draconia::util::model::ModelConfig;
using net::draconia::util::model::ModelConfigSourceURL;
using namespace net::draconia::util::ui;

void SourceConfigPanelURL::endingTextChanged(const QString &sText)
{
    ModelConfig &model = getController().getModel().getConfiguration();
    if(model.getSource() == "URL")
        static_cast<ModelConfigSourceURL &>(model.getSourceConfig()).setEnding(sText);
}


QLabel *SourceConfigPanelURL::getEndingLabel()
{
    if(mLblEnding == nullptr)
        {
        mLblEnding = new QLabel("&Ending:", this);

        mLblEnding->setAutoFillBackground(false);
        mLblEnding->setBuddy(getEndingText());
        }

    return(mLblEnding);
}

QTextEdit *SourceConfigPanelURL::getEndingText()
{
    if(mTxtEnding == nullptr)
        {
        mTxtEnding = new QTextEdit(this);

        connect(mTxtEnding, SIGNAL(QTextEdit::textChanged(QString&)), this, SLOT(SourceConfigPanelURL::endingTextChanged(QString&)));
        }

    return(mTxtEnding);
}

QLabel *SourceConfigPanelURL::getOpeningLabel()
{
    if(mLblOpening == nullptr)
        {
        mLblOpening = new QLabel("O&pening:", this);

        mLblOpening->setAutoFillBackground(false);
        mLblOpening->setBuddy(getOpeningText());
        }

    return(mLblOpening);
}

QTextEdit *SourceConfigPanelURL::getOpeningText()
{
    if(mTxtOpening == nullptr)
        {
        mTxtOpening = new QTextEdit(this);

        connect(mTxtOpening, SIGNAL(QTextEdit::textChanged(QString&)), this, SLOT(SourceConfigPanelURL::openingTextChanged(QString&)));
        }

    return(mTxtOpening);
}

QLabel *SourceConfigPanelURL::getURLLabel()
{
    if(mLblURL == nullptr)
        {
        mLblURL = new QLabel("&URL:", this);

        mLblURL->setAutoFillBackground(false);
        mLblURL->setBuddy(getURLText());
        }

    return(mLblURL);
}

QLineEdit *SourceConfigPanelURL::getURLText()
{
    if(mTxtURL == nullptr)
        {
        mTxtURL = new QLineEdit(this);

        connect(mTxtURL, SIGNAL(QLineEdit::textChanged(QString&)), this, SLOT(SourceConfigPanelURL::urlTextChanged(QString&)));
        }

    return(mTxtURL);
}

void SourceConfigPanelURL::initControls()
{
    QGridLayout *layout = new QGridLayout(this);

    layout->addWidget(getURLLabel(), 0, 0, 1, 1);
    layout->addWidget(getURLText(), 0, 1, 1, 1);
    layout->addWidget(getOpeningLabel(), 1, 0, 1, 2, Qt::AlignLeft);
    layout->addWidget(getOpeningText(), 2, 0, 1, 2, Qt::AlignLeft);
    layout->addWidget(getEndingLabel(), 3, 0, 1, 2, Qt::AlignLeft);
    layout->addWidget(getEndingText(), 4, 0, 1, 2, Qt::AlignLeft);

    setLayout(layout);
}

void SourceConfigPanelURL::initPanel()
{
    setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));

    initControls();
}

void SourceConfigPanelURL::openingTextChanged(const QString &sText)
{
    ModelConfig &model = getController().getModel().getConfiguration();
    if(model.getSource() == "URL")
        static_cast<ModelConfigSourceURL &>(model.getSourceConfig()).setOpening(sText);
}

void SourceConfigPanelURL::URLTextChanged(const QString &sText)
{
    ModelConfig &model = getController().getModel().getConfiguration();
    if(model.getSource() == "URL")
        static_cast<ModelConfigSourceURL &>(model.getSourceConfig()).setEnding(sText);
}

SourceConfigPanelURL::SourceConfigPanelURL(QWidget *parent)
    :   SourceConfigPanelURL(parent, static_cast<App *>(qApp)->getController())
{ }

SourceConfigPanelURL::SourceConfigPanelURL(QWidget *parent, const Controller &refController)
    :   SourceConfigPanel(parent, refController)
    ,   mLblEnding(nullptr)
    ,   mLblOpening(nullptr)
    ,   mLblURL(nullptr)
    ,   mTxtURL(nullptr)
    ,   mTxtEnding(nullptr)
    ,   mTxtOpening(nullptr)
{
    initPanel();
}

void SourceConfigPanelURL::reject()
{
    ModelConfigSourceURL &refModel = static_cast<ModelConfigSourceURL &>(getModel());

    refModel.setEnding("");
    refModel.setOpening("");
    refModel.setURL("");
}
