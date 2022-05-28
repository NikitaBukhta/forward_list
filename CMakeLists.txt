cmake_minimum_required(VERSION 3.0.0)

project(list)

set(
    EXE
    $CACHE{CMAKE_PROJECT_NAME}
)

set(
    SRC
    main.cpp
)

add_executable(
    ${EXE}
    ${SRC}
)

#------------------------------------- INCLUDE LIBS #-------------------------------------#

add_subdirectory(forward_list)

set(
    ALL_LIBS
    list_lib
)

target_link_libraries(
    ${EXE}
    ${ALL_LIBS}
)