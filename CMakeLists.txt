cmake_minimum_required(VERSION 3.22)

project(vostok LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL2 REQUIRED)
find_package(Vulkan REQUIRED)

add_executable(vostok src/main.cxx src/application.cxx)
target_include_directories(vostok PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(vostok PRIVATE SDL2::SDL2 Vulkan::Vulkan)

# EOF
