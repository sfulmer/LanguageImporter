#include "App.h"
#include "Controller.h"
#include <QFileDialog>
#include "SourceConfigDialog.h"

using namespace net::draconia::util::languageimporter;
using net::draconia::util::languageimporter::ui::SourceConfigDialog;

App &Controller::getApplication()
{
    return(mRefApp);
}

Controller::Controller(App &refApp)
    :   mRefApp(refApp)
{
    getModel().getConfiguration().setSource("URL");
}

Controller::~Controller()
{ }

void Controller::browseForDBPath()
{
    getModel().getConfiguration().setDatabasePath(QFileDialog::getOpenFileName(&(getApplication().getMainWindow()), tr("Identify Database Path")));
}

void Controller::exit()
{
    getApplication().exit();
}

Model &Controller::getModel()
{
    return(mObjModel);
}

void Controller::reset()
{ }

void Controller::save()
{ }

void Controller::setModel(Model &refModel)
{
    mObjModel = refModel;
}

void Controller::showConfigDialog()
{
    SourceConfigDialog *dialog = new SourceConfigDialog(&(getApplication().getMainWindow()), *this);

    dialog->exec();

    delete dialog;
}
