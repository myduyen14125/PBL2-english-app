#include "Play.h"

void Play::loadResource() {
	background.loadFromFile("Resource/Image/backgroundPlay.jpg");
	spriteBackground.setTexture(background);
	
	spriteSpeakPlay.setTexture(speak);
	spriteSpeakPlay.setScale(0.03, 0.03);
	spriteSpeakPlay.setPosition(700, 500);
	
	heart.loadFromFile("Resource/Image/heart.png");
	for(int i = 0; i < 3; i++) {
		spriteHeart[i].setTexture(heart);
		spriteHeart[i].setPosition(50 + 40 * i, 30);
	}

	correctMusic.openFromFile("Resource/Music/WinAnswer.wav");
	wrongMusic.openFromFile("Resource/Music/WrongAnswer.wav");
}

void Play::setTextLoadingGame() {
	textPercent.setFont(font[2]);
	textPercent.setFillColor(Color::Red);
	textPercent.setPosition(250, 400);
	textPercent.setCharacterSize(50);
	
	ready.setString("Do you want to play game?");
	ready.setFont(font[2]);
	ready.setFillColor(Color::Black);
	ready.setCharacterSize(50);
	ready.setPosition(450, 350);
	rect = ready.getLocalBounds();
	ready.setOrigin(rect.width/2, rect.height/2);
	
	confirmPlayGame.setSize(Vector2f(100.f, 50.f));
	confirmPlayGame.setTexture(&button);
	confirmPlayGame.setPosition(500, 450);
	
	confirmNotPlayGame.setSize(Vector2f(100.f, 50.f));
	confirmNotPlayGame.setTexture(&button);
	confirmNotPlayGame.setPosition(300, 450);
	
	yes.setString("Yes");
	yes.setFont(font[2]);
	yes.setFillColor(Color::Black);
	yes.setCharacterSize(40);
	rect = confirmPlayGame.getLocalBounds();
	yes.setPosition(confirmPlayGame.getPosition().x + rect.width/2, confirmPlayGame.getPosition().y + rect.height/2 - 10);
	rect = yes.getLocalBounds();
	yes.setOrigin(rect.width/2, rect.height/2);
	
	no.setString("No");
	no.setFont(font[2]);
	no.setFillColor(Color::Black);
	no.setCharacterSize(40);
	rect = confirmNotPlayGame.getLocalBounds();
	no.setPosition(confirmNotPlayGame.getPosition().x + rect.width/2, confirmNotPlayGame.getPosition().y + rect.height/2 - 10);
	rect = no.getLocalBounds();
	no.setOrigin(rect.width/2, rect.height/2);
	
	scorePlayText.setFont(font[4]);
	scorePlayText.setCharacterSize(30);
	scorePlayText.setFillColor(Color::Red);
	scorePlayText.setPosition(700, 50);
}

void Play::setTextResult() {
	congratulation.setFont(font[2]);
	congratulation.setCharacterSize(35);
	
	for(int i = 0; i < MAX_ITEMS; i++) {
		eng[i].setFont(font[4]);
		eng[i].setCharacterSize(25);
		eng[i].setPosition(33, 190 + 80 * i);
		eng[i].setFillColor(Color::Black);
		
		type[i].setFont(font[4]);
		type[i].setCharacterSize(25);
		type[i].setPosition(255, 190 + 80*i);
		type[i].setFillColor(Color::Black);
		
		meaning[i].setFont(font[4]);
		meaning[i].setCharacterSize(25);
		meaning[i].setPosition(370 , 190 + 80*i);
		meaning[i].setFillColor(Color::Black);
		
		times[i].setFont(font[4]);
		times[i].setCharacterSize(25);
		times[i].setPosition(710, 190 + 80*i);
		times[i].setFillColor(Color(0,128,0));
		
		score[i].setFont(font[4]);
		score[i].setCharacterSize(25);
		score[i].setPosition(820, 190 + 80*i);
		score[i].setFillColor(Color::Red);
		
		spriteSpeaks[i].setTexture(speak);
		spriteSpeaks[i].setScale(0.02, 0.02);
		spriteSpeaks[i].setPosition(650, 190 + 80*i);
		
		word[i] = new Word;
	}
	
	sub[0].setString("Vocabulary"); 
	sub[0].setPosition(30, 120);
	sub[1].setString("Type"); 
	sub[1].setPosition(255, 120);
	sub[2].setString("Meaning");
	sub[2].setPosition(370, 120);
	sub[3].setString("Image");
	sub[3].setPosition(570, 120);
	sub[4].setString("Times");
	sub[4].setPosition(695, 120);
	sub[5].setString("Score");
	sub[5].setPosition(805, 120);
	for(int i = 0; i < 6; i++) {
		sub[i].setFont(font[2]);
		sub[i].setCharacterSize(30);
		sub[i].setFillColor(Color(42, 0, 162));
	}
	bulkhead.setString("------------------------------------------------------------------------------");
	bulkhead.setPosition(20, 720);
	bulkhead.setFont(font[2]);
	bulkhead.setFillColor(Color(0,128,0));
	
	totalScoreText.setString("Total Score");
	totalScoreText.setFont(font[4]);
	totalScoreText.setCharacterSize(25);
	totalScoreText.setFillColor(Color::Red);
	totalScoreText.setPosition(25, 760);
	
	totalScoreInt.setFont(font[4]);
	totalScoreInt.setCharacterSize(25);
	totalScoreInt.setFillColor(Color::Red);
	totalScoreInt.setPosition(808, 760);
	
	continueGame.setString("Play continue");
	continueGame.setFont(font[2]);
	continueGame.setCharacterSize(25);
	continueGame.setFillColor(Color::Black);
	continueGame.setPosition(600, 820);
	confirmContinueGame.setSize(Vector2f(180.f, 50.f));
	confirmContinueGame.setTexture(&button);
	confirmContinueGame.setPosition(Vector2f(continueGame.getPosition().x-15, continueGame.getPosition().y-10));
}

void Play::setTextError() {
	error[0].setString("Error. Can't load vocabulary");
	error[1].setString("There is no vocabulary in the dictionary");
	error[2].setString("Please add words to the dictionary");
	error[3].setString("Thank you for using this app");
	for(int i = 0; i < 4; i++) {
		error[i].setFont(font[2]);
		error[i].setCharacterSize(40);
		error[i].setFillColor(Color::Red);
		rect = error[i].getLocalBounds();
		error[i].setOrigin(rect.width/2, rect.height/2);
		error[i].setPosition(450, 300 + 100 * i);
	}
	error[3].setFillColor(Color(0, 128, 0));
}

Play::Play() {
	loadResource();
	setTextResult();
	setTextError();
	setTextLoadingGame();
	
	endGame.setFont(font[2]);
	endGame.setString("End game");
	endGame.setCharacterSize(30);
	endGame.setPosition(700, 800);
	endGame.setFillColor(Color::Black);
	confirmEndGame.setSize(Vector2f(150.f, 50.f));
	confirmEndGame.setTexture(&button);
	confirmEndGame.setPosition(endGame.getPosition().x - 10, endGame.getPosition().y - 5);
	
	blurred_background.setSize(Vector2f(900.f, 900.f));
	blurred_background.setFillColor(Color(0, 0, 0, 90));
	
	bulletin_board_image.loadFromFile("F:\\Project\\Resource\\Image\\Note.png");
	bulletin_board_rectangle.setSize(Vector2f(900.f, 500.f));
	bulletin_board_rectangle.setTexture(&bulletin_board_image);
	bulletin_board_rectangle.setFillColor(Color::White);
	bulletin_board_rectangle.setPosition(5, 170);
	
	confirmEndGameText.setString("Do you want to end game?");
	confirmEndGameText.setFont(font[2]);
	confirmEndGameText.setFillColor(Color::Black);
	confirmEndGameText.setCharacterSize(50);
	confirmEndGameText.setPosition(450, 350);
	rect = confirmEndGameText.getLocalBounds();
	confirmEndGameText.setOrigin(rect.width/2, rect.height/2);
}

Play::~Play() {
	
}

void Play::setWordPlay(const HashTable &table) {
	int i = positionSentences;
	word[i] = table.randomWord();
	correctWord = word[i]->getEnglish();
	if(correctWord[0] >= 'a' && correctWord[0] <= 'z')		correctWord[0] = correctWord[0] - 32;
	defectWord = correctWord;
	
	srand(time(NULL));
	int length = correctWord.length();
	do {
		randomIndex = rand() % length;
	} while(defectWord[randomIndex] == ' ');
	defectWord[randomIndex] = '_';
	
	// load imageWord, musicWord
	spriteImageWordPlay.setTexture(word[i]->getImage());
	spriteImageWordPlay.setPosition(275, 200);
	
	wordPlay.setString(defectWord);
	wordPlay.setFillColor(Color::Black);
	wordPlay.setFont(font[2]);
	wordPlay.setCharacterSize(80);
	rect = wordPlay.getLocalBounds();
	wordPlay.setOrigin(rect.width/2, rect.height/2);
	wordPlay.setPosition(450, 100);
	
	//tempFill = "Fill in the space: ";
	fill_character.setString("Fill in the space: ");
	fill_character.setFillColor(Color::Black);
	fill_character.setFont(font[2]);
	fill_character.setCharacterSize(40);
	fill_character.setPosition(200, 700);
	
	inforWord.setString(word[i]->getMeaning() + " (" + word[i]->getType() + ")");
	inforWord.setFont(font[2]);
	inforWord.setCharacterSize(40);
	rect = inforWord.getLocalBounds();
	inforWord.setOrigin(rect.width/2, rect.height/2);
	inforWord.setPosition(450, 650);
	inforWord.setFillColor(Color(0, 128, 0));
	
	// Set resource result
	eng[i].setString(word[i]->getEnglish());
	type[i].setString(word[i]->getType());
	meaning[i].setString(word[i]->getMeaning());
	
	spriteImages[i].setTexture(word[i]->getImage());
	spriteImages[i].setPosition(570, 170 + 80 * i);
	spriteImages[i].setScale(0.17, 0.17);
}

int Play::handle(RenderWindow &window, int keypressed, bool isKeyPressed, HashTable &table, Score &objectScore) {
	if(table.isEmpty()) {
		initial = -1;
	}

	if(isPlayGame) {
		if(initial == 0 && positionSentences < MAX_ITEMS) {
			initial = 1;
			setWordPlay(table);
			positionSentences++;
		}
		
		if(!isExist) {
			if(confirmEndGame.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y)) {
				confirmEndGame.setTexture(&buttonHover);
				endGame.setFillColor(Color::White);
				if(Mouse::isButtonPressed(Mouse::Left)) {
					isExist = true;
					Sleep(100);
				}
			}
			else {
				confirmEndGame.setTexture(&button);
				endGame.setFillColor(Color::Black);
			}
			if(isKeyPressed && !isCorrect && countGuess_of_sentences[positionSentences - 1] <= MAX_GUESS) {
				if(keypressed >= 0 && keypressed <= 25) {
					if(randomIndex == 0)	defectWord[randomIndex] = keyboard[keypressed] - 32;
					else defectWord[randomIndex] = keyboard[keypressed];
					
					tempFill = "Fill in the space: ";
					tempFill += keyboard[keypressed];
					fill_character.setString(tempFill);
					wordPlay.setString(defectWord);
					countGuess_of_sentences[positionSentences - 1]++;
				}
				else {
					defectWord[randomIndex] = '_';
					tempFill = "Fill in the space: ";
					fill_character.setString(tempFill);
					wordPlay.setString(defectWord);
					wordPlay.setFillColor(Color::Black);
					if(keypressed == 59) {
						return 1;
					}
				}
				if(defectWord != correctWord) {
					wordPlay.setFillColor(Color::Red);
					wrongMusic.play();
					srand(time(NULL));
					if(countGuess_of_sentences[positionSentences - 1] == MAX_GUESS) {
						times[positionSentences - 1].setString(to_string(MAX_GUESS) + "/3");
						times[positionSentences - 1].setFillColor(Color::Red);
						score_of_sentences[positionSentences - 1] = rand() % 21;
						score[positionSentences - 1].setString(to_string(score_of_sentences[positionSentences - 1]));
						totalScore += score_of_sentences[positionSentences - 1];
					}
				}
				else {
					isCorrect = true;
				   	wordPlay.setFillColor(Color(0,128,0));
				   	correctMusic.play();
				   	times[positionSentences - 1].setString(to_string(countGuess_of_sentences[positionSentences - 1]) + "/3");
				   	srand(time(NULL));
				   	if(countGuess_of_sentences[positionSentences - 1] == 0) {
				   		score_of_sentences[positionSentences - 1] = 0;
					}
					else if(countGuess_of_sentences[positionSentences - 1] == 1) {
						score_of_sentences[positionSentences - 1] = rand() % 20 + 81;
					}
					else if((countGuess_of_sentences[positionSentences - 1] == 2)) {
						score_of_sentences[positionSentences - 1] = rand() % 40 + 51;
					}
					else if((countGuess_of_sentences[positionSentences - 1] == 3)){
						score_of_sentences[positionSentences - 1] = rand() % 60 + 21;
					}
					
					scorePlayText.setString("Score: " + to_string(score_of_sentences[positionSentences - 1]));
					score[positionSentences - 1].setString(to_string(score_of_sentences[positionSentences - 1]));
					totalScore += score_of_sentences[positionSentences - 1];
				    word[positionSentences - 1]->playMusic();
				    
				    number_of_correct_sentences++;
				    return 1;
				}		
			}
			if(spriteSpeakPlay.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y) && isCorrect) {
		        spriteSpeakPlay.setTexture(speakHover);
		        if(Mouse::isButtonPressed(Mouse::Left))    	word[positionSentences - 1]->playMusic();	
			}
			else spriteSpeakPlay.setTexture(speak);	
		}
		else {
			if(confirmPlayGame.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y)) {
				confirmPlayGame.setTexture(&buttonHover);
				yes.setFillColor(Color::White);
				if(Mouse::isButtonPressed(Mouse::Left)) {
					isEndGame = true;
					isPlayGame = false;
					isExist = false;
				}
			}
			else {
				yes.setFillColor(Color::Black);
				confirmPlayGame.setTexture(&button);
			}
			
			if(confirmNotPlayGame.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y)) {
				confirmNotPlayGame.setTexture(&buttonHover);
				no.setFillColor(Color::White);
				if(Mouse::isButtonPressed(Mouse::Left)) {
					isPlayGame = true;
					isEndGame = false;
					isExist = false;
				}
			}
			else {
				no.setFillColor(Color::Black);
				confirmNotPlayGame.setTexture(&button);
			}
		}
	}
	else if(isEndGame) {
		totalScoreInt.setString(to_string(totalScore));
		if(number_of_correct_sentences >= positionSentences/2 + 1) {
			congratulation.setString("Congratulations! You answered correctly " + to_string(number_of_correct_sentences) + "/" + to_string(positionSentences) + " words!");                            
			congratulation.setFillColor(Color(0, 128, 0));
		}
		else {
			congratulation.setString("Try your best! You answered correctly " + to_string(number_of_correct_sentences) + "/" + to_string(positionSentences) + " words!");
			congratulation.setFillColor(Color::Red);
		}
		rect = congratulation.getLocalBounds();
		congratulation.setOrigin(rect.width/2, rect.height/2);
		congratulation.setPosition(450, 60);
		
		if(confirmContinueGame.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y)) {
			confirmContinueGame.setTexture(&buttonHover);
			continueGame.setFillColor(Color::White);
			if(Mouse::isButtonPressed(Mouse::Left)) {
				objectScore.updateHistory(totalScore);
				objectScore.updateFileScore();
				reset();
				return 1;
			}
		}
		else {
			confirmContinueGame.setTexture(&button);
			continueGame.setFillColor(Color::Black);
		}
		
		if(spriteArrow.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y)) {
			spriteArrow.setTexture(arrowHover);
			if(Mouse::isButtonPressed(Mouse::Left)) {
				objectScore.updateHistory(totalScore);
				objectScore.updateFileScore();
				reset();
				return 0;
			}
		}
		else 	spriteArrow.setTexture(arrow);
		
		for(int i = 0; i < MAX_ITEMS; i++) {
			if(spriteSpeaks[i].getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y)){
				spriteSpeaks[i].setTexture(speakHover);
				if(Mouse::isButtonPressed(Mouse::Left))		word[i]->playMusic();	
			}
			else 	spriteSpeaks[i].setTexture(speak);
		}
	}
	if(initial == -1) {
		if(spriteArrow.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y)) {
			spriteArrow.setTexture(arrowHover);
			if(Mouse::isButtonPressed(Mouse::Left)) {
				initial = 0;
				return 0;
			}
		}
		else 	spriteArrow.setTexture(arrow);
	}
	else if(initial == 0 && percent <= 100) {
		textPercent.setString("Loading game: " + to_string(percent) + " %");
		Sleep(30);
		percent++;
	}
	else if(percent == 101 && initial == 0) {
		if(confirmPlayGame.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y)) {
			confirmPlayGame.setTexture(&buttonHover);
			yes.setFillColor(Color::White);
			if(Mouse::isButtonPressed(Mouse::Left)) {
				yes.setFillColor(Color::Black);
				isPlayGame = true;
				return 1;
			}
		}
		else {
			yes.setFillColor(Color::Black);
			confirmPlayGame.setTexture(&button);
		}
		
		if(confirmNotPlayGame.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y)) {
			confirmNotPlayGame.setTexture(&buttonHover);
			no.setFillColor(Color::White);
			if(Mouse::isButtonPressed(Mouse::Left)) {
				reset();
				Sleep(100);
				return 0;
			}
		}
		else {
			no.setFillColor(Color::Black);
			confirmNotPlayGame.setTexture(&button);
		}	
	}
	return 1;
}
void Play::draw(RenderWindow &window) {
	window.draw(spriteBackground);
	if(initial == -1) {
		drawErrorGame(window);
		return;
	}
	if(!isPlayGame && !isEndGame)	drawLoadingGame(window);
    else if(isPlayGame) {
    	drawPlayGame(window);
    	if(isExist) {
    		window.draw(blurred_background);
    		window.draw(bulletin_board_rectangle);
    		window.draw(confirmEndGameText);
    		window.draw(confirmPlayGame);
			window.draw(confirmNotPlayGame);
			window.draw(yes);
			window.draw(no);	
		}
	}
	else	drawEndGame(window);
}
void Play::drawErrorGame(RenderWindow &window) {
	for(int i = 0; i < 4; i++)		window.draw(error[i]);
	window.draw(spriteArrow);
}
void Play::drawLoadingGame(RenderWindow &window) {
	if(percent <= 100) 		window.draw(textPercent);
	else {
		window.draw(ready);
		window.draw(confirmPlayGame);
		window.draw(confirmNotPlayGame);
		window.draw(yes);
		window.draw(no);
	}
}

void Play::drawPlayGame(RenderWindow &window) {
	window.draw(fill_character);
    window.draw(wordPlay);
    window.draw(confirmEndGame);
    window.draw(endGame);
    for(int i = 0; i < 3 - countGuess_of_sentences[positionSentences - 1]; i++) 	window.draw(spriteHeart[i]);
		
    if(isCorrect) {
        window.draw(inforWord);
        window.draw(spriteSpeakPlay);
        window.draw(scorePlayText);
	}
	
	if((isCorrect || countGuess_of_sentences[positionSentences - 1] == MAX_GUESS) && !isResetClock) {
		clock.restart();
		isResetClock = true;
	}
	
	if(isResetClock) {
		timeSeconds = clock.getElapsedTime();
		if(timeSeconds.asSeconds() > 3) {
			isResetClock = false;
			isCorrect = false;
			initial = 0;
			if(positionSentences == MAX_ITEMS) {
				isPlayGame = false;
				isEndGame= true;
			}	
		}
	}
    window.draw(spriteImageWordPlay);
}
void Play::drawEndGame(RenderWindow &window) {
	window.draw(spriteArrow);
	window.draw(congratulation);
    for(int i = 0; i < 6; i++) 		window.draw(sub[i]);
    for(int i = 0; i < positionSentences; i++) {
       	window.draw(eng[i]);
       	window.draw(type[i]);
       	window.draw(meaning[i]);
       	window.draw(spriteImages[i]);
       	window.draw(spriteSpeaks[i]);
       	window.draw(times[i]);
       	window.draw(score[i]);
	}
	window.draw(bulkhead);
	window.draw(totalScoreText);
	window.draw(totalScoreInt);
	window.draw(confirmContinueGame);
	window.draw(continueGame);
}

void Play::reset() {
	positionSentences = 0;
	percent = 0;
	initial = 0;
	totalScore = 0;
	number_of_correct_sentences = 0;
	for(int i = 0; i < MAX_ITEMS; i++) {
		countGuess_of_sentences[i] = 0;
		score_of_sentences[i] = 0;
	}
	isPlayGame = false;
	isEndGame = false;
	isCorrect = false;
}

