#include "Play.h"


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
}
void Play::loadMusic() {
	correctMusic.openFromFile("Resource/Music/WinAnswer.wav");
	wrongMusic.openFromFile("Resource/Music/WrongAnswer.wav");
}
void Play::loadResource() {
	loadFont();
	loadTexture();
	loadMusic();
	setSprite();
}
Play::Play() {
	loadResource();
}
Play::~Play(){
}
void Play::runGame() {
	hashtable.randomWord(correctWord, type, meaning);
	correctWord[0] = correctWord[0] - 32;
	defectWord = correctWord;
	
	// Random vi tri trong -> _
	srand(time(NULL));
	int length = correctWord.length();
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
	wordPlay.setOrigin(rect.width/2, rect.height/2);
	wordPlay.setPosition(450, 100);
	
	fill = "Fill in the space: ";
	fill_in_word.setString(fill);
	fill_in_word.setFillColor(Color::White);
	fill_in_word.setFont(font);
	fill_in_word.setCharacterSize(40);
	fill_in_word.setPosition(200, 700);
	
	inforWord.setString(meaning + " (" + type +")");
	inforWord.setFont(font);
	inforWord.setCharacterSize(40);
	rect = inforWord.getLocalBounds();
	inforWord.setOrigin(rect.width/2, rect.height/2);
	inforWord.setPosition(450, 650);
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
		}
	}
    window.draw(spriteImageWord);
}







