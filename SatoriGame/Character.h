#pragma once
#include <SFML\Graphics.hpp>
#include "GameManager.h"

namespace Dan
{
	class Character
	{
	public:
		Character(pointerGameStuff data);
		~Character();

		void Update(float dt);
		void Animation(float dt,float _switchTime, bool isFaceRight);
		void Draw();

	private:
		sf::Vector2i textureSize;
		sf::Sprite _sprite;
		sf::Texture _texture;
		pointerGameStuff _data;
		float _speed;
		int _row;
		int _col;
		float _totalTime;
		int _spritePerRow;
		bool _isFaceRight;
		sf::Clock _clock;
	};
}

