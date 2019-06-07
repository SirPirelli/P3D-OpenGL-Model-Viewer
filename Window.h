#pragma once

#include <stdio.h>
#include <GL\glew.h>
#include <GLFW/glfw3.h>
class Window
{
public:
	Window();

	Window(GLint WindowWidth, GLint windowHeight);

	int initialise();

	GLfloat getBufferWidth() { return  bufferWidth; }
	GLfloat getBufferHeight() { return bufferHeight; }
	bool getShouldSlose() { return glfwWindowShouldClose(mainWindow);}
	GLFWwindow *mainWindow;

	bool* getKeys() { return keys; }
	GLfloat getXChange();
	GLfloat getYChange();
	GLdouble getScroll();
	void swapBuffers() { glfwSwapBuffers(mainWindow); }
	~Window();

private: 
	
	GLint width, height;
	GLint bufferWidth, bufferHeight;

	bool keys[1024];
	GLfloat lastX;
	GLfloat lastY;
	GLfloat xChange;
	GLfloat yChange;
	GLdouble scrollChange;
	GLdouble lastScroll;
	bool scrollFirstMoved;

	bool mousedFirstMoved;
	

	void createCallCallbacks();
	static void handleKeys(GLFWwindow* window, int key, int code, int action, int mode);
	static void handleMouse(GLFWwindow* window, double xPos, double yPos);
	static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
};

