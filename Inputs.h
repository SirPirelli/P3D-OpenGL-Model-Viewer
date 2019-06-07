#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

class Inputs
{
public:
	Inputs();
	Inputs(bool keysCallback, bool mouseCallback, bool scrollCallback, GLFWwindow* window);
	~Inputs();

	void Update();

	bool useScrollCallback;
	bool useKeysCallBack;
	bool useMouseCallback;

private:

	GLFWwindow* window;

	glm::vec2 scrollOffset = { 0.0f, 0.0f };


};

