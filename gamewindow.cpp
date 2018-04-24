#include "gamewindow.h"

GameWindow::GameWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setWindowTitle("The royal game of Ur");
    QToolBar *mainBar = new QToolBar(this);
    addToolBar(mainBar);
    newGameAction = new QAction(tr("New game"), mainBar);
    settingsAction = new QAction(tr("Settings"), mainBar);
    mainBar->addAction(newGameAction);
    mainBar->addAction(settingsAction);
    gameView = new GraphicsView(this);
    setCentralWidget(gameView);
    connect(newGameAction, SIGNAL(triggered()),
            this, SLOT(newGame()));
    connect(settingsAction, SIGNAL(triggered()),
            this, SLOT(openSettings()));
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

void GameWindow::displayWinner(WhoWon winner) {
    // open popup dialog with options
}

void GameWindow::newGame()
{
    //popup: do you really want to ?
    delete gameScene;
    gameScene = new GraphicsScene();
    connect(gameScene, SIGNAL(gameEnded(WhoWon)), this, SLOT(displayWinner(WhoWon)));
    gameView->setScene(gameScene);
}

GameWindow::~GameWindow()
{
    delete gameScene;
    delete gameView;
}
