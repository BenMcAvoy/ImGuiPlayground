TARGET = ImGuiPlayground

run:
	cmake -S . -B build/ -D CMAKE_BUILD_TYPE=Debug && cmake --build ./build/ && ./build/$(TARGET)
