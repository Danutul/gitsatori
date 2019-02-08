#pragma once
#include "GameManager.h"
#include "IntroScreen.h"
#include <iostream>

namespace Dan
{
	GameManager::GameManager(int width, int height, std::string title)
	{
		_data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Default);
		_data->state.AddState(uPointerState(new IntroScreen(this->_data)));
		this->Go();
	}

	GameManager::~GameManager()
	{
	}

	void GameManager::Go()
	{
		float frameTime, interpolation;
		float accumulator = 0.0f;

		while (this->_data->window.isOpen())
		{
			this->_data->state.ManageStates();

			frameTime = _clock.restart().asSeconds();

			if (frameTime > 0.25f)
			{
				frameTime = 0.25f;
			}
			accumulator += frameTime;

			while (accumulator >= dt)
			{
				this->_data->state.GetState()->HandleInput();
				this->_data->state.GetState()->Update(dt);
				accumulator -= dt;
			}

			interpolation = accumulator / dt;

			this->_data->state.GetState()->Draw(interpolation);

		}
	}
}


