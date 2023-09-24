cmake_minimum_required(VERSION 3.26)

add_executable(26_4_1 ../main.cpp
        ../include/utilities.h
        ../include/player.h
        ../include/track.h
        utilities.cpp
        player.cpp
        track.cpp
)

target_include_directories(26_4_1 PUBLIC ${CMAKE_SOURCE_DIR}/include)
