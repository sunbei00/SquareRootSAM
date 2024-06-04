cmake_minimum_required(VERSION 3.5)
project(SquareRootSAM.cpp)

set(CMAKE_CXX_STANDARD 17)

# cmake policy CMP0074
if(POLICY CMP0074)
    cmake_policy(SET CMP0074 NEW)
endif()

# find_package
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/")
find_package(OpenGL REQUIRED)
find_package(GLFW3 REQUIRED)

add_definitions("-D SOPHUS_USE_BASIC_LOGGING")

# SquareRootSAM
set(SQUARE_ROOT_SAM_INCLUDE_DIRS
    ${CMAKE_SOURCE_DIR}/ThirdParty/eigen
    ${CMAKE_SOURCE_DIR}/ThirdParty/sophus
    ${CMAKE_SOURCE_DIR}/SquareRootSAM/include

)

add_library(SquareRootSAM ${CMAKE_SOURCE_DIR}/SquareRootSAM/src/SquareRootSAM.cpp)
target_include_directories(SquareRootSAM PUBLIC ${SQUARE_ROOT_SAM_INCLUDE_DIRS})

# Viewer
set(VIEWER_INCLUDE_DIRS
        ${CMAKE_SOURCE_DIR}/ThirdParty/
        ${CMAKE_SOURCE_DIR}/ThirdParty/glad/include
        ${GLFW3_INCLUDE_DIR}
        ${CMAKE_SOURCE_DIR}/ThirdParty/imgui
        ${CMAKE_SOURCE_DIR}/ThirdParty/eigen
        ${CMAKE_SOURCE_DIR}/ThirdParty/sophus
        ${CMAKE_SOURCE_DIR}/SquareRootSAM/include
)
file(GLOB VIEWER_SRC_FILES
        ${CMAKE_SOURCE_DIR}/ThirdParty/imgui/*.cpp
        ${CMAKE_SOURCE_DIR}/ThirdParty/imgui/backends/imgui_impl_glfw.cpp
        ${CMAKE_SOURCE_DIR}/ThirdParty/imgui/backends/imgui_impl_opengl3.cpp

        ${CMAKE_SOURCE_DIR}/ThirdParty/glad/src/glad.c
)

add_executable(Viewer ${CMAKE_SOURCE_DIR}/Viewer/Viewer.cpp ${VIEWER_SRC_FILES})
target_include_directories(Viewer PRIVATE ${VIEWER_INCLUDE_DIRS})
target_link_libraries(Viewer PRIVATE OpenGL::GL ${GLFW3_LIBRARY} SquareRootSAM)
