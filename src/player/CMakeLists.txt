# Add the player library
add_library(player player.cpp)

# Include headers for the player library
target_include_directories(player PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(player PRIVATE ${SFML_SOURCE_DIR}/include) 
target_compile_features(player PRIVATE cxx_std_17)


