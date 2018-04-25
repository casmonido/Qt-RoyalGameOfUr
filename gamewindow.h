#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include <QtWidgets>
#include <math.h>
#include "game.h"
#include "newgamedialog.h"
#include "settingswindow.h"
#include "settingsmodel.h"

class GraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    GraphicsScene():
        QGraphicsScene(-8*BoardSquare::WIDTH, -3*BoardSquare::WIDTH, 16*BoardSquare::WIDTH, 6*BoardSquare::WIDTH)
    {
        game = new Game();
        game->setPos(0*BoardSquare::WIDTH, 0*BoardSquare::WIDTH);
        addItem(game);
        connect(game, SIGNAL(gameEnded(WhoWon)), this, SIGNAL(gameEnded(WhoWon)));
    }
    ~GraphicsScene() {
        delete game;
    }
public slots:
    void changeFont(QFont);
    void changeMoveTime(int);
    void changePlayersColor(QColor);
signals:
    void gameEnded(WhoWon);
private:
    Game *game;
};


class GraphicsView : public QGraphicsView
{
public:
    GraphicsView(QMainWindow *parent) : QGraphicsView(parent)
    {
        setRenderHint(QPainter::Antialiasing);
        setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
        setBackgroundBrush(backgoundColor);
        setWindowTitle("The royal game of Ur");
    }
protected:
    void resizeEvent(QResizeEvent *) override
    {
        this->fitInView(QRectF(-8*BoardSquare::WIDTH, -3*BoardSquare::WIDTH,
                               16*BoardSquare::WIDTH, 6*BoardSquare::WIDTH), Qt::KeepAspectRatio);
    }
private:
    QColor backgoundColor = QColor(32, 12, 75);
};


class GameWindow: public QMainWindow
{
    Q_OBJECT
public:
    GameWindow(QWidget *parent = 0);
    ~GameWindow();
public slots:
    void newGame();
    void openSettings();
    void displayWinner(WhoWon);
private:
    QAction *newGameAction;
    QAction *settingsAction;
    GraphicsView *gameView;
    GraphicsScene *gameScene;
    SettingsModel *settingsModel;
};

#endif // GAMEWINDOW_H
