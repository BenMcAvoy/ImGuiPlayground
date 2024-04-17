#include <GLFW/glfw3.h>

#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>

#include <stdio.h>

#include "logging.hpp"
#include "globals.cpp"
#include "custom.cpp"

Custom custom;

int main(void) {
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(1280, 720, "GuiClass", NULL, NULL);

	if (!window) {
		ERROR("Failed to create window");
		glfwTerminate();
		return -1;
	}

	INFO("Window created\n");

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	INFO("Made context current\n");

	/* Initialize ImGui */
	IMGUI_CHECKVERSION();

	INFO("ImGui version checked\n");

	INFO("OpenGL version: %s\n", glGetString(GL_VERSION));
	INFO("GLSL version: %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));
	INFO("Renderer: %s\n", glGetString(GL_RENDERER));
	INFO("GLFW version: %s\n", glfwGetVersionString());
	INFO("ImGui version: %s\n", IMGUI_VERSION);

	ImGui::CreateContext();
	INFO("ImGui context created\n");

	ImGuiIO& io = ImGui::GetIO(); (void)io;

	/* Setup Dear ImGui style */
	ImGui::StyleColorsDark();

	/* Setup Platform/Renderer bindings */
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 130");

	INFO("ImGui initialized\n");

	ImGui::SetNextWindowSize(ImVec2(128, 128));

	bool showDemo = true;
	bool init = true;

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window) && !globals::shouldExit) {
		/* Update code here */
		custom.Update();
		/* Update code end  */

		glfwPollEvents();

		/* Start the ImGui frame */
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		if (init) {
			ImGui::SetNextWindowSize(ImVec2(256, 128));
			init = false;
		}

		/* Render code here */
		custom.Render();

		if (!custom.overwriteDefaultWindows) {
			ImGui::Begin("ImGui playground");

			if (ImGui::Button("Exit"))
				globals::shouldExit = true;

			ImGui::Checkbox("Demo window", &showDemo);

			if (showDemo)
				ImGui::ShowDemoWindow(&showDemo);

			ImGui::End();
		}
		/* Render code end  */

		ImGui::Render();

		/* Render OpenGL */
		glClear(GL_COLOR_BUFFER_BIT);
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		glfwSwapBuffers(window);
	}

	/* Cleanup */
	glfwDestroyWindow(window);
	INFO("Window destroyed\n");

	glfwTerminate();
	INFO("GLFW terminated\n");

	return 0;
}
