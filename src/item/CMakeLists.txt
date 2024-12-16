# Add the item library
add_library(item item.cpp item.h)

# Include headers for the item library
target_include_directories(item PRIVATE ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(item PRIVATE sfml-graphics player)
target_compile_features(item PRIVATE cxx_std_17)