#pragma once

#include "logging.hpp"
#include <imgui.h>

class Custom {
	public:
		Custom();
		~Custom();

		void Render();
		void Update();

		bool overwriteDefaultWindows = false;
};

Custom::Custom() {
	LOG_INFO("Custom class created\n");
}

Custom::~Custom() {
	LOG_INFO("Custom class destroyed\n");
}

void Custom::Render() {
	ImGui::Begin("Custom window");

	if (ImGui::CollapsingHeader("Log test")) {
		if (ImGui::Button("INFO"))
			LOG_INFO("Button pressed\n");

		if (ImGui::Button("WARN"))
			LOG_INFO("Button pressed\n");

		if (ImGui::Button("ERROR"))
			LOG_INFO("Button pressed\n");
	}

	ImGui::Text("Hello, world!");

	ImGui::End();
}

void Custom::Update() {
	/* Update code here */
}
