#pragma once

#include "Model.h"
#include <QObject>

using net::draconia::util::languageimporter::model::Model;

namespace net
{
    namespace draconia
    {
        namespace util
        {
            namespace languageimporter
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
                    Model &getModel();
                    void reset();
                    void save();
                    void setModel(Model &refModel);
                    void showConfigDialog();
                };
            }
        }
    }
}
