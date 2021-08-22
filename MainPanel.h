#pragma once

#include "ButtonPanel.h"
#include <QComboBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTableView>
#include <QWidget>

using net::draconia::util::languageimporter::Controller;

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
                    class MainPanel : public QWidget
                    {
                        Q_OBJECT

                        ButtonPanel *mPnlButtons;
                        QComboBox *mCboSource;
                        QLabel *mLblDBPath, *mLblSource;
                        QLineEdit *mTxtDBPath;
                        QPushButton *mBtnBrowse, *mBtnConfig;
                        QTableView *mTblData;
                    protected:
                        void doBrowse();
                        void doConfig();
                        QPushButton *getBrowseButton();
                        ButtonPanel *getButtonPanel();
                        QPushButton *getConfigButton();
                        Controller &getController() const;
                        QTableView *getDataTable();
                        QLabel *getDBPathLabel();
                        QLineEdit *getDBPathText();
                        Model &getModel();
                        QComboBox *getSourceComboBox();
                        QLabel *getSourceLabel();
                        void initControls();
                        void initPanel();
                        virtual void resizeEvent(QResizeEvent *event);
                        void sourceChanged(const QString &sSource);
                    public:
                        MainPanel(QWidget *parent);
                        MainPanel(QWidget *parent, const Controller &refController);
                        ~MainPanel();

                    public slots:
                        void dbPathChanged(const QString &sDBPath);
                    };
                }
            }
        }
    }
}
