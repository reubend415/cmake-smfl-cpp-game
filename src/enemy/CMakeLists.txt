# Add the enemy library
add_library(enemy enemy.cpp enemy.h)

# Include headers for the enemy library
target_include_directories(enemy PRIVATE ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(enemy PRIVATE sfml-graphics utils player)
target_compile_features(enemy PRIVATE cxx_std_17)