#pragma once
#include <SFML\Graphics.hpp>
#include "VirtualState.h"
#include "GameManager.h"
#include "GameScreen.h"
#include "PathNames.h"

namespace Dan
{
	class MainMenu : public VirtualState
	{
	public:
		MainMenu(pointerGameStuff data);
		~MainMenu();

		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		sf::Sprite _spritePlay;
		sf::Sprite _spriteRetry;
		sf::Sprite _spriteCredits;
		sf::Sprite _spriteExit;

		sf::Sprite _spriteTitle;

		pointerGameStuff _data;
	};
}

