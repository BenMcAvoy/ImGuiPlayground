#ifdef _WIN32
#include <windows.h>
#endif

#include <GLFW/glfw3.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>
#include <imgui.h>
#include <stdio.h>

#include "globals.cpp"
#include "logging.hpp"
#include "window.cpp"

int main(void) {
  GLFWwindow *window = createWindow("ImGui playground", 1280, 720);

  bool showDemo = true;

  // Loop until the user closes the window
  while (!glfwWindowShouldClose(window) && !globals::shouldExit) {
    // Update code here
    //
    // Update code here

    // Start the ImGui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    // Render code here
    //
    // Render code here

    ImGui::SetNextWindowSize(ImVec2(200, 100), ImGuiCond_FirstUseEver);
    ImGui::Begin("ImGui playground");

    if (ImGui::Button("Exit"))
      globals::shouldExit = true;

    ImGui::Checkbox("Demo window", &showDemo);

    if (showDemo)
      ImGui::ShowDemoWindow(&showDemo);

    ImGui::End();

    ImGui::Render();

    // Render OpenGL
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    glfwSwapBuffers(window);

    glfwPollEvents();
  }

  // Cleanup
  glfwDestroyWindow(window);
  LOG_INFO("Window destroyed\n");

  glfwTerminate();
  LOG_INFO("GLFW terminated\n");

  return 0;
}
