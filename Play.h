#ifndef PLAY_H
#define PLAY_H

#include "library.h"
#include "Hashtable.h"

class Play {
	private:
		bool check = false;
		bool resetClock = false;
		string correctWord, defectWord, meaning, type, fill;
		int random_index, countGuess = 0;
		const int MAX_GUESS_WORD = 3;
		int initialization = 0;
		const char keyboard[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n'
						, 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
		
		Font font;			
		Text wordPlay, fill_in_word, inforWord;
		Texture imageWord, audio, audioHover;
		Sprite spriteImageWord, spriteAudio;
		Music musicWord, correctMusic, wrongMusic;
		HashTable hashtable;
		Clock clock;
		Time timeSeconds;
	public:
		Play();
		~Play();
		void loadFont();
		void loadTexture();
		void setSprite();
		void loadMusic();
		void loadResource();
		
		int handlePlay(RenderWindow &window, int keypressed, bool isKeyPressed);
		void drawPlay(RenderWindow &window);
		
		void runGame();
};
#endif
