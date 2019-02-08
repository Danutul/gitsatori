#pragma once
#include "IntroScreen.h"
#include "PathNames.h"
#include "GameScreen.h"
#include <sstream>
#include <iostream>
namespace Dan
{
	IntroScreen::IntroScreen(pointerGameStuff data)
		:
		_data(data)
	{
	}

	void IntroScreen::Init()
	{
		this->_data->asset.AddTexture("Logo", Intro_FilePath);
		_spriteLogo.setTexture(_data->asset.GetTexture("Logo"));
	}

	void IntroScreen::HandleInput()
	{
		sf::Event event;
		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type ||
				event.key.code == sf::Keyboard::Escape)
			{
				this->_data->window.close();
			}
		}

	}

	void IntroScreen::Update(float dt)
	{
		if (_clock.getElapsedTime().asSeconds() > 3.0f)
		{
			this->_data->state.AddState(uPointerState(new MainMenu(this->_data)), true);
		}
	}

	void IntroScreen::Draw(float dt)
	{
		this->_data->window.clear();
		this->_data->window.draw(_spriteLogo);
		this->_data->window.display();
	}
}