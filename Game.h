#ifndef GAME_H
#define GAME_H

#include "Base.h"
#include "Menu.h"
#include "Play.h"
#include "View.h"
#include "Edit.h"
#include "Score.h"
#include "Instruction.h"
#include "About.h"
#include "HashTable.h"

class Game: public Base {
	private:
		RenderWindow window;
		int checkOptions = 0;
		int keycode;
		HashTable table;
		Menu menu;
		Play play;
		ViewDictionary view;
		Edit edit;
		Score score;
		Instruction instruction;
		About about;

	private:
		void processEvents();
		void update();
		void render();
		
		int handle(RenderWindow& window) {}
		void draw(RenderWindow& window) {}
	public:
		Game();
		~Game();
		void run();

};
#endif
