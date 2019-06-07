#pragma once

#include <glm/glm.hpp>
#include <GL/glew.h>
class Light
{
public:
	Light();
	Light(GLfloat red, GLfloat green, GLfloat blue, GLfloat aIntensity, GLfloat dIntensity);

	glm::vec3 getColor();
	GLfloat getAmbientIntensity();
	GLfloat getDiffuseIntensity();

	void setAmbientIntensity(GLfloat value);
	void setDiffuseIntensity(GLfloat value);
	void setColor(glm::vec3 value);
	~Light();


protected:

	glm::vec3 colour;
	GLfloat ambientIntensity;
	GLfloat diffuseIntensity;


};

