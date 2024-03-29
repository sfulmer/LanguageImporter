#pragma once

#include "MainPanel.h"
#include <QMainWindow>

namespace net
{
    namespace draconia
    {
        namespace util
        {
            namespace languageimporter
            {
                namespace ui
                {
                    class MainWindow : public QMainWindow
                    {
                        Q_OBJECT

                        MainPanel *mPnlMain;
                    protected:
                        MainPanel *getMainPanel();
                        void initControls();
                        void initWindow();
                    public:
                        MainWindow(QWidget *parent = nullptr);
                        ~MainWindow();
                    };
                }
            }
        }
    }
}
