#pragma once

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>

#include <GL/glew.h>

#include "DirectionalLight.h"
#include "PointLight.h"
#include "SpotLight.h"

#include "CommonValues.h"

class Shader
{
public:
	Shader();


	std::string ReadFile(const char* fileLocation);
	void   CreateFromString(const char* vertexCode, const char* fragmentCode);
	void   CreateFromFiles(const char* vertexLocation, const char* fragmentLocation);

	
	GLuint GetProjectionLocation();
	GLuint GetModelLocation();
	GLuint GetViewLocation();
	GLuint GetAmbientColourLocation();
	GLuint GetAmbientIntensityLocation();
	GLuint GetDiffuseIntensityLocation();
	GLuint GetDirectionLocation();
	GLuint GetSpecularIntensityLocation();
	GLuint GetShininessLocation();
	GLuint GetEyePositionLocation();
	GLuint GetTimeElapsedLocation();
	GLuint GetRandomizeLocation();

	void SetDirectionalLight(DirectionalLight *dLight);
	void SetPointLights(PointLight *pLight, unsigned int lightCount);
	void SetSpotLights(SpotLight *sLight, unsigned int lightCount);
	void UseShader();
	void ClearShader();

	~Shader();

private:

	int pointLightCount;
	int SpotLightCount;
	GLuint shaderID, uniformProjection, uniformModel, uniformEyePosition, uniformSpecularIntensity, uniformShininess, uniformView, uniformTimeElapsed, uniformRandomize;


	struct {

		GLuint uniformColour;
		GLuint uniformAmbientIntensity;
		GLuint uniformDiffuseIntenity;

		GLuint uniformDirection;

	}uniformDirectionalLight;

	GLuint uniformPointLightCount;

	struct {

		GLuint uniformColour;
		GLuint uniformAmbientIntensity;
		GLuint uniformDiffuseIntenity;

		GLuint uniformPosition;
		GLuint uniformConstant;
		GLuint uniformLinear;
		GLuint uniformExponent;

	}uniformPointLight[MAX_POINT_LIGHTS];
	  

	GLuint uniformSpotLightCount;


	struct {

		GLuint uniformColour;
		GLuint uniformAmbientIntensity;
		GLuint uniformDiffuseIntenity;

		GLuint uniformPosition;
		GLuint uniformConstant;
		GLuint uniformLinear;
		GLuint uniformExponent;

		GLuint uniformDirection;
		GLuint uniformEdge;

	}uniformSpotLight[MAX_SPOT_LIGHTS];
	 
	void CompileShader(const char* vertexCode, const char* fragmentCode);
	void AddShader(GLuint theProgram, const char* shaderCode, GLenum shaderType);


};

