/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   scop.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/07 12:09:51 by mteerlin      #+#    #+#                 */
/*   Updated: 2025/05/11 17:36:26 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Mesh.h"
#include <iostream>

int main(int argc, char** argv)
{
	if (argc != 2 || argv[1] == NULL)
	{
		std::cout << "Usecase: ./scop <file>";
	}

	Mesh newmesh(argv[1]);
	for (std::vector<std::vector<int>>::iterator iter = newmesh.m_faces.begin(); iter != newmesh.m_faces.end(); iter++)
	{
		std::cout << "Face:\t";
		for (std::vector<int>::iterator fIter = (*iter).begin(); fIter != (*iter).end(); fIter++)
			std::cout << *fIter;
		for (std::vector<int>::iterator fIter = (*iter).begin(); fIter != (*iter).end(); fIter++)
		{
			std::cout << std::endl;
			std::cout << "\tvertex:\t";
			for (std::vector<float>::iterator vIter = newmesh.m_vertices[*fIter].begin(); vIter != newmesh.m_vertices[*fIter].end(); vIter++)
			{
				std::cout << *vIter << ",";
			}
			std::cout << std::endl;
		}
	}
	return 0;
}