#include "TestTexture.h"
#include "ShaderUtil.h"

#include <glm/glm.hpp>
#include <glm/ext.hpp>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

void TestTexture::Initialize()
{
	const float positions[] = { -1.0f, -1.0f, 0.0f,
								1.0f, -1.0f, 0.0f,
								0.0f, 1.0f, 0.0f };
								
	m_shaderProgram = ShaderUtil::CreateShaderProgram("VTexture.glsl", "FTexture.glsl");
	m_transformLocation = glGetUniformLocation(m_shaderProgram, "transformation");
	
	glGenVertexArrays(1, &m_arrayBufferObject);
	glGenBuffers(1, &m_vertexBufferObject);
	
	glBindVertexArray(m_arrayBufferObject);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferObject);
	glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);
	glVertexAttribPointer(0,3,GL_FLOAT, GL_FALSE, 3* sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glBindVertexArray(0);
	glBindBuffer (GL_ARRAY_BUFFER, 0);
	
	int w; 
	int h;
	int comp;
	unsigned char* image = stbi_load("Texture.jpg"
	
	
