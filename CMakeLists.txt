cmake_minimum_required(VERSION 3.10)
project(QTViewBDF)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)

add_subdirectory(Reader)
include_directories(Reader)

link_directories(${PROJECT_BINARY_DIR}/lib)

# QT

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(QT NAMES Qt5 REQUIRED COMPONENTS Widgets OpenGL)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets
    OpenGL)
find_package(VTK)
find_package(OpenCASCADE)

find_package(OpenCASCADE)
if (NOT OpenCASCADE_FOUND)
    message(FATAL_error "OpenCASCADE is not found")
endif()
include_directories(${OpenCASCADE_INCLUDE_DIR})


find_package(Eigen3)
include_directories(${EIGEN3_INCLUDE_DIR})

set(SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        occview.h occview.cpp occdocument.cpp occdocument.h)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
        qt_add_executable(QTViewBDF
            MANUAL_FINALIZATION
            ${SOURCES}
        )
else()
        add_executable(QTViewBDF
            ${SOURCES}
        )
endif()

target_link_libraries(QTViewBDF PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
            Qt${QT_VERSION_MAJOR}::OpenGL
            ${VTK_LIBRARIES}
            ${OpenCASCADE_LIBRARIES} Reader)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(QTViewBDF)
endif()
