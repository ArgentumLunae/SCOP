/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   scop.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/07 12:09:51 by mteerlin      #+#    #+#                 */
/*   Updated: 2025/05/13 21:30:54 by argentumlun   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Mesh.hpp"
#include "windowManagement.h"
#include <iostream>

int main(int argc, char** argv)
{
	GLFWwindow *window;

	if (argc != 2)
	{
		std::cout << "Usecase: ./scop <file>" << std::endl;
		return 1;
	}

	Mesh newmesh(argv[1]);
	if (newmesh.m_vertices.begin() == newmesh.m_vertices.end())
		std::cout << "why is this empty?" << std::endl;\
	else
	{
		std::cout << "not empty. what's in there?" << std::endl;
		std::cout << (*newmesh.m_vertices.begin())[0] << std::endl;
	}
	for (std::vector<std::vector<int>>::iterator iter = newmesh.m_faces.begin(); iter != newmesh.m_faces.end(); iter++)
	{
		std::cout << "Face:\t";
		for (std::vector<int>::iterator fIter = (*iter).begin(); fIter != (*iter).end(); fIter++)
		{
			std::cout << *fIter;
			if (fIter + 1 != newmesh.m_faces[*fIter].end())
				std::cout << ",";
		}
		std::cout << std::endl;
		for (std::vector<int>::iterator fIter = (*iter).begin(); fIter != (*iter).end(); fIter++)
		{
			std::cout << "  vertex:  ";
			for (std::vector<float>::iterator vIter = newmesh.m_vertices[*fIter].begin(); vIter != newmesh.m_vertices[*fIter].end(); vIter++)
			{
				if (*vIter > 0)
					std::cout << " ";
				std::cout << *vIter;
				if (vIter + 1 != newmesh.m_vertices[*fIter].end())
					std::cout << ",";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	if (!glfwInit())
		return -1;
	window = setupWindow(newmesh.getName());
	if (!window || setUpGlad())
		return -1;
	glfwTerminate();
	return 0;
}