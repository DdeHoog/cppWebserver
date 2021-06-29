set(BINARY ${CMAKE_PROJECT_NAME}_test)


# add test files here
# set(TEST_SOURCES main.cpp ReceiverTests.cpp SenderTests.cpp ResponseTests.cpp)
set(TEST_SOURCES main.cpp ReceiverTests.cpp)

add_executable(${BINARY} ${TEST_SOURCES})

add_test(NAME ${BINARY} COMMAND ${BINARY})

target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib gtest)