#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "src/window.hpp"

int main()
{
    Window window(1080, 900, "MyEngine");

    while(!window.windowShouldClose())
    {
        window.windowSwapBuffers();
        window.windowPollEvents();
    }
    window.~Window();
    return 0;
}

