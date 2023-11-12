#include "CMakeBaseTemplate.hpp"

using namespace std;

int main()
{
	cout << "Hello CMake." << endl;

	const int width = 640;
	const int height = 480;

	if (!glfwInit())
	{
		std::cerr << "glfwInit failed" << std::endl;
		exit(EXIT_FAILURE);
	}

	// Hint
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);

	glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);


	GLFWwindow* m_window = glfwCreateWindow(width, height, "ShaderPlayground", NULL, NULL);

	if (!m_window)
	{
		std::cerr << "glfwCreateWindow failed" << std::endl;
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	const GLFWvidmode* videoMode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	glfwSetWindowPos(m_window, videoMode->width / 2 - width / 2, videoMode->height / 2 - height / 2);

	glfwMakeContextCurrent(m_window);

	glViewport(0, 0, width, height);

	GLenum err = glewInit();

	if (GLEW_OK != err)
	{
		std::cerr << "Glew Init Error: " << glewGetErrorString(err) << std::endl;
		exit(EXIT_FAILURE);
	}

	//Depth Buffer activation
	glEnable(GL_DEPTH_TEST);
	// anti-aliasing
	glEnable(GL_MULTISAMPLE);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);


	glfwSwapInterval(1);

	glfwShowWindow(m_window);

	while (!glfwWindowShouldClose(m_window))
	{
		// render
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

		glfwSwapBuffers(m_window);
		glfwPollEvents();

#ifdef _DEBUG
		GLenum err = glGetError();

		if (err != GL_NO_ERROR) {
			std::cerr << "Error: " << err << std::endl;
		}
#endif
	}

	glfwTerminate();


	return 0;
}
