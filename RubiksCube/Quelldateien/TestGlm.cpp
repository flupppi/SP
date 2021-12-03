#include "TestGlm.h"

#include <glm/glm.hpp>
#include <glm/ext.hpp>
/* Vorlesung 3 erste Hälfte
void TestGlm::Initialize()
{
	
	glm::mat4 testMat = glm::mat4(1.0f);
	testMat = glm::translate(testMat, glm::vec3(1.0f, -1.0f, 1.0f));
	testMat = glm::rotate(testMat, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f)); 
	glm::vec3 firstColumn = testMat[0]; 
	float innerProduct = glm::dot(firstColumn, firstColumn);
	innerProduct = innerProduct;
}

void TestGlm::Update(double deltaTime)
 {
	 
 }
 */

void TestGlm::Initialize()
{
	GLuint test = ShaderUtil::CreateShaderProgram("VSimple.glsl", "FSimple.glsl");
	m_orientationQuaternion = glm::quat(1.0f, 0.0f, 0.0f, 0.0f);
}

// HACK HACK HACK
int passed = 0;
void TestGlm::Update(double deltaTime)
{
	if (passed == 0)
	{
		passed = 1;
		return;
	}
	glm::quat rotVelocity = glm::quat(0.0f, glm::radians(180.0f), 0.0f, 0.0f);
	
	glm::quat timeDerivative = 0.5f * rotVelocity * m_orientationQuaternion;
	
	m_orientationQuaternion +=  ((float)deltaTime) * timeDerivative;
	
	m_orientationQuaternion = normalize(m_orientationQuaternion);
	
	glm::mat4 rotationMatrix = glm::mat4_cast(m_orientationQuaternion);
}
