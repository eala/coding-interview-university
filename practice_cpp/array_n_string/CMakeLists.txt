project(array_n_string)

file(GLOB SRCS *.cpp)

add_library(array_n_string SHARED ${SRCS})
