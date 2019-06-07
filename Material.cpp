#include "pch.h"
#include "Material.h"



Material::Material()
{
	name_ = "NewMaterial";
	specularIntensity_ = 0;
	shininess_ = 0;
}

Material::Material(const char* name, GLfloat sIntensity, GLfloat shine) {
	name_ = name;
	specularIntensity_ = sIntensity;
	shininess_ = shine;

}



void  Material::UseMaterial(GLuint specularIntensityLocation, GLuint shininessLocation) {

	glUniform1f(specularIntensityLocation, specularIntensity_);
	glUniform1f(shininessLocation, shininess_);
}


const char* Material::getName()
{
	return name_;
}

Material::~Material()
{
}
