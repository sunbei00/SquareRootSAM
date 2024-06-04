cmake_minimum_required(VERSION 3.5)
project(SquareRootSAM)

set(CMAKE_CXX_STANDARD 17)

# 정책 CMP0074 설정
if(POLICY CMP0074)
    cmake_policy(SET CMP0074 NEW)
endif()


set(INCLUDE_DIRS
        ${CMAKE_SOURCE_DIR}/ThirdParty/
        ${CMAKE_SOURCE_DIR}/ThirdParty/glad/include
        ${GLFW3_INCLUDE_DIR}
        ${CMAKE_SOURCE_DIR}/ThirdParty/imgui
        ${CMAKE_SOURCE_DIR}/ThirdParty/eigen
)
file(GLOB SRC_FILES
        ${CMAKE_SOURCE_DIR}/ThirdParty/imgui/*.cpp
        ${CMAKE_SOURCE_DIR}/ThirdParty/imgui/backends/imgui_impl_glfw.cpp
        ${CMAKE_SOURCE_DIR}/ThirdParty/imgui/backends/imgui_impl_opengl3.cpp

        ${CMAKE_SOURCE_DIR}/ThirdParty/glad/src/glad.c
)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/")

find_package(OpenGL REQUIRED)
find_package(GLFW3 REQUIRED)

add_executable(Viewer Viewer.cpp ${SRC_FILES})
target_include_directories(Viewer PUBLIC ${INCLUDE_DIRS})
target_link_libraries(Viewer PUBLIC OpenGL::GL ${GLFW3_LIBRARY})
