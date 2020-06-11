TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
INCLUDEPATH += "C:/SFML-2.5.1/include"
LIBS += -L"C:/SFML-2.5.1/lib"
CONFIG(debug, debug|release){
    LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
} else {
    LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
}

SOURCES += \
        animation.cpp \
        button.cpp \
        entity.cpp \
        game.cpp \
        gamestate.cpp \
        hitbox.cpp \
        main.cpp \
        mainmenu.cpp \
        monsters.cpp \
        movement.cpp \
        player.cpp \
        state.cpp

HEADERS += \
    animation.h \
    button.h \
    entity.h \
    game.h \
    gamestate.h \
    hitbox.h \
    mainmenu.h \
    monsters.h \
    movement.h \
    player.h \
    state.h
