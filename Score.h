#ifndef SCORE_H
#define SCORE_H

#include "Base.h"
#include <fstream>

class Score : public Base{
	private:
		Text title;
		Text times[20], score[20];
		Text totalScore;
		Text scoreText;
		Text subTimeText[2], subScoreText[2];
		int partition = 0;
		int sizeFile = 0;
		int totalScoreInt = 0;
		int year;
		string month, day, hour, minite;
		string scoreString, timeString;
		
		Clock clock;
		Time timeAsSeconds;
	public:
		Score();
		~Score();
		
		void readFileScore();
		void updateFileScore();
		void formatTime(int time, string &s);
		void getTime(int &year, string &month, string &day, string &hour, string &minite);
		
		void setPositionTimesText();
		void updateHistory(int scorePlay);
		int handle(RenderWindow& window);
		void draw(RenderWindow &window);
		
		void printScore();
};
#endif
