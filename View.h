#ifndef VIEW_H
#define VIEW_H

#include "Base.h"
#include "HashTable.h"
class ViewDictionary: public Base {
	private:
		int positionWord;
		int countReadWord;
		int initial;
		string search = "Search: ";
		string inputWord = "";
		
		WordEng word[MAX_ITEMS];
		WordEng firstWordCurrent, endWordCurrent;
		Sprite spriteImageWords[MAX_ITEMS], spriteSpeaks[MAX_ITEMS];
		Text eng[MAX_ITEMS], type[MAX_ITEMS], meaning[MAX_ITEMS];
		Text title, searchText;
		RectangleShape marker, rectangle;
		Clock clock;
		Time time;
	public:
		ViewDictionary();
		~ViewDictionary();
		void loadResource();
		WordEng getWord();
		WordEng getFirstWordCurrent();
		void setFirstWordCurrent(HashTable &table);
		void setTitle(string s);
		int handle(RenderWindow& window){}
		int handle(RenderWindow& window, int keypressed, bool isKeyPressed, HashTable& table);
		void draw(RenderWindow& window);
};

#endif
