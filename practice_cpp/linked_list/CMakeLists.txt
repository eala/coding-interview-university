project(linked_list)

file(GLOB SRCS *.cpp)

add_library(linked_list SHARED ${SRCS})
