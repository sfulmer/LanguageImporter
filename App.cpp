#include "App.h"
#include <QMetaType>
#include <QWindow>

using namespace net::draconia::util::languageimporter;

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
    ,   mPtrController(nullptr)
{
    setArguments(argc, argv);
}

App::~App()
{
    if(mPtrController != nullptr)
        {
        delete mPtrController;

        mPtrController = nullptr;
        }
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

QList<QString> &App::getArguments()
{
    return(mLstArgs);
}

Controller &App::getController()
{
    if(mPtrController == nullptr)
        mPtrController = new Controller(*this);

    return(*mPtrController);
}

MainWindow &App::getMainWindow()
{
    return(mWndMain);
}
