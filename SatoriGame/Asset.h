#pragma once
#include <SFML\Graphics.hpp>
#include <map>
#include <string>
namespace Dan
{
	class Asset
	{
	public:
		Asset() {}
		~Asset() {}

		void AddTexture(std::string name, std::string pathName);
		sf::Texture& GetTexture(std::string name);

		void AddFont(std::string name, std::string pathName);
		sf::Font& GetFont(std::string name);

	private:
		std::map<std::string, sf::Texture> _texturesContainer;
		std::map<std::string, sf::Font> _fontsContainer;
	};

}