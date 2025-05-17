/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   windowManagement.cpp                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/16 15:34:34 by mteerlin      #+#    #+#                 */
/*   Updated: 2025/05/16 16:09:46 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "windowManagement.h"
#include "glCallbacks.h"

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
	setGLCallbacks(window);
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
