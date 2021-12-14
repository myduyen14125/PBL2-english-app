#include "Score.h"


Score::Score() {
	background.loadFromFile("Resource/Image/backgroundView.jpg");
	spriteBackground.setTexture(background);
	
	title.setString("YOUR SCORE");
	title.setFont(font[3]);
	title.setCharacterSize(50);
	title.setPosition(450, 35);
	rect = title.getLocalBounds();
	title.setOrigin(rect.width/2, rect.height/2);
	title.setFillColor(Color::Red);
	
	for(int i = 0; i < 20; i++) {
		times[i].setFont(font[2]);
		score[i].setFont(font[2]);
		times[i].setFillColor(Color::Black);
		score[i].setFillColor(Color(0, 128, 0));
	}
	
	scoreText.setFont(font[2]);
	scoreText.setPosition(100, 90);
	scoreText.setString("TOTAL SCORE: ");
	scoreText.setFillColor(Color::Black);
	scoreText.setCharacterSize(30);
	
	totalScore.setFont(font[2]);
	totalScore.setPosition(700, 90);
	totalScore.setFillColor(Color::Black);
	totalScore.setCharacterSize(30);
	
	for(int i = 0; i < 2; i++) {
		subTimeText[i].setString("Time");
		subTimeText[i].setFont(font[2]);
		subTimeText[i].setCharacterSize(30);
		subTimeText[i].setFillColor(Color(42, 0, 162));
		
		subScoreText[i].setString("Score");
		subScoreText[i].setFont(font[2]);
		subScoreText[i].setCharacterSize(30);
		subScoreText[i].setFillColor(Color(42, 0, 162));
	}
	subTimeText[0].setPosition(150, 150);
	subTimeText[1].setPosition(600, 150);
	subScoreText[0].setPosition(340, 150);
	subScoreText[1].setPosition(795, 150);
	
	this->readFileScore();
	setPositionTimesText();
}
Score::~Score() {
	
}
int Score::handle(RenderWindow& window) {
	if(spriteArrow.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y)) {
		spriteArrow.setTexture(arrowHover);
		if(Mouse::isButtonPressed(Mouse::Left)) {
			return 0;
		}
	}
	else	spriteArrow.setTexture(arrow);
	return 4;	
}
void Score::draw(RenderWindow &window) {
	window.draw(spriteBackground);
	window.draw(spriteArrow);
	window.draw(title);
	window.draw(scoreText);
	window.draw(totalScore);
	
	for(int i = 0; i < 2; i++) {
		window.draw(subTimeText[i]);
		window.draw(subScoreText[i]);
	}
	
	for(int i = 0; i < sizeFile; i++) {
		window.draw(times[i]);
		window.draw(score[i]);
	}
}

void Score::readFileScore() {
	ifstream FileIn;
	FileIn.open("F:\\PBL2-english-app\\Data\\score.txt", ios_base::in);
	if (FileIn.fail()) {
        cout << "Open file failed!" << endl;
    }
    
    string line = "";
    getline(FileIn, line);
    totalScoreInt = stoi(line);
    totalScore.setString(line);
    
    string s = "";
    line = "";
    int j;
	for(int i = 0; i < 20; i++) {
		getline(FileIn, line);
		if(line == "")	break;
		j = 0;
		while(line[j] != '@') {
		    s += line[j];
		    j++;
		}
		j++;
		times[i].setString(s);
		s = "";
		while(line[j] != '@') {
		    s += line[j];
		    j++;
		}
		j++;
		score[i].setString(s);
		s = "";
		sizeFile++;
		line = "";
	}
	FileIn.close();
}
void Score::setPositionTimesText() {
	if(sizeFile < 20) {
		for(int i = sizeFile - 1; i >= sizeFile - 10; i--) {
			times[i].setPosition(70, 200 + 70 * (sizeFile - 1 - i));
			score[i].setPosition(350, 200 + 70 * (sizeFile - 1 - i));
		}
		for(int i = sizeFile - 11; i >= 0; i--) {
			times[i].setPosition(520, 200 + 70 * (sizeFile - 11 - i));
			score[i].setPosition(800, 200 + 70 * (sizeFile - 11 - i));
		}
	}
	else {
		if(partition >= 10) {
			for(int i = partition - 1; i >= partition - 10; i--) {
				times[i].setPosition(70, 200 + 70 * (partition - 1 - i));
				score[i].setPosition(350, 200 + 70 * (partition - 1 - i));
			}
			if(partition == 10) {
				for(int i = 19; i >= 10; i--) {
					times[i].setPosition(520, 200 + 70 * (19 - i));
					score[i].setPosition(800, 200 + 70 * (19 - i));
				}
			}
			else {
				for(int i = partition - 11; i >= 0; i--) { 
					times[i].setPosition(520, 200 + 70 * (partition - 11 - i));
					score[i].setPosition(800, 200 + 70 * (partition - 11 - i));
				}
				for(int i = 19; i >= partition; i++) {
					times[i].setPosition(520, 200 + 70 * (19 - i + partition - 10));
					score[i].setPosition(800, 200 + 70 * (19 - i + partition - 10));
				}
			}
		}
		else {
			if(partition == 0) {
				for(int i = 19; i >= 10; i--) {
					times[i].setPosition(70, 200 + 70 * (19 - i));
					score[i].setPosition(350, 200 + 70 * (19 - i));
				}
				for(int i = 9; i >= 0; i--) {
					times[i].setPosition(520, 200 + 70 * (9 - i));
					score[i].setPosition(800, 200 + 70 * (9 - i));
				}
			}
			else {
				for(int i = partition - 1; i >= 0; i--) {
					times[i].setPosition(70, 200 + 70 * (partition - 1 - i));
					score[i].setPosition(350, 200 + 70 * (partition - 1 - i));
				}
				for(int i = 19; i >= 10 + partition; i--) {
					times[i].setPosition(70, 200 + 70 * (19 - i + partition));
					score[i].setPosition(350, 200 + 70 * (19 - i + partition));
				}
				
				for(int i = 9 + partition; i >= partition; i--) {
					times[i].setPosition(520, 200 + 70 * (9 + partition - i));
					score[i].setPosition(820, 200 + 70 * (9 + partition - i));
				}
			}
		}
	}
}
void Score::updateHistory(int scorePlay) {
	year = 0;
	month = day = hour = minite = "";
	if(sizeFile < 20) {
		getTime(year, month, day, hour, minite);
		times[sizeFile].setString(hour + ":" + minite + " " + day + "/" + month + "/" + to_string(year));
		score[sizeFile].setString(to_string(scorePlay));
		sizeFile++;
	}
	else {
		getTime(year, month, day, hour, minite);
		times[partition].setString(hour + ":" + minite + " " + day + "/" + month + "/" + to_string(year));
		score[partition].setString(to_string(scorePlay));
		partition++;
		if(partition == 20)		partition = 0;
	}
	totalScoreInt += scorePlay;
	totalScore.setString(to_string(totalScoreInt));
	setPositionTimesText();
}

void Score::updateFileScore() {
	ofstream FileOut;
	FileOut.open("F:\\PBL2-english-app\\Data\\score.txt", ios::out);
	string totalString = totalScore.getString();
	FileOut<<totalString<<endl;	
	for(int i = partition; i < sizeFile; i++) {
		timeString = times[i].getString();
		scoreString = score[i].getString();
		FileOut<<timeString<<"@"<<scoreString<<"@"<<endl;
	}
	for(int i = 0; i < partition; i++) {
		timeString = times[i].getString();
		scoreString = score[i].getString();
		FileOut<<timeString<<"@"<<scoreString<<"@"<<endl;
	}
	FileOut.close();
}

void Score::formatTime(int time, string &s){
	s += (time/10) + '0';
	s += (time % 10) + '0';
}

void Score::getTime(int &year, string &month, string &day, string &hour, string &minite){
	time_t now = time(0);
   	tm *ltm = localtime(&now);

  	int YEAR   = 1900 + ltm->tm_year;
   	int MONTH  = 1    + ltm->tm_mon;
   	int DAY    = ltm->tm_mday ;
   	int HOUR   = ltm->tm_hour;
   	int MINITE = ltm->tm_min ;
 	year = YEAR;
   	formatTime(MINITE,minite);
   	formatTime(HOUR,hour);
   	formatTime(DAY,day);
   	formatTime(MONTH,month);
}

