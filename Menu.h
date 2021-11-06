#ifndef MENU_H
#define MENU_H

#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<windows.h>
#include<iostream>
#include<string>

#define MAX_NUMBER_OF_ITEMS 7

using namespace sf;
class Menu{
	private:
		Font font[4];
		Text about[MAX_NUMBER_OF_ITEMS];
		Texture background, backgroundAbout, logo;
		Sprite spriteBackground, spriteBackgroundAbout, spriteLogo;
	public:
		Music music;
		Text menu[MAX_NUMBER_OF_ITEMS];
		RectangleShape rectangle[MAX_NUMBER_OF_ITEMS];
		Texture button, buttonHover, aboutImage, arrow, arrowHover;
		Sprite spriteAbout, spriteArrow;
	public:
		Menu(){}
		Menu(float width, float height, Color color);
		void loadResource();
		~Menu();
		void draw(RenderWindow &window);
		void drawAbout(RenderWindow &window);
};
#endif
