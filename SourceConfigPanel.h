#pragma once

#include "Controller.h"
#include "ModelConfigSource.h"
#include <QLineEdit>
#include <QTextEdit>
#include <QWidget>

using net::draconia::util::Controller;
using net::draconia::util::model::ModelConfigSource;

namespace net
{
    namespace draconia
    {
        namespace util
        {
            namespace ui
            {
                class SourceConfigPanel : public QWidget
                {
                    Q_OBJECT

                    Controller &mRefController;
                protected:
                    Controller &getController() const;
                    ModelConfigSource &getModel() const;
                public:
                    SourceConfigPanel(QWidget *parent);
                    SourceConfigPanel(QWidget *parent, const Controller &mRefController);
                    virtual ~SourceConfigPanel() = 0;

                    virtual void reject() = 0;
                };
            }
        }
    }
}
