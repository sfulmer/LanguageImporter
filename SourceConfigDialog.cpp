#include "App.h"
#include "ModelConfig.h"
#include <QVBoxLayout>
#include "SourceConfigButtonPanel.h"
#include "SourceConfigPanelURL.h"
#include "SourceConfigDialog.h"

using net::draconia::util::model::ModelConfig;
using namespace net::draconia::util::ui;

SourceConfigButtonPanel *SourceConfigDialog::getButtonsPanel()
{
    if(mPnlButtons == nullptr)
        mPnlButtons = new SourceConfigButtonPanel(this);

    return(mPnlButtons);
}

Controller &SourceConfigDialog::getController() const
{
    return(mRefController);
}

SourceConfigPanel *SourceConfigDialog::getSourceConfigPanel()
{
    ModelConfig &model = getController().getModel().getConfiguration();

    if(model.getSource() == "URL")
        mPnlSourceConfig = new SourceConfigPanelURL(this, getController());

    return(mPnlSourceConfig);
}

void SourceConfigDialog::initControls()
{
    QLayout *layout = new QVBoxLayout(this);

    layout->addWidget(getSourceConfigPanel());
    layout->addWidget(getButtonsPanel());

    setLayout(layout);
}

void SourceConfigDialog::initDialog()
{
    setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));

    initControls();
}

SourceConfigDialog::SourceConfigDialog(QWidget *parent)
    :   SourceConfigDialog(parent, static_cast<App *>(qApp)->getController())
{ }

SourceConfigDialog::SourceConfigDialog(QWidget *parent, const Controller &refController)
    :   QDialog(parent)
    ,   mRefController(const_cast<Controller &>(refController))
    ,   mPnlButtons(nullptr)
    ,   mPnlSourceConfig(nullptr)
{
    initDialog();
}

void SourceConfigDialog::reject()
{
    getSourceConfigPanel()->reject();

    QDialog::reject();
}
