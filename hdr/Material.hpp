/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Material.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/17 17:14:47 by mteerlin      #+#    #+#                 */
/*   Updated: 2025/05/17 17:17:38 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <vector>

class Material
{
	private:
		std::string _name;
		std::vector<double> _ambient;
		std::vector<double> _diffuse;
		std::vector<double> _specular;
		int					_specularExponent;
		int					_illumination;

	public:
		Material(std::string mtlfile);
		~Material();

		std::string getName() const;
		void setName(const std::string name);
}