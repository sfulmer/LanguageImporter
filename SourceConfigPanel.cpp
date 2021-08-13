#include "App.h"
#include "SourceConfigPanel.h"

using namespace net::draconia::util::languageimporter::ui;

Controller &SourceConfigPanel::getController() const
{
    return(mRefController);
}

ModelConfigSource &SourceConfigPanel::getModel() const
{
    return(getController().getModel().getConfiguration().getSourceConfig());
}

SourceConfigPanel::SourceConfigPanel(QWidget *parent)
    :   SourceConfigPanel(parent, static_cast<App *>(qApp)->getController())
{ }

SourceConfigPanel::SourceConfigPanel(QWidget *parent, Controller &mRefController)
    :   QWidget(parent)
    ,   mRefController(mRefController)
{ }

SourceConfigPanel::~SourceConfigPanel()
{ }
