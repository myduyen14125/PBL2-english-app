#ifndef GAME_H
#define GAME_H

#include "Menu.h"
#include "Play.h"
#include "About.h"
#include "View.h"
using namespace std;

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
