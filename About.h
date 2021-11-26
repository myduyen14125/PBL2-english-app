#ifndef ABOUT_H
#define ABOUT_H

#include "library.h"


class About {
	private:
		Font font[4];
		Text about[MAX_NUMBER_OF_ITEMS];
		Texture backgroundAbout, logo, arrow, arrowHover;
		Sprite spriteBackgroundAbout, spriteLogo, spriteArrow;
	public:
		About();
		~About();
		
		void loadFont();
		void loadTexture();
		void setSprite();
		void loadResource();
		
		int handleAbout(RenderWindow &window);
		void drawAbout(RenderWindow &window);
};
#endif
