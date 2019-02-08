#pragma once
#include <SFML\Graphics.hpp>
#include "VirtualState.h"
#include "GameManager.h"
#include "PathNames.h"
#include "Character.h"

#include <vector>

namespace Dan
{
	class GameScreen : public VirtualState
	{
	public:
		GameScreen(pointerGameStuff data);
		~GameScreen();

		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		std::vector<sf::Sprite> _backgroundSprites;
		sf::Clock _clock;
		Character* character;
		pointerGameStuff _data;
	};
}