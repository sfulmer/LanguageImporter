#include "App.h"
#include "DataTableModel.h"
#include "DBPathObserver.h"
#include "MainPanel.h"
#include <QDebug>
#include <QException>
#include <QGridLayout>

using net::draconia::util::languageimporter::observers::DBPathObserver;
using namespace net::draconia::util::languageimporter::ui;
using net::draconia::util::languageimporter::ui::model::DataTableModel;

void MainPanel::dbPathChanged(QString &sDBPath)
{
    getModel().getConfiguration().setDatabasePath(sDBPath);
}

void MainPanel::doBrowse()
{
    getController().browseForDBPath();
}

void MainPanel::doConfig()
{
    getController().showConfigDialog();
}

QPushButton *MainPanel::getBrowseButton()
{
    if(mBtnBrowse == nullptr)
        {
        mBtnBrowse = new QPushButton("&Browse...", this);

        connect(mBtnBrowse, &QPushButton::clicked, this, &MainPanel::doBrowse);
        }

    return(mBtnBrowse);
}

ButtonPanel *MainPanel::getButtonPanel()
{
    if(mPnlButtons == nullptr)
        mPnlButtons = new ButtonPanel(this, getController());

    return(mPnlButtons);
}

QPushButton *MainPanel::getConfigButton()
{
    if(mBtnConfig == nullptr)
        {
        mBtnConfig = new QPushButton("Config...", this);

        connect(mBtnConfig, &QPushButton::clicked, this, &MainPanel::doConfig);
        }

    return(mBtnConfig);
}

Controller &MainPanel::getController() const
{
    return(static_cast<App *>(QCoreApplication::instance())->getController());
}

QTableView *MainPanel::getDataTable()
{
    if(mTblData == nullptr)
        {
        mTblData = new QTableView(this);
        try
            {
            QList<Language> &lstModel = getModel().getLanguages();
            DataTableModel *model = new DataTableModel(lstModel);

            mTblData->setModel(model);
            }
        catch(QException e)
            {
            qDebug() << e.what();
            }
        }

    return(mTblData);
}

QLabel *MainPanel::getDBPathLabel()
{
    if(mLblDBPath == nullptr)
        {
        mLblDBPath = new QLabel("&DB Path:", this);
        mLblDBPath->setBuddy(getDBPathText());
        mLblDBPath->setAutoFillBackground(false);
        }

    return(mLblDBPath);
}

QLineEdit *MainPanel::getDBPathText()
{
    if(mTxtDBPath == nullptr)
        {
        mTxtDBPath = new QLineEdit(this);
        mTxtDBPath->setContextMenuPolicy(Qt::ContextMenuPolicy::DefaultContextMenu);

        connect(mTxtDBPath, SIGNAL(QLineEdit::textChanged(QString&)), this, SLOT(MainWindow::dbPathChanged(QString&)));
        }

    return(mTxtDBPath);
}

Model &MainPanel::getModel()
{
    return(getController().getModel());
}

QComboBox *MainPanel::getSourceComboBox()
{
    if(mCboSource == nullptr)
        {
        mCboSource = new QComboBox(this);

        mCboSource->addItems({{"URL", "Text", "Database"}});
        mCboSource->setCurrentIndex(0);
        mCboSource->setEditable(false);

        connect(mCboSource, SIGNAL(QComboBox::currentTextChanged(QString&)), this, SLOT(MainPanel::sourceChanged(QString&)));
        }

    return(mCboSource);
}

QLabel *MainPanel::getSourceLabel()
{
    if(mLblSource == nullptr)
        {
        mLblSource = new QLabel("&Source:", this);
        mLblSource->setBuddy(getSourceComboBox());
        mLblSource->setAutoFillBackground(false);
        }

    return(mLblSource);
}

void MainPanel::initControls()
{
    QGridLayout *layout = new QGridLayout(this);

    layout->addWidget(getSourceLabel(), 0, 0, 1, 1);
    layout->addWidget(getSourceComboBox(), 0, 1, 1, 1);
    layout->addWidget(getConfigButton(), 0, 2, 1, 1);
    layout->addWidget(getDBPathLabel(), 1, 0, 1, 1);
    layout->addWidget(getDBPathText(), 1, 1, 1, 1);
    layout->addWidget(getBrowseButton(), 1, 2, 1, 1);
    layout->addWidget(getDataTable(), 2, 0, 1, 3);
    layout->addWidget(getButtonPanel(), 3, 0, 1, 3);

    setLayout(layout);
}

void MainPanel::initPanel()
{
    setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));

    initControls();
}

void MainPanel::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    getDBPathText()->setText(getModel().getConfiguration().getDatabasePath());
    getSourceComboBox()->setCurrentIndex(0);

    getModel().getConfiguration().addObserver(new DBPathObserver(getDBPathText()));
}

void MainPanel::sourceChanged(QString &sSource)
{
    getModel().getConfiguration().setSource(sSource);
}

MainPanel::MainPanel(QWidget *parent)
    :   QWidget(parent)
    ,   mPnlButtons(nullptr)
    ,   mCboSource(nullptr)
    ,   mLblDBPath(nullptr)
    ,   mLblSource(nullptr)
    ,   mTxtDBPath(nullptr)
    ,   mBtnBrowse(nullptr)
    ,   mBtnConfig(nullptr)
    ,   mTblData(nullptr)
{
    initPanel();
}

MainPanel::~MainPanel()
{ }
