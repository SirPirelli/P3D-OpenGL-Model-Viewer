#include "pch.h"
#include "Window.h"


Window::Window()
{
	width = 800;
	height = 600;
	for (size_t i = 0; i < 1024; i++) {
		keys[i] = 0;
	}
	yChange = 0;
	xChange = 0;
}

Window::Window(GLint WindowWidth, GLint windowHeight) {

	width = WindowWidth;
	height = windowHeight;
	yChange = 0;
	xChange = 0;
	scrollChange = 0;
	for (size_t i = 0; i < 1024; i++) {
		keys[i] = 0;
	}
}
int Window::initialise() {
	// Initialise GLFW
	if (!glfwInit())
	{
		printf("GLFW initialisation failed!");
		glfwTerminate();
		return 1;
	}

	// Setup GLFW window properties
	// OpenGL version
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Core Profile
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// Allow Forward Compatbility
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	// Create the window
	mainWindow = glfwCreateWindow(width, height, "Test Window", /*glfwGetPrimaryMonitor()*/NULL, NULL);
	if (!mainWindow)
	{
		printf("GLFW window creation failed!");
		glfwTerminate();
		return 1;
	}

	// Get Buffer Size information
	
	glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

	// Set context for GLEW to use
	glfwMakeContextCurrent(mainWindow);

	// Handle Mouse, keyboarinput
	createCallCallbacks();

	glfwSetInputMode(mainWindow, GLFW_CURSOR, GLFW_CROSSHAIR_CURSOR);
	// Allow modern extension features
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK)
	{
		printf("GLEW initialisation failed!");
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
		return 1;
	}
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_STENCIL_TEST);

	// Setup Viewport size
	glViewport(0, 0, bufferWidth, bufferHeight);

	glfwSetWindowUserPointer(mainWindow, this);


}

void Window::createCallCallbacks() {

	glfwSetKeyCallback(mainWindow, handleKeys);
	glfwSetCursorPosCallback(mainWindow, handleMouse);
	glfwSetScrollCallback(mainWindow, scroll_callback);
}


GLfloat Window::getXChange() {
	GLfloat theChange = xChange;
	xChange = 0.0f;
	return theChange;

}

GLfloat Window::getYChange() {
	GLfloat theChange = yChange;
	yChange = 0.0f;
	return theChange;
}


GLdouble Window::getScroll() {
	

	return scrollChange;
}


void Window::handleMouse(GLFWwindow* window, double xPos, double yPos) {
	Window* theWindow = static_cast<Window*>(glfwGetWindowUserPointer(window));
	if (theWindow->mousedFirstMoved) {
		theWindow->lastX = xPos;
		theWindow->lastY = yPos;
		theWindow->mousedFirstMoved = false;
	}

	theWindow->xChange = xPos - theWindow->lastX;
	theWindow->yChange = theWindow->lastY - yPos;


	theWindow->lastX = xPos;
	theWindow->lastY = yPos;
	//printf("x: %.6f,  y: %.6f\n", theWindow->xChange, theWindow->yChange);

}


void Window::scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	Window* theWindow = static_cast<Window*>(glfwGetWindowUserPointer(window));
	//theWindow->scrollChange = (yoffset/(double)100);


	if (theWindow->scrollFirstMoved) {
		theWindow->lastScroll = yoffset;
	
		theWindow->scrollFirstMoved = false;
	}

	theWindow->scrollChange = theWindow->lastScroll - yoffset;

	theWindow->lastScroll += yoffset;
	//printf("%f \n", theWindow->getScroll());

}


 void Window::handleKeys(GLFWwindow* window, int key, int code, int action, int mode) {
	 Window* theWindow = static_cast<Window*>(glfwGetWindowUserPointer(window));
	 if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		 glfwSetWindowShouldClose(window, GL_TRUE);
	 }
	 if (key >=0 && key <1024) {
		 if (action == GLFW_PRESS) {
			 theWindow->keys[key] = true;
			 printf("Pressed: %d\n", key);
		 }
		 else if (action == GLFW_RELEASE) {
			 theWindow->keys[key] = false;
			 printf("Released: %d\n", key);
		 }
	 }

}

Window::~Window()
{
	glfwDestroyWindow(mainWindow);
	glfwTerminate();
}
