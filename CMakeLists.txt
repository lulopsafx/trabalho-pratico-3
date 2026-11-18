cmake_minimum_required(VERSION 3.10)
project(PROJECT3 C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

include_directories(headers)

set(SOURCES
    main.c
    sources/pokemon.c
    sources/trainer.c
    sources/pokelist.c
    sources/team.c
)
add_executable(aedstp2 ${SOURCES})
target_link_libraries(aedstp2 m)