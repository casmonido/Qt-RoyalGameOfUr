QT += widgets

HEADERS += \
    board.h \
    piece.h \
    square.h \
    enums.h \
    game.h \
    dies.h

SOURCES += \
        main.cpp \
    board.cpp \
    piece.cpp \
    square.cpp \
    game.cpp \
    dies.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/graphicsview/royalurgame
INSTALLS += target

RESOURCES += \
    board.qrc
