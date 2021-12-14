#include "Base.h"

Base::Base() {
	if(initial == 0) {
		loadResource();
	}
	else initial = 1;
}
Base::~Base() {
	
}
void Base::loadResource() {
	font[0].loadFromFile("Resource/Font/BungeeShade.ttf");
	font[1].loadFromFile("Resource/Font/MATURASC.ttf");
	font[2].loadFromFile("Resource/Font/timesbd.ttf");
	font[3].loadFromFile("Resource/Font/ALGER.ttf");
	font[4].loadFromFile("Resource/Font/TiengAnh.ttf");
	
	button.loadFromFile("Resource/Image/Button.jpg");
	buttonHover.loadFromFile("Resource/Image/ButtonHover.jpg");
	arrow.loadFromFile("Resource/Image/muiten.png");
	arrowHover.loadFromFile("Resource/Image/muitenhover.png");
	speak.loadFromFile("Resource/Image/loa.png");
	speakHover.loadFromFile("Resource/Image/LoaHover.png");
	
	spriteArrow.setTexture(arrow);
	spriteButton.setTexture(button);
	spriteSpeak.setTexture(speak);
	
	spriteArrow.setScale(0.1,0.1);
	spriteArrow.setPosition(5,5);
}
