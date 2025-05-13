/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   windowManagement.cpp                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: argentumlunae <argentumlunae@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/13 20:09:59 by argentumlun   #+#    #+#                 */
/*   Updated: 2025/05/13 21:29:06 by argentumlun   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "windowManagement.h"

GLFWwindow  *setupWindow(std::string fileName)
{
    GLFWwindow *window;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, VERSION_MAJOR);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, VERSION_MINOR);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(WIN_WIDTH, WIN_HEIGHT, fileName.c_str(), NULL, NULL);
    if (!window)
    {
        std::cout << "Failed to create GLFW window." << std::endl;
        glfwTerminate();
        return NULL;
    }
    glfwMakeContextCurrent(window);
    return window;
}

int setUpGlad()
{
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cerr << "Couldn't Load OpenGL." << std::endl;
		glfwTerminate();
		return -1;
	}
	return 0;
}
