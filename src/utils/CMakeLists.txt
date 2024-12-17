# Add the utils library
add_library(utils gameobject.cpp gameobject.h)

# Include headers for the utils library
target_include_directories(utils PRIVATE ${CMAKE_SOURCE_DIR}/src)
target_include_directories(utils PRIVATE ${SFML_SOURCE_DIR}/include) 
target_compile_features(utils PRIVATE cxx_std_17)


