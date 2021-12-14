#include "Instruction.h"

Instruction::Instruction() {
	instructionImages[0].loadFromFile("Resource/Image/InstructionPlay.jpg");
	instructionImages[1].loadFromFile("Resource/Image/InstructionView.jpg");
	instructionImages[2].loadFromFile("Resource/Image/InstructionEdit.jpg");
	for(int i = 0; i < 3; i++) {
		spriteInstructionImages[i].setTexture(instructionImages[i]);;
	}
	
	previous.setTexture(&button);
	previous.setSize(Vector2f(150, 40));
	previous.setPosition(20, 840);
	
	previousText.setString("Previous");
	previousText.setCharacterSize(30);
	previousText.setFont(font[2]);
	previousText.setFillColor(Color::Black);
	rect = previous.getLocalBounds();
	previousText.setPosition(previous.getPosition().x + rect.width/2, previous.getPosition().y + rect.height/2 - 10);
	rect = previousText.getLocalBounds();
	previousText.setOrigin(rect.width/2, rect.height/2);
	
	next.setTexture(&button);
	next.setSize(Vector2f(150, 40));
	next.setPosition(730, 840);
	
	nextText.setString("Next");
	nextText.setCharacterSize(30);
	nextText.setFont(font[2]);
	nextText.setFillColor(Color::Black);
	rect = next.getLocalBounds();
	nextText.setPosition(next.getPosition().x + rect.width/2, next.getPosition().y + rect.height/2 - 10);
	rect = nextText.getLocalBounds();
	nextText.setOrigin(rect.width/2, rect.height/2);
}

Instruction::~Instruction() {
	
}

int Instruction::handle(RenderWindow& window) {
	if(spriteArrow.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y)) {
		spriteArrow.setTexture(arrowHover);
		if(Mouse::isButtonPressed(Mouse::Left)) {
			position = 0;
			return 0;
		}
	}
	else spriteArrow.setTexture(arrow);
	
	if(previous.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y) && check) {
		previous.setTexture(&buttonHover);
		previousText.setFillColor(Color::White);
		if(Mouse::isButtonPressed(Mouse::Left)) {
			check = false;
			clock.restart();
			if(position > 0) 	position--;
		}
	}
	else {
		previousText.setFillColor(Color::Black);
		previous.setTexture(&button);
	} 
	
	if(next.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y) && check) {
		next.setTexture(&buttonHover);
		nextText.setFillColor(Color::White);
		if(Mouse::isButtonPressed(Mouse::Left)) {
			check = false;
			clock.restart();
			if(position < 2) 	position++;
		}
	}
	else {
		nextText.setFillColor(Color::Black);
		next.setTexture(&button);
	} 
	return 5;
}
void Instruction::draw(RenderWindow& window) {
	window.draw(spriteInstructionImages[position]);
	timeSeconds = clock.getElapsedTime();
	if(timeSeconds.asSeconds() > 0.2) 	check = true;
	
	window.draw(spriteArrow);
	window.draw(previous);
	window.draw(next);
	window.draw(previousText);
	window.draw(nextText);
}
