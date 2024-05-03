TARGET = ImGuiPlayground

run:
	cmake -S . -B build/ -D CMAKE_BUILD_TYPE=Debug && cmake --build ./build/
ifeq ($(OS),Windows_NT)
    cd ./build; $(TARGET).exe
else
	cd ./build && ./$(TARGET)
endif
