//#include <random>
//#include <cstdlib>
#include"Menu.h"

using namespace std;

void Menu::loadFont() {
	font[0].loadFromFile("Resource/Font/BungeeShade.ttf");
	font[1].loadFromFile("Resource/Font/MATURASC.ttf");
	font[2].loadFromFile("Resource/Font/timesbd.ttf");
	font[3].loadFromFile("Resource/Font/ALGER.ttf");
}
void Menu::loadTexture() {
	background.loadFromFile("Resource/Image/backgroundMenu.jpg");
	button.loadFromFile("Resource/Image/Button.jpg");
	buttonHover.loadFromFile("Resource/Image/ButtonHover.jpg");
	aboutImage.loadFromFile("Resource/Image/BangGo.png");
	aboutImageHover.loadFromFile("Resource/Image/BangGoHover.png");
}
void Menu::setSprite() {
	spriteBackground.setTexture(background);
	spriteBackground.setScale(1.25,1);
	
	spriteAbout.setTexture(aboutImage);
	spriteAbout.setScale(0.25,0.25);
	spriteAbout.setPosition(0, 600);
}

void Menu::loadResource(){
	loadFont();
	loadTexture();
	setSprite();
}
Menu::Menu(const float &WIDTH, const float &HEIGHT){
	loadResource();
	// Menu Game
	menu[0].setString("ToD English Game !");
	menu[0].setFont(font[0]);
	menu[0].setFillColor(Color::Black);
	menu[0].setCharacterSize(60);
	menu[0].setPosition(Vector2f(WIDTH/2-350, HEIGHT/7-50));
	
	menu[1].setString("Play");
	menu[2].setString("View dictionary");
	menu[3].setString("Edit dictionary");
	menu[4].setString("Score");
	menu[5].setString("How to play?");
	menu[6].setString("About");
	menu[6].setPosition(90, 675);
	
	FloatRect rect;
	for(int i=1;i<7;i++){
		menu[i].setFont(font[1]);
		menu[i].setCharacterSize(40);
		menu[i].setFillColor(Color::Black);
		
		if(i != 6){
			rect = menu[i].getLocalBounds();
			menu[i].setOrigin(rect.width/2, rect.height/2);
			menu[i].setPosition(Vector2f(WIDTH/2, 150 + 90*i));
			
			rectangle[i].setSize(Vector2f(350.f, 60.f));
			rectangle[i].setTexture(&button);
			rectangle[i].setPosition(Vector2f(menu[i].getPosition().x-175, menu[i].getPosition().y-20));
		}
	}
}
Menu::~Menu(){
	
}

int Menu::handleMenu(RenderWindow &window) {
	for(int i=1;i<=5;i++){
		if(rectangle[i].getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y)){
			rectangle[i].setTexture(&buttonHover);
			menu[i].setFillColor(Color::White);
			if(Mouse::isButtonPressed(Mouse::Left)) {
				return i;
			}
		}
		else{
			rectangle[i].setTexture(&button);
			menu[i].setFillColor(Color::Black);
		}
	}
	if(45<=Mouse::getPosition(window).x && Mouse::getPosition(window).x<=266
		&& 660<=Mouse::getPosition(window).y && Mouse::getPosition(window).y<=753)
	{
		if(Mouse::isButtonPressed(Mouse::Left)) {
			return 6;
		}
		spriteAbout.setTexture(aboutImageHover);
		menu[6].setFillColor(Color::White);
	}
	else{
		spriteAbout.setTexture(aboutImage);
		menu[6].setFillColor(Color::Black);
	}
	return 0;
}
void Menu::drawMenu(RenderWindow &window){
	window.draw(spriteBackground);
    for(int i=0;i<6;i++){
    	window.draw(rectangle[i]);
		window.draw(menu[i]);
	}
	window.draw(spriteAbout);
	window.draw(menu[6]);
}

