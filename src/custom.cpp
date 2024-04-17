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
	INFO("Custom class created\n");
}

Custom::~Custom() {
	INFO("Custom class destroyed\n");
}

void Custom::Render() {
	ImGui::Begin("Custom window");

	ImGui::Text("Hello, world!");

	ImGui::End();
}

void Custom::Update() {
	/* Update code here */
}
