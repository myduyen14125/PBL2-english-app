#ifndef ABOUT_H
#define ABOUT_H

#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<windows.h>

using namespace sf;

#define MAX_NUMBER_OF_ITEMS 7

class About {
	private:
		Font font[4];
		Text about[MAX_NUMBER_OF_ITEMS];
		Texture backgroundAbout, logo, arrow, arrowHover;
		Sprite spriteBackgroundAbout, spriteLogo, spriteArrow;
	public:
		About();
		About(const float &WIDTH, const float &HEIGHT);
		~About();
		
		void loadFont();
		void loadTexture();
		void setSprite();
		void loadResource();
		
		int handleAbout(RenderWindow &window);
		void drawAbout(RenderWindow &window);
};
#endif
