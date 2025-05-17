/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Mesh.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/07 15:16:15 by mteerlin      #+#    #+#                 */
/*   Updated: 2025/05/17 17:21:15 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Material.hpp"
#include <map>

class Mesh
{
	private:
	std::string 					_name;
	std::map<std::string, Material>	_materials;

	void	parseVertex(std::stringstream & line);
	void	parseTexture(std::stringstream & line);
	void	parseFace(std::stringstream & line);
	void	parseMaterial(std::stringstream &line);
	
	public:
	std::vector<std::vector<float>> m_vertices;
	std::vector<std::vector<float>> m_textureVertices;
	std::vector<std::vector<int>> m_faces;
	
	Mesh();
	Mesh(std::string file);
	~Mesh();
	
	void	loadFromFile(std::string file);

	std::string						getName() const;
	std::vector<std::vector<float>>	getVertices() const;
	std::vector<std::vector<int>>	getFaces() const;

	void	setName(std::string name);
};
