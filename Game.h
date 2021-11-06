#ifndef GAME_H
#define GAME_H

#include"Menu.h"

using namespace std;

class Game{
	private:
		RenderWindow window;
		Text text;
		Font font;
		int checkOptions = 0;
		string s;
		int i = 0;
	private:
		void processEvents();
		void update();
		void render();
	public:
		Game();
		void run();
		friend class Menu;
};
#endif
