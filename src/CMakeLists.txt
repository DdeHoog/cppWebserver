set(BINARY ${CMAKE_PROJECT_NAME})

<<<<<<< HEAD
# add source files
set(SOURCES HttpRequest.hpp HttpResponse.hpp HttpParser.cpp HttpParser.hpp Utils.hpp Response.cpp Response.hpp)
=======
# add all source files here, except for main
set(SOURCES main.cpp HttpServer.cpp HttpRequest.hpp HttpParser.cpp HttpParser.hpp Utils.hpp Sender.cpp Sender.hpp)
>>>>>>> 9552f076cb7f0c2ce934816540004f5164bf39a4

add_executable(${BINARY}_run ${SOURCES})

add_library(${BINARY}_lib STATIC ${SOURCES})

target_link_libraries(${BINARY}_run ws2_32)
