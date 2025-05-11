/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Mesh.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/07 15:16:15 by mteerlin      #+#    #+#                 */
/*   Updated: 2025/03/14 13:32:03 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>

class Mesh
{
	public:
	std::map<std::string, int> m_indexedVectors;
	std::map<std::string, int> m_indexedFaces;

	private:
	Mesh::Mesh();
	Mesh::~Mesh();

	std::map<std::string, int> Mesh::getVectors();
	std::map<std::string, int> Mesh::getFaces();
};
