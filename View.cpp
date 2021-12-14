#include "View.h"

void ViewDictionary::loadResource() {
	background.loadFromFile("Resource/Image/backgroundView.jpg");
	spriteBackground.setTexture(background);
	
	for(int i = 0; i < MAX_ITEMS; i++) {
		spriteSpeaks[i].setTexture(speak);
		spriteSpeaks[i].setScale(0.1, 0.1);
		spriteSpeaks[i].setPosition(720, 100 * (i+1) + 100);
		spriteSpeaks[i].setScale(0.018, 0.018);
	}
	
	// Rectangle
	rectangle.setSize(Vector2f(750.f, 80.f));
	rectangle.setFillColor(Color(220,220,220));
	
	// marker
	marker.setSize(Vector2f(15.f, 5.f));
	marker.setPosition(320, 133);
	marker.setFillColor(Color::Black);
}
ViewDictionary::ViewDictionary() {
	loadResource();
	
	title.setFont(font[3]);
	title.setString("VIEW DICTIONARY");
	title.setCharacterSize(50);
	title.setPosition(450, 30);
	rect = title.getLocalBounds();
	title.setOrigin(rect.width/2, rect.height/2);
	title.setFillColor(Color::Red);
	
	searchText.setString(search);
	searchText.setFont(font[2]);
	searchText.setFillColor(Color::Red);
	searchText.setPosition(200,100);
	searchText.setCharacterSize(35);
	
	for(int i = 0; i < MAX_ITEMS; i++) {
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
		
		word[i] = new Word;
	}
	firstWordCurrent = new Word;
	firstWordCurrent = nullptr;
	initial = 0;
}
ViewDictionary::~ViewDictionary() {
}

int ViewDictionary::handle(RenderWindow& window, int keypressed, bool isKeyPressed, HashTable& table) {
	if(firstWordCurrent == nullptr && initial == 0) {
		firstWordCurrent = table.findFirstWord();
		countReadWord = table.findViewWord(word, firstWordCurrent);
		initial = 1;
	}

	if(isKeyPressed) {
		if(keypressed == Keyboard::Up) {
			if(table.getCountWord() == 0)
				return 2;
			if(positionWord != 0) positionWord--;
			else {
				firstWordCurrent = table.findLeftWord(word[0]);
			}
		}
		else if(keypressed == Keyboard::Down) {
			if(table.getCountWord() == 0)
				return 2;
			if(positionWord < countReadWord - 1) {
				positionWord++;
			}
			else {
				firstWordCurrent = table.findRightWord(word[0]);
				countReadWord = table.findViewWord(word, firstWordCurrent);
				if(word[6] == nullptr) {
					firstWordCurrent = table.findLeftWord(word[0]);
				}
			}
		}
		else if(keypressed >= Keyboard::A && keypressed <= Keyboard::Z) {
			inputWord += keyboard[keypressed];
			search += keyboard[keypressed];
			searchText.setString(search);
			
			rect = searchText.getLocalBounds();
			marker.setPosition(searchText.getPosition().x + rect.width + 3, 133);
			
			firstWordCurrent = table.findWord(inputWord);
			if(firstWordCurrent == nullptr) {
				countReadWord = 0;
				return 2;
			}
			positionWord = 0;
		}
		else if(keypressed == Keyboard::BackSpace) {
			if(search.length() > 8) {
				inputWord.pop_back();
				search.pop_back();
				
				searchText.setString(search);
				rect = searchText.getLocalBounds();
				
				marker.setPosition(searchText.getPosition().x + rect.width + 3, 133);
			}	
			if(inputWord != "") {
				firstWordCurrent = table.findWord(inputWord);
			}
			else {
				firstWordCurrent = table.findFirstWord();
				positionWord = 0;
			}
		}
		else firstWordCurrent = table.findWord(inputWord);
	}

	countReadWord = table.findViewWord(word, firstWordCurrent);

	if(positionWord >= countReadWord) {
		if(positionWord > 0) {
			positionWord--;
		}
	}
	for(int i = 0; i < countReadWord; i++) {
		eng[i].setString(word[i]->getEnglish());
		type[i].setString(word[i]->getType());
		meaning[i].setString(word[i]->getMeaning());
		spriteImageWords[i].setTexture(word[i]->getImage());
		spriteImageWords[i].setScale(0.2 , 0.2);
		spriteImageWords[i].setPosition(780, 100*(i+1) + 80);			
	}
	rectangle.setPosition(eng[positionWord].getPosition().x-10, eng[positionWord].getPosition().y-20);
    
	if(spriteArrow.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y)) {
		spriteArrow.setTexture(arrowHover);
		if(Mouse::isButtonPressed(Mouse::Left)) {
			inputWord = "";
			search = "Search: ";
			positionWord = 0;
			firstWordCurrent = table.findFirstWord();
			searchText.setString(search);
			marker.setPosition(320, 133);
			return 0;
		}
	}
	else	spriteArrow.setTexture(arrow);
	
	for(int i = 0; i < countReadWord; i++) {
		if(spriteSpeaks[i].getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y)) {
			spriteSpeaks[i].setTexture(speakHover);
			if(Mouse::isButtonPressed(Mouse::Left)) {
				word[i]->playMusic();
				Sleep(500);
			}
		}
		else	spriteSpeaks[i].setTexture(speak);	
	}
	return 2;
}

void ViewDictionary::draw(RenderWindow &window) {
	window.draw(spriteBackground);
	window.draw(spriteArrow);
    window.draw(rectangle);
    window.draw(title);
    window.draw(searchText);
    time = clock.getElapsedTime();
	if(time.asSeconds() > 0.5) {
		window.draw(marker);
	}
	if(time.asSeconds() > 1) {
		clock.restart();
	}	
    for(int i = 0; i< countReadWord; i++) {
       	if(i == positionWord) {
        	eng[i].setFillColor(Color::Red);
       		type[i].setFillColor(Color::Red);
        	meaning[i].setFillColor(Color::Red);
		}
		else {
			eng[i].setFillColor(Color::Black);
        	type[i].setFillColor(Color::Black);
        	meaning[i].setFillColor(Color::Black);
		}
       	window.draw(eng[i]);
       	window.draw(type[i]);
        window.draw(meaning[i]);
        window.draw(spriteSpeaks[i]);
	    window.draw(spriteImageWords[i]);
	}
}
WordEng ViewDictionary::getWord() {
	return word[positionWord];
}
WordEng ViewDictionary::getFirstWordCurrent() {
	return firstWordCurrent;
}
void ViewDictionary::setFirstWordCurrent(HashTable &table) {
	firstWordCurrent = table.findFirstWord();
}
void ViewDictionary::setTitle(string s) {
	title.setString(s);
}
