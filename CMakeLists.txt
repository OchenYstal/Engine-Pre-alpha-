cmake_minimum_required(VERSION 3.10)

project(Engine C CXX)

add_executable(${PROJECT_NAME}
    main.cpp
    src/glad.c
    src/window.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE include)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

target_link_libraries(${PROJECT_NAME}
    OpenGL::GL
    glfw
)
