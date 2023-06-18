cmake_minimum_required(VERSION 3.22)

project(vostok LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
set(SDL_SHARED TRUE CACHE BOOL "Build a SDL shared library (if available)")
set(SDL_STATIC TRUE CACHE BOOL "Build a SDL static library (if available)")
FetchContent_Declare(
    SDL
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG main  # Replace this with a particular git tag or git hash
    GIT_SHALLOW TRUE
    GIT_PROGRESS TRUE
)
message(STATUS "Using SDL3 via FetchContent")
FetchContent_MakeAvailable(SDL)
set_property(DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/_deps/sdl-src" PROPERTY EXCLUDE_FROM_ALL TRUE)

add_executable(vostok src/main.cxx)

target_link_libraries(vostok PRIVATE SDL3::SDL3)

# EOF
