cmake_minimum_required(VERSION 3.10)
project(CurvesLibrary)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

include_directories(inc)

# Список исходных файлов для библиотеки
set(LIB_SOURCES
    src/circle.cpp
    src/ellipse.cpp
    src/helix.cpp
)

add_library(curves SHARED ${LIB_SOURCES})

# add_executable(curves_app src/main.cpp)
# target_link_libraries(curves_app curves)