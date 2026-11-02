#include "window.hpp"

Window::Window(int width, int height, const std::string& title)  
    : m_width(width), m_height(height), m_title(title), m_window(nullptr)
{
    init();
}

Window::~Window()
{
    if(m_window)
    {
        glfwDestroyWindow(m_window);
    }
    glfwTerminate();
}

void Window::init()
{
    glfwInit();
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_window = glfwCreateWindow(m_width, m_height, m_title.c_str(), NULL, NULL);
    if(m_window == NULL)
    {
        fprintf(stderr, "ERROR::WINDOW::DID::NOT::OPEN");
        glfwTerminate();
        exit(-1);
    }
    glfwMakeContextCurrent(m_window);
    glfwSetFramebufferSizeCallback(m_window, framebuffer_size_callback);
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "FAILED::TO::INITIALIZE::GLAD\n";
        exit(-1);
    }
    glViewport(0, 0, m_width, m_height);
    glEnable(GL_DEPTH_TEST);

}

void Window::framebuffer_size_callback(GLFWwindow* window, int width, int height) 
{
    Window* handler = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));
    if(handler)
    {
        handler->m_width = width;
        handler->m_height = height;
        glViewport(0,0, width, height);
    }
    
}

bool Window::windowShouldClose() const
{
    return glfwWindowShouldClose(m_window);
}

void Window::windowSwapBuffers() 
{
    return glfwSwapBuffers(m_window);
}

void Window::windowPollEvents()
{
    return glfwPollEvents();
}
