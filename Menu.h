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
class Menu {
	private:
		Font font[4];
		Text menu[MAX_NUMBER_OF_ITEMS];
		
		Texture background, button, buttonHover, aboutImage, aboutImageHover;
		Sprite spriteBackground, spriteAbout;
		RectangleShape rectangle[MAX_NUMBER_OF_ITEMS];
		
	public:
		Menu();
		~Menu();
		Menu(const float &WIDTH, const float &HEIGHT);
		
		void loadFont();
		void loadTexture();
		void setSprite();
		void loadResource();
		
		int handleMenu(RenderWindow &window);
		void drawMenu(RenderWindow &window);
};
#endif
