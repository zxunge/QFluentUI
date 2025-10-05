cmake_minimum_required(VERSION 3.22)

project(QFluentUI VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Core Gui Widgets Svg Charts)
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Svg Charts Core5Compat)

qt_standard_project_setup()

add_subdirectory("3rdparty")
add_subdirectory("FluControls")
add_subdirectory("FluUtils")

message(STATUS "Configuration Options Summary --
    Target system:          ${CMAKE_SYSTEM}
    Compiler:
        Build type:         ${CMAKE_BUILD_TYPE}
        C++ compiler:       ${CMAKE_CXX_COMPILER}
        Qt version:         ${QT_DEFAULT_MAJOR_VERSION}
        Qt toolchain:       ${QT_QMAKE_EXECUTABLE}"
)
