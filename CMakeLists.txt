cmake_minimum_required(VERSION 3.10)
project(g4-ne697)
set(APP_NAME sim)

file(GLOB SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)

include_directories(${PROJECT_SOURCE_DIR}/include) #point to the header files

# Now we use the variable, instead of specifying one .cpp file
add_executable(${APP_NAME} ${SOURCES})