#include "App.h"
#include <QMetaType>
#include <QWindow>

using namespace net::draconia::util;

void App::setArguments(int argc, char *argv[])
{
    for(int iLength = argc, iLoop = 0; iLoop < iLength; iLoop++)
        mLstArgs.append(argv[iLoop]);
}

void App::showMainWindow()
{
    getMainWindow().show();
}

App::App(int argc, char *argv[])
    :   QApplication(argc, argv)
    ,   mObjController(*this)
{
    setArguments(argc, argv);
}

int App::exec()
{
    showMainWindow();

    return(QApplication::exec());
}

void App::exit()
{
    getMainWindow().close();
}

QList<QString> &App::getArguments() const
{
    return(const_cast<App &>(*this).mLstArgs);
}

Controller &App::getController()
{
    return(mObjController);
}

MainWindow &App::getMainWindow()
{
    return(mWndMain);
}
