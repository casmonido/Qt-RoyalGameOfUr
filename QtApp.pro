QT += widgets

HEADERS += \
    board.h \
    piece.h \
    square.h \
    enums.h \
    game.h \
    dice.h \
    settingswindow.h \
    gamewindow.h

SOURCES += \
        main.cpp \
    board.cpp \
    piece.cpp \
    square.cpp \
    game.cpp \
    dice.cpp \
    settingswindow.cpp \
    gamewindow.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/graphicsview/royalurgame
INSTALLS += target

RESOURCES += \
    board.qrc

FORMS += \
    settingswindow.ui
