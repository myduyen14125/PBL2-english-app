#include"Game.h"

#define WIDTH 900
#define HEIGHT 900

#define HOVER true
#define NO_HOVER false 

Menu menu(WIDTH, HEIGHT);
About about(WIDTH, HEIGHT);
ViewDictionary view;
Game::Game() : window(VideoMode(WIDTH, HEIGHT), "SFML Application")
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
				if(checkOptions == 2)
				{
					keycode = event.key.code;
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
	else if(checkOptions==1){
		
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
	}
	else if(checkOptions == 2) {
		view.drawView(window);
	}
	else if(checkOptions == 6){
		about.drawAbout(window);
	}	
	window.display();
}


