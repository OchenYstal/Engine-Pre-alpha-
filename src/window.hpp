#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>

class Window
{
    public:
    Window(int width, int height, const std::string& title);
    ~Window();

    bool windowShouldClose() const;
    void windowSwapBuffers();
    void windowPollEvents();

    int getWidth() const { return m_width; }
    int getHeight() const { return m_height; }
    GLFWwindow* getNativeWindow();

    private:
    void init();

    static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

    private:
    GLFWwindow* m_window;
    int m_width;
    int m_height;
    std::string m_title;

};