#include "Inputs.h"

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

Inputs::Inputs()
{
	useKeysCallBack = true;
	useMouseCallback = true;
	useScrollCallback = false;
	window = nullptr;
}

Inputs::Inputs(bool keysCallback, bool mouseCallback, bool scrollCallback, GLFWwindow* window)
{
	useKeysCallBack = keysCallback;
	useMouseCallback = mouseCallback;
	useScrollCallback = scrollCallback;
	this->window = window;
}


Inputs::~Inputs()
{
}

void Inputs::Update()
{
	glfwPollEvents();

	if (useKeysCallBack)
	{

	}

	if (useMouseCallback)
	{

	}

	if (useScrollCallback)
	{
		
		

		glfwSetScrollCallback(window, scroll_callback);
		
	}
}






