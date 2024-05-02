#ifdef _WIN32
#include <windows.h>
#endif

#include <GLFW/glfw3.h>

#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>

#include <stdio.h>

#include "logging.hpp"
#include "globals.cpp"

int main(void) {
	GLFWwindow* window;

	// Initialize the library
	if (!glfwInit())
		return -1;

	// Create a windowed mode window and its OpenGL context
	window = glfwCreateWindow(1280, 720, "ImGuiPlayGround", NULL, NULL);

	if (!window) {
		LOG_ERROR("Failed to create window");
		glfwTerminate();
		return -1;
	}

	LOG_INFO("Window created\n");

	// Make the window's context current
	glfwMakeContextCurrent(window);

	LOG_INFO("Made context current\n");

	// Initialize ImGui
	IMGUI_CHECKVERSION();

	LOG_INFO("ImGui version checked\n");

	LOG_INFO("OpenGL version: %s\n", glGetString(GL_VERSION));

#ifdef __linux__
	LOG_INFO("GLSL version: %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));
#endif

	LOG_INFO("Renderer: %s\n", glGetString(GL_RENDERER));
	LOG_INFO("GLFW version: %s\n", glfwGetVersionString());
	LOG_INFO("ImGui version: %s\n", IMGUI_VERSION);

	ImGui::CreateContext();
	LOG_INFO("ImGui context created\n");

	ImGuiIO& io = ImGui::GetIO(); (void)io;

	// Setup Dear ImGui style
	ImGui::StyleColorsDark();

	// Setup Platform/Renderer bindings
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 130");

	LOG_INFO("ImGui initialized\n");

	ImGui::SetNextWindowSize(ImVec2(128, 128));

	bool showDemo = true;
	bool init = true;

	// Loop until the user closes the window
	while (!glfwWindowShouldClose(window) && !globals::shouldExit) {
		// Update code here

		glfwPollEvents();

		// Start the ImGui frame
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		if (init) {
			ImGui::SetNextWindowSize(ImVec2(256, 128));
			init = false;
		}

		// Render code here
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
	}

	// Cleanup
	glfwDestroyWindow(window);
	LOG_INFO("Window destroyed\n");

	glfwTerminate();
	LOG_INFO("GLFW terminated\n");

	return 0;
}
