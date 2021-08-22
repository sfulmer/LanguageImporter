#pragma once

#include "Controller.h"
#include "ModelConfigSource.h"
#include <QPushButton>
#include <QWidget>

using net::draconia::util::languageimporter::model::ModelConfigSource;

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
                        Controller &getController() const;
                        ModelConfigSource &getModel() const;
                        void initControls();
                        void initPanel();
                        void okClicked();
                        virtual void resizeEvent(QResizeEvent *event);
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
