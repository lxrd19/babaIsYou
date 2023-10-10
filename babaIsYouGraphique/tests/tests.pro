include(../defaults.pri)


TEMPLATE = app
CONFIG += console

SOURCES += main.cpp \
    test.cpp \
    game.cpp \
    box.cpp \
    baba.cpp \
    best.cpp \
    boardview.cpp \
    composant.cpp \
    controller.cpp \
    direction.cpp \
    effect.cpp \
    connector.cpp \
    element.cpp \
    filemanager.cpp \
    flag.cpp \
    goop.cpp \
    grass.cpp \
    is.cpp \
    isbest.cpp \
    iskill.cpp \
    ispush.cpp \
    issink.cpp \
    isstop.cpp \
    isubject.cpp \
    iswin.cpp \
    isyou.cpp \
    kill.cpp \
    lava.cpp \
    metal.cpp \
    position.cpp \
    movecommand.cpp \
    managedata.cpp \
    managedata.h \
    push.cpp \
    rock.cpp \
    rule.cpp \
    sink.cpp \
    stop.cpp \
    textobject.cpp \
    wall.cpp \
    win.cpp \
    you.cpp \

HEADERS += \
    catch.hpp \
    game.h \
    box.h\
    baba.h \
    best.h \
    boardview.h \
    composant.h \
    controller.h \
    direction.h \
    effect.h \
    connector.h \
    element.h \
    filemanager.h \
    flag.h \
    goop.h \
    grass.h \
    is.h \
    isbest.h \
    iskill.h \
    ispush.h \
    issink.h \
    isstop.h \
    isubject.h \
    iswin.h \
    isyou.h \
    kill.h \
    lava.h \
    metal.h \
    position.h \
    movecommand.h \
    push.h \
    rock.h \
    rule.h \
    sink.h \
    stop.h \
    textobject.h \
    wall.h \
    win.h \
    you.h \

OTHER_FILES += \
    file/level_0.txt \
