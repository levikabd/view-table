cmake_minimum_required(VERSION 3.13.0)
project(view-table VERSION 0.1.0 LANGUAGES C CXX)

add_executable(view-table main.cpp view-table.cpp)

set(CURSES_HAVE_NCURSES_H TRUE)
set(CURSES_NEED_NCURSES TRUE)
find_package(Curses)
set(CMAKE_CXX_FLAGS "-lncursesw")
