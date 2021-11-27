#include "Play.h"

<<<<<<< HEAD

void Play::loadFont() {
	font.loadFromFile("Resource/Font/timesbd.ttf");
}
void Play::loadTexture() {
	audio.loadFromFile("Resource/Image/Loa.png");
	audioHover.loadFromFile("Resource/Image/LoaHover.png");
}
void Play::setSprite() {
	spriteAudio.setTexture(audio);
	spriteAudio.setScale(0.03, 0.03);
	spriteAudio.setPosition(700, 500);
=======
void Play::loadFont() {
	font.loadFromFile("Resource/Font/timesbd.ttf");
	fontTiengAnh.loadFromFile("Resource/Font/TiengAnh.ttf");
}
void Play::loadTexture() {
	background.loadFromFile("Resource/Image/backgroundPlay.jpg");
	audio.loadFromFile("Resource/Image/Loa.png");
	audioHover.loadFromFile("Resource/Image/LoaHover.png");
	arrow.loadFromFile("Resource/Image/muiten.png");
	arrowHover.loadFromFile("Resource/Image/muitenHover.png");
	buttonContinueGame.loadFromFile("Resource/Image/Button.jpg");
	buttonContinueGameHover.loadFromFile("Resource/Image/ButtonHover.jpg");
}
void Play::setSprite() {
	spriteBackground.setTexture(background);
	
	spriteAudioPlay.setTexture(audio);
	spriteAudioPlay.setScale(0.03, 0.03);
	spriteAudioPlay.setPosition(700, 500);
	
	spriteArrow.setTexture(arrow);
	spriteArrow.setPosition(5, 5);
	spriteArrow.setScale(0.1, 0.1);
>>>>>>> master
}
void Play::loadMusic() {
	correctMusic.openFromFile("Resource/Music/WinAnswer.wav");
	wrongMusic.openFromFile("Resource/Music/WrongAnswer.wav");
}
<<<<<<< HEAD
=======
void Play::setTextResult() {
	loadingPercent.setFont(font);
	loadingPercent.setFillColor(Color::Red);
	loadingPercent.setPosition(250, 400);
	loadingPercent.setCharacterSize(50);
	
	congratulation.setFont(font);
	congratulation.setCharacterSize(35);
	
	for(int i = 0; i < MAX_NUMBERS_SENTENCES; i++) {
		eng[i].setFont(fontTiengAnh);
		eng[i].setCharacterSize(25);
		eng[i].setPosition(33, 190 + 80*i);
		eng[i].setFillColor(Color::Black);
		
		type[i].setFont(fontTiengAnh);
		type[i].setCharacterSize(25);
		type[i].setPosition(255, 190 + 80*i);
		type[i].setFillColor(Color::Black);
		
		meaning[i].setFont(fontTiengAnh);
		meaning[i].setCharacterSize(25);
		meaning[i].setPosition(370 , 190 + 80*i);
		meaning[i].setFillColor(Color::Black);
		
		times[i].setFont(fontTiengAnh);
		times[i].setCharacterSize(25);
		times[i].setPosition(710, 190 + 80*i);
		times[i].setFillColor(Color(0,128,0));
		
		score[i].setFont(fontTiengAnh);
		score[i].setCharacterSize(25);
		score[i].setPosition(820, 190 + 80*i);
		score[i].setFillColor(Color::Red);
		
		spriteAudioResult[i].setTexture(audio);
		spriteAudioResult[i].setScale(0.02, 0.02);
		spriteAudioResult[i].setPosition(650, 190 + 80*i);
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
		sub[i].setFont(font);
		sub[i].setCharacterSize(30);
		sub[i].setFillColor(Color(42, 0, 162));
	}
	bulkhead.setString("------------------------------------------------------------------------------");
	bulkhead.setPosition(20, 720);
	bulkhead.setFont(font);
	bulkhead.setFillColor(Color(0,128,0));
	
	textTotalScore.setString("Total Score");
	textTotalScore.setFont(fontTiengAnh);
	textTotalScore.setCharacterSize(25);
	textTotalScore.setFillColor(Color::Red);
	textTotalScore.setPosition(25, 760);
	
	totalScore.setFont(fontTiengAnh);
	totalScore.setCharacterSize(25);
	totalScore.setFillColor(Color::Red);
	totalScore.setPosition(808, 760);
	
	continueGame.setString("Play continue");
	continueGame.setFont(font);
	continueGame.setCharacterSize(25);
	continueGame.setFillColor(Color::Black);
	continueGame.setPosition(600, 820);
	rectangle.setSize(Vector2f(180.f, 50.f));
	rectangle.setTexture(&buttonContinueGame);
	rectangle.setPosition(Vector2f(continueGame.getPosition().x-15, continueGame.getPosition().y-10));
}
>>>>>>> master
void Play::loadResource() {
	loadFont();
	loadTexture();
	loadMusic();
	setSprite();
}
Play::Play() {
	loadResource();
<<<<<<< HEAD
}
Play::~Play(){
}
void Play::runGame() {
	hashtable.randomWord(correctWord, type, meaning);
	correctWord[0] = correctWord[0] - 32;
=======
	setTextResult();
}

Play::~Play(){
}
void Play::runGame() {
	hashtable.randomWord(correctWord, typePlay, meaningPlay);
	if(correctWord[0] >= 'a' && correctWord[0] <= 'z')	correctWord[0] = correctWord[0] - 32;
>>>>>>> master
	defectWord = correctWord;
	
	// Random vi tri trong -> _
	srand(time(NULL));
	int length = correctWord.length();
<<<<<<< HEAD
	random_index = rand() % length;
	defectWord[random_index] = '_';
	
	// load imageWord, musicWord
	imageWord.loadFromFile("Resource/ImageWord/" + correctWord + ".jpg");
	spriteImageWord.setTexture(imageWord);
	spriteImageWord.setPosition(275, 200);
	musicWord.openFromFile("Resource/MusicWord/" + correctWord + ".wav");
	
	wordPlay.setString(defectWord);
	wordPlay.setFillColor(Color::White);
	wordPlay.setFont(font);
	wordPlay.setCharacterSize(80);
	FloatRect rect = wordPlay.getLocalBounds();
=======
	do {
		random_index = rand() % length;
	} while(defectWord[random_index] == ' ');
	defectWord[random_index] = '_';
	
	// load imageWord, musicWord
	imageWordPlay.loadFromFile("Resource/ImageWord/" + correctWord + ".jpg");
	spriteImageWordPlay.setTexture(imageWordPlay);
	spriteImageWordPlay.setPosition(275, 200);
	
	wordPlay.setString(defectWord);
	wordPlay.setFillColor(Color::Black);
	wordPlay.setFont(font);
	wordPlay.setCharacterSize(80);
	rect = wordPlay.getLocalBounds();
>>>>>>> master
	wordPlay.setOrigin(rect.width/2, rect.height/2);
	wordPlay.setPosition(450, 100);
	
	fill = "Fill in the space: ";
<<<<<<< HEAD
	fill_in_word.setString(fill);
	fill_in_word.setFillColor(Color::White);
	fill_in_word.setFont(font);
	fill_in_word.setCharacterSize(40);
	fill_in_word.setPosition(200, 700);
	
	inforWord.setString(meaning + " (" + type +")");
=======
	fill_character.setString(fill);
	fill_character.setFillColor(Color::Black);
	fill_character.setFont(font);
	fill_character.setCharacterSize(40);
	fill_character.setPosition(200, 700);
	
	inforWord.setString(meaningPlay + " (" + typePlay +")");
>>>>>>> master
	inforWord.setFont(font);
	inforWord.setCharacterSize(40);
	rect = inforWord.getLocalBounds();
	inforWord.setOrigin(rect.width/2, rect.height/2);
	inforWord.setPosition(450, 650);
<<<<<<< HEAD
	inforWord.setFillColor(Color::Green);
	
	// Music
	musicWord.openFromFile("Resource/MusicWord/" + correctWord + ".wav");
}
int Play::handlePlay(RenderWindow &window, int keypressed, bool isKeyPressed) {
	if(initialization == 0) {
		runGame();
		initialization = 1;
	}
	if(isKeyPressed && !check && countGuess < 3) {
		if(keypressed >= 0 && keypressed <= 25) {
			if(random_index == 0)	defectWord[random_index] = keyboard[keypressed] - 32;
			else defectWord[random_index] = keyboard[keypressed];
			fill = "Fill in the space: ";
			fill += keyboard[keypressed];
			fill_in_word.setString(fill);
			wordPlay.setString(defectWord);
			countGuess++;
		}
		else {
			fill = "Fill in the space: ";
			defectWord[random_index] = '_';
			fill_in_word.setString(fill);
			wordPlay.setString(defectWord);
			wordPlay.setFillColor(Color::White);
			if(keypressed == 59) {
				return 1;
			}
		}
		if(defectWord != correctWord){
			wordPlay.setFillColor(Color::Red);
			wrongMusic.play();
		}
		else {
			check = true;
		   	wordPlay.setFillColor(Color::Green);
		   	correctMusic.play();
		    musicWord.play();
		    return 1;
		}		
	}
	if(spriteAudio.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y) && check) {
        spriteAudio.setTexture(audioHover);
        if(Mouse::isButtonPressed(Mouse::Left)) {
        	musicWord.play();
		}		
	}
	else spriteAudio.setTexture(audio);	
	return 1;
}
void Play::drawPlay(RenderWindow &window) {
    window.draw(fill_in_word);
    window.draw(wordPlay);
    if(check) {
        window.draw(inforWord);
        window.draw(spriteAudio);
	}
	if(check && !resetClock || countGuess == 3 && !resetClock) {
=======
	inforWord.setFillColor(Color(0, 128, 0));
	
	// Set resource result
	eng[number_of_sentences].setString(correctWord);
	type[number_of_sentences].setString(typePlay);
	meaning[number_of_sentences].setString(meaningPlay);
	musicWord[number_of_sentences].openFromFile("Resource/MusicWord/" + correctWord + ".wav");
	imageWordResult[number_of_sentences].loadFromFile("Resource/ImageWord/" + correctWord + ".jpg");
	spriteImageWordResult[number_of_sentences].setTexture(imageWordResult[number_of_sentences]);
	spriteImageWordResult[number_of_sentences].setPosition(570, 170 + 80 * number_of_sentences);
	spriteImageWordResult[number_of_sentences].setScale(0.17, 0.17);
}
int Play::handlePlay(RenderWindow &window, int keypressed, bool isKeyPressed) {
	if(playGame) {
		if(initialization == 0 && number_of_sentences < MAX_NUMBERS_SENTENCES) {
			runGame();
			initialization = 1;
			number_of_sentences++;
		}
		if(isKeyPressed && !check && count_guess_of_sentences[number_of_sentences - 1] < MAX_GUESS_WORD) {
			if(keypressed >= 0 && keypressed <= 25) {
				if(random_index == 0)	defectWord[random_index] = keyboard[keypressed] - 32;
				else defectWord[random_index] = keyboard[keypressed];
				fill = "Fill in the space: ";
				fill += keyboard[keypressed];
				fill_character.setString(fill);
				wordPlay.setString(defectWord);
				count_guess_of_sentences[number_of_sentences - 1]++;
			}
			else {
				fill = "Fill in the space: ";
				defectWord[random_index] = '_';
				fill_character.setString(fill);
				wordPlay.setString(defectWord);
				wordPlay.setFillColor(Color::Black);
				if(keypressed == 59) {
					return 1;
				}
			}
			if(defectWord != correctWord){
				wordPlay.setFillColor(Color::Red);
				wrongMusic.play();
				srand(time(NULL));
				if(count_guess_of_sentences[number_of_sentences - 1] == MAX_GUESS_WORD) {
					times[number_of_sentences - 1].setString(to_string(MAX_GUESS_WORD) + "/3");
					times[number_of_sentences - 1].setFillColor(Color::Red);
					score_of_sentences[number_of_sentences - 1] = rand() % 21;
					score[number_of_sentences - 1].setString(to_string(score_of_sentences[number_of_sentences - 1]));
					totalScoreInt += score_of_sentences[number_of_sentences - 1];
				}
			}
			else {
				check = true;
			   	wordPlay.setFillColor(Color(0,128,0));
			   	correctMusic.play();
			   	times[number_of_sentences - 1].setString(to_string(count_guess_of_sentences[number_of_sentences - 1]) + "/3");
			   	srand(time(NULL));
				if(count_guess_of_sentences[number_of_sentences - 1] == 1) {
					score_of_sentences[number_of_sentences - 1] = rand() % 20 + 81;
				}
				else if((count_guess_of_sentences[number_of_sentences - 1] == 2)) {
					score_of_sentences[number_of_sentences - 1] = rand() % 40 + 51;
				}
				else {
					score_of_sentences[number_of_sentences - 1] = rand() % 60 + 21;
				}
				score[number_of_sentences - 1].setString(to_string(score_of_sentences[number_of_sentences - 1]));
				totalScoreInt += score_of_sentences[number_of_sentences - 1];
			    musicWord[number_of_sentences - 1].play();
			    number_of_correct_sentences++;
			    return 1;
			}		
		}
		if(spriteAudioPlay.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y) && check) {
	        spriteAudioPlay.setTexture(audioHover);
	        if(Mouse::isButtonPressed(Mouse::Left)) {
	        	musicWord[number_of_sentences - 1].play();
			}		
		}
		else spriteAudioPlay.setTexture(audio);	
	}
	else if(endGame){
		totalScore.setString(to_string(totalScoreInt));
		if(number_of_correct_sentences >=4) {
			congratulation.setString("Congratulations! You answered correctly "+ to_string(number_of_correct_sentences)+"/7 words!");
			congratulation.setFillColor(Color(0, 128, 0));
		}
		else {
			congratulation.setString("Try your best! You answered correctly "+ to_string(number_of_correct_sentences)+"/7 words!");
			congratulation.setFillColor(Color::Red);
		}
		rect = congratulation.getLocalBounds();
		congratulation.setOrigin(rect.width/2, rect.height/2);
		congratulation.setPosition(450, 60);
		if(rectangle.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y)){
			rectangle.setTexture(&buttonContinueGameHover);
			continueGame.setFillColor(Color::White);
			if(Mouse::isButtonPressed(Mouse::Left)) {
				number_of_sentences = 0;
				initialization = 0;
				percent = 0;
				check = false;
				playGame = false;
				endGame = false;
				return 1;
			}
		}
		else {
			rectangle.setTexture(&buttonContinueGame);
			continueGame.setFillColor(Color::Black);
		}
		if(Mouse::getPosition(window).x<=77 && Mouse::getPosition(window).y<=55) {
			spriteArrow.setTexture(arrowHover);
			if(Mouse::isButtonPressed(Mouse::Left))
			{
				return 0;
				spriteArrow.setTexture(arrow);
			}
		}
		else {
			spriteArrow.setTexture(arrow);
		}
		for(int i = 0; i < 7; i++) {
			if(spriteAudioResult[i].getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y)){
				spriteAudioResult[i].setTexture(audioHover);
				if(Mouse::isButtonPressed(Mouse::Left)) {
					musicWord[i].play();
				}
			}
			else 	spriteAudioResult[i].setTexture(audio);
		}
	}
	return 1;
}
void Play::draw(RenderWindow &window) {
    if(!playGame && !endGame)	drawLoadingGame(window);
    else if(playGame){
    	drawPlayGame(window);
	}
	else {
		drawEndGame(window);
	}
}
void Play::drawLoadingGame(RenderWindow &window) {
	if(percent <= 100){
		textPercent = "Loading game: " + to_string(percent);
		textPercent += " %";
		loadingPercent.setString(textPercent);
	}
	if(percent <= 100) { 
		window.draw(loadingPercent);
		Sleep(30);
		percent++;
		if(percent == 101)	playGame = true;
	}
}
void Play::drawPlayGame(RenderWindow &window) {
	window.draw(spriteBackground);
	window.draw(fill_character);
    window.draw(wordPlay);
    if(check) {
        window.draw(inforWord);
        window.draw(spriteAudioPlay);
	}
	if((check || count_guess_of_sentences[number_of_sentences - 1] == MAX_GUESS_WORD) && !resetClock) {
>>>>>>> master
		clock.restart();
		resetClock = true;
	}
	if(resetClock) {
		timeSeconds = clock.getElapsedTime();
		if(timeSeconds.asSeconds() > 3) {
			resetClock = false;
			check = false;
			countGuess = 0;
			initialization = 0;
<<<<<<< HEAD
		}
	}
    window.draw(spriteImageWord);
=======
			if(number_of_sentences == MAX_NUMBERS_SENTENCES) {
				playGame = false;
				endGame= true;
			}	
		}
	}
    window.draw(spriteImageWordPlay);
}
void Play::drawEndGame(RenderWindow &window) {
	window.draw(spriteBackground);
	window.draw(spriteArrow);
	window.draw(congratulation);
    for(int i = 0; i < 6; i++) {
    	window.draw(sub[i]);
	}
    for(int i = 0; i < MAX_NUMBERS_SENTENCES; i++) {
       	window.draw(eng[i]);
       	window.draw(type[i]);
       	window.draw(meaning[i]);
       	window.draw(spriteImageWordResult[i]);
       	window.draw(times[i]);
       	window.draw(score[i]);
       	window.draw(spriteAudioResult[i]);
	}
	window.draw(bulkhead);
	window.draw(textTotalScore);
	window.draw(totalScore);
	window.draw(rectangle);
	window.draw(continueGame);
>>>>>>> master
}







