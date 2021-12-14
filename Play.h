#ifndef PLAY_H
#define PLAY_H

#include "Base.h"
#include "Score.h"
class Play: public Base {
	private:
		WordEng word[MAX_ITEMS];
		Sprite spriteImages[MAX_ITEMS], spriteSpeaks[MAX_ITEMS], spriteSpeakPlay, spriteImageWordPlay;
		Texture heart;
		Sprite spriteHeart[3];
		Text inforWord, wordPlay, fill_character;
		Text textPercent, ready, yes, no;
		Text congratulation, bulkhead, totalScoreText, totalScoreInt, continueGame, scorePlayText;
		Text eng[MAX_ITEMS], type[MAX_ITEMS], meaning[MAX_ITEMS], times[MAX_ITEMS], score[MAX_ITEMS], sub[6], error[4];
		RectangleShape confirmContinueGame, confirmPlayGame, confirmNotPlayGame;
		Music correctMusic, wrongMusic;
		Time timeSeconds;
		Clock clock;
		
		int initial = 0;
		int percent = 0;
		bool isResetClock = false;
		bool isCorrect = false;
		bool isPlayGame = false;
		bool isEndGame = false;
		
		string defectWord;
		string correctWord;
		string tempFill;
		int randomIndex;
		
		int number_of_correct_sentences = 0; // So cau dung
		int countGuess_of_sentences[MAX_ITEMS] = {0}; // So lan doan / 1 cau
		const int MAX_GUESS = 3; // So lan doan toi da
		int score_of_sentences[MAX_ITEMS] = {0}; // Diem / cau
		int totalScore = 0; // tong diem
		int positionSentences = 0; // So cau hien tai
	public:
		Play();
		~Play();
		
		int handle(RenderWindow& window) {
		}
		int handle(RenderWindow &window, int keypressed, bool isKeyPressed, HashTable &table, Score &objectScore);
		void draw(RenderWindow &window);
	private:
		void loadResource();
		void setWordPlay(const HashTable &table);
		void setTextLoadingGame();
		void setTextResult();
		void setTextError();
		
		void drawErrorGame(RenderWindow &window);
		void drawLoadingGame(RenderWindow &window);
		void drawPlayGame(RenderWindow &window);
		void drawEndGame(RenderWindow &window);
		
		void reset();
};

#endif
