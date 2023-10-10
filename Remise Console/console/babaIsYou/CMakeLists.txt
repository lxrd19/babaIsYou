cmake_minimum_required(VERSION 3.5)

project(babaIsYou LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS  "-Wall -pedantic-errors")
set(CMAKE_PREFIX_PATH "C:/Qt/6.5.0/mingw_64/lib/cmake/Qt6")
find_package(Qt6 COMPONENTS Core REQUIRED)
add_executable(babaIsYou main.cpp baba.cpp baba.h best.cpp best.h boardview.cpp boardview.h box.cpp box.h
command.h composant.cpp composant.h connector.cpp connector.h controller.h controller.cpp connector.h direction.cpp
direction.h effect.cpp effect.h element.cpp element.h filemanager.cpp filemanager.h flag.cpp flag.h game.cpp
game.h goop.cpp goop.h grass.cpp grass.h iobserver.h is.cpp is.h kill.cpp kill.h isubject.cpp
isubject.h lava.cpp lava.h metal.cpp metal.h movecommand.cpp movecommand.h movecommandnoposition.cpp
movecommandnoposition.h position.cpp position.h push.cpp push.h rock.cpp rock.h rule.cpp rule.h sink.cpp sink.h
stop.cpp stop.h textobject.cpp textobject.h wall.cpp wall.h win.cpp win.h you.cpp you.h file/level_0.txt
file/level_1.txt file/level_2.txt file/level_3.txt file/level_4.txt level_0.txt resouces.qrc ${RESOURCE_FILES})

qt6_add_resources(RESOURCE_FILES resources.qrc)
install(TARGETS babaIsYou
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
