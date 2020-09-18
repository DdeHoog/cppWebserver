set(BINARY ${CMAKE_PROJECT_NAME})

set(SOURCES HttpRequest.hpp HttpParser.cpp HttpParser.hpp Utils.hpp)

# add_executable(${BINARY}_run ${SOURCES})

add_library(${BINARY}_lib STATIC ${SOURCES})

# target_link_libraries(${BINARY}_run ws2_32)
