#include "Character.h"


namespace Dan
{
	Character::Character(pointerGameStuff data)
		:
		_data(data)
	{
		_sprite.setTexture(_data->asset.GetTexture("Character Texture"));
		_sprite.setPosition(sf::Vector2f(200.0f, 250.0f));
		textureSize = (sf::Vector2i)_sprite.getTexture()->getSize();
		textureSize.x /= 15;
		textureSize.y /= 5;
		_sprite.setTextureRect(sf::IntRect(textureSize.x * 0, textureSize.y * 0, textureSize.x, textureSize.y));
		
		_sprite.scale(sf::Vector2f(0.5f, 0.5f));
		
		_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
		
		
		
		_totalTime = 0.0f;
		
		_isFaceRight = true;
		_speed = 150.0f;
		
	}


	Character::~Character()
	{
	}

	void Character::Animation(float dt, float _switchTime, bool isFaceRight)
	{
		_totalTime += dt;
		if (_totalTime >= _switchTime)
		{
			_totalTime -= _switchTime;
			_col++;
			
			switch (_row)
			{
			case 0:
					if (_col >= 2)
					{
						_col = 0;
					}
				break;
			case 1:
				if (_col >= 6)
				{
					_col = 0;
				}
				break;
			case 2:
				if (_col >= 2)
				{
					_col = 0;
				}
				break;
			case 3:
				if (_col >= 1)
				{
					_col = 0;
				}
				break;
			default:
				break;
			}
		}
		if (_isFaceRight)
		{
			_sprite.setTextureRect(sf::IntRect(textureSize.x * _col, textureSize.y * _row, textureSize.x, textureSize.y));
		}
		else
		{
			_sprite.setTextureRect(sf::IntRect(textureSize.x * (_col+1), textureSize.y * _row, -textureSize.x, textureSize.y));
		}
		
	}

	void Character::Update(float dt)
	{
		
		sf::Vector2f _movement(0.0f, 0.0f);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			_movement.x += _speed * dt;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			_movement.x -= _speed * dt;
		}

		if (_movement.x == 0.0f)
		{
			_row = 0;
		}
		else
		{
			_row = 1;
			if (_movement.x > 0.0f)
			{
				_isFaceRight = true;
			}
			else
			{
				_isFaceRight = false;
			}
		}
		
		
		Animation(dt, 1.5f, _isFaceRight);
		if (_isFaceRight)
		{
			_sprite.setTextureRect(sf::IntRect(textureSize.x * _col, textureSize.y * _row, textureSize.x, textureSize.y));
		}
		else
		{
			_sprite.setTextureRect(sf::IntRect(textureSize.x * (_col + 1), textureSize.y * _row, -textureSize.x, textureSize.y));
		}
		_sprite.move(_movement);
	}

	void Character::Draw()
	{
		_data->window.draw(_sprite);
	}
}