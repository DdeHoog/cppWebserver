set(BINARY ${CMAKE_PROJECT_NAME})

# add all source files here, except for main
set(SOURCES main.cpp HttpServer.cpp HttpRequest.hpp HttpParser.cpp HttpParser.hpp Utils.hpp Sender.cpp Sender.hpp Response.cpp Response.hpp)

add_executable(${BINARY}_run ${SOURCES})

add_library(${BINARY}_lib STATIC ${SOURCES})

target_link_libraries(${BINARY}_run ws2_32)
