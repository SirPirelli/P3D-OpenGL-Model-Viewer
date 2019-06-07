#include "pch.h"
#include "Light.h"


Light::Light()
{
	colour = glm::vec3(1.0f, 1.0f, 1.0f);
	ambientIntensity = 1.0f;

	diffuseIntensity = 0.0f;

}

Light::Light(GLfloat red, GLfloat green, GLfloat blue, GLfloat aIntensity, GLfloat dIntensity) {
	colour = glm::vec3(red,green,blue);
	ambientIntensity = aIntensity;
	
	diffuseIntensity = dIntensity;
}

glm::vec3 Light::getColor()
{
	return colour;
}

GLfloat Light::getAmbientIntensity()
{
	return ambientIntensity;
}

GLfloat Light::getDiffuseIntensity()
{
	return diffuseIntensity;
}

void Light::setAmbientIntensity(GLfloat value)
{
	ambientIntensity = value;
}

void Light::setDiffuseIntensity(GLfloat value)
{
	diffuseIntensity = value;
}

void Light::setColor(glm::vec3 value)
{
	colour = value;
}



Light::~Light()
{
}
