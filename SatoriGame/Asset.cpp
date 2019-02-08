#pragma once
#include "Asset.h"
namespace Dan
{
	void Asset::AddTexture(std::string name, std::string pathName)
	{
		sf::Texture texture;
		if (texture.loadFromFile(pathName))
		{
			this->_texturesContainer[name] = texture;
		}
	}

	sf::Texture & Asset::GetTexture(std::string name)
	{
		return this->_texturesContainer.at(name);
	}

	void Asset::AddFont(std::string name, std::string pathName)
	{
		sf::Font font;
		if (font.loadFromFile(pathName))
		{
			this->_fontsContainer[name] = font;
		}
	}

	sf::Font & Asset::GetFont(std::string name)
	{
		return this->_fontsContainer.at(name);
	}
}