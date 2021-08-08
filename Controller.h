#pragma once

#include "Model.h"
#include <QObject>

using net::draconia::util::model::Model;

namespace net
{
    namespace draconia
    {
        namespace util
        {
            class App;

            class Controller : public QObject
            {
                Q_OBJECT

                App &mRefApp;
                Model mObjModel;
            protected:
                App &getApplication();
            public:
                Controller(App &refApp);
                ~Controller();

                void browseForDBPath();
                void exit();
                Model &getModel() const;
                void reset();
                void save();
                void setModel(const Model &refModel);
                void showConfigDialog();
            };
        }
    }
}
