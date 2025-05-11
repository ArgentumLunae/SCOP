/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Mesh.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/07 15:16:15 by mteerlin      #+#    #+#                 */
/*   Updated: 2025/05/11 16:51:47 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <vector>

class Mesh
{
	private:
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

	std::vector<std::vector<float>>	getVertices() const;
	std::vector<std::vector<int>>	getFaces() const;
};
