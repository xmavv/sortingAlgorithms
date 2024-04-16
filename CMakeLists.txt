cmake_minimum_required(VERSION 3.27)
project(PROJEKT_SORTOWANIE)

MATH(EXPR stack_size "16 * 1024 * 1024")
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--stack,${stack_size}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--stack,16777216")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(PROJEKT_SORTOWANIE
        TESTING/Sources2/xdd.cpp
        TESTING/Headers2/pytanie.h
        TESTING/Sources2/pytanie.cpp
        TESTING/Headers2/event.h
        TESTING/Headers2/event.h
        TESTING/Sources2/event.cpp
        TESTING/Sources2/event.cpp
        TESTING/Headers2/Przyjaciele.h
        TESTING/Headers2/Przyjaciele.h
        TESTING/Sources2/Przyjaciele.cpp
        TESTING/Sources2/Przyjaciele.cpp
        TESTING/Sources2/polimorfizm.cpp
        TESTING/Sources2/polimorfizm.cpp
        Sources/main.cpp
        Sources/Menu.cpp
        Headers/Menu.h
        Headers/Menu.h
        Sources/Menu.cpp
        Sources/Algorithm.cpp
        Headers/Algorithm.h
        Headers/Algorithm.h
        Sources/Algorithm.cpp
        Sources/Quicksort.cpp
        Headers/Quicksort.h
        Headers/Quicksort.h
        Sources/Heapsort.cpp
        Headers/Heapsort.h
        Sources/Heapsort.cpp
        Headers/Heapsort.h
        Sources/Insertionsort.cpp
        Headers/Insertionsort.h
        Headers/Insertionsort.h
        Sources/Shellsort.cpp
        Headers/Shellsort.h
        Headers/Shellsort.h
        Sources/Utilities.cpp
        Headers/Utilities.h
        Sources/App.cpp
        Headers/App.h
        Headers/App.h
        TESTING/Sources2/WSKAZNIKI.cpp
        Sources/App.cpp
        Headers/App.h
        Sources/PreSort.cpp
        Headers/PreSort.h
        Headers/PreSort.h)
