#pragma once

#include "MainWindow.h"
#include "Controller.h"
#include <QApplication>
#include <QList>
#include <QString>

using net::draconia::util::languageimporter::ui::MainWindow;

namespace net
{
    namespace draconia
    {
        namespace util
        {
            namespace languageimporter
            {
                class App : public QApplication
                {
                    MainWindow *mWndMain;
                    Controller *mPtrController;
                    QList<QString> mLstArgs;
                protected:
                    void setArguments(int argc, char *argv[]);
                    void showMainWindow();
                public:
                    App(int argc, char *argv[]);
                    ~App();
                    int exec();
                    void exit();
                    QList<QString> &getArguments();
                    Controller &getController();
                    MainWindow *getMainWindow();
                };
            }
        }
    }
}
