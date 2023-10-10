cmake_minimum_required(VERSION 3.5)

project(babaIsYouGraphique VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS  "-Wall -pedantic-errors")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    baba.cpp baba.h best.cpp best.h boardview.cpp boardview.h box.cpp box.h
    command.h composant.cpp composant.h connector.cpp connector.h controller.h controller.cpp connector.h direction.cpp
    direction.h effect.cpp effect.h element.cpp element.h filemanager.cpp filemanager.h flag.cpp flag.h game.cpp
    game.h goop.cpp goop.h grass.cpp grass.h iobserver.h is.cpp is.h kill.cpp kill.h isubject.cpp
    isubject.h lava.cpp lava.h metal.cpp metal.h movecommand.cpp movecommand.h managedata.cpp managedata.h
    position.cpp position.h push.cpp push.h rock.cpp rock.h rule.cpp rule.h sink.cpp sink.h
    stop.cpp stop.h textobject.cpp textobject.h wall.cpp wall.h win.cpp win.h you.cpp you.h gamecomponent.h irule.h
    isyou.cpp isyou.h isPush.cpp isPush.h iskill.cpp iskill.h issink.cpp issink.h isstop.cpp isstop.h isbest.cpp
    isbest.h isWin.h isWin.cpp file/level_0.txt file/level_1.txt file/level_2.txt file/level_3.txt file/level_4.txt
    file/baba.png file/baba_text.png file/best_text.png file/flag.png file/flag_text.png file/grass.png file/grass1.png
    file/is.png file/kill_text.png file/lava.png file/lava_text.png file/metal.png file/push.png file/rock.png file/rock_text.png
    file/sink_text.png file/stop_text.png file/wall.png file/wall_text.png file/water.png file/water_text.png file/win_text.png
    file/you.png
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(babaIsYouGraphique
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET babaIsYouGraphique APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(babaIsYouGraphique SHARED
            ${PROJECT_SOURCES}
        )
    # Define properties for Android with Qt 5 after find_package() calls as:
    #    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
else()
    add_executable(babaIsYouGraphique
        ${PROJECT_SOURCES}
    )
endif()
endif()

target_link_libraries(babaIsYouGraphique PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(babaIsYouGraphique PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS babaIsYouGraphique
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(babaIsYouGraphique)
endif()
