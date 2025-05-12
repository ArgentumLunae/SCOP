/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Mesh.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/11 14:03:35 by mteerlin      #+#    #+#                 */
/*   Updated: 2025/05/11 17:37:27 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Mesh.h"
#include <sstream>
#include <fstream>

#include <iostream>

Mesh::Mesh()
{	
}

Mesh::Mesh(std::string file)
{
	loadFromFile(file);
}

Mesh::~Mesh()
{
}

void	Mesh::loadFromFile(std::string file)
{
	std::ifstream	objFile;
	std::string		line("");

	objFile.open(file);
	if (objFile.fail())
	{
		std::cout << "Could not open file." << std::endl;
		return ;
	}
	while (std::getline(objFile, line))
	{
		std::stringstream linestream(line);
		std::string lineheader("");

		
		if (linestream >> lineheader)
		{
			if (lineheader == "v")
				parseVertex(linestream);
			else if (lineheader == "vt")
				parseTexture(linestream);
			else if (lineheader == "f")
				parseFace(linestream);
			else
				continue ;
		}
	}
}

void Mesh::parseVertex(std::stringstream & line)
{
	std::vector<float> vertex;
	float x, y, z;

	line >> x >> y >> z;
	vertex.push_back(x);
	vertex.push_back(y);
	vertex.push_back(z);
	m_vertices.push_back(vertex);
}

void Mesh::parseTexture(std::stringstream & line)
{
	std::vector<float> textureVertex;
	float x, y, z;

	line >> x >> y >> z;
	textureVertex.push_back(x);
	textureVertex.push_back(y);
	m_textureVertices.push_back(textureVertex);
}

void Mesh::parseFace(std::stringstream & line)
{
	int vertexIndex;
	std::vector<int> vertexIndeces;

	while (line >> vertexIndex)
	{
		vertexIndeces.push_back(vertexIndex);
	}
	m_faces.push_back(vertexIndeces);
	return ;
}

std::vector<std::vector<float>> Mesh::getVertices() const
{
	return m_vertices;
}

std::vector<std::vector<int>> Mesh::getFaces() const
{
	return m_faces;
}
