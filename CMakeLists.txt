cmake_minimum_required(VERSION 3.20)
project(geom_ode VERSION 0.1.0 LANGUAGES CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# collecting all .cpp files in src/
file(GLOB_RECURSE SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

# Packages
find_package(Torch REQUIRED)

# defining library target
add_library(geom_ode ${SOURCES})

# including headers to geom_ode
target_include_directories(geom_ode PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)
target_include_directories(geom_ode PRIVATE ${TORCH_INCLUDE_DIRS})

# linking libraries to geom_ode
target_link_libraries(geom_ode PRIVATE ${TORCH_LIBRARIES})
