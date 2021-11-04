#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

int main()
{	
	// init GLFW
	glfwInit();
	
	// tell GLFW wtf we're doing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // saying opengl version 3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); // saying opengl version 3
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // core profile for modern functions
	
	// create window w/ size 800 x 800
	GLFWwindow* window = glfwCreateWindow(800, 800, "OpenGL", NULL, NULL);

	// check if failed to create
	if (window == NULL) {
		std::cout << "Failed to open window." << std::endl;
		glfwTerminate();
		return - 1;
	}

	// set context to window
	glfwMakeContextCurrent(window);
	
	// load opengl
	gladLoadGL();

	// define where opengl is located
	glViewport(0, 0, 800, 800);

	// set color of background
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(window);

	// while loop to keep window open until closed
	while (!glfwWindowShouldClose(window))
	{	
		// update window while running
		glfwPollEvents();
	}

	// destroy window & terminate glfw
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}