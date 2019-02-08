#pragma once

#define Width 928
#define Height 693
#define Intro_FilePath "Stuff/images/intro.png"

//background
#define Spite_1_FilePath "Stuff/images/background/Layer_0000_9.png"
#define Spite_2_FilePath "Stuff/images/background/Layer_0001_8.png"
#define Spite_3_FilePath "Stuff/images/background/Layer_0002_7.png"
#define Spite_4_FilePath "Stuff/images/background/Layer_0003_6.png"
#define Spite_5_FilePath "Stuff/images/background/Layer_0004_Lights.png"
#define Spite_6_FilePath "Stuff/images/background/Layer_0005_5.png"
#define Spite_7_FilePath "Stuff/images/background/Layer_0006_4.png"
#define Spite_8_FilePath "Stuff/images/background/Layer_0007_Lights.png"
#define Spite_9_FilePath "Stuff/images/background/Layer_0008_3.png"
#define Spite_10_FilePath "Stuff/images/background/Layer_0009_2.png"
#define Spite_11_FilePath "Stuff/images/background/Layer_0010_1.png"

//character sprite
#define Sprite_FilePath "Stuff/images/frame.png"

//Main Menu
#define PlayButton_FilePath "Stuff/images/play_button.png"
#define Retry_FilePath "Stuff/images/retry.png"
#define Credits_FilePath "Stuff/images/credits.png"
#define Exit_FilePath "Stuff/images/exit.png"

//Title
#define TitleName_FilePath "Stuff/images/title.png"

//character states
enum CharacterState
{
	Idle,
	Walking,
	Running,
	Dead
};

enum GameStates
{
	eReady,
	ePlaying,
	eGameOver
};