cmake_minimum_required(VERSION 3.16)
project(Platformer)

set(CMAKE_CXX_STANDARD 20)
set(BIN_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${BIN_DIRECTORY})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${BIN_DIRECTORY})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN_DIRECTORY})

link_directories("$ENV{BAMBOO_DIR}/bin")

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_options(-DPROFILE)
endif ()

file(GLOB_RECURSE SOURCES src/*.cpp)
file(GLOB_RECURSE INCLUDE src/*.hpp)

add_library(Platformer SHARED "${SOURCES}" Platformer.def "${INCLUDE}")

set_target_properties(Platformer
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${BIN_DIRECTORY}"
        LIBRARY_OUTPUT_DIRECTORY "${BIN_DIRECTORY}"
        RUNTIME_OUTPUT_DIRECTORY "${BIN_DIRECTORY}"
)

# add_custom_command(TARGET Platformer POST_BUILD
#         COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:Platformer> ${BIN_DIRECTORY}
# )

target_include_directories(Platformer PUBLIC ${PROJECT_SOURCE_DIR}/src)

# Dependencies - Bamboo
target_include_directories(Platformer PUBLIC $ENV{BAMBOO_DIR}/include)
target_link_libraries(Platformer Bamboo)