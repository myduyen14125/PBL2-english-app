#include "Word.h"

Word::Word() {
	this->next = nullptr;
	this->prev = nullptr;
}
Word::~Word() {
	
}
void Word::setWord(string english, string type, string meaning) {
	this->english = english;
	this->type = type;
	this->meaning = meaning;
	if(!this->image.loadFromFile("Resource/ImageWord/" + english + ".jpg")) {
		this->image.loadFromFile("Resource/ImageWord/notFound.jpg");
		this->music.openFromFile("Resource/MusicWord/notFound.wav");
	}
	else {
		this->image.loadFromFile("Resource/ImageWord/" + english + ".jpg");
		this->music.openFromFile("Resource/MusicWord/" + english + ".wav");
	}
	this->next = nullptr;
	this->prev = nullptr;
}
void Word::setKey(int key) {
	this->key = key;
}
void Word::setNext(WordEng next) {
	if(next != nullptr) {
		this->next = next;
		next->prev = this; 
	}
	else this->next = next;
}
void Word::setPrev(WordEng prev) {
	if(prev != nullptr) {
		this->prev = prev;
		prev->next = this; 
	}
	else this->prev = prev;
}
WordEng Word::getNext() {
	return next;
}
WordEng Word::getPrev() {
	return prev;
}
string Word::getEnglish() {
	return english;
}
string Word::getType() {
	return type;
}
string Word::getMeaning() {
	return meaning;
}
Texture& Word::getImage() {
	return image;
}
void Word::playMusic() {
	this->music.play();
}
const WordEng& Word::operator = (const WordEng eng) {
	this->setWord(eng->getEnglish(), eng->getType(), eng->getMeaning());
	this->setNext(eng->getNext());
	this->setPrev(eng->getPrev());
	return this;
}
