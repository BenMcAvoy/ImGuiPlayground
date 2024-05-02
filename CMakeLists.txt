# Project configuration
cmake_minimum_required(VERSION 3.5...3.19)
project(ImGuiPlayground)

# Download dependencies with `FetchContent`
include(FetchContent)
find_package(OpenGL)
FetchContent_Declare(glfw GIT_REPOSITORY https://github.com/glfw/glfw.git GIT_TAG master)
FetchContent_MakeAvailable(glfw)

FetchContent_Declare(imgui GIT_REPOSITORY https://github.com/ocornut/imgui.git GIT_TAG docking)
FetchContent_GetProperties(imgui)

if (NOT imgui_POPULATED)
    FetchContent_Populate(imgui)
    set(IMGUI_INCLUDE_DIR ${imgui_SOURCE_DIR}/)
    file(GLOB IMGUI_SOURCES ${imgui_SOURCE_DIR}/*.cpp)
    file(GLOB IMGUI_HEADERS ${imgui_SOURCE_DIR}/*.h)
    add_library(imgui STATIC ${IMGUI_SOURCES} ${IMGUI_SOURCES} ${imgui_SOURCE_DIR}/backends/imgui_impl_glfw.cpp ${imgui_SOURCE_DIR}/backends/imgui_impl_opengl3.cpp)
    target_include_directories(imgui PUBLIC ${IMGUI_INCLUDE_DIR} ${OPENGL_INCLUDE_DIR} ${GLFW_INCLUDE_DIR})
    target_link_libraries(imgui ${OPENGL_LIBRARIES} glfw)
endif ()

# Build options
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_VERBOSE_MAKEFILE 1)
set(CMAKE_CXX_STANDARD 20)

# Configure GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

# Build the project
add_executable(ImGuiPlayground src/main.cpp)

# Link with GLFW and ImGui
target_link_libraries(ImGuiPlayground PRIVATE glfw imgui OpenGL::GL)
target_include_directories(ImGuiPlayground PRIVATE ${CMAKE_CURRENT_LIST_DIR}/include ${CMAKE_CURRENT_LIST_DIR}/src ${imgui_INCLUDE_DIRS})

# Link with OpenGL
find_package(OpenGL REQUIRED)
target_link_libraries(ImGuiPlayground PRIVATE glfw imgui OpenGL::GL)

if (UNIX)
	# Enable all warnings and treat them as errors
	target_compile_options(ImGuiPlayground PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()

if (MSVC)
	# Enable all warnings and treat them as errors
	target_compile_options(ImGuiPlayground PRIVATE /W4 /WX)
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(DEBUG)
endif()
