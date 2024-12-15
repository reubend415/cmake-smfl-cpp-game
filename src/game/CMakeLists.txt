# Add the game library
add_library(game game.cpp game.h)

# Include headers for the game library
target_include_directories(game PRIVATE ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(game PRIVATE sfml-graphics player)
target_compile_features(game PRIVATE cxx_std_17)