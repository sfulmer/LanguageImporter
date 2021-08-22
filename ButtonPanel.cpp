#include "ButtonPanel.h"
#include <QHBoxLayout>

using namespace net::draconia::util::languageimporter::ui;

void ButtonPanel::doQuit()
{
    getController().exit();
}

void ButtonPanel::doReset()
{
    getController().reset();
}

void ButtonPanel::doSave()
{
    getController().save();
}

Controller &ButtonPanel::getController() const
{
    return(mRefController);
}

QPushButton *ButtonPanel::getQuitButton()
{
    if(mBtnQuit == nullptr)
        {
        mBtnQuit = new QPushButton("&Quit", this);

        connect(mBtnQuit, &QPushButton::clicked, this, &ButtonPanel::doQuit);
        }

    return(mBtnQuit);
}

QPushButton *ButtonPanel::getResetButton()
{
    if(mBtnReset == nullptr)
        {
        mBtnReset = new QPushButton("&Reset", this);

        connect(mBtnReset, &QPushButton::clicked, this, &ButtonPanel::doReset);
        }

    return(mBtnReset);
}

QPushButton *ButtonPanel::getSaveButton()
{
    if(mBtnSave == nullptr)
        {
        mBtnSave = new QPushButton("&Save", this);
        mBtnSave->setDisabled(true);

        connect(mBtnSave, &QPushButton::clicked, this, &ButtonPanel::doSave);
        }

    return(mBtnSave);
}

void ButtonPanel::initControls()
{
    QLayout *layout = new QHBoxLayout(this);

    layout->addWidget(getResetButton());
    layout->addWidget(getSaveButton());
    layout->addWidget(getQuitButton());

    setLayout(layout);
}

void ButtonPanel::initPanel()
{
    setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));

    initControls();
}

ButtonPanel::ButtonPanel(QWidget *parent, Controller &refController)
    :   QWidget(parent)
    ,   mRefController(refController)
    ,   mBtnQuit(nullptr)
    ,   mBtnReset(nullptr)
    ,   mBtnSave(nullptr)
{
    initPanel();
}

ButtonPanel::~ButtonPanel()
{ }
