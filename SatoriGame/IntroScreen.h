#pragma once
#include <SFML\Graphics.hpp>
#include "StateManager.h"
#include "GameManager.h"
#include "MainMenu.h"
#include <iostream>

namespace Dan
{
	class IntroScreen : public VirtualState
	{
	public:
		IntroScreen(pointerGameStuff data);
		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		pointerGameStuff _data;
		sf::Clock _clock;
		sf::Sprite _spriteLogo;
	};
}