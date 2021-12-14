#ifndef MENU_H
#define MENU_H

#include "Base.h"

class Menu: public Base {
	private:
		Text menu[MAX_ITEMS];
		Texture aboutImage, aboutImageHover;
		Sprite spriteAbout;
		RectangleShape rectangle[MAX_ITEMS];
	public:
		Menu();
		~Menu();
		void loadResource();
		int handle(RenderWindow& window);
		void draw(RenderWindow& window);
};
#endif
