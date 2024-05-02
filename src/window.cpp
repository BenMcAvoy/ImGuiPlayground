#include <GLFW/glfw3.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>
#include <imgui.h>

#include "logging.hpp"

GLFWwindow *createWindow(const char *title, int width, int height) {
  // Initialize the library
  if (!glfwInit()) {
    const char *description;
    glfwGetError(&description);

    LOG_ERROR("Failed to initialize GLFW: %s\n", description);

    return nullptr;
  }

  // Create a windowed mode window and its OpenGL context
  GLFWwindow *window = glfwCreateWindow(width, height, title, NULL, NULL);

  if (!window) {
    glfwTerminate();

    const char *description;
    glfwGetError(&description);
    LOG_ERROR("Failed to create window: %s\n", description);

    return nullptr;
  }

  LOG_INFO("Window created\n");

  // Make the window's context current
  glfwMakeContextCurrent(window);
  LOG_INFO("ImGui context created\n");

  // Initialize ImGui
  IMGUI_CHECKVERSION();

  ImGui::CreateContext();

  LOG_INFO("ImGui version checked\n");

  LOG_INFO("OpenGL version: %s\n", glGetString(GL_VERSION));

#ifdef __linux__
  LOG_INFO("GLSL version: %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));
#endif

  LOG_INFO("Renderer: %s\n", glGetString(GL_RENDERER));
  LOG_INFO("GLFW version: %s\n", glfwGetVersionString());
  LOG_INFO("ImGui version: %s\n", IMGUI_VERSION);

  // Setup Dear ImGui style
  ImGui::StyleColorsDark();

  // Setup Platform/Renderer bindings
  ImGui_ImplGlfw_InitForOpenGL(window, true);
  ImGui_ImplOpenGL3_Init("#version 130");

  LOG_INFO("ImGui initialized\n");

  return window;
}
