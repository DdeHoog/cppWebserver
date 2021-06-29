set(BINARY ${CMAKE_PROJECT_NAME})

# add source files
set(SOURCES HttpRequest.hpp HttpResponse.hpp HttpParser.cpp HttpParser.hpp Utils.hpp Response.cpp Response.hpp)

# add_executable(${BINARY}_run ${SOURCES})

add_library(${BINARY}_lib STATIC ${SOURCES})

# target_link_libraries(${BINARY}_run ws2_32)
