/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   windowManagement.h                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/16 15:35:21 by mteerlin      #+#    #+#                 */
/*   Updated: 2025/05/16 15:35:22 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "glad.h"
#include <GLFW/glfw3.h>

#define VERSION_MAJOR   3
#define VERSION_MINOR   3
#define WIN_WIDTH       1280
#define WIN_HEIGHT      720

GLFWwindow  *setupWindow(std::string fileName);
int          setUpGlad();