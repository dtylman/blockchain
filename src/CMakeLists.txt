file(GLOB BC_SOURCES *.cpp)

include_directories("../include")
add_library(bclib STATIC ${BC_SOURCES})
