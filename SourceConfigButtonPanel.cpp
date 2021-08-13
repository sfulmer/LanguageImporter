#include "App.h"
#include <QHBoxLayout>
#include "SourceConfigButtonPanel.h"
#include "SourceConfigDialog.h"

using namespace net::draconia::util::languageimporter::ui;

void SourceConfigButtonPanel::cancelClicked()
{
    static_cast<QDialog *>(parentWidget())->reject();
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
}

QPushButton *SourceConfigButtonPanel::getCancelButton()
{
    if(mBtnCancel == nullptr)
        {
        mBtnCancel = new QPushButton("Cancel", this);

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
