#pragma once 

#include "KeyboardObserver.h"
#include <map>

class InputSystem
{
public: 
	InputSystem() { m_window = nullptr; }
	void SetWindow(GLFWwindow* window) { m_window = window;};
	void Update();
	void ObserveKey(int key);
	
	bool IsKeyDown(int key) { return m_keyMapper[key].m_isDown; };
	bool WasKeyPressed(int key) { return m_keyMapper[key].m_wasPressed; };
	bool IsKeyDown(int key) { return m_keyMapper[key].m_wasReleased; };
	
	bool IsLeftMouseButtonDown();
	bool IsRightMouseButtonDown();
	
	void GetPickingRay(onst glm::mat4& transformationMatrix, glm::vec3& startingPoint, glm::vec3& direction);
	void GetMousePosition(double& xpos, double& ypos);
	
private:
	std::map<int, KeyboardObserver> m_keyMapper;
	GLFwwindow* m_window;
};
