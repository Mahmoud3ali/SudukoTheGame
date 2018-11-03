#include <SFML/Graphics.hpp>
#include<SFML\Audio.hpp>
#include<string>
#include <iostream>


sf::RenderWindow Window;

sf::Event Event;

sf::Font font;
sf::Font font2;
sf::Font font3;

sf::Text wa2t;
sf::Text notes;
sf::Text TIME;
sf::Text solve;
sf::Text allchecks;
sf::Text number_of_checks;
sf::Text oneloading;
sf::Text check;
sf::Text text1;
sf::Text text2;
sf::Text text3;
sf::Text text4;
sf::Text text5;
sf::Text text6;
sf::Text text7;
sf::Text About;

sf::Texture Time;
sf::Sprite Timeicon;
sf::Texture loading;
sf::Sprite load;
sf::Texture load2;
sf::Sprite loading2;
sf::Texture play;
sf::Sprite play1;
sf::Texture background;
sf::Sprite bacg;
sf::Texture icon;
sf::Sprite Icon;
sf::Texture sTexture;
sf::Sprite Ground;
sf::Texture ftexture;
sf::Sprite Back;
sf::Texture mTexture;
sf::Sprite mute;
sf::Texture rTexture;
sf::Sprite speaker;
sf::Texture playa;
sf::Sprite play2;
sf::Texture congratulations;
sf::Sprite con;

sf::Sound sound2;
sf::SoundBuffer soundbuffer2;
sf::Sound sound;
sf::SoundBuffer soundbuffer;


sf::RectangleShape rect;


//counter for each page
int about = 1;

//counter for 4 strings in page one
int intro = 1;

int  xx = 0, yy = 0, pages = 1, page2 = 1;

bool mouseback = true, musical = true, escape = true, sound1 = true;
float x, y;
void New_Game();
void Select_Number_in_New_Game(char suduko_board[][10]);
void Print_Numbers_in_New_Game(char suduko_board[][10]);
void Print_Numbers_in_Custom_Puzzle(char suduko_board[][9]);
void Select_Number_in_Custom_Puzzle(char suduko_board[][9]);
void Custom_puzzle();