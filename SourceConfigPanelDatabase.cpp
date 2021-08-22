#include "App.h"
#include "DatabaseDriver.h"
#include <QGridLayout>
#include <QSqlDatabase>
#include "SourceConfigPanelDatabase.h"

using net::draconia::util::languageimporter::model::DatabaseDriver;
using namespace net::draconia::util::languageimporter::ui;

QComboBox *SourceConfigPanelDatabase::getDatabaseField()
{
    if(mCboDatabase == nullptr)
        {
        mCboDatabase = new QComboBox(this);

        connect(mCboDatabase, SIGNAL(currentIndexChanged(int)), this, SLOT(DatabaseIndexChanged(int)));
        }

    return(mCboDatabase);
}

QLabel *SourceConfigPanelDatabase::getDatabaseLabel()
{
    if(mLblDatabase == nullptr)
        {
        mLblDatabase = new QLabel("Data&base", this);

        mLblDatabase->setAutoFillBackground(false);
        mLblDatabase->setBuddy(getDatabaseField());
        }

    return(mLblDatabase);
}

QComboBox *SourceConfigPanelDatabase::getDriverField()
{
    if(mCboDriver == nullptr)
        {
        mCboDriver = new QComboBox(this);

        for(const DatabaseDriver &driver : DatabaseDriver::getDrivers())
            {
            QVariant variant;

            variant.setValue(driver);

            mCboDriver->addItem(driver.getName(), variant);
            }

        connect(mCboDriver, SIGNAL(currentIndexChanged(int)), this, SLOT(DriverIndexChanged(int)));
        }

    return(mCboDriver);
}

QLabel *SourceConfigPanelDatabase::getDriverLabel()
{
    if(mLblDriver == nullptr)
        {
        mLblDriver = new QLabel("&Driver:", this);

        mLblDriver->setAutoFillBackground(false);
        mLblDriver->setBuddy(getDriverField());
        }

    return(mLblDriver);
}

QComboBox *SourceConfigPanelDatabase::getLanguageFieldField()
{
    if(mCboLanguageField == nullptr)
        {
        mCboLanguageField = new QComboBox(this);

        connect(mCboLanguageField, SIGNAL(currentIndexChanged(int)), this, SLOT(LanguageFieldIndexChanged(int)));
        }

    return(mCboLanguageField);
}

QLabel *SourceConfigPanelDatabase::getLanguageFieldLabel()
{
    if(mLblLanguageField == nullptr)
        {
        mLblLanguageField = new QLabel("&Language Field:", this);

        mLblLanguageField->setAutoFillBackground(false);
        mLblLanguageField->setBuddy(getLanguageFieldField());
        }

    return(mLblDriver);
}

QComboBox *SourceConfigPanelDatabase::getLocaleFieldField()
{
    if(mCboLocaleField == nullptr)
        {
        mCboLocaleField = new QComboBox(this);

        connect(mCboLocaleField, SIGNAL(currentIndexChanged(int)), this, SLOT(LocaleFieldIndexChanged(int)));
        }

    return(mCboLocaleField);
}

QLabel *SourceConfigPanelDatabase::getLocaleFieldLabel()
{
    if(mLblLocaleField == nullptr)
        {
        mLblLocaleField = new QLabel("Loc&ale:", this);

        mLblLocaleField->setAutoFillBackground(false);
        mLblLocaleField->setBuddy(getLocaleFieldField());
        }

    return(mLblLocaleField);
}

QComboBox *SourceConfigPanelDatabase::getTableField()
{
    if(mCboTable == nullptr)
        {
        mCboTable = new QComboBox(this);

        connect(mCboTable, SIGNAL(currentIndexChanged(int)), this, SLOT(TableFieldIndexChanged(int)));
        }

    return(mCboTable);
}

QLabel *SourceConfigPanelDatabase::getTableLabel()
{
    if(mLblTable == nullptr)
        {
        mLblTable = new QLabel("&Table:", this);

        mLblTable->setAutoFillBackground(false);
        mLblTable->setBuddy(getTableField());
        }

    return(mLblTable);
}

void SourceConfigPanelDatabase::initControls()
{
    QGridLayout *layout = new QGridLayout(this);

    layout->addWidget(getDriverLabel(), 0, 0, 1, 1);
    layout->addWidget(getDriverField(), 0, 1, 1, 1);
    layout->addWidget(getDatabaseLabel(), 1, 0, 1, 1);
    layout->addWidget(getDatabaseField(), 1, 1, 1, 1);
    layout->addWidget(getTableLabel(), 2, 0, 1, 1);
    layout->addWidget(getTableField(), 2, 1, 1, 1);
    layout->addWidget(getLanguageFieldLabel(), 3, 0, 1, 1);
    layout->addWidget(getLanguageFieldField(), 3, 1, 1, 1);
    layout->addWidget(getLocaleFieldLabel(), 4, 0, 1, 1);
    layout->addWidget(getLocaleFieldField(), 4, 1, 1, 1);

    setLayout(layout);
}

void SourceConfigPanelDatabase::initPanel()
{
    setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));

    initControls();
}

SourceConfigPanelDatabase::SourceConfigPanelDatabase(SourceConfigDialog *parent)
    :   SourceConfigPanelDatabase(parent, static_cast<App *>(qApp)->getController())
{ }

SourceConfigPanelDatabase::SourceConfigPanelDatabase(SourceConfigDialog *parent, Controller &refController)
    :   SourceConfigPanel(parent, refController)
    ,   mCboDatabase(nullptr)
    ,   mCboDriver(nullptr)
    ,   mCboLanguageField(nullptr)
    ,   mCboLocaleField(nullptr)
    ,   mCboTable(nullptr)
    ,   mLblDatabase(nullptr)
    ,   mLblDriver(nullptr)
    ,   mLblLanguageField(nullptr)
    ,   mLblLocaleField(nullptr)
    ,   mLblTable(nullptr)
{
    initPanel();
}

bool SourceConfigPanelDatabase::isOkAble()
{
    return(!getDriverField()->currentText().isEmpty() && !getDatabaseField()->currentText().isEmpty() && !getTableField()->currentText().isEmpty() && !getLanguageFieldField()->currentText().isEmpty() && !getLocaleFieldField()->currentText().isEmpty());
}

void SourceConfigPanelDatabase::reject()
{
    getDriverField()->setCurrentIndex(-1);
    getDatabaseField()->setCurrentIndex(-1);
    getTableField()->setCurrentIndex(-1);
    getLanguageFieldField()->setCurrentIndex(-1);
    getLocaleFieldField()->setCurrentIndex(-1);
}

void SourceConfigPanelDatabase::DatabaseIndexChanged(int iDatabase)
{
    Q_UNUSED(iDatabase);
}

void SourceConfigPanelDatabase::DriverIndexChanged(int iDriver)
{
    getDatabaseField()->clear();

    if(iDriver >= 0)
        {
        QString &sDriver = qvariant_cast<DatabaseDriver>(getDriverField()->currentData()).getDriver();

        if(QSqlDatabase::isDriverAvailable(sDriver))
            {
            QSqlDatabase db(sDriver);


            }
        }
}

void SourceConfigPanelDatabase::LanguageFieldIndexChanged(const int iLanguageField)
{
    Q_UNUSED(iLanguageField);
}

void SourceConfigPanelDatabase::LocaleFieldIndexChanged(const int iLocaleField)
{
    Q_UNUSED(iLocaleField);
}

void SourceConfigPanelDatabase::TableIndexChanged(const int iTable)
{
    Q_UNUSED(iTable);
}
