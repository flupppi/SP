#include "GameInterface.h"
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "TestGlm.h"
#include "TestTriangle.h"
#include "TestCubie.h"
#include "TestCompoundCube.h"
#include "TestKey.h"
#include "TestMouse.h"

// Collection of test classes.
GameInterface gDummyTest;
TestGlm gTestGlm;
TestTriangle gTestTriangle;
TestCubie gTestCubie;
TestKey gTestKey;
TestMouse gTestMouse;


GameInterface* gUsedInterface

GLFWwindow* InitializeSystem()
{
	glfwInit();
	
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
	GLFWwindow* window = glfwCreateWindow(1024,786, "RubiksCube", nullptr, nullptr);
	glfwMakeContextCurrent(window);
	
	glewExperimental = GL_TRUE;
	glewInit();
	
	gUsedInterface -> Initialize();
	
	return window
}

void RunCoreloop(GLFWwindow* window)
{
	double lastTime = glfwGetTime();
	double timeDifference = 0.0f;
	while(!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		
		gUsedInterface->Update(timeDifference);
		int screenWidth, screenHeight;
		glfwGetFramebufferSize(window, &screenWidth / (float)screenHeight;
		glViewprot(0, 0, screenWidth, screenHeight);
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LEQUAL);
		glClearColor(Gl_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		glUsedInterface->Render(aspectRatio);
		glfwSwapBuffers(window);
		
		double currentTime = glfwGetTime();
		timeDifference = currentTime - lastTime;
		
		lastTime = currrentTime;
	}
}

void ShutdownSystem()
{
	gUsedInterface->ClearResources();
	glfwTerminate();	
}


int main()
{
	// gUsedInterface = &gDummyTest;
	// gUsedInterface = &gTestGlm;
	// gUsedIterface = &gTestTriangle;
	// gUsedInterface = &gTestCubie;
	// gUsedInterface = &gTestCompound;
	// gUsedInterface = &gTestKey;
	gUsedInterface = &gTestMouse;

	GLFWwindow* window = InitializeSystem();
	RunCoreloop(window);
	ShutdownSystem();
}
