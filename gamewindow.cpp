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
    settingsModel = new SettingsModel();
}


void GameWindow::openSettings()
{
    SettingsWindow *settings =  new SettingsWindow(this, settingsModel,
                            SettingsModel::FONT, SettingsModel::MOVE_TIME,
                            SettingsModel::PLAYER_COLOR == Qt::white ?
                                          SettingsModel::Q_STRING_WHITE : SettingsModel::Q_STRING_BLACK);
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
