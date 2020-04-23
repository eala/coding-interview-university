file(GLOB SRCS *.cpp)

ADD_EXECUTABLE(testArrayString ${SRCS})

include_directories("${gtest_SOURCE_DIR}/include")
link_directories("${CMAKE_BUILD_DIR}/array_n_string")

TARGET_LINK_LIBRARIES(testArrayString
    array_n_string
    gtest
    gmock
)

add_test(NAME testArrayString
         COMMAND testArrayString)