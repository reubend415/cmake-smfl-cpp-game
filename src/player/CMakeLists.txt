# Add the player library
add_library(player player.cpp player.h)

# Include headers for the player library
target_include_directories(player PRIVATE ${CMAKE_SOURCE_DIR}/src)
target_include_directories(player PRIVATE ${SFML_SOURCE_DIR}/include) 
target_compile_features(player PRIVATE cxx_std_17)


