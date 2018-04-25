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
    gameScene = new GraphicsScene();
    connect(gameScene, SIGNAL(gameEnded(WhoWon)), this, SLOT(displayWinner(WhoWon)));
    gameView->setScene(gameScene);
    settingsModel = SettingsModel::getInstance(); //new SettingsModel();
    connect(settingsModel, SIGNAL(fontChanged(QFont)), gameScene, SLOT(changeFont(QFont)));
    connect(settingsModel, SIGNAL(moveTimeChanged(int)), gameScene, SLOT(changeMoveTime(int)));
    connect(settingsModel, SIGNAL(playersColorChanged(QColor)), gameScene, SLOT(changePlayersColor(QColor)));
}


void GameWindow::openSettings()
{
    SettingsWindow *settings =  new SettingsWindow(this, settingsModel);
    settings->show();
}

void GameWindow::displayWinner(WhoWon winner) {
    // open popup dialog with options
}

void GameWindow::newGame()
{
    NewGameDialog* dialog = new NewGameDialog(this);
    if (dialog->exec() != QDialog::Accepted)
        return;
    delete gameScene;
    gameScene = new GraphicsScene();
    connect(gameScene, SIGNAL(gameEnded(WhoWon)), this, SLOT(displayWinner(WhoWon)));
    gameView->setScene(gameScene);
}

GameWindow::~GameWindow()
{
    delete gameScene;
    delete gameView;
    delete settingsModel;
}






void GraphicsScene::changeFont(QFont f) {
    game->changeFont(f);
}

void GraphicsScene::changeMoveTime(int time) {
    game->changeMoveTime(time);
}

void GraphicsScene::changePlayersColor(QColor c) {
    game->changePlayersColor(c);
}
