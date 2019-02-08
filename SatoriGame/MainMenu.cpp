#include "MainMenu.h"


namespace Dan
{
	MainMenu::MainMenu(pointerGameStuff data)
		:
		_data(data)
	{
	}

	MainMenu::~MainMenu()
	{
	}

	void MainMenu::Init()
	{
		//addTitle
		_data->asset.AddTexture("Title Name", TitleName_FilePath);
		
		//addtexture buttons
		_data->asset.AddTexture("Play Button", PlayButton_FilePath);
		_data->asset.AddTexture("Retry Button", Retry_FilePath);
		_data->asset.AddTexture("Credits Button", Credits_FilePath);
		_data->asset.AddTexture("Exit Button", Exit_FilePath);

		//setTitle
		_spriteTitle.setTexture(_data->asset.GetTexture("Title Name"));

		//settexture buttons
		_spritePlay.setTexture(_data->asset.GetTexture("Play Button"));
		_spriteRetry.setTexture(_data->asset.GetTexture("Retry Button"));
		_spriteCredits.setTexture(_data->asset.GetTexture("Credits Button"));
		_spriteExit.setTexture(_data->asset.GetTexture("Exit Button"));

		//setposition title
		_spriteTitle.setPosition((Width / 2) - (_spriteTitle.getGlobalBounds().width / 2),
			(Height / 2) - 200.0f);

		//setposition buttons
		_spritePlay.setPosition((Width / 2) - (_spritePlay.getGlobalBounds().width / 2),
			Height / 2);
		_spriteRetry.setPosition((Width / 2) - (_spriteRetry.getGlobalBounds().width / 2),
			(Height /2 ) + _spritePlay.getGlobalBounds().height + 10.0f);
		_spriteCredits.setPosition((Width / 2) - (_spriteCredits.getGlobalBounds().width / 2),
			(Height / 2) + (_spritePlay.getGlobalBounds().height * 2) + 20.0f);
		_spriteExit.setPosition((Width / 2) - (_spriteCredits.getGlobalBounds().width / 2),
			(Height / 2) + (_spritePlay.getGlobalBounds().height * 3) + 30.0f);

	}
	void MainMenu::HandleInput()
	{
		sf::Event event;
		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type ||
				event.key.code == sf::Keyboard::Escape)
			{
				this->_data->window.close();
			}
			if (_data->input.IsSpriteClicked(_spritePlay, sf::Mouse::Left, _data->window))
			{
				_data->state.AddState(uPointerState(new GameScreen(_data)), true);
			}
		}
	}
	void MainMenu::Update(float dt)
	{}
	void MainMenu::Draw(float dt)
	{
		
		this->_data->window.clear(sf::Color(7, 123,108));
		this->_data->window.draw(_spriteTitle);
		this->_data->window.draw(_spritePlay);
		this->_data->window.draw(_spriteRetry);
		this->_data->window.draw(_spriteCredits);
		this->_data->window.draw(_spriteExit);
		this->_data->window.display();
	}
}