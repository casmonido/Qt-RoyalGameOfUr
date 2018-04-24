#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include <QtWidgets>
#include <math.h>
#include "game.h"

class GraphicsScene : public QGraphicsScene
{
public:
    GraphicsScene():
        QGraphicsScene(-8*BoardSquare::WIDTH, -3*BoardSquare::WIDTH, 16*BoardSquare::WIDTH, 6*BoardSquare::WIDTH)
    {
        game = new Game();
        game->setPos(0*BoardSquare::WIDTH, 0*BoardSquare::WIDTH);
        addItem(game);
    }
    ~GraphicsScene() {
        delete game;
    }
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
//    QGraphicsView* mainPanel_;
//    GameState* gameState_;
public:
    GameWindow(QWidget *parent = 0);
    ~GameWindow();
public slots:
    void newGame();
    void openSettings();
private:
    QAction *newGameAction;
    QAction *settingsAction;
    GraphicsView *gameView;
    GraphicsScene *gameScene;
};

#endif // GAMEWINDOW_H
