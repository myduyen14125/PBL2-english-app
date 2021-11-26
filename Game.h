#ifndef GAME_H
#define GAME_H

#include "Menu.h"
#include "Play.h"
#include "About.h"
#include "View.h"
#include "Edit.h"
using namespace std;
//int i = 0;
//string s;
//Text text;
//text.setFont(font[2]);
//text.setFillColor(Color::Red);
//text.setPosition(window.getSize().x/2-200, window.getSize().y/2-50);
//text.setCharacterSize(50);
//if(i<=100){
//	s = "Loading game: " + to_string(i);
//	s += " %";
//	text.setString(s);
//}
//if(i<=100){ // render
//	window.draw(text);
//	window.display();
//	if(i==100)	Sleep(900);
//	else Sleep(30);
//	i++;
//}
const int WIDTH  = 900;
const int HEIGHT = 900;
class Game{
	private:
		RenderWindow window;
		int checkOptions = 0;
		int keycode;
		bool isKeyPressed;
		
		Menu menu;
		Play play;
		About about;
		ViewDictionary view;
		
	private:
		void processEvents();
		void update();
		void render();
		
	public:
		Game();
		void run();

};
#endif
