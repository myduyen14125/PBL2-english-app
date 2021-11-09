#include<windows.h>

#include"Game.h"

using namespace std;
using namespace sf;

#define width 900
#define height 900
Menu menu(width, height, Color::Black);

Game::Game() : window(VideoMode(width, height), "SFML Application")
{
	if(!font.loadFromFile("Font/timesbd.ttf")){
		// handle error
	}
	text.setFont(font);
	text.setFillColor(Color::Red);
	text.setPosition(window.getSize().x/2-200, window.getSize().y/2-50);
	text.setCharacterSize(50);
}
void Game::run()
{
	while(window.isOpen()) {
		processEvents();
		update();
		render();
	}
}

void Game::processEvents()
{
	Event event;
	while(window.pollEvent(event)) {
	
		switch (event.type)
		{
			case Event::Closed:
				window.close();
				break;
		}
	}
	if(checkOptions == 0){
		for(int i=1;i<=5;i++){
			if(menu.rectangle[i].getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y)){
				menu.rectangle[i].setTexture(&menu.buttonHover);
				menu.menu[i].setFillColor(Color::White);
				if(Mouse::isButtonPressed(Mouse::Left)){
					checkOptions = i;
					break;
				}
			}
			else{
				menu.rectangle[i].setTexture(&menu.button);
				menu.menu[i].setFillColor(Color::Black);
			}
		}
		if(45<=Mouse::getPosition(window).x && Mouse::getPosition(window).x<=266
			&& 660<=Mouse::getPosition(window).y && Mouse::getPosition(window).y<=753)
		{
			if(Mouse::isButtonPressed(Mouse::Left))
			{
				checkOptions = 6;
			}
			menu.aboutImage.loadFromFile("Image/BangGoHover.png");
			menu.spriteAbout.setTexture(menu.aboutImage);
			menu.menu[6].setFillColor(Color::White);
		}
		else{
			menu.aboutImage.loadFromFile("Image/BangGo.png");
			menu.spriteAbout.setTexture(menu.aboutImage);
			menu.menu[6].setFillColor(Color::Black);
		}
	}
	else if(checkOptions==6){
		menu.music.pause();
		if(Mouse::getPosition(window).x<=77 && Mouse::getPosition(window).y<=55)
		{
			menu.spriteArrow.setTexture(menu.arrowHover);
			if(Mouse::isButtonPressed(Mouse::Left))
			{
				checkOptions = 0;
				menu.spriteArrow.setTexture(menu.arrow);
				menu.music.play();
			}
		}
		else{
			menu.spriteArrow.setTexture(menu.arrow);
		}
	}
}
void Game::update()
{
	if(checkOptions==1){
		menu.music.pause();
		if(i<=100){
			s = "Loading game: " + to_string(i);
			s += " %";
			text.setString(s);
		}
		else{
			i = 0;
			checkOptions = 0;
			menu.music.play();
		}
	}
	else if(checkOptions==6) checkOptions=6;
	else checkOptions = 0;
}
void Game::render()
{
	window.clear();
	if(checkOptions==1)
	{
		if(i<=100){
			window.draw(text);
			window.display();
			if(i==100)	Sleep(900);
			else Sleep(30);
			i++;
		}
	}
	else if(checkOptions==6){
		menu.drawAbout(window);
	}	
	else if(checkOptions == 0){
		menu.draw(window);
	}
	window.display();
}

