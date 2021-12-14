#include "Form.h"

void Form::loadResource() {
	background.loadFromFile("Resource/Image/backgroundForm.jpg");
	spriteBackground.setTexture(background);
}

Form::Form() {
	loadResource();
	form.setSize(Vector2f(500.f,500.f));
	form.setOutlineThickness(2.f);
	form.setOutlineColor(Color::Black);
	form.setFillColor(Color(230, 241, 216));
	form.setPosition(200, 150);
	text[0].setString("English");
	text[1].setString("Type");
	text[2].setString("Meaning");
	confirm.setFont(font[4]);
	confirm.setCharacterSize(30);
	confirm.setFillColor(Color::Black);
	
	title.setFont(font[3]);
	title.setCharacterSize(45);
	title.setFillColor(Color::Red);
	title.setPosition(450, 70);
	
	rowConfirm.setSize(Vector2f(400, 50));
	rowConfirm.setPosition(form.getPosition().x + 50, form.getPosition().y + 400);
	rowConfirm.setOutlineThickness(2.f);
	rowConfirm.setOutlineColor(Color::Black);
	rowConfirm.setFillColor(Color(131, 199, 93));
	confirm.setPosition(rowConfirm.getPosition().x + 135, rowConfirm.getPosition().y + 5);
	
	marker.setSize(Vector2f(15.f, 5.f));
	marker.setFillColor(Color::Black);
	
	for(int i = 0; i < 3; i++) {
		text[i].setPosition(form.getPosition().x + 50, form.getPosition().y + 40 + 110 * i);
		text[i].setFont(font[4]);
		text[i].setCharacterSize(30);
		text[i].setFillColor(Color::Black);
		row[i].setSize(Vector2f(400, 50));
		row[i].setPosition(form.getPosition().x + 50, form.getPosition().y + 90 + 110 * i);
		row[i].setOutlineThickness(2.f);
		row[i].setOutlineColor(Color::Black);
		
		wordText[i].setFont(font[2]);
		wordText[i].setCharacterSize(30);
		wordText[i].setFillColor(Color::Black);
		wordText[i].setPosition(row[i].getPosition().x + 10, row[i].getPosition().y + 5);
		wordString[i] = "";
	}
	
	positionInput = 0;
	word = new Word;
}

Form::~Form() {
	
}

int Form::handle(RenderWindow& window, int keypressed, bool isKeyPressed) {
	if(spriteArrow.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y)) {
		spriteArrow.setTexture(arrowHover);
		if(Mouse::isButtonPressed(Mouse::Left))		return 0;
	}
	else	spriteArrow.setTexture(arrow);
	
	for(int i = 0; i < 3; i++) {
		if(row[i].getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y) && Mouse::isButtonPressed(Mouse::Left)) {
			positionInput = i;
			break;
		}
	}
	if(isKeyPressed) {
		if(keypressed >= Keyboard::A && keypressed <= Keyboard::Z) {
			wordString[positionInput] += keyboard[keypressed];
			wordText[positionInput].setString(wordString[positionInput]);
		}
		else if(keypressed == Keyboard::Space) {
			wordString[positionInput] += " ";
			wordText[positionInput].setString(wordString[positionInput]);
		}
		else if(keypressed == Keyboard::BackSpace) {
			if(wordString[positionInput].length() > 0) {
				wordString[positionInput].pop_back();
				wordText[positionInput].setString(wordString[positionInput]);
			}
		}
	}
	rect = wordText[positionInput].getLocalBounds();
	marker.setPosition(wordText[positionInput].getPosition().x + rect.width + 3, wordText[positionInput].getPosition().y + 30);
	
	if(rowConfirm.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y)) {
		rowConfirm.setFillColor(Color(72, 150, 32));
		if(Mouse::isButtonPressed(Mouse::Left)) {
			if(wordString[0] == "") {
				marker.setPosition(wordText[0].getPosition().x + rect.width + 3, wordText[0].getPosition().y + 30);
			}
			else if(wordString[1] == "") {
				marker.setPosition(wordText[1].getPosition().x + rect.width + 3, wordText[1].getPosition().y + 30);
			}
			else if(wordString[2] == "") {
				marker.setPosition(wordText[2].getPosition().x + rect.width + 3, wordText[2].getPosition().y + 30);
			}
			else {
				word->setWord(wordString[0], wordString[1], wordString[2]);
				return 1;
			}
		}
	}
	else rowConfirm.setFillColor(Color(131, 199, 93));
	return 2;
}

void Form::draw(RenderWindow& window) {
	window.draw(spriteBackground);
    window.draw(spriteArrow);
    window.draw(title);
    window.draw(form);
    for(int i = 0; i < 3; i++) {
       	window.draw(row[i]);
       	window.draw(text[i]);
       	window.draw(wordText[i]);
	}
	time = clock.getElapsedTime();
	if(time.asSeconds() > 0.5) {
		window.draw(marker);
	}
	if(time.asSeconds() > 1) {
		clock.restart();
	}
	window.draw(rowConfirm);
	window.draw(confirm);
}

WordEng Form::getWord() {
	WordEng temp = word;
	word = new Word;
	return temp;
}

void Form::resetForm() {
	for(int i = 0; i < 3; i++) {
		wordString[i] = "";
		wordText[i].setString("");
	}
	word = new Word;
	positionInput = 0;
}

void Form::setTitle(string titleString, string confirmString) {
	title.setString(titleString);
	confirm.setString(confirmString);
	rect = title.getLocalBounds();
	title.setOrigin(rect.width/2, rect.height/2);
}

void Form::setPositionForm(float x, float y) {
	form.setPosition(x, y);
	for(int i = 0; i < 3; i++) {
		text[i].setPosition(form.getPosition().x + 50, form.getPosition().y + 40 + 110 * i);
		row[i].setPosition(form.getPosition().x + 50, form.getPosition().y + 90 + 110 * i);
		wordText[i].setPosition(row[i].getPosition().x + 10, row[i].getPosition().y + 5);
	}
	rowConfirm.setPosition(form.getPosition().x + 50, form.getPosition().y + 400);
	confirm.setPosition(rowConfirm.getPosition().x + 135, rowConfirm.getPosition().y + 5);
	marker.setPosition(wordText[positionInput].getPosition().x + rect.width + 3, wordText[positionInput].getPosition().y + 30);
}

float Form::getPositionXForm() {
	return form.getPosition().x;
}

float Form::getPositionYForm() {
	return form.getPosition().y;
}

