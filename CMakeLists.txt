# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("FreeBurn")

# Include sub-projects.
add_subdirectory ("FreeBurn")

# RWSDK
target_include_directories(
    ${PROJECT_NAME} 
    PUBLIC "$ENV{RWGSDK}/include/opengl"
)
