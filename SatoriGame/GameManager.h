#pragma once
#include <SFML\Graphics.hpp>
#include "StateManager.h"
#include "Asset.h"
#include "InputManager.h"
#include <memory>
#include <string>

namespace Dan
{
	struct GameStuff
	{
		sf::RenderWindow window;
		StateManager state;
		Asset asset;
		InputManager input;
	};

	typedef std::shared_ptr<GameStuff> pointerGameStuff;

	class GameManager
	{
	public:
		GameManager(int width, int height, std::string title);
		~GameManager();

	private:
		const float dt = 1.0f / 60.0f;
		sf::Clock _clock;
		pointerGameStuff _data = std::make_shared<GameStuff>();

		void Go();
	};
}