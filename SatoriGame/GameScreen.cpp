#include "GameScreen.h"

namespace Dan
{
	GameScreen::GameScreen(pointerGameStuff data)
		:
		_data(data)
	{

	}

	GameScreen::~GameScreen()
	{

	}

	void GameScreen::Init()
	{
		//background
	    this->_data->asset.AddTexture("Background I", Spite_1_FilePath);
		this->_data->asset.AddTexture("Background II", Spite_2_FilePath);
		this->_data->asset.AddTexture("Background III", Spite_3_FilePath);
		this->_data->asset.AddTexture("Background IV", Spite_4_FilePath);
		this->_data->asset.AddTexture("Background V", Spite_5_FilePath);
		this->_data->asset.AddTexture("Background VI", Spite_6_FilePath);
		this->_data->asset.AddTexture("Background VII", Spite_7_FilePath);
		this->_data->asset.AddTexture("Background VIII", Spite_8_FilePath);
		this->_data->asset.AddTexture("Background IX", Spite_9_FilePath);
		this->_data->asset.AddTexture("Background X", Spite_10_FilePath);
		this->_data->asset.AddTexture("Background XI", Spite_11_FilePath);
		
		sf::Sprite sprite1(_data->asset.GetTexture("Background I"));
		sf::Sprite sprite2(_data->asset.GetTexture("Background II"));
		sf::Sprite sprite3(_data->asset.GetTexture("Background III"));
		sf::Sprite sprite4(_data->asset.GetTexture("Background IV"));
		sf::Sprite sprite5(_data->asset.GetTexture("Background V"));
		sf::Sprite sprite6(_data->asset.GetTexture("Background VI"));
		sf::Sprite sprite7(_data->asset.GetTexture("Background VII"));
		sf::Sprite sprite8(_data->asset.GetTexture("Background VIII"));
		sf::Sprite sprite9(_data->asset.GetTexture("Background IX"));
		sf::Sprite sprite10(_data->asset.GetTexture("Background X"));
		sf::Sprite sprite11(_data->asset.GetTexture("Background XI"));
		
		_backgroundSprites.push_back(sprite1);
		_backgroundSprites.push_back(sprite2);
		_backgroundSprites.push_back(sprite3);
		_backgroundSprites.push_back(sprite4);
		_backgroundSprites.push_back(sprite5);
		_backgroundSprites.push_back(sprite6);
		_backgroundSprites.push_back(sprite7);
		_backgroundSprites.push_back(sprite8);
		_backgroundSprites.push_back(sprite9);
		_backgroundSprites.push_back(sprite10);
		_backgroundSprites.push_back(sprite11);

		for (int i = _backgroundSprites.size() - 1; i >= 0; i--)
		{
			this->_backgroundSprites.at(i).setPosition(0.0f, -100.0f);
		}

		//character
		_data->asset.AddTexture("Character Texture", Sprite_FilePath);
		character = new Character(_data);
		
	}

	void GameScreen::HandleInput()
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
	void GameScreen::Update(float dt)
	{
		//character->Animation(dt);
		character->Update(dt);	
	}

	void GameScreen::Draw(float dt)
	{
		this->_data->window.clear();
		
		
		for (int i = _backgroundSprites.size() - 1; i >= 0 ; i-- )
		{
			this->_data->window.draw(_backgroundSprites.at(i));
			
		}
		character->Draw();
		this->_data->window.display();
	}
}
