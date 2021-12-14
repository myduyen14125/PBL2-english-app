#include"Game.h"


#define HOVER true
#define NO_HOVER false 

Game::Game(): window(VideoMode(WIDTH, HEIGHT), " Ung dung hoc Tu Vung Tieng Anh") {
}

Game::~Game() {
}

void Game::run() {
	while(window.isOpen()) {
		processEvents();
		update();
		render();
	}
}

void Game::processEvents() {
	Event event;
	while(window.pollEvent(event)) {
		switch (event.type)
		{
			case Event::Closed:
				window.close();
				break;
			case Event::KeyPressed:
				keycode = event.key.code;
				if(checkOptions == 1) 		checkOptions = play.handle(window, keycode, true, table, score);
				else if(checkOptions == 2) 	checkOptions = view.handle(window, keycode, true, table);
				else if(checkOptions == 3) 	checkOptions = edit.handle(window, keycode, true, table);
				break;
		}
	}
}

void Game::update() {
	if(checkOptions == 0) 		checkOptions = menu.handle(window);
	else if(checkOptions == 1)	checkOptions = play.handle(window, keycode, false, table, score);
	else if(checkOptions == 2)	checkOptions = view.handle(window, keycode, false, table);
	else if(checkOptions == 3)	checkOptions = edit.handle(window, keycode, false, table);
	else if(checkOptions == 4)	checkOptions = score.handle(window);
	else if(checkOptions == 5)	checkOptions = instruction.handle(window);
	else if(checkOptions == 6)	checkOptions = about.handle(window);
}

void Game::render() {
	window.clear();
	if(checkOptions == 0)		menu.draw(window);
	else if(checkOptions == 1) 	play.draw(window);	
	else if(checkOptions == 2) 	view.draw(window);
	else if(checkOptions == 3) 	edit.draw(window);
	else if(checkOptions == 4) 	score.draw(window);
	else if(checkOptions == 5) 	instruction.draw(window);
	else if(checkOptions == 6) 	about.draw(window);
	window.display();
}

int main() {
	Game game;
	game.run();
	return 0;
}

