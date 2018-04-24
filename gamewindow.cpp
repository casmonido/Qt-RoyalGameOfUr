#include "gamewindow.h"

GameWindow::GameWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QToolBar *mainBar = new QToolBar;
    addToolBar(mainBar);
    newGameAction = new QAction(tr("New game"), mainBar);
    settingsAction = new QAction(tr("Settings"), mainBar);
    mainBar->addAction(newGameAction);
    mainBar->addAction(settingsAction);
    gameView = new GraphicsView(this);
    setCentralWidget(gameView);

    //    connect(newGameAction,
    //            SIGNAL(triggered()),
    //            this,
    //            SLOT(newGame()));
    //    connect(settingsAction,
    //            SIGNAL(triggered()),
    //            this,
    //            SLOT(openSettings()));
    //    connect(exitAction,
    //            SIGNAL(triggered()),
    //            this,
    //            SLOT(close()));
    newGame();
}


void GameWindow::openSettings()
{
//    GameSettingsDialog* settingsDialog = new GameSettingsDialog(player1Name,
//                                                                player2Name,
//                                                                this);
//    if(settingsDialog->exec() == QDialog::Accepted)
//    {
//        player1Name = settingsDialog->getPlayer1Name();
//        player2Name = settingsDialog->getPlayer2Name();
//    }
}

void GameWindow::newGame()
{
    //popup: do you really want to ?
    delete gameScene;
    gameScene = new GraphicsScene();
    gameView->setScene(gameScene);
}

GameWindow::~GameWindow()
{
    delete gameScene;
    delete gameView;
}
