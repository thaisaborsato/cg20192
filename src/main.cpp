#include <glad/glad.h>
#include <glfw/glfw3.h>


#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/vec3.hpp>
#include <glm/mat3x3.hpp>

#include <iostream>
#include <vector>

void loadTriangleMesh(const std::string & filename,
	std::vector<glm::vec3> & positions,
	std::vector<glm::vec3> & normals,
	std::vector<glm::vec2> & textureCoordinates,
	std::vector<size_t> & positionIndices,
	std::vector<size_t> & normalsIndices,
	std::vector<size_t> & textureCoordinates)

bool BACKGROUND_STATE = false;

//Resize OpenGL buffer
void resize(GLFWwindow * window, int width, int height){
	glViewport(0, 0, width, height);
}

//Keyboard event
void keyboard
		(GLFWwindow * window, 
		int key, int scancode, int action, int modifiers){
	if(key == GLFW_KEY_A && action == GLFW_PRESS)
		BACKGROUND_STATE = !BACKGROUND_STATE;	
}

int main(int argc, char** argv) {
	glm::vec3 u(2.0f, 0, 0);
	glm::vec3 v(0, 1.0f, 0);
	
	glm::vec3 c = glm::normalize(u);
	
	glm::mat3 m(
	1, 2, 3,
	4, 5, 6, 
	7, 8, 9);
	
	std::cout << glm::to_string(m[0][0]) << std::endl;
	
	// Check GlFW initialization
	if (!glfwInit()){
		std::cout << "Cannot initialize GLFW" << std::endl;
		return -1;
	}
		
	// Setup OpenGL context
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
	// Create window
	GLFWwindow * window = glfwCreateWindow(800, 600, "Test", nullptr, nullptr);
	
	// Check if cannot create window
	if (window == nullptr) {
		glfwTerminate();
		
		std::cout << "Cannot create window." << std::endl;
		return -1;
	}
	
	//Register callback
	glfwSetFramebufferSizeCallback(window, resize);
	glfwSetKeyCallback(window, keyboard);
	
	// Setup window context
	glfwMakeContextCurrent(window);
	
	
	// Check if cannot load OpenGL procedures
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		glfwTerminate();
		
		std::cout << "Cannot load OpenGL procedures." << std::endl;
		return -1;
	}
	
	// Render loop
	while (!glfwWindowShouldClose(window)) {
		// Setup color buffer
		if(BACKGROUND_STATE)
			glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
		else
			glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
			
		glClear(GL_COLOR_BUFFER_BIT);
		
		// Swap double buffer
		glfwSwapBuffers(window);
		
		// Process events and callbacks
		glfwPollEvents();
	}
	
	//Destroy window
	glfwDestroyWindow(window);
	
	// Deinitialize GLFW
	glfwTerminate();
	
	return 0;
}
