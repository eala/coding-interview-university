file(GLOB SRCS *.cpp)

ADD_EXECUTABLE(testLinkedList ${SRCS})

include_directories("${gtest_SOURCE_DIR}/include")
link_directories("${CMAKE_BUILD_DIR}/linked_list")

TARGET_LINK_LIBRARIES(testLinkedList
    linked_list
    gtest
    gmock
)

add_test(NAME testLinkedList
         COMMAND testLinkedList)