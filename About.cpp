#include "About.h"

#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
#include<windows.h>
#include<string.h>

const int WIDTH  = 900;
const int HEIGHT = 900;
void About::loadFont() {
	font[0].loadFromFile("Resource/Font/BungeeShade.ttf");
	font[1].loadFromFile("Resource/Font/MATURASC.ttf");
	font[2].loadFromFile("Resource/Font/timesbd.ttf");
	font[3].loadFromFile("Resource/Font/ALGER.ttf");
}

void About::loadTexture() {
	backgroundAbout.loadFromFile("Resource/Image/backgroundAbout.jpg");
	logo.loadFromFile("Resource/Image/logo.png");
	arrow.loadFromFile("Resource/Image/muiten.png");
	arrowHover.loadFromFile("Resource/Image/muitenhover.png");
}

void About::setSprite() {
	spriteBackgroundAbout.setTexture(backgroundAbout);
	spriteBackgroundAbout.setScale(1.6,1.2);
	
	spriteLogo.setTexture(logo);
	spriteLogo.setScale(0.2,0.2);
	spriteLogo.setPosition(350, 220);
	
	spriteArrow.setTexture(arrow);
	spriteArrow.setScale(0.1,0.1);
	spriteArrow.setPosition(5,5);
}

void About::loadResource(){
	loadFont();
	loadTexture();
	setSprite();
}

About::About() {
	loadResource();
	// About
	about[0].setString("TRUONG DAI HOC BACH KHOA");
	about[1].setString("KHOA CONG NGHE THONG TIN");
	about[2].setString("DE TAI: UNG DUNG HOC TU VUNG TIENG ANH");
	about[3].setString("Sinh vien thuc hien:");
	about[4].setString("NGUYEN TRAN MY DUYEN  - 102200017");
	about[5].setString("NGUYEN PHUOC DAI TOAN - 102200035");
	about[6].setString("Giang vien huong dan: LE THI MY HANH");
	
	about[0].setFont(font[3]); // font[3]
	about[0].setFillColor(Color::Black);
	about[0].setCharacterSize(50);
	about[0].setPosition(Vector2f(WIDTH/2-340, HEIGHT/7-50));
	FloatRect rect;
	for(int i=1;i<=6;i++){
		about[i].setFont(font[2]); // font[2]
		about[i].setCharacterSize(35);
		about[i].setFillColor(Color::Black);
		rect = about[i].getLocalBounds();
		about[i].setOrigin(rect.width/2, rect.height/2);
		if(i==1){
			about[i].setPosition(Vector2f(WIDTH/2, 170));
		}
		else{
			about[i].setPosition(Vector2f(WIDTH/2, 270+85*i));
		}
	}
}

About::~About() {
	
}

int About::handleAbout(RenderWindow &window) {
	if(Mouse::getPosition(window).x<=77 && Mouse::getPosition(window).y<=55)
	{
		spriteArrow.setTexture(arrowHover);
		if(Mouse::isButtonPressed(Mouse::Left))
		{
			return 0;
			spriteArrow.setTexture(arrow);
		}
	}
	else{
		spriteArrow.setTexture(arrow);
	}
	return 6;
}

void About::drawAbout(RenderWindow &window) {
	window.draw(spriteBackgroundAbout);
	window.draw(spriteLogo);
	window.draw(spriteArrow);
    int R, G, B;
    srand(time(NULL));
	for(int i=0;i<7;i++){
		if(i==4 || i==5){
			R = rand() % 255;
	    	G = rand() % 255;
	   		B = rand() % 255;
	   		about[i].setFillColor(Color ( R, G, B ));
		}
		window.draw(about[i]);
	}
}

