cmake_minimum_required(VERSION 3.0)
project(LearnOpenGL)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 14)

include_directories(${PROJECT_SOURCE_DIR}/include)

# 使用 GLFW 和 GLAD 来设置 OpenGL上下文 并创建一个窗口
add_subdirectory(HelloWindow)