#include<iostream>
#include<SFML\Graphics.hpp>
#include<SFML\Audio.hpp>
#include<string>
#include <iomanip>
#include <time.h>
#include <cmath>
#include "SFML.h"
#include "Start_New_Game.h"
#include "Solver.h"

int main()
{

	Window.create(sf::VideoMode(800, 600), "SUDOKU", sf::Style::Default);     //open game window

																			  //load fonts
	font.loadFromFile("Third_Font.ttf");
	font2.loadFromFile("Fifth_Font.ttf");
	font3.loadFromFile("Second_Font.ttf");



	//prepare to the first background  (Loading......)
	oneloading.setCharacterSize(25);
	oneloading.setFont(font);
	oneloading.setString("LOADING....");
	oneloading.setColor(sf::Color::White);
	oneloading.setPosition(650, 525);

	load2.loadFromFile("loading.JPG");
	loading2.setTexture(load2);
	//Random choice first background (Loading.......)
	char time_now[10];
	int  temp, mi, se;
	_strtime_s(time_now, 10);
	mi = ((time_now[3] - 48) * 10) + (time_now[4] - 48);
	se = ((time_now[6] - 48) * 10) + (time_now[7] - 48);
	temp = abs((rand() + mi + se) % 11);

	switch (temp)
	{
	case 0:
		loading.loadFromFile("Did you know11.JPG");
		load.setTexture(loading);
		break;
	case 1:
		loading.loadFromFile("Did you know1.JPG");
		load.setTexture(loading);
		break;
	case 2:
		loading.loadFromFile("Did you know2.JPG");
		load.setTexture(loading);
		break;
	case 3:
		loading.loadFromFile("Did you know3.JPG");
		load.setTexture(loading);
		break;
	case 4:
		loading.loadFromFile("Did you know4.JPG");
		load.setTexture(loading);
		break;
	case 5:
		loading.loadFromFile("Did you know5.JPG");
		load.setTexture(loading);
		break;
	case 6:
		loading.loadFromFile("Did you know6.JPG");
		load.setTexture(loading);
		break;
	case 7:
		loading.loadFromFile("Did you know7.JPG");
		load.setTexture(loading);
		break;
	case 8:
		loading.loadFromFile("Did you know8.JPG");
		load.setTexture(loading);
		break;
	case 9:
		loading.loadFromFile("Did you know9.JPG");
		load.setTexture(loading);
		break;
	case 10:
		loading.loadFromFile("Did you know10.JPG");
		load.setTexture(loading);
		break;
	}
	//The first background  (Loading......)
	Window.draw(load);
	Window.draw(oneloading);
	Window.display();

	//load the Game Music and prepare the Game menu


	soundbuffer2.loadFromFile("Music.wav");
	sound2.setBuffer(soundbuffer2);

	soundbuffer.loadFromFile("Choice_Sound.wav");
	sound.setVolume(40);
	sound.setBuffer(soundbuffer);


	play.loadFromFile("Pause-icon.PNG");
	play1.setTexture(play);
	play1.setPosition(650, 525);

	sTexture.loadFromFile("sudokua.JPG");
	Ground.setTexture(sTexture);

	ftexture.loadFromFile("arrow-back.PNG");
	Back.setTexture(ftexture);
	Back.setPosition(720, 525);

	mTexture.loadFromFile("Sound-off.PNG");
	mute.setTexture(mTexture);
	mute.setPosition(720, 525);

	rTexture.loadFromFile("Sound-on.PNG");
	speaker.setTexture(rTexture);
	speaker.setPosition(720, 525);

	playa.loadFromFile("Play-icon.PNG");
	play2.setTexture(playa);
	play2.setPosition(650, 525);

	text1.setFont(font);
	text1.setString("NEW GAME");
	text1.setCharacterSize(55);
	text1.setColor(sf::Color(237, 251, 68));
	text1.setPosition(243, 250);

	text2.setFont(font);
	text2.setString("SOLVE MY BOARD");
	text2.setCharacterSize(55);
	text2.setColor(sf::Color(255, 255, 255));
	text2.setPosition(170, 320);

	text3.setFont(font);
	text3.setString("ABOUT");
	text3.setCharacterSize(55);
	text3.setColor(sf::Color(255, 255, 255));
	text3.setPosition(310, 390);

	text4.setFont(font);
	text4.setString("EXIT");
	text4.setCharacterSize(55);
	text4.setColor(sf::Color(255, 255, 255));
	text4.setPosition(335, 460);





	//prepare the New Game menu


	background.loadFromFile("Board_Background.PNG");
	bacg.setTexture(background);

	icon.loadFromFile("check-icon.PNG");
	Icon.setTexture(icon);
	Icon.setPosition(590, 115);

	check.setString("Check Answer");
	check.setPosition(569, 63);
	check.setColor(sf::Color::White);
	check.setFont(font);
	check.setCharacterSize(30);

	text5.setFont(font);
	text5.setString("EASY");
	text5.setCharacterSize(55);
	text5.setColor(sf::Color(237, 251, 68));
	text5.setPosition(330, 280);

	text6.setFont(font);
	text6.setString("MEDIUM");
	text6.setCharacterSize(55);
	text6.setColor(sf::Color(255, 255, 255));
	text6.setPosition(290, 350);

	text7.setFont(font);
	text7.setString("HARD");
	text7.setCharacterSize(55);
	text7.setColor(sf::Color(255, 255, 255));
	text7.setPosition(330, 420);




	//prepare the About page
	About.setString("A Sudoku puzzle consists of 81 cells which are divided into nine columns\nrows and regions. \nThe task is now to place the numbers from 1 to 9 into the empty cells in \nsuch a way that in every row, column and 3×3 region each number \nappears only once . \n A Sudoku has at least 17 given numbers but normally there are 22 to 30. \n This Game is Made by : \tMostafa Negm ElDeen. \n\t\t\t\t\t\t\t\t\t\t\t\t Mahmoud Ali. \n \t\t\t\t\t\t\t\t\t\t\t\tMohannad Bayoumi. \n \t\t\t\t\t\t\t\t\t\t\t\tMahmoud Khedr. \n \t\t\t\t\t\t\t\t\t\t\t\tMuhammed Fathi.");
	About.setCharacterSize(25);
	About.setColor(sf::Color(64, 0, 64));
	About.setFont(font3);
	About.setPosition(0, 170);


	// Now Start the Game
	sound2.play();
	Window.clear();
	Window.draw(Ground);
	Window.draw(text1);
	Window.draw(text2);
	Window.draw(text3);
	Window.draw(text4);
	Window.draw(speaker);
	Window.draw(play2);
	Window.display();


	// Sukuko Game....

	while (Window.isOpen())
	{
		while (Window.pollEvent(Event))
		{

			switch (Event.type)
			{
			case sf::Event::Closed:
				Window.close();
				break;
			}
			if (Event.type == sf::Event::KeyPressed)
			{
				//Up And Down On first Page And About Must be one
				if (Event.key.code == sf::Keyboard::Up&&pages == 1 && about == 1)
				{
					sound.play();
					intro--;

					if (intro < 1)
					{
						intro = 6;
					}
					// Now Change the icons color
					if (intro == 1 && sound1 == true && musical == true)
					{
						speaker.setColor(sf::Color(255, 255, 255));
						text2.setColor(sf::Color(255, 255, 255));
						text4.setColor(sf::Color(255, 255, 255));
						text1.setColor(sf::Color(237, 251, 68));
						text3.setColor(sf::Color(255, 255, 255));
						play2.setColor(sf::Color::White);

					}
					else if (intro == 4 && sound1 == true && musical == true)
					{
						speaker.setColor(sf::Color(255, 255, 255));
						text2.setColor(sf::Color(255, 255, 255));
						text4.setColor(sf::Color(237, 251, 68));
						text1.setColor(sf::Color(255, 255, 255));
						text3.setColor(sf::Color(255, 255, 255));
						play2.setColor(sf::Color::White);
					}
					else if (intro == 2 && sound1 == true && musical == true)
					{

						text2.setColor(sf::Color(237, 251, 68));
						text4.setColor(sf::Color(255, 255, 255));
						text1.setColor(sf::Color(255, 255, 255));
						text3.setColor(sf::Color(255, 255, 255));
						speaker.setColor(sf::Color(255, 255, 255));
						play2.setColor(sf::Color::White);
					}
					else if (intro == 3 && sound1 == true && musical == true)
					{

						text2.setColor(sf::Color(255, 255, 255));
						text4.setColor(sf::Color(255, 255, 255));
						text1.setColor(sf::Color(255, 255, 255));
						text3.setColor(sf::Color(237, 251, 68));
						speaker.setColor(sf::Color(255, 255, 255));
						play2.setColor(sf::Color::White);
					}
					else if (intro == 5 && sound1 == true && musical == true)
					{
						text2.setColor(sf::Color(255, 255, 255));
						text4.setColor(sf::Color(255, 255, 255));
						text1.setColor(sf::Color(255, 255, 255));
						text3.setColor(sf::Color(255, 255, 255));
						speaker.setColor(sf::Color(237, 251, 68));
						play2.setColor(sf::Color::White);
					}
					else if (intro == 6 && sound1 == true && musical == true)
					{
						text2.setColor(sf::Color(255, 255, 255));
						text4.setColor(sf::Color(255, 255, 255));
						text1.setColor(sf::Color(255, 255, 255));
						text3.setColor(sf::Color(255, 255, 255));
						speaker.setColor(sf::Color(255, 255, 255));
						play2.setColor(sf::Color(237, 251, 68));
					}
					else if (intro == 1 && sound1 == true && musical == false)
					{
						text2.setColor(sf::Color(255, 255, 255));
						text4.setColor(sf::Color(255, 255, 255));
						text1.setColor(sf::Color(237, 251, 68));
						text3.setColor(sf::Color(255, 255, 255));
						speaker.setColor(sf::Color(255, 255, 255));
						play1.setColor(sf::Color(255, 255, 255));
					}
					else if (intro == 2 && sound1 == true && musical == false)
					{
						text1.setColor(sf::Color(255, 255, 255));
						text2.setColor(sf::Color(237, 251, 68));
						text4.setColor(sf::Color(255, 255, 255));
						text3.setColor(sf::Color(255, 255, 255));
						speaker.setColor(sf::Color(255, 255, 255));
						play1.setColor(sf::Color(255, 255, 255));
					}
					else if (intro == 3 && sound1 == true && musical == false)
					{
						text2.setColor(sf::Color(255, 255, 255));
						text4.setColor(sf::Color(255, 255, 255));
						text1.setColor(sf::Color(255, 255, 255));
						text3.setColor(sf::Color(237, 251, 68));
						speaker.setColor(sf::Color(255, 255, 255));
						play1.setColor(sf::Color(255, 255, 255));
					}
					else if (intro == 4 && sound1 == true && musical == false)
					{
						text2.setColor(sf::Color(255, 255, 255));
						text4.setColor(sf::Color(237, 251, 68));
						text1.setColor(sf::Color(255, 255, 255));
						text3.setColor(sf::Color(255, 255, 255));
						speaker.setColor(sf::Color(255, 255, 255));
						play1.setColor(sf::Color(255, 255, 255));
					}
					else if (intro == 5 && sound1 == true && musical == false)
					{
						text2.setColor(sf::Color(255, 255, 255));
						text4.setColor(sf::Color(255, 255, 255));
						text1.setColor(sf::Color(255, 255, 255));
						text3.setColor(sf::Color(255, 255, 255));
						speaker.setColor(sf::Color(237, 251, 68));
						play1.setColor(sf::Color(255, 255, 255));
					}
					else if (intro == 6 && sound1 == true && musical == false)
					{
						text2.setColor(sf::Color(255, 255, 255));
						text4.setColor(sf::Color(255, 255, 255));
						text1.setColor(sf::Color(255, 255, 255));
						text3.setColor(sf::Color(255, 255, 255));
						speaker.setColor(sf::Color(255, 255, 255));
						play1.setColor(sf::Color(237, 251, 68));
					}
					else if (intro == 1 && sound1 == false && musical == true)
					{
						mute.setColor(sf::Color(255, 255, 255));
						text2.setColor(sf::Color(255, 255, 255));
						text4.setColor(sf::Color(255, 255, 255));
						text1.setColor(sf::Color(237, 251, 68));
						text3.setColor(sf::Color(255, 255, 255));
						play2.setColor(sf::Color::White);
					}
					else if (intro == 4 && sound1 == false && musical == true)
					{
						mute.setColor(sf::Color(255, 255, 255));
						text2.setColor(sf::Color(255, 255, 255));
						text4.setColor(sf::Color(237, 251, 68));
						text1.setColor(sf::Color(255, 255, 255));
						text3.setColor(sf::Color(255, 255, 255));
						play2.setColor(sf::Color::White);
					}
					else if (intro == 2 && sound1 == false && musical == true)
					{

						text2.setColor(sf::Color(237, 251, 68));
						text4.setColor(sf::Color(255, 255, 255));
						text1.setColor(sf::Color(255, 255, 255));
						text3.setColor(sf::Color(255, 255, 255));
						mute.setColor(sf::Color(255, 255, 255));
						play2.setColor(sf::Color::White);
					}
					else if (intro == 3 && sound1 == false && musical == true)
					{

						text2.setColor(sf::Color(255, 255, 255));
						text4.setColor(sf::Color(255, 255, 255));
						text1.setColor(sf::Color(255, 255, 255));
						text3.setColor(sf::Color(237, 251, 68));
						mute.setColor(sf::Color(255, 255, 255));
						play2.setColor(sf::Color::White);
					}
					else if (intro == 5 && sound1 == false && musical == true)
					{
						text2.setColor(sf::Color(255, 255, 255));
						text4.setColor(sf::Color(255, 255, 255));
						text1.setColor(sf::Color(255, 255, 255));
						text3.setColor(sf::Color(255, 255, 255));
						mute.setColor(sf::Color(237, 251, 68));
						play2.setColor(sf::Color::White);
					}
					else if (intro == 6 && sound1 == false && musical == true)
					{
						text2.setColor(sf::Color(255, 255, 255));
						text4.setColor(sf::Color(255, 255, 255));
						text1.setColor(sf::Color(255, 255, 255));
						text3.setColor(sf::Color(255, 255, 255));
						mute.setColor(sf::Color(255, 255, 255));
						play2.setColor(sf::Color(237, 251, 68));
					}
					else if (intro == 1 && sound1 == false && musical == false)
					{
						text2.setColor(sf::Color(255, 255, 255));
						text4.setColor(sf::Color(255, 255, 255));
						text1.setColor(sf::Color(237, 251, 68));
						text3.setColor(sf::Color(255, 255, 255));
						mute.setColor(sf::Color(255, 255, 255));
						play1.setColor(sf::Color(255, 255, 255));
					}
					else if (intro == 2 && sound1 == false && musical == false)
					{
						text1.setColor(sf::Color(255, 255, 255));
						text2.setColor(sf::Color(237, 251, 68));
						text4.setColor(sf::Color(255, 255, 255));
						text3.setColor(sf::Color(255, 255, 255));
						mute.setColor(sf::Color(255, 255, 255));
						play1.setColor(sf::Color(255, 255, 255));
					}
					else if (intro == 3 && sound1 == false && musical == false)
					{
						text2.setColor(sf::Color(255, 255, 255));
						text4.setColor(sf::Color(255, 255, 255));
						text1.setColor(sf::Color(255, 255, 255));
						text3.setColor(sf::Color(237, 251, 68));
						mute.setColor(sf::Color(255, 255, 255));
						play1.setColor(sf::Color(255, 255, 255));
					}
					else if (intro == 4 && sound1 == false && musical == false)
					{
						text2.setColor(sf::Color(255, 255, 255));
						text4.setColor(sf::Color(237, 251, 68));
						text1.setColor(sf::Color(255, 255, 255));
						text3.setColor(sf::Color(255, 255, 255));
						mute.setColor(sf::Color(255, 255, 255));
						play1.setColor(sf::Color(255, 255, 255));
					}
					else if (intro == 5 && sound1 == false && musical == false)
					{
						text2.setColor(sf::Color(255, 255, 255));
						text4.setColor(sf::Color(255, 255, 255));
						text1.setColor(sf::Color(255, 255, 255));
						text3.setColor(sf::Color(255, 255, 255));
						mute.setColor(sf::Color(237, 251, 68));
						play1.setColor(sf::Color(255, 255, 255));
					}
					else if (intro == 6 && sound1 == false && musical == false)
					{
						text2.setColor(sf::Color(255, 255, 255));
						text4.setColor(sf::Color(255, 255, 255));
						text1.setColor(sf::Color(255, 255, 255));
						text3.setColor(sf::Color(255, 255, 255));
						mute.setColor(sf::Color(255, 255, 255));
						play1.setColor(sf::Color(237, 251, 68));
					}


					//Now Draw The icons
					if (sound1 == true && musical == true)
					{

						Window.clear();
						Window.draw(Ground);
						Window.draw(text1);
						Window.draw(text2);
						Window.draw(text3);
						Window.draw(text4);
						Window.draw(speaker);
						Window.draw(play2);
						Window.display();
					}
					else if (sound1 == false && musical == true)
					{
						Window.clear();
						Window.draw(Ground);
						Window.draw(text1);
						Window.draw(text2);
						Window.draw(text3);
						Window.draw(text4);
						Window.draw(mute);
						Window.draw(play2);
						Window.display();

					}
					else if (sound1 == false && musical == false)
					{

						Window.clear();
						Window.draw(Ground);
						Window.draw(text1);
						Window.draw(text2);
						Window.draw(text3);
						Window.draw(text4);
						Window.draw(mute);
						Window.draw(play1);
						Window.display();

					}
					else if (sound1 == true && musical == false)
					{
						Window.clear();
						Window.draw(Ground);
						Window.draw(text1);
						Window.draw(text2);
						Window.draw(text3);
						Window.draw(text4);
						Window.draw(speaker);
						Window.draw(play1);
						Window.display();
					}
				}
				else if (Event.key.code == sf::Keyboard::Down&&pages == 1 && about == 1)
				{
					sound.play();
					intro++;

					if (intro > 6)
					{
						intro = 1;
					}
					//std::cout << intro << std::endl;

					if (intro == 1 && sound1 == true && musical == true)
					{
						speaker.setColor(sf::Color(255, 255, 255));
						text2.setColor(sf::Color(255, 255, 255));
						text4.setColor(sf::Color(255, 255, 255));
						text1.setColor(sf::Color(237, 251, 68));
						text3.setColor(sf::Color(255, 255, 255));
						play2.setColor(sf::Color::White);

					}
					else if (intro == 4 && sound1 == true && musical == true)
					{
						speaker.setColor(sf::Color(255, 255, 255));
						text2.setColor(sf::Color(255, 255, 255));
						text4.setColor(sf::Color(237, 251, 68));
						text1.setColor(sf::Color(255, 255, 255));
						text3.setColor(sf::Color(255, 255, 255));
						play2.setColor(sf::Color::White);
					}

					else if (intro == 2 && sound1 == true && musical == true)
					{

						text2.setColor(sf::Color(237, 251, 68));
						text4.setColor(sf::Color(255, 255, 255));
						text1.setColor(sf::Color(255, 255, 255));
						text3.setColor(sf::Color(255, 255, 255));
						speaker.setColor(sf::Color(255, 255, 255));
						play2.setColor(sf::Color::White);
					}
					else if (intro == 3 && sound1 == true && musical == true)
					{

						text2.setColor(sf::Color(255, 255, 255));
						text4.setColor(sf::Color(255, 255, 255));
						text1.setColor(sf::Color(255, 255, 255));
						text3.setColor(sf::Color(237, 251, 68));
						speaker.setColor(sf::Color(255, 255, 255));
						play2.setColor(sf::Color::White);
					}
					else if (intro == 5 && sound1 == true && musical == true)
					{
						text2.setColor(sf::Color(255, 255, 255));
						text4.setColor(sf::Color(255, 255, 255));
						text1.setColor(sf::Color(255, 255, 255));
						text3.setColor(sf::Color(255, 255, 255));
						speaker.setColor(sf::Color(237, 251, 68));
						play2.setColor(sf::Color::White);
					}
					else if (intro == 6 && sound1 == true && musical == true)
					{
						text2.setColor(sf::Color(255, 255, 255));
						text4.setColor(sf::Color(255, 255, 255));
						text1.setColor(sf::Color(255, 255, 255));
						text3.setColor(sf::Color(255, 255, 255));
						speaker.setColor(sf::Color(255, 255, 255));
						play2.setColor(sf::Color(237, 251, 68));
					}
					else if (intro == 1 && sound1 == true && musical == false)
					{
						text2.setColor(sf::Color(255, 255, 255));
						text4.setColor(sf::Color(255, 255, 255));
						text1.setColor(sf::Color(237, 251, 68));
						text3.setColor(sf::Color(255, 255, 255));
						speaker.setColor(sf::Color(255, 255, 255));
						play1.setColor(sf::Color(255, 255, 255));
					}
					else if (intro == 2 && sound1 == true && musical == false)
					{
						text1.setColor(sf::Color(255, 255, 255));
						text2.setColor(sf::Color(237, 251, 68));
						text4.setColor(sf::Color(255, 255, 255));
						text3.setColor(sf::Color(255, 255, 255));
						speaker.setColor(sf::Color(255, 255, 255));
						play1.setColor(sf::Color(255, 255, 255));
					}
					else if (intro == 3 && sound1 == true && musical == false)
					{
						text2.setColor(sf::Color(255, 255, 255));
						text4.setColor(sf::Color(255, 255, 255));
						text1.setColor(sf::Color(255, 255, 255));
						text3.setColor(sf::Color(237, 251, 68));
						speaker.setColor(sf::Color(255, 255, 255));
						play1.setColor(sf::Color(255, 255, 255));
					}

					else if (intro == 4 && sound1 == true && musical == false)
					{
						text2.setColor(sf::Color(255, 255, 255));
						text4.setColor(sf::Color(237, 251, 68));
						text1.setColor(sf::Color(255, 255, 255));
						text3.setColor(sf::Color(255, 255, 255));
						speaker.setColor(sf::Color(255, 255, 255));
						play1.setColor(sf::Color(255, 255, 255));
					}

					else if (intro == 5 && sound1 == true && musical == false)
					{
						text2.setColor(sf::Color(255, 255, 255));
						text4.setColor(sf::Color(255, 255, 255));
						text1.setColor(sf::Color(255, 255, 255));
						text3.setColor(sf::Color(255, 255, 255));
						speaker.setColor(sf::Color(237, 251, 68));
						play1.setColor(sf::Color(255, 255, 255));
					}

					else if (intro == 6 && sound1 == true && musical == false)
					{
						text2.setColor(sf::Color(255, 255, 255));
						text4.setColor(sf::Color(255, 255, 255));
						text1.setColor(sf::Color(255, 255, 255));
						text3.setColor(sf::Color(255, 255, 255));
						speaker.setColor(sf::Color(255, 255, 255));
						play1.setColor(sf::Color(237, 251, 68));
					}


					else if (intro == 1 && sound1 == false && musical == true)
					{
						mute.setColor(sf::Color(255, 255, 255));
						text2.setColor(sf::Color(255, 255, 255));
						text4.setColor(sf::Color(255, 255, 255));
						text1.setColor(sf::Color(237, 251, 68));
						text3.setColor(sf::Color(255, 255, 255));
						play2.setColor(sf::Color::White);
					}
					else if (intro == 4 && sound1 == false && musical == true)
					{
						mute.setColor(sf::Color(255, 255, 255));
						text2.setColor(sf::Color(255, 255, 255));
						text4.setColor(sf::Color(237, 251, 68));
						text1.setColor(sf::Color(255, 255, 255));
						text3.setColor(sf::Color(255, 255, 255));
						play2.setColor(sf::Color::White);
					}

					else if (intro == 2 && sound1 == false && musical == true)
					{


						text2.setColor(sf::Color(237, 251, 68));
						text4.setColor(sf::Color(255, 255, 255));
						text1.setColor(sf::Color(255, 255, 255));
						text3.setColor(sf::Color(255, 255, 255));
						mute.setColor(sf::Color(255, 255, 255));
						play2.setColor(sf::Color::White);
					}
					else if (intro == 3 && sound1 == false && musical == true)
					{

						text2.setColor(sf::Color(255, 255, 255));
						text4.setColor(sf::Color(255, 255, 255));
						text1.setColor(sf::Color(255, 255, 255));
						text3.setColor(sf::Color(237, 251, 68));
						mute.setColor(sf::Color(255, 255, 255));
						play2.setColor(sf::Color::White);
					}
					else if (intro == 5 && sound1 == false && musical == true)
					{
						text2.setColor(sf::Color(255, 255, 255));
						text4.setColor(sf::Color(255, 255, 255));
						text1.setColor(sf::Color(255, 255, 255));
						text3.setColor(sf::Color(255, 255, 255));
						mute.setColor(sf::Color(237, 251, 68));
						play2.setColor(sf::Color::White);
					}
					else if (intro == 6 && sound1 == false && musical == true)
					{
						text2.setColor(sf::Color(255, 255, 255));
						text4.setColor(sf::Color(255, 255, 255));
						text1.setColor(sf::Color(255, 255, 255));
						text3.setColor(sf::Color(255, 255, 255));
						mute.setColor(sf::Color(255, 255, 255));
						play2.setColor(sf::Color(237, 251, 68));
					}


					else if (intro == 1 && sound1 == false && musical == false)
					{
						text2.setColor(sf::Color(255, 255, 255));
						text4.setColor(sf::Color(255, 255, 255));
						text1.setColor(sf::Color(237, 251, 68));
						text3.setColor(sf::Color(255, 255, 255));
						mute.setColor(sf::Color(255, 255, 255));
						play1.setColor(sf::Color(255, 255, 255));
					}
					else if (intro == 2 && sound1 == false && musical == false)
					{
						text1.setColor(sf::Color(255, 255, 255));
						text2.setColor(sf::Color(237, 251, 68));
						text4.setColor(sf::Color(255, 255, 255));
						text3.setColor(sf::Color(255, 255, 255));
						mute.setColor(sf::Color(255, 255, 255));
						play1.setColor(sf::Color(255, 255, 255));
					}
					else if (intro == 3 && sound1 == false && musical == false)
					{
						text2.setColor(sf::Color(255, 255, 255));
						text4.setColor(sf::Color(255, 255, 255));
						text1.setColor(sf::Color(255, 255, 255));
						text3.setColor(sf::Color(237, 251, 68));
						mute.setColor(sf::Color(255, 255, 255));
						play1.setColor(sf::Color(255, 255, 255));
					}

					else if (intro == 4 && sound1 == false && musical == false)
					{
						text2.setColor(sf::Color(255, 255, 255));
						text4.setColor(sf::Color(237, 251, 68));
						text1.setColor(sf::Color(255, 255, 255));
						text3.setColor(sf::Color(255, 255, 255));
						mute.setColor(sf::Color(255, 255, 255));
						play1.setColor(sf::Color(255, 255, 255));
					}

					else if (intro == 5 && sound1 == false && musical == false)
					{
						text2.setColor(sf::Color(255, 255, 255));
						text4.setColor(sf::Color(255, 255, 255));
						text1.setColor(sf::Color(255, 255, 255));
						text3.setColor(sf::Color(255, 255, 255));
						mute.setColor(sf::Color(237, 251, 68));
						play1.setColor(sf::Color(255, 255, 255));
					}

					else if (intro == 6 && sound1 == false && musical == false)
					{
						text2.setColor(sf::Color(255, 255, 255));
						text4.setColor(sf::Color(255, 255, 255));
						text1.setColor(sf::Color(255, 255, 255));
						text3.setColor(sf::Color(255, 255, 255));
						mute.setColor(sf::Color(255, 255, 255));
						play1.setColor(sf::Color(237, 251, 68));
					}




					if (sound1 == true && musical == true)
					{

						Window.clear();
						Window.draw(Ground);
						Window.draw(text1);
						Window.draw(text2);
						Window.draw(text3);
						Window.draw(text4);
						Window.draw(speaker);
						Window.draw(play2);
						Window.display();
					}

					else if (sound1 == false && musical == true)
					{
						Window.clear();
						Window.draw(Ground);
						Window.draw(text1);
						Window.draw(text2);
						Window.draw(text3);
						Window.draw(text4);
						Window.draw(mute);
						Window.draw(play2);
						Window.display();

					}
					else if (sound1 == false && musical == false)
					{

						Window.clear();
						Window.draw(Ground);
						Window.draw(text1);
						Window.draw(text2);
						Window.draw(text3);
						Window.draw(text4);
						Window.draw(mute);
						Window.draw(play1);
						Window.display();

					}
					else if (sound1 == true && musical == false)
					{
						Window.clear();
						Window.draw(Ground);
						Window.draw(text1);
						Window.draw(text2);
						Window.draw(text3);
						Window.draw(text4);
						Window.draw(speaker);
						Window.draw(play1);
						Window.display();
					}


				}
				//Up And Down On Page Two And About Must Be One
				else if (Event.key.code == sf::Keyboard::Up&&pages == 2 && about == 1)
				{

					sound.play();

					page2--;

					if (page2 < 1)
					{
						page2 = 4;
					}
					//	std::cout << page2 << "l" << std::endl;

					if (page2 == 3)
					{
						text7.setColor(sf::Color(237, 251, 68));
						text6.setColor(sf::Color(255, 255, 255));
						text5.setColor(sf::Color(255, 255, 255));
						Back.setColor(sf::Color(255, 255, 255));

					}
					else if (page2 == 2)
					{

						text7.setColor(sf::Color(255, 255, 255));
						text6.setColor(sf::Color(237, 251, 68));
						text5.setColor(sf::Color(255, 255, 255));
						Back.setColor(sf::Color(255, 255, 255));
					}
					else if (page2 == 1)
					{
						text7.setColor(sf::Color(255, 255, 255));
						text6.setColor(sf::Color(255, 255, 255));
						text5.setColor(sf::Color(237, 251, 68));
						Back.setColor(sf::Color(255, 255, 255));
					}
					else if (page2 == 4)
					{
						text7.setColor(sf::Color(255, 255, 255));
						text6.setColor(sf::Color(255, 255, 255));
						text5.setColor(sf::Color(255, 255, 255));
						Back.setColor(sf::Color(237, 251, 68));
					}
					Window.clear();
					Window.draw(Ground);
					Window.draw(text5);
					Window.draw(text6);
					Window.draw(text7);
					Window.draw(Back);
					Window.display();

				}
				else if (Event.key.code == sf::Keyboard::Down&&pages == 2 && about == 1)
				{


					sound.play();

					page2++;

					if (page2 > 4)
					{
						page2 = 1;
					}

					//	std::cout << page2 << "l" << std::endl;

					if (page2 == 3)
					{
						text7.setColor(sf::Color(237, 251, 68));
						text6.setColor(sf::Color(255, 255, 255));
						text5.setColor(sf::Color(255, 255, 255));
						Back.setColor(sf::Color(255, 255, 255));
					}
					else if (page2 == 2)
					{

						text7.setColor(sf::Color(255, 255, 255));
						text6.setColor(sf::Color(237, 251, 68));
						text5.setColor(sf::Color(255, 255, 255));
						Back.setColor(sf::Color(255, 255, 255));
					}
					else if (page2 == 1)
					{
						text7.setColor(sf::Color(255, 255, 255));
						text6.setColor(sf::Color(255, 255, 255));
						text5.setColor(sf::Color(237, 251, 68));
						Back.setColor(sf::Color(255, 255, 255));
					}
					else if (page2 == 4)
					{
						text7.setColor(sf::Color(255, 255, 255));
						text6.setColor(sf::Color(255, 255, 255));
						text5.setColor(sf::Color(255, 255, 255));
						Back.setColor(sf::Color(237, 251, 68));
					}
					Window.clear();
					Window.draw(Ground);
					Window.draw(text5);
					Window.draw(text6);
					Window.draw(text7);
					Window.draw(Back);
					Window.display();

				}

			}
			//First menu Suduko Game   page 1
			else if ((Event.key.code == sf::Keyboard::Space&&pages == 1))
			{
				sound.play();
				if (intro == 4)
				{
					Window.close();
				}

				if (intro == 1)
				{
					// New Game choice
					pages++;
					if (pages == 2)
					{
						page2 = 1;
					}
					if (pages > 2)
					{
						pages = 2;

					}
					Window.clear();
					Window.draw(Ground);
					Window.draw(text5);
					Window.draw(text6);
					Window.draw(text7);
					Window.draw(Back);
					Window.display();

				}
				if (intro == 3)
				{
					//About choice
					about++;
					if (about > 2)
					{
						about = 2;
					}
					Window.clear();
					Window.draw(Ground);
					Window.draw(About);
					Window.display();
				}
				else if (intro == 2)
				{
					//Solve my board choice
					Window.clear();
					Custom_puzzle();
					mouseback = false;

				}
				//volume icons choice
				else if (intro == 5 && sound1 == true && musical == true)
				{
					sound.setVolume(0);
					sound1 = false;
					Window.clear();
					Window.draw(Ground);
					mute.setColor(sf::Color(237, 251, 68));
					Window.draw(mute);
					Window.draw(text1);
					Window.draw(text2);
					Window.draw(text3);
					Window.draw(text4);
					Window.draw(play2);
					Window.display();
				}
				else if (intro == 5 && sound1 == false && musical == true)
				{
					sound.setVolume(60);
					sound1 = true;
					Window.clear();
					Window.draw(Ground);
					Window.draw(text1);
					Window.draw(text2);
					Window.draw(text3);
					Window.draw(text4);
					speaker.setColor(sf::Color(237, 251, 68));
					Window.draw(speaker);
					Window.draw(play2);
					Window.display();
				}
				else if (intro == 5 && sound1 == false && musical == false)
				{
					sound.setVolume(60);
					sound1 = true;
					Window.clear();
					Window.draw(Ground);
					Window.draw(text1);
					Window.draw(text2);
					Window.draw(text3);
					Window.draw(text4);
					speaker.setColor(sf::Color(237, 251, 68));
					Window.draw(speaker);
					Window.draw(play1);
					Window.display();
				}
				else if (intro == 5 && sound1 == true && musical == false)
				{
					sound.setVolume(0);
					sound1 = false;
					Window.clear();
					Window.draw(Ground);
					Window.draw(text1);
					Window.draw(text2);
					Window.draw(text3);
					Window.draw(text4);
					mute.setColor(sf::Color(237, 251, 68));
					Window.draw(mute);
					Window.draw(play1);
					Window.display();
				}
				else if (intro == 6 && sound1 == true && musical == true)
				{
					sound2.setVolume(0);
					musical = false;
					Window.clear();
					Window.draw(Ground);
					play1.setColor(sf::Color(237, 251, 68));
					Window.draw(speaker);
					Window.draw(text1);
					Window.draw(text2);
					Window.draw(text3);
					Window.draw(text4);
					Window.draw(play1);
					Window.display();
				}
				else if (intro == 6 && sound1 == false && musical == true)
				{
					sound2.setVolume(0);
					musical = false;
					Window.clear();
					Window.draw(Ground);
					Window.draw(text1);
					Window.draw(text2);
					Window.draw(text3);
					Window.draw(text4);
					play1.setColor(sf::Color(237, 251, 68));
					Window.draw(mute);
					Window.draw(play1);
					Window.display();
				}
				else if (intro == 6 && sound1 == false && musical == false)
				{
					sound2.setVolume(100);
					musical = true;
					Window.clear();
					Window.draw(Ground);
					Window.draw(text1);
					Window.draw(text2);
					Window.draw(text3);
					Window.draw(text4);
					play2.setColor(sf::Color(237, 251, 68));
					Window.draw(mute);
					Window.draw(play2);
					Window.display();
				}
				else if (intro == 6 && sound1 == true && musical == false)
				{
					sound2.setVolume(100);
					musical = true;
					Window.clear();
					Window.draw(Ground);
					Window.draw(text1);
					Window.draw(text2);
					Window.draw(text3);
					Window.draw(text4);
					play2.setColor(sf::Color(237, 251, 68));
					Window.draw(speaker);
					Window.draw(play2);
					Window.display();
				}
			}
			//Second  menu New Game   page 2
			else if (Event.key.code == sf::Keyboard::Space&&pages == 2)
			{
				sound.play();
				if (page2 == 4)
				{
					pages--;

					if (pages == 1)
					{
						page2 = 1;
					}
					if (sound1 == true && musical == true)
					{

						Window.clear();
						Window.draw(Ground);
						Window.draw(speaker);
						Window.draw(text1);
						Window.draw(text2);
						Window.draw(text3);
						Window.draw(text4);
						Window.draw(play2);
						Window.display();
					}
					else if (sound1 == false && musical == true)
					{

						Window.clear();
						Window.draw(Ground);
						Window.draw(text1);
						Window.draw(text2);
						Window.draw(text3);
						Window.draw(text4);
						Window.draw(mute);
						Window.draw(play2);
						Window.display();
					}
					else if (sound1 == false && musical == false)
					{

						Window.clear();
						Window.draw(Ground);
						Window.draw(text1);
						Window.draw(text2);
						Window.draw(text3);
						Window.draw(text4);
						Window.draw(mute);
						Window.draw(play1);
						Window.display();
					}
					else if (sound1 == true && musical == false)
					{


						Window.clear();
						Window.draw(Ground);
						Window.draw(text1);
						Window.draw(text2);
						Window.draw(text3);
						Window.draw(text4);
						Window.draw(speaker);
						Window.draw(play1);
						Window.display();
					}
				}
				else if (page2 == 1)
				{
					//Easy  ....
					pages++;
					if (pages == 3)
					{
						pages = 3;
					}
					deleted_cells = 48;
					Window.clear();
					Window.draw(loading2);
					Window.draw(oneloading);
					Window.display();
					New_Game();
					mouseback = false;
				}
				else if (page2 == 2)
				{
					//MEDIUM....
					pages++;
					if (pages == 3)
					{
						pages = 3;
					}
					deleted_cells = 57;
					Window.clear();
					Window.draw(loading2);
					Window.draw(oneloading);
					Window.display();
					New_Game();
					mouseback = false;
				}
				else if (page2 == 3)
				{
					//Hard
					pages++;
					if (pages == 3)
					{
						pages = 3;
					}
					deleted_cells = 64;
					Window.clear();
					Window.draw(loading2);
					Window.draw(oneloading);
					Window.display();
					New_Game();
					mouseback = false;
				}
			}
			//BackSpace In Each Page . . .. . . .
			if (Event.key.code == sf::Keyboard::Escape)
			{
				pages--;
				sound.play();
				//Condition for pages to no not to get out of pages
				about--;
				//Condition for about to not to get out of the page
				if (about < 1)
				{
					about = 1;
				}
				if (pages < 1)
				{
					pages = 1;
				}

				if (pages == 1)
				{
					if (sound1 == true && musical == true)
					{
						Window.clear();
						Window.draw(Ground);
						Window.draw(speaker);
						Window.draw(text1);
						Window.draw(text2);
						Window.draw(text3);
						Window.draw(text4);
						Window.draw(play2);
						Window.display();
					}
					else if (sound1 == false && musical == true)
					{
						Window.clear();
						Window.draw(Ground);
						Window.draw(text1);
						Window.draw(text2);
						Window.draw(text3);
						Window.draw(text4);
						Window.draw(mute);
						Window.draw(play2);
						Window.display();
					}
					else if (sound1 == false && musical == false)
					{
						Window.clear();
						Window.draw(Ground);
						Window.draw(text1);
						Window.draw(text2);
						Window.draw(text3);
						Window.draw(text4);
						Window.draw(mute);
						Window.draw(play1);
						Window.display();
					}
					else if (sound1 == true && musical == false)
					{
						Window.clear();
						Window.draw(Ground);
						Window.draw(text1);
						Window.draw(text2);
						Window.draw(text3);
						Window.draw(text4);
						Window.draw(speaker);
						Window.draw(play1);
						Window.display();
					}
				}
				else if (pages == 2)
				{
					Window.clear();
					Window.draw(Ground);
					Window.draw(text5);
					Window.draw(text6);
					Window.draw(text7);
					Window.draw(Back);
					Window.display();
				}
			}
			else if (mouseback == false && pages == 2)
			{
				Window.clear();
				Window.draw(Ground);
				Window.draw(text5);
				Window.draw(text6);
				Window.draw(text7);
				Window.draw(Back);
				Window.display();
			}
			else if (mouseback == false && pages == 1)
			{
				if (sound1 == true && musical == true)
				{

					Window.clear();
					Window.draw(Ground);
					Window.draw(speaker);
					Window.draw(text1);
					Window.draw(text2);
					Window.draw(text3);
					Window.draw(text4);
					Window.draw(play2);
					Window.display();
				}
				else if (sound1 == false && musical == true)
				{

					Window.clear();
					Window.draw(Ground);
					Window.draw(text1);
					Window.draw(text2);
					Window.draw(text3);
					Window.draw(text4);
					Window.draw(mute);
					Window.draw(play2);
					Window.display();
				}
				else if (sound1 == false && musical == false)
				{

					Window.clear();
					Window.draw(Ground);
					Window.draw(text1);
					Window.draw(text2);
					Window.draw(text3);
					Window.draw(text4);
					Window.draw(mute);
					Window.draw(play1);
					Window.display();
				}
				else if (sound1 == true && musical == false)
				{


					Window.clear();
					Window.draw(Ground);
					Window.draw(text1);
					Window.draw(text2);
					Window.draw(text3);
					Window.draw(text4);
					Window.draw(speaker);
					Window.draw(play1);
					Window.display();
				}
				mouseback = true;
			}

		}
	}
	return 0;
}



void New_Game()
{

	// load Suduko Board Background
	//prepare to the Game....
	sf::Texture background;
	sf::Sprite backg;
	background.loadFromFile("Board_Background.PNG");
	backg.setTexture(background);

	number_of_checks.setString("CHECKS");
	number_of_checks.setFont(font);
	number_of_checks.setCharacterSize(32);
	number_of_checks.setPosition(630, 300);

	congratulations.loadFromFile("congratulations.JPG");
	con.setTexture(congratulations);

	string checks;
	if (deleted_cells == 48)
	{
		checks = "0 / 5";
	}
	else if (deleted_cells == 57)
	{
		checks = "0 / 3";
	}
	else
	{
		checks = "0 / 1";
	}

	allchecks.setString(checks);
	allchecks.setFont(font2);
	allchecks.setCharacterSize(30);
	allchecks.setPosition(633, 340);

	icon.loadFromFile("check-icon.png");
	Icon.setTexture(icon);
	Icon.setPosition(647, 115);

	sf::Text check("CHECK ANSWER", font, 32);
	check.setPosition(569, 63);
	check.setColor(sf::Color::White);

	wa2t.setString("TIME");
	wa2t.setCharacterSize(32);
	wa2t.setColor(sf::Color::White);
	wa2t.setPosition(643, 180);
	wa2t.setFont(font);

	notes.setString(" Press check to\n check your answer.");
	notes.setFont(font3);
	notes.setCharacterSize(25);
	notes.setPosition(565, 405);
	notes.setColor(sf::Color::White);


	TIME.setCharacterSize(30);
	TIME.setColor(sf::Color::White);
	TIME.setPosition(643, 220);
	TIME.setFont(font2);

	solve.setCharacterSize(30);
	solve.setFont(font);
	solve.setPosition(569, 63);
	solve.setColor(sf::Color::White);
	solve.setString("Solve");

	Time.loadFromFile("Time-icon.PNG");
	Timeicon.setTexture(Time);
	Timeicon.setPosition(590, 220);


	//Now processing....
	borad_maker(suduko_board, copy_of_suduko_board);
	if (deleted_cells != 64)
		empties(suduko_board, check_board, deleted_cells);
	else
		choose_hard(suduko_board, copy_of_suduko_board, check_board);
	board_swaping(suduko_board, copy_of_suduko_board, check_board);
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			green_red[i][j] = check_board[i][j];
		}
	}
	escape = true;
	mouseback = true;
	// Timer 
	char time_now[10];
	_strtime_s(time_now, 10);
	int sec = (((time_now[6] - 48) * 10) + (time_now[7] - 48));
	string s = "00:00";
	double n = 0, z = 0;

	// Start Play .......
	while (Window.isOpen())
	{
		while (Window.pollEvent(Event))
		{
			switch (Event.type)
			{

			case sf::Event::Closed:
				Window.close();
				break;

			case sf::Event::TextEntered:
				if (Event.text.unicode > 48 && Event.text.unicode < 58)
				{
					Window.draw(rect);
					suduko_board[xx + 1][yy + 1] = (char)Event.text.unicode;
					Print_Numbers_in_New_Game(suduko_board);
				}
				break;
			case sf::Event::MouseButtonPressed:
				if (Event.mouseButton.button == sf::Mouse::Left&&Event.mouseButton.x >= 646 && Event.mouseButton.x <= 695 && Event.mouseButton.y >= 113 && Event.mouseButton.y <= 163)
				{
					cout << deleted_cells << " " << checks[0] << endl;
					checks[0]++;
					if (deleted_cells == 48 && checks[0]<'6')
					{
						check_board_true_or_false(suduko_board, copy_of_suduko_board, green_red);
					}
					else if (deleted_cells == 48 && checks[0] == '6')
					{
						checks = "5 / 5";
					}
					if (deleted_cells == 57 && checks[0]<'4')
					{
						check_board_true_or_false(suduko_board, copy_of_suduko_board, green_red);
					}
					else if (deleted_cells == 57 && checks[0] == '4')
					{
						checks = "3 / 3";
					}

					if (deleted_cells == 64 && checks[0]<'2')
					{
						check_board_true_or_false(suduko_board, copy_of_suduko_board, green_red);
					}
					else if (deleted_cells == 64 && checks[0] == '2')
					{
						checks = "1 / 1";
					}

				}
				else if (Event.mouseButton.x >= 720 && Event.mouseButton.x <= 768 && Event.mouseButton.y >= 524 && Event.mouseButton.y <= 573 && Event.mouseButton.button == sf::Mouse::Left)
				{
					pages = 2;
					cout << "1\n";
					mouseback = false;

				}
				break;
			case sf::Event::KeyPressed:
				if (Event.key.code == sf::Keyboard::BackSpace)
				{
					suduko_board[xx + 1][yy + 1] = '0';
					green_red[xx + 1][yy + 1] = 0;
					Print_Numbers_in_New_Game(suduko_board);
				}
				else if (Event.key.code == sf::Keyboard::Escape)
				{
					cout << "2\n";
					escape = false;
				}
			}

		}



		if (!mouseback)
		{
			cout << "3\n";
			break;
		}

		if (Event.mouseMove.x >= 646 && Event.mouseMove.x <= 695)
		{
			if (Event.mouseMove.y >= 114 && Event.mouseMove.y <= 163)
			{
				Icon.setColor(sf::Color::Yellow);
			}
		}

		if (Event.mouseMove.x >= 720 && Event.mouseMove.x <= 768)
		{
			if (Event.mouseMove.y >= 524 && Event.mouseMove.y <= 573)
			{
				Back.setColor(sf::Color::Yellow);
			}
		}

		_strtime_s(time_now, 10);
		sec = (((time_now[6] - 48) * 10) + (time_now[7] - 48));
		n++;
		if (n == 1)
		{
			z = sec;
		}
		if (sec == 0)
		{
			z = 0;
		}
		if (sec - z == 1)
		{
			n = 0;
			s[4]++;
			if (s[4] > '9')
			{
				s[4] = '0';
				s[3]++;
			}
			if (s[3] == '6')
			{
				s[1]++;
				s[3] = '0';
			}
			if (s[1] > '9')
			{
				s[1] = '0';
				s[0]++;
			}
		}
		z = sec;
		if (check_board_true_or_false_for_end(suduko_board, copy_of_suduko_board) == 81)
		{
			check_board_true_or_false(suduko_board, copy_of_suduko_board, green_red);
			Window.clear();
			Window.draw(con);
			Window.display();
		}
		else
		{
			cout << "WHY\n";
			allchecks.setString(checks);
			TIME.setString(s);
			Window.draw(backg);
			Window.draw(check);
			Window.draw(rect);
			Window.draw(Icon);
			Window.draw(Timeicon);
			Window.draw(allchecks);
			Window.draw(TIME);
			Window.draw(wa2t);
			Window.draw(Back);
			Window.draw(notes);
			Print_Numbers_in_New_Game(suduko_board);
			Window.draw(number_of_checks);
			Icon.setColor(sf::Color::White);
			Back.setColor(sf::Color::White);
			Select_Number_in_New_Game(suduko_board);
			Window.display();
		}

		if (escape == false)
		{
			cout << "4\n";
			break;
		}
	}
}
void Print_Numbers_in_New_Game(char suduko_board[][10])
{
	sf::Font font;
	font.loadFromFile("Fourth_Font.ttf");
	y = 48;
	for (int i = 0; i < 9; i++)
	{
		x = 50;
		for (int j = 0; j < 9; j++)
		{
			if (suduko_board[i + 1][j + 1] != '0' && check_board[i + 1][j + 1] == 1 && green_red[i + 1][j + 1] == 1)
			{
				sf::Text text(suduko_board[i + 1][j + 1], font, 45);
				text.setColor(sf::Color::Black);
				text.setPosition(x + (j * 56), y + (i * 54));
				Window.draw(text);
			}
			else if (suduko_board[i + 1][j + 1] != '0' && check_board[i + 1][j + 1] == 0 && green_red[i + 1][j + 1] == 1)
			{
				sf::Text text(suduko_board[i + 1][j + 1], font, 45);
				text.setColor(sf::Color(0, 168, 0));
				text.setPosition(x + (j * 56), y + (i * 54));
				Window.draw(text);
			}
			else if (suduko_board[i + 1][j + 1] != '0' && check_board[i + 1][j + 1] == 0 && green_red[i + 1][j + 1] == 0)
			{
				sf::Text text(suduko_board[i + 1][j + 1], font, 45);
				text.setColor(sf::Color::Red);
				text.setPosition(x + (j * 56), y + (i * 54));
				Window.draw(text);
			}
			if (j == 2 || j == 5)
			{
				x += 6;
			}
		}
		if (i == 2 || i == 5)
		{
			y += 9;
		}
	}
}
void Select_Number_in_New_Game(char suduko_board[][10])
{
	float x1 = 42, x2 = 95, y1 = 52, y2 = 104;
	int c = 0;
	y = 48;
	for (int i = 0; i < 9; i++)
	{
		x1 = 42; x2 = 95;
		x = 50;
		if (i == 3 || i == 6)
		{
			y1 += 4;
			y2 += 4;
		}
		for (int j = 0; j < 9; j++)
		{
			if (j == 3 || j == 6)
			{
				x1 += 4;
				x2 += 4;
			}
			if (check_board[i + 1][j + 1] == 0 && green_red[i + 1][j + 1] == 0)
			{
				if (Event.mouseButton.x >= x1 + (j * 56) && Event.mouseButton.x <= x2 + (j * 56))
				{
					if (Event.mouseButton.y >= y1 + (i * 55) && Event.mouseButton.y <= y2 + (i * 55))
					{
						rect.setSize(sf::Vector2f(54, 53));
						rect.setFillColor(sf::Color(221, 221, 221, 221));
						rect.setPosition(x1 + (j * 56), y1 + (i * 55));
						xx = i; yy = j;
						Event.mouseButton.x = 0;
						Event.mouseButton.y = 0;
					}
				}

			}
			if (j == 2 || j == 5)
			{
				x += 6;
			}
		}
		if (i == 2 || i == 5)
		{
			y += 9;
		}
	}
}

void Custom_puzzle()
{
	// load Suduko Board Background
	//prepare to the Solver....
	sf::Font font;
	sf::Texture background;
	sf::Sprite backg;
	background.loadFromFile("Board_Background.PNG");
	backg.setTexture(background);

	sf::Font font2;
	font2.loadFromFile("Third_Font.ttf");


	sf::Texture icon;
	sf::Sprite Icon;
	icon.loadFromFile("check-icon.png");
	Icon.setTexture(icon);
	Icon.setPosition(650, 117);

	font.loadFromFile("Fifth_Font.ttf");

	sf::Text check("SOLVE", font2, 50);
	check.setPosition(600, 50);
	check.setColor(sf::Color::White);

	sf::Text Note;
	Note.setString("\n\n\n\n\nPress solve after \nentering your puzzle.");
	Note.setFont(font3);
	Note.setCharacterSize(25);
	Note.setPosition(558, 200);
	Note.setColor(sf::Color::White);

	sf::Texture ftexture;
	sf::Sprite Back;
	ftexture.loadFromFile("arrow-back.PNG");
	Back.setTexture(ftexture);
	Back.setPosition(720, 525);

	escape = true;
	for (int i = 0; i <= 8; i++)
	{
		for (int j = 0; j <= 8; j++)
		{
			suduko[i][j] = '0';
			check_board[i][j] = 0;
		}
	}

	bool s = 1;


	while (Window.isOpen())
	{


		mouseback = true;

		while (Window.pollEvent(Event))
		{

			switch (Event.type)
			{

			case sf::Event::Closed:
				Window.close();
				break;

			case sf::Event::TextEntered:
				if (Event.text.unicode > 48 && Event.text.unicode < 58)
				{
					Window.draw(rect);
					suduko[xx][yy] = (char)Event.text.unicode;
					Print_Numbers_in_Custom_Puzzle(suduko);
				}
				break;
			case sf::Event::MouseButtonPressed:
				if (Event.mouseButton.button == sf::Mouse::Left&&Event.mouseButton.x >= 646 && Event.mouseButton.x <= 695 && Event.mouseButton.y >= 113 && Event.mouseButton.y <= 163)
				{
					if (Check_if_Board_is_Valid(suduko))
					{

						for (int i = 0; i < 9; i++)
						{
							for (int j = 0; j < 9; j++)
							{
								if (suduko[i][j] != '0')
								{
									check_board[i][j] = 1;
								}
							}
						}
						grid_solver(suduko);
					}
				}
				else if (Event.mouseButton.x >= 720 && Event.mouseButton.x <= 768 && Event.mouseButton.y >= 524 && Event.mouseButton.y <= 573 && Event.mouseButton.button == sf::Mouse::Left)
				{
					pages = 1;
					mouseback = false;
				}
				break;
			case sf::Event::KeyPressed:
				if (Event.key.code == sf::Keyboard::BackSpace)
				{
					suduko[xx][yy] = '0';
					Print_Numbers_in_Custom_Puzzle(suduko);
				}
				else if (Event.key.code == sf::Keyboard::Escape)
				{
					escape = false;
				}
				break;

			}





		}


		if (Event.mouseMove.x >= 646 && Event.mouseMove.x <= 695)
		{
			if (Event.mouseMove.y >= 114 && Event.mouseMove.y <= 163)
			{
				Icon.setColor(sf::Color::Yellow);
			}
		}


		if (Event.mouseMove.x >= 720 && Event.mouseMove.x <= 768)
		{
			if (Event.mouseMove.y >= 524 && Event.mouseMove.y <= 573)
			{
				Back.setColor(sf::Color::Yellow);
			}
		}


		Window.draw(backg);
		Window.draw(check);
		Window.draw(rect);
		Window.draw(Icon);
		Window.draw(Back);
		Print_Numbers_in_Custom_Puzzle(suduko);
		Window.draw(Note);
		Icon.setColor(sf::Color::White);
		Back.setColor(sf::Color::White);
		Select_Number_in_Custom_Puzzle(suduko);
		Window.display();
		if (mouseback == false)
			break;
		if (escape == false)
		{
			break;
		}
	}
}
void Print_Numbers_in_Custom_Puzzle(char suduko_board[][9])
{
	sf::Font font;
	font.loadFromFile("Fourth_Font.ttf");
	y = 48;
	for (int i = 0; i < 9; i++)
	{
		x = 50;
		for (int j = 0; j < 9; j++)
		{
			if (suduko[i][j] != '0' && check_board[i][j] == 1)
			{
				sf::Text text(suduko[i][j], font, 45);
				text.setColor(sf::Color::Black);
				text.setPosition(x + (j * 56), y + (i * 54));
				Window.draw(text);
			}
			else if (suduko[i][j] != '0' && check_board[i][j] == 0)
			{
				sf::Text text(suduko[i][j], font, 45);
				text.setColor(sf::Color(0, 168, 0));
				text.setPosition(x + (j * 56), y + (i * 54));
				Window.draw(text);
			}

			if (j == 2 || j == 5)
			{
				x += 6;
			}
		}
		if (i == 2 || i == 5)
		{
			y += 9;
		}
	}
}
void Select_Number_in_Custom_Puzzle(char suduko[][9])
{
	float x1 = 42, x2 = 95, y1 = 52, y2 = 104;
	int c = 0;
	y = 48;
	for (int i = 0; i < 9; i++)
	{
		x1 = 42; x2 = 95;
		x = 50;
		if (i == 3 || i == 6)
		{
			y1 += 4;
			y2 += 4;
		}
		for (int j = 0; j < 9; j++)
		{
			if (j == 3 || j == 6)
			{
				x1 += 4;
				x2 += 4;
			}
			if (check_board[i][j] == 0)
			{
				if (Event.mouseButton.x >= x1 + (j * 56) && Event.mouseButton.x <= x2 + (j * 56))
				{
					if (Event.mouseButton.y >= y1 + (i * 55) && Event.mouseButton.y <= y2 + (i * 55))
					{
						rect.setSize(sf::Vector2f(54, 53));
						rect.setFillColor(sf::Color(221, 221, 221, 221));
						rect.setPosition(x1 + (j * 56), y1 + (i * 55));
						//Window.draw(rect);
						xx = i; yy = j;
						Event.mouseButton.x = 0;
						Event.mouseButton.y = 0;
					}
				}

			}
			if (j == 2 || j == 5)
			{
				x += 6;
			}
		}
		if (i == 2 || i == 5)
		{
			y += 9;
		}
	}
}