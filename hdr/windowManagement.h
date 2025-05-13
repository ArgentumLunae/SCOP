/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   windowManagement.h                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: argentumlunae <argentumlunae@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/13 20:54:37 by argentumlun   #+#    #+#                 */
/*   Updated: 2025/05/13 21:27:43 by argentumlun   ########   odam.nl         */
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