#ifndef WORD_H
#define WORD_H

#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<windows.h>
#include<iostream>
#include<string.h>

using namespace std;
using namespace sf;

typedef class Word* WordEng;
class Word {
	private:
		int key;
		string english;
		string type;
		string meaning;
		Texture image;
		Music music;
		
		WordEng prev;
		WordEng next;
	public:
		Word();
		~Word();
		void setWord(string, string, string);
		void setKey(int key);
		void setNext(WordEng next);
		void setPrev(WordEng prev);
		
		int getKey();
		WordEng getNext();
		WordEng getPrev();
		string getEnglish();
		string getType();
		string getMeaning();
		Texture& getImage();
		void playMusic();
		void printWord() {
			cout<<this->english<<"\t"<<this->type<<"\t"<<this->meaning<<endl;
		}
		const WordEng& operator = (const WordEng eng);
		
	friend class HashTable;
};
#endif
