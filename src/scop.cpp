/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   scop.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/07 12:09:51 by mteerlin      #+#    #+#                 */
/*   Updated: 2025/05/16 16:10:06 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Mesh.hpp"
#include "windowManagement.h"
#include "render.h"
#include "glCallbacks.h"
#include <iostream>

void printMesh(Mesh mesh)
{
	if (mesh.m_vertices.begin() == mesh.m_vertices.end())
		std::cout << "why is this empty?" << std::endl;\
	else
	{
		std::cout << "not empty. what's in there?" << std::endl;
		std::cout << (*mesh.m_vertices.begin())[0] << std::endl;
	}
	for (std::vector<std::vector<int>>::iterator iter = mesh.m_faces.begin(); iter != mesh.m_faces.end(); iter++)
	{
		std::cout << "Face:\t";
		for (std::vector<int>::iterator fIter = (*iter).begin(); fIter != (*iter).end(); fIter++)
		{
			std::cout << *fIter;
			if (fIter + 1 != mesh.m_faces[*fIter].end())
				std::cout << ",";
		}
		std::cout << std::endl;
		for (std::vector<int>::iterator fIter = (*iter).begin(); fIter != (*iter).end(); fIter++)
		{
			std::cout << "  vertex:  ";
			for (std::vector<float>::iterator vIter = mesh.m_vertices[*fIter].begin(); vIter != mesh.m_vertices[*fIter].end(); vIter++)
			{
				if (*vIter > 0)
					std::cout << " ";
				std::cout << *vIter;
				if (vIter + 1 != mesh.m_vertices[*fIter].end())
					std::cout << ",";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
}

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "Usecase: ./scop <file>" << std::endl;
		return 1;
	}
	
	Mesh mesh(argv[1]);
	GLFWwindow *window;

	if (!glfwInit())
		return -1;
	window = setupWindow(mesh.getName());
	if (!window || setUpGlad())
		return -1;
	renderScene(window);
	glfwTerminate();
	return 0;
}