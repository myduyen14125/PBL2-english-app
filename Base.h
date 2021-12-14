#ifndef BASE_H
#define BASE_H

#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<windows.h>
#include<iostream>
#include<string.h>
#include "HashTable.h"
using namespace std;
using namespace sf;

#define MAX_ITEMS 7
const int WIDTH  = 900;
const int HEIGHT = 900;
class Base {
	protected:
		int initial = 0;
		Font font[5];
		const char keyboard[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n'
						, 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
		Texture background;
		Texture arrow, arrowHover, button, buttonHover, speak, speakHover;
		Sprite spriteBackground, spriteArrow, spriteButton, spriteSpeak;
		
		FloatRect rect;
	public:
		Base();
		~Base();
		virtual int handle(RenderWindow& window) = 0;
		virtual void draw(RenderWindow& window) = 0;
		void loadResource();
};
#endif
