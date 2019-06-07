#include "pch.h"
#include "Camera.h"
#include<stdio.h>

Camera::Camera() {


}

Camera::Camera(glm::vec3 startPosition, glm::vec3 startUp, GLfloat startYaw, GLfloat startPitch,GLfloat startMoveSpeed, GLfloat startTurnSpeed)
{
	circularPosition = glm::vec3(0.0f, 0.0f, 0.0f); //Resets Circular Position
	position = startPosition;
	worldUp = startUp;
	yaw = startYaw;
	pitch = startPitch;
	radius = 6;
	MouseChangeXZ = 0;
	MouseChangeY  = 0;

	front = glm::vec3(0.0f, 0.0f, -1.0f);
	moveSpeed = startMoveSpeed;
	turnSpeed = startTurnSpeed;

	update();
	
}
void Camera::KeyControl(bool* keys, GLfloat deltaTime) {

	GLfloat velocity = moveSpeed * deltaTime;


 //Code for Camera Movement
 //  
	//if (keys[GLFW_KEY_W]) {
	//	
	//	position += front * velocity;
	//}
	//if (keys[GLFW_KEY_S]) {
	//
	//	position -= front * velocity;
	//}
	//if (keys[GLFW_KEY_A]) {
	//	position -= right * velocity;
	//
	//}
	//if (keys[GLFW_KEY_D]) {
	//
	//	position += right * velocity;
	//	
	//}


	
}

void Camera::MouseControl(GLfloat xChange, GLfloat yChange) {

	xChange *= turnSpeed;
	yChange *= turnSpeed;

    MouseChangeXZ += xChange;
	MouseChangeY += yChange;


	if (MouseChangeY > 89.0f) {
		MouseChangeY = 89.0f;
	}

	if (MouseChangeY < -89.0f) {
		MouseChangeY = -89.0f;
	}

	circularPosition.x = (radius ) * sin(MouseChangeXZ);
	circularPosition.y = (radius ) * sin(MouseChangeY);
	circularPosition.z = (radius ) * cos(MouseChangeXZ);


	if (pitch > 89.0f) {
		pitch = 89.0f;
	}

	if (pitch < -89.0f) {
		pitch = -89.0f;
	}


	update();
}

glm::mat4 Camera::calculateViewMatrix() {
	//return glm::lookAt(position,position + front,up);
	return glm::lookAt(circularPosition, glm::vec3(0.0f,0.0f,0.0f), glm::vec3(0.0f,1.0f,0.0f));
}

glm::vec3 Camera::getCameraPosition() {
	return circularPosition;
}

void Camera::update() {

	//Code for Camera Movement
	front.x = cos(glm::radians(yaw)*cos(glm::radians(pitch)));
	front.y = sin(glm::radians(pitch));
	front.z=  sin(glm::radians(yaw)*cos(glm::radians(pitch)));
	front = glm::normalize(front);

	right = glm::normalize(glm::cross(front, worldUp));
	up = glm::normalize(glm::cross(right, front));
	
}

Camera::~Camera()
{
}
