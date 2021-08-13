#pragma once

#include "Controller.h"
#include <QPushButton>
#include <QWidget>

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
                    class SourceConfigButtonPanel : public QWidget
                    {
                        Q_OBJECT

                        Controller &mRefController;
                        QPushButton *mBtnCancel, *mBtnOk;
                    protected:
                        void cancelClicked();
                        void initControls();
                        void initPanel();
                        void okClicked();
                    public:
                        SourceConfigButtonPanel(QWidget *parent);
                        SourceConfigButtonPanel(QWidget *parent, const Controller &refController);

                        QPushButton *getCancelButton();
                        QPushButton *getOkButton();
                    };
                }
            }
        }
    }
}
