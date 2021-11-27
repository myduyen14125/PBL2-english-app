#ifndef PLAY_H
#define PLAY_H

#include "library.h"
#include "Hashtable.h"
#include<iostream>
using namespace std;

class Play {
	HashTable hashtable;
	// Loading game
	private:
		int percent = 99;
		string textPercent = "";
		Text loadingPercent;
	// Play game
	private:
		bool check = false;
		bool resetClock = false;
		bool playGame = false;
		bool endGame = false;
		string correctWord, defectWord, meaningPlay, typePlay, fill;
		int random_index, countGuess = 0, initialization = 0, number_of_sentences = 0;
		int score_of_sentences[7] = {0};
		int count_guess_of_sentences[7] = {0};
		int totalScoreInt = 0;
		int number_of_correct_sentences = 0;
		
		const int MAX_GUESS_WORD = 3;
		const int MAX_NUMBERS_SENTENCES = 7;
		const char keyboard[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n'
						, 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
		FloatRect rect;
		Font font, fontTiengAnh;			
		Text wordPlay, fill_character, inforWord;
		Texture imageWordPlay, audio, audioHover, background;
		Sprite spriteImageWordPlay, spriteAudioPlay, spriteBackground;
		Music musicWord[7], correctMusic, wrongMusic;
		Clock clock;
		Time timeSeconds;
		
		// Result
		Text eng[7], type[7], meaning[7], times[7], score[7], sub[6];
		Text congratulation, bulkhead, textTotalScore, totalScore, continueGame;
		Texture imageWordResult[7], arrow, arrowHover, buttonContinueGame, buttonContinueGameHover;
		Sprite spriteImageWordResult[7], spriteAudioResult[7], spriteArrow;
		RectangleShape rectangle;
	public:
		Play();
		~Play();
		void loadFont();
		void loadTexture();
		void setSprite();
		void loadMusic();
		void loadResource();
		void setTextResult();
		
		int handlePlay(RenderWindow &window, int keypressed, bool isKeyPressed);
		
		void drawLoadingGame(RenderWindow &window);
		void drawPlayGame(RenderWindow &window);
		void drawEndGame(RenderWindow &window);
		void draw(RenderWindow &window);
		
		void runGame();
};
#endif
