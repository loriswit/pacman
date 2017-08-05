cmake_minimum_required(VERSION 3.9)
project(pacman)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SOURCE_FILES src/*)

include_directories(C:/Users/loris/Repositories/SFML/include)
link_directories(C:/Users/loris/Repositories/SFML/lib C:/Users/loris/Repositories/SFML/extlibs/libs-mingw/x86)

add_executable(pacman ${SOURCE_FILES})
target_link_libraries(pacman sfml-graphics-s sfml-window-s sfml-system-s opengl32 freetype jpeg winmm gdi32)
add_definitions(-DSFML_STATIC)

set(CMAKE_CXX_FLAGS "--debug -Og \
    -Wall \
    -Wextra \
    -pedantic -Wcast-align \
    -Wcast-qual \
    -Wfloat-equal \
    -Wdisabled-optimization \
    -Wformat=2 \
    -Winit-self \
    -Wlogical-op \
    -Wmissing-include-dirs \
    -Wnoexcept \
    -Wold-style-cast \
    -Woverloaded-virtual \
    -Wredundant-decls \
    -Wshadow \
    -Wsign-conversion \
    -Wsign-promo \
    -Wstrict-null-sentinel \
    -Wstrict-overflow=5 \
    -Wswitch-default \
    -Wundef")

