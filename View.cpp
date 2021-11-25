#include "View.h"

HashTable hashtable;
void ViewDictionary::loadFont() {
	font[0].loadFromFile("Resource/Font/BungeeShade.ttf");
	font[1].loadFromFile("Resource/Font/MATURASC.ttf");
	font[2].loadFromFile("Resource/Font/timesbd.ttf");
	font[3].loadFromFile("Resource/Font/ALGER.ttf");
}
void ViewDictionary::loadTexture() {
	backgroundView.loadFromFile("Resource/Image/backgroundView.jpg");
	button.loadFromFile("Resource/Image/Button.jpg");
	buttonHover.loadFromFile("Resource/Image/ButtonHover.jpg");
	arrow.loadFromFile("Resource/Image/muiten.png");
	arrowHover.loadFromFile("Resource/Image/muitenhover.png");
	for(int i = 0; i <= 6; i++) 	loa[i].loadFromFile("Resource/Image/loa.png");
	
}
void ViewDictionary::setSprite() {
	spriteBackgroundView.setTexture(backgroundView);
	spriteBackgroundView.setScale(1.25, 1);
	
	for(int i = 0; i <= 6; i++) {
		spriteLoa[i].setTexture(loa[i]);
		spriteLoa[i].setScale(0.1 , 0.1);
		spriteLoa[i].setPosition(720, 100*(i+1) + 100);
		spriteLoa[i].setScale(0.018, 0.018);
	}
	
	spriteArrow.setTexture(arrow);
	spriteArrow.setScale(0.1,0.1);
	spriteArrow.setPosition(5,5);
}
void ViewDictionary::loadResource() {
	loadFont();
	loadTexture();
	setSprite();
}
ViewDictionary::ViewDictionary() {
	loadResource();
	// Head
	head.setFont(font[3]);
	head.setString("VIEW DICTIONARY");
	head.setPosition(270, 10);
	head.setCharacterSize(50);
	head.setFillColor(Color::Red);
	
	// Search
	searchWord.setString(inputSearch);
	searchWord.setFont(font[2]);
	searchWord.setFillColor(Color::Red);
	searchWord.setPosition(200,100);
	searchWord.setCharacterSize(35);
	
	// Rectangle
	rectangle.setSize(Vector2f(750.f, 80.f));
	rectangle.setFillColor(Color(220,220,220));
	
	// marker
	marker.setSize(Vector2f(15.f, 5.f));
	marker.setPosition(320, 133);
	marker.setFillColor(Color::Black);
	
	for(int i = 0; i <= 6; i++) {
		eng[i].setCharacterSize(30);
		eng[i].setFont(font[2]);
		eng[i].setFillColor(Color::Black);
		eng[i].setPosition(50, 100*(i+2));
		type[i].setCharacterSize(30);
		type[i].setFont(font[2]);
		type[i].setFillColor(Color::Black);
		type[i].setPosition(320, 100*(i+2));
		meaning[i].setCharacterSize(30);
		meaning[i].setFont(font[2]);
		meaning[i].setFillColor(Color::Black);
		meaning[i].setPosition(500, 100*(i+2));
	}
}
ViewDictionary::~ViewDictionary() {
	
}
int ViewDictionary::handleView(RenderWindow &window, int keypressed, bool isKeyPressed) {
	if(tempWord == "")		hashtable.searchTable(tempWord, eng, type, meaning, countReadWord);
	for(int i = 0; i < 7; i++) {
		image[i].loadFromFile("Resource/ImageWord/" + eng[i].getString() + ".jpg");
		spriteImage[i].setTexture(image[i]);
		spriteImage[i].setScale(0.2 , 0.2);
		spriteImage[i].setPosition(780, 100*(i+1) + 80);
	}
	if(isKeyPressed) {
		if(keypressed == Keyboard::Up) {
			if(indexRectangle != 0) indexRectangle--;
			else {
				tempWord = hashtable.leftWord(eng[0].getString());
				if(tempWord != "") {
					hashtable.searchTable(tempWord, eng, type, meaning, countReadWord);
				}
			}
		}
		else if(keypressed == Keyboard::Down) {
			if(indexRectangle < countReadWord-1) {
				indexRectangle++;
			}
			else {
				tempWord = hashtable.rightWord(eng[0].getString());
				if(tempWord != "zzz" && countReadWord == 7) {
					hashtable.searchTable(tempWord, eng, type, meaning, countReadWord);
				}
			}
		}
		else if(keypressed >= Keyboard::A && keypressed <= Keyboard::Z) {
			inputWord += keyboard[keypressed];
			inputSearch += keyboard[keypressed];
			searchWord.setString(inputSearch);
			rect = searchWord.getLocalBounds();
			marker.setPosition(searchWord.getPosition().x + rect.width + 3, 133);
			hashtable.searchTable(inputWord, eng, type, meaning, countReadWord);
			tempWord = inputWord;
		}
		else if(keypressed == Keyboard::BackSpace) {
			if(inputSearch.length() > 8) {
				inputWord.pop_back();
				inputSearch.pop_back();
				searchWord.setString(inputSearch);
				rect = searchWord.getLocalBounds();
				marker.setPosition(searchWord.getPosition().x + rect.width + 3, 133);
				hashtable.searchTable(inputWord, eng, type, meaning, countReadWord);
				tempWord = inputWord;
			}	
		}
	}
	rectangle.setPosition(eng[indexRectangle].getPosition().x-10, eng[indexRectangle].getPosition().y-20);
    
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
	return 2;
}
void ViewDictionary::drawView(RenderWindow &window) {
	window.draw(spriteBackgroundView);
	window.draw(spriteArrow);
    window.draw(rectangle);
    window.draw(head);
    window.draw(searchWord);
    time = clock.getElapsedTime();
	if(time.asSeconds() > 0.5) {
		window.draw(marker);
	}
	if(time.asSeconds() > 1) {
		clock.restart();
	}	
    for(int i=0; i< countReadWord; i++) {
        if(i == indexRectangle) {
        	eng[i].setFillColor(Color::Black);
       		type[i].setFillColor(Color::Black);
        	meaning[i].setFillColor(Color::Black);
		}
		else {
			eng[i].setFillColor(Color::Black);
        	type[i].setFillColor(Color::Black);
        	meaning[i].setFillColor(Color::Black);
		}
       	window.draw(eng[i]);
       	window.draw(type[i]);
        window.draw(meaning[i]);
        window.draw(spriteLoa[i]);
	    window.draw(spriteImage[i]);
	}
}

