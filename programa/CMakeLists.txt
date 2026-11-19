cmake_minimum_required(VERSION 3.10)
project(PROJECT3 C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

include_directories(headers)

set(SOURCES
    main.c
    sources/pokemon.c
    sources/pokelist.c
    sources/pokecenter.c
)
add_executable(aedstp3 ${SOURCES})
target_link_libraries(aedstp3 m)