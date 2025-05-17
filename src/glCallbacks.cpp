/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   glCallbacks.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/16 15:33:49 by mteerlin      #+#    #+#                 */
/*   Updated: 2025/05/16 16:01:47 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "glCallbacks.h"

void setGLCallbacks(GLFWwindow *window)
{
	glfwSetFramebufferSizeCallback(window, frameBufferSizeCallback);
}

void frameBufferSizeCallback(GLFWwindow *window, int width, int height)
{
	(void)window;
	glViewport(0, 0, width, height);
}
