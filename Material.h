#pragma once
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <GL/glew.h>
#include <string>
class Material
{
public:
	
	Material();
	Material(const char* name, GLfloat sIntensity, GLfloat shine);
	void  UseMaterial(GLuint specularIntensityLocation, GLuint shininessLocation);

	typedef struct ShaderLocations
	{
		GLuint specularIntensityLocation;
		GLuint shininessLocation;
	};

	const char* getName();

	~Material();
private: 
	GLfloat specularIntensity_;
	GLfloat shininess_; //specular Power (smoothness of the surface)) 

	const char* name_;


};

