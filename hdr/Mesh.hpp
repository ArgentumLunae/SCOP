/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Mesh.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/07 15:16:15 by mteerlin      #+#    #+#                 */
/*   Updated: 2025/05/13 21:07:41 by argentumlun   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <vector>

class Mesh
{
	private:
	std::string _name;

	void	parseVertex(std::stringstream & line);
	void	parseTexture(std::stringstream & line);
	void	parseFace(std::stringstream & line);
	
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
