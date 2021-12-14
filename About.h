#ifndef ABOUT_H
#define ABOUT_H

#include "Base.h"

class About: public Base {
	private:
		Text about[MAX_ITEMS];
		Texture logo;
		Sprite spriteLogo;
		
	public:
		About();
		~About();
		
		void loadResource();
		int handle(RenderWindow& window);
		void draw(RenderWindow& window);
};
#endif
