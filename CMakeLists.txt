cmake_minimum_required(VERSION 3.17)

project(SFML_Practice)

set(CMAKE_CXX_STANDARD 17)

set(SFML_DIR "c:/SFML/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS audio graphics window system REQUIRED)

add_executable(SFML_Practice main.cpp
        UIElements/UIElement.h UIElements/UIConstructor.cpp UIElements/UIConstructor.h UIElements/UIElement.cpp

        UIBodies/RectShapeBody.cpp UIBodies/RectShapeBody.h UIBodies/DrawingBody.cpp UIBodies/DrawingBody.h
        UIBodies/CameraBody.cpp UIBodies/CameraBody.h UIBodies/UIElementBody.cpp UIBodies/UIElementBody.h

        translator.cpp translator.h

        UIEvents/ButtonEvent.cpp UIEvents/ButtonEvent.h UIEvents/InputTextBoxEvent.cpp UIEvents/InputTextBoxEvent.h
        UIEvents/GraphNavEvent.cpp UIEvents/GraphNavEvent.h  UIEvents/DefaultEvent.cpp UIEvents/DefaultEvent.h
        UIEvents/UIEvent.cpp UIEvents/UIEvent.h)

target_link_libraries(SFML_Practice sfml-graphics sfml-audio sfml-window sfml-system)