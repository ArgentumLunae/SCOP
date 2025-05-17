/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   glCallbacks.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/16 15:44:01 by mteerlin      #+#    #+#                 */
/*   Updated: 2025/05/16 16:03:37 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <glad.h>
#include <GLFW/glfw3.h>

void setGLCallbacks(GLFWwindow *window);
void frameBufferSizeCallback(GLFWwindow *window, int width, int height);