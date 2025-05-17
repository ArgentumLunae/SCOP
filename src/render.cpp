/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/16 15:52:57 by mteerlin      #+#    #+#                 */
/*   Updated: 2025/05/16 16:16:15 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

int renderScene(GLFWwindow *window)
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	while (!glfwWindowShouldClose(window))
	{
		glfwSwapBuffers(window);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwPollEvents();
	}
	return 0;
}