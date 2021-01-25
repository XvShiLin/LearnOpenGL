// HelloWindow.cpp -- 你好，窗口
// 使用 GLFW 和 GLAD 来设置 OpenGL上下文 并创建一个窗口
#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}
// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main()
{
    glfwInit(); // 初始化 GLFW
    // 使用 glfwWindowHint(选项, int) 来配置 GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);                 // 主版本号
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);                 // 次版本号
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // 核心模式
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // Mac OS X系统
#endif

    // 创建一个窗口对象
    GLFWwindow *window = glfwCreateWindow(800, 600, "HelloWindow", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to initialize GLAD\n";
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window); // 设置为当前线程的主上下文
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // GLAD初始化，管理 OpenGL 的函数指针
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD\n";
        return -1;
    }

    // ViewPort
    glViewport(0, 0, 800, 600);

    // 渲染循环 Render Loop
    while (!glfwWindowShouldClose(window))
    {
        // input
        processInput(window);

        // render
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        //
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}