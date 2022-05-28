set(
    LIB_NAME
    list_lib
)

set(
    SRC
    src/forward_list.cpp
    src/node.cpp
)

set(
    HEADERS_DIR
    include
    ${CMAKE_CURRENT_SOURCE_DIR}
)

add_library(
    ${LIB_NAME}
    ${SRC}
)

target_include_directories(
    ${LIB_NAME}
    PUBLIC
    ${HEADERS_DIR}
)