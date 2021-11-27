#include"Game.h"


#define HOVER true
#define NO_HOVER false 


Game::Game() : window(VideoMode(WIDTH, HEIGHT), "Hoc tu vung tieng anh")
{

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
				if(checkOptions == 1) {
					isKeyPressed = true;
					checkOptions = play.handlePlay(window, keycode, isKeyPressed);
				}
				if(checkOptions == 2) {
					isKeyPressed = true;
					checkOptions = view.handleView(window, keycode, isKeyPressed);
				}	
				break;
			case Event::KeyReleased:
				isKeyPressed = false;
				break;
				
		}
	}
}
void Game::update() {
	if(checkOptions == 0) 		checkOptions = menu.handleMenu(window);
	else if(checkOptions == 1){
		checkOptions = play.handlePlay(window, keycode, false);
	}
	else if(checkOptions == 2) {
		checkOptions = view.handleView(window, keycode, false);
	}
	else if(checkOptions == 6) {
		checkOptions = about.handleAbout(window);
	}
}
void Game::render() {
	window.clear();
	if(checkOptions == 0){
		menu.drawMenu(window);
	}
	else if(checkOptions == 1)
	{
		play.draw(window);
	}
	else if(checkOptions == 2) {
		view.drawView(window);
	}
	else if(checkOptions == 3) {
		checkOptions = 0;
	}
	else if(checkOptions == 4) {
		checkOptions = 0;
	}
	else if(checkOptions == 5) {
		checkOptions = 0;
	}
	else if(checkOptions == 6){
		about.drawAbout(window);
	}	
	window.display();
}


