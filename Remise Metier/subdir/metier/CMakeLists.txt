cmake_minimum_required(VERSION 3.5)

project(BabaIsYou LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS  "-Wall -pedantic-errors")
add_executable(BabaIsYou main.cpp BoardView.h Game.h Box.h IObserver.h ISubject.h ObjectManager.h FileManager.h
RuleElement.h RuleConnector.h RuleEffect.h Player.h ObjectState.h GameObject.h Position.h Direction.h
Material.h Rule.h Element.h Connector.h Effect.h Controller.h)



install(TARGETS BabaIsYou
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
