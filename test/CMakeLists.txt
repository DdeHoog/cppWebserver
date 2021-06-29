set(BINARY ${CMAKE_PROJECT_NAME}_test)

<<<<<<< HEAD
# add test files
set(TEST_SOURCES main.cpp ReceiverTests.cpp ResponseTests.cpp)
=======
# add test files here
# set(TEST_SOURCES main.cpp ReceiverTests.cpp SenderTests.cpp)
set(TEST_SOURCES main.cpp ReceiverTests.cpp)
>>>>>>> 9552f076cb7f0c2ce934816540004f5164bf39a4

add_executable(${BINARY} ${TEST_SOURCES})

add_test(NAME ${BINARY} COMMAND ${BINARY})

target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib gtest)