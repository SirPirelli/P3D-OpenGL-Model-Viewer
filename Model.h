#pragma once


#include <vector>
#include <string>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include "Mesh.h"
#include "Texture.h"
#include "Material.h"


class Model
{
public:
	Model();

	void LoadModel(const std::string &fileName);
	void RenderModel(bool renderTextures, Material::ShaderLocations locations);
	void ClearModel();

	~Model();

private :

	void UseMaterial(GLuint specularIntensityLocation, GLuint shininessLocation);

	
	
	void LoadNode(aiNode *node,  const aiScene *scene);
	void LoadMesh(aiMesh *mesh,  const aiScene *scene);
	void LoadMaterials(const aiScene *scene);

	std::vector<Mesh*> meshList;
	std::vector<Texture*> textureList;
	std::vector<unsigned int> meshToTex;

	std::vector<Material*> materialList;
};

