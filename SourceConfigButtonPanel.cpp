#include "App.h"
#include <QHBoxLayout>
#include "SourceConfigButtonPanel.h"
#include "SourceConfigDialog.h"
#include "URLButtonObserver.h"

using net::draconia::util::languageimporter::observers::URLButtonObserver;
using namespace net::draconia::util::languageimporter::ui;

void SourceConfigButtonPanel::cancelClicked()
{
    static_cast<QDialog *>(parentWidget())->reject();
}

Controller &SourceConfigButtonPanel::getController() const
{
    return(mRefController);
}

ModelConfigSource &SourceConfigButtonPanel::getModel() const
{
    return(getController().getModel().getConfiguration().getSourceConfig());
}

void SourceConfigButtonPanel::initControls()
{
    QLayout *layout = new QHBoxLayout(this);

    layout->addWidget(getOkButton());
    layout->addWidget(getCancelButton());

    setLayout(layout);
}

void SourceConfigButtonPanel::initPanel()
{
    setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));

    initControls();
}

void SourceConfigButtonPanel::okClicked()
{
    static_cast<SourceConfigDialog *>(parentWidget())->accept();
}

void SourceConfigButtonPanel::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    getOkButton()->setEnabled(static_cast<SourceConfigDialog *>(parent())->getSourceConfigPanel()->isOkAble());
}

SourceConfigButtonPanel::SourceConfigButtonPanel(QWidget *parent)
    :   SourceConfigButtonPanel(parent, static_cast<App *>(qApp)->getController())
{ }

SourceConfigButtonPanel::SourceConfigButtonPanel(QWidget *parent, const Controller &refController)
    :   QWidget(parent)
    ,   mRefController(const_cast<Controller &>(refController))
    ,   mBtnCancel(nullptr)
    ,   mBtnOk(nullptr)
{
    initPanel();

    getModel().addObserver(new URLButtonObserver(getOkButton()));
}

QPushButton *SourceConfigButtonPanel::getCancelButton()
{
    if(mBtnCancel == nullptr)
        {
        mBtnCancel = new QPushButton("&Cancel", this);

        connect(mBtnCancel, &QPushButton::clicked, this, &SourceConfigButtonPanel::cancelClicked);
        }

    return(mBtnCancel);
}

QPushButton *SourceConfigButtonPanel::getOkButton()
{
    if(mBtnOk == nullptr)
        {
        mBtnOk = new QPushButton("&Ok", this);

        connect(mBtnOk, &QPushButton::clicked, this, &SourceConfigButtonPanel::okClicked);
        }

    return(mBtnOk);
}
