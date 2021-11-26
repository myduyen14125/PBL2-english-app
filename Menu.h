#ifndef MENU_H
#define MENU_H

#include "library.h"

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
		
		void loadFont();
		void loadTexture();
		void setSprite();
		void loadResource();
		
		int handleMenu(RenderWindow &window);
		void drawMenu(RenderWindow &window);
};
#endif
