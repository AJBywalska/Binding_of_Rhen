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
        blank.cpp \
        boss.cpp \
        bossshoot.cpp \
        button.cpp \
        entity.cpp \
        fire.cpp \
        game.cpp \
        gamestate.cpp \
        heart.cpp \
        hitbox.cpp \
        main.cpp \
        mainmenu.cpp \
        map.cpp \
        monsters.cpp \
        movement.cpp \
        player.cpp \
        shoot.cpp \
        state.cpp

HEADERS += \
    animation.h \
    blank.h \
    boss.h \
    bossshoot.h \
    button.h \
    entity.h \
    fire.h \
    game.h \
    gamestate.h \
    heart.h \
    hitbox.h \
    mainmenu.h \
    map.h \
    monsters.h \
    movement.h \
    player.h \
    shoot.h \
    state.h
