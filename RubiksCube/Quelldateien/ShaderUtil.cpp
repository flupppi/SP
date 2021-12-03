#include "ShaderUtil.h"
#include <iostream>
#include <fstream>

GLuint ShaderUtil::CreateShaderProgram(const char* vertexFilename, const char* fragmentFilename)

{
	std::string vertexProgram = LoadFile(vertexFilename);
	const char* vertexString = vertexProgram.c_str();
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	PrintOGlErrors();
	glCompileShader(vertexShader);
	PrintOGLErrors();
	int vertCompiled;
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &vertCompiled);
	if (vertCompiled != 1)
	{
		std::cout << "Vertex shader error " << std::endl;
		PrintShaderLog(vertexShader);
	}
	
	std::string fragementProgram = LoadFile(fragementFilename);
	const char* fragmentString = fragmentProgram.c_str();
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragementString, NULL);
	
	PrintOGlErrors();
	glCompileShader(fragmentShader);
	PrintOGLErrors();
	int fragCompiled;
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &fragCompiled);
	if (fragompiled != 1)
	{
		std::cout << "Fragment shader error " << std::endl;
		PrintShaderLog(fragmentShader);
	}
	
	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	PrintOGlErrors();
	int linked;
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &linked);
	if (linked != 1)
	{
		std::cout << "Linking failed:" << std::endl;
		PrintProgramLog(shaderProgram);
	}
	
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	
	return shaderProgram;
}
std::string ShaderUtil::LoadFile(const char* fileName)
{
	std::string result;
	std::ifstream fileStream(fileName, std::ios::in);
	while (!fileStream.eof())
	{
		std::string line;
		std::getline(fileStream, line);
		result.append(line + "\n");
	}
	fileStream.close();
	return result;
}

void ShaderUtil::PrintShaderLog(GLuint shader)
{
	int memLength;
	int messageLength;
	char* log;
	
	glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &memLength);
	if (memLength == 0)
		return;
	log = (char*)malloc(memLength);
	glGetShaderInfoLog(shader, memLength, &messageLength, log);
	std::cout << "Shader Info Log: " << log << std::endl;
	free(log);
}

void ShaderUtil::PrintProgramLog(GLuint program)
{
	int memLength;
	int messageLength;
	char* log;
	
	glGetShaderiv(program, GL_INFO_LOG_LENGTH, &memLength);
	if (memLength == 0)
		return;
	log = (char*)malloc(memLength);
	glGetShaderInfoLog(program, memLength, &messageLength, log);
	std::cout << "Program Info Log: " << log << std::endl;
	free(log);
}

void ShaderUtil::PrintOGlErrors()
{
	int error = glGetError();
	while (error != GL_NO_ERROR)
	{
		std::cout << "OpenGL error: " << error << std::endl;
		error = glGetError();
	}
}
