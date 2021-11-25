#ifndef VIEW_H
#define VIEW_H

#include "Hashtable.h"

using namespace sf;
using namespace std;
#define MAX_NUMBER_OF_ITEMS 7
class ViewDictionary {
	protected:
		int indexRectangle = 0, countReadWord = 0;
		Font font[4];
		Texture backgroundView, image[MAX_NUMBER_OF_ITEMS], loa[MAX_NUMBER_OF_ITEMS], button, buttonHover, arrow, arrowHover;;
		Sprite spriteBackgroundView, spriteImage[MAX_NUMBER_OF_ITEMS], spriteLoa[MAX_NUMBER_OF_ITEMS], spriteArrow;
		Text head, searchWord, eng[MAX_NUMBER_OF_ITEMS], type[MAX_NUMBER_OF_ITEMS], meaning[MAX_NUMBER_OF_ITEMS];
		Clock clock;
		Time time;
		RectangleShape marker,  rectangle; // rectangle de noi bat dong chu dang tro den
		FloatRect rect;
		string inputSearch = "Search: ";
		string inputWord = "";
		string tempWord = "";
		const char keyboard[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n'
						, 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	public:
		ViewDictionary();
		~ViewDictionary();
		
		void loadFont();
		void loadTexture();
		void setSprite();
		void loadResource();
		
		int handleView(RenderWindow &window, int keypress, bool isKeyPressed);
		void drawView(RenderWindow &window);		
};
#endif
