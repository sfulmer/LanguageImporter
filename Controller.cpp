#include "App.h"
#include "Controller.h"
#include <QFileDialog>
#include "SourceConfigDialog.h"

using namespace net::draconia::util;
using net::draconia::util::ui::SourceConfigDialog;

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

Model &Controller::getModel() const
{
    return(const_cast<Controller &>(*this).mObjModel);
}

void Controller::reset()
{ }

void Controller::save()
{ }

void Controller::setModel(const Model &refModel)
{
    mObjModel = refModel;
}

void Controller::showConfigDialog()
{
    SourceConfigDialog *dialog = new SourceConfigDialog(&(getApplication().getMainWindow()), *this);

    dialog->exec();

    delete dialog;
}
