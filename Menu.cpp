//#include <random>
//#include <cstdlib>
#include"Menu.h"

using namespace std;
using namespace sf;
void Menu::loadResource(){
	font[0].loadFromFile("Font/BungeeShade.ttf");
	font[1].loadFromFile("Font/MATURASC.ttf");
	font[2].loadFromFile("Font/timesbd.ttf");
	font[3].loadFromFile("Font/ALGER.ttf");
	
	// Background main menu
	background.loadFromFile("Image/backgroundMenu.jpg");
	spriteBackground.setTexture(background);
	
	// Button main menu
	button.loadFromFile("Image/Button.jpg");
	buttonHover.loadFromFile("Image/ButtonHover.jpg");
	
	// Background About
	backgroundAbout.loadFromFile("Image/backgroundAbout.jpg");
	spriteBackgroundAbout.setTexture(backgroundAbout);
	
	// About
	aboutImage.loadFromFile("Image/BangGo.png");
	spriteAbout.setTexture(aboutImage);
	
	// Arrow
	arrow.loadFromFile("Image/muiten.png");
	arrowHover.loadFromFile("Image/muitenhover.png");
	spriteArrow.setTexture(arrow);
	spriteArrow.setScale(0.1,0.1);
	spriteArrow.setPosition(5,5);
	// Logo
	logo.loadFromFile("Image/logo.png");
	spriteLogo.setTexture(logo);
	// Music
	music.openFromFile("Music/faded.wav");
}
Menu::Menu(float width, float height, Color color){
	loadResource();
	// Menu Game
	menu[0].setString("ToD English Game !");
	menu[0].setFont(font[0]);
	menu[0].setFillColor(Color::Black);
	menu[0].setCharacterSize(60);
	menu[0].setPosition(Vector2f(width/2-350, height/7-50));
	
	menu[1].setString("Play");
	menu[2].setString("View dictionary");
	menu[3].setString("Edit dictionary");
	menu[4].setString("Score");
	menu[5].setString("How to play?");
	menu[6].setString("About");
	menu[6].setPosition(90, 675);
	
	FloatRect rect;
	for(int i=1;i<7;i++){
		menu[i].setFont(font[1]);
		menu[i].setCharacterSize(40);
		menu[i].setFillColor(Color::Black);
		
		if(i != 6){
			rect = menu[i].getLocalBounds();
			menu[i].setOrigin(rect.width/2, rect.height/2);
			menu[i].setPosition(Vector2f(width/2, 150 + 90*i));
			
			rectangle[i].setSize(Vector2f(350.f, 60.f));
			rectangle[i].setTexture(&button);
			rectangle[i].setPosition(Vector2f(menu[i].getPosition().x-175, menu[i].getPosition().y-20));
		}
	}
	
	// BackGround Menu
	spriteBackground.setScale(1.25,1);
	
	// background About
	spriteBackgroundAbout.setScale(1.6,1.2);
	
	// Bang go about
	spriteAbout.setScale(0.25,0.25);
	spriteAbout.setPosition(0, 600);
	
	// Logo
	spriteLogo.setScale(0.2,0.2);
	spriteLogo.setPosition(350, 220);
	
	// About
	about[0].setString("TRUONG DAI HOC BACH KHOA");
	about[1].setString("KHOA CONG NGHE THONG TIN");
	about[2].setString("DE TAI: UNG DUNG HOC TU VUNG TIENG ANH");
	about[3].setString("Sinh vien thuc hien:");
	about[4].setString("NGUYEN TRAN MY DUYEN  - 102200017");
	about[5].setString("NGUYEN PHUOC DAI TOAN - 102200035");
	about[6].setString("Giang vien huong dan: LE THI MY HANH");
	
	about[0].setFont(font[3]);
	about[0].setFillColor(Color::Black);
	about[0].setCharacterSize(50);
	about[0].setPosition(Vector2f(width/2-340, height/7-50));
	for(int i=1;i<=6;i++){
		about[i].setFont(font[2]);
		about[i].setCharacterSize(35);
		about[i].setFillColor(Color::Black);
		rect = about[i].getLocalBounds();
		about[i].setOrigin(rect.width/2, rect.height/2);
		if(i==1){
			about[i].setPosition(Vector2f(width/2, 170));
		}
		else{
			about[i].setPosition(Vector2f(width/2, 270+85*i));
		}
	}
	
	music.play();
}
Menu::~Menu(){
	
}
void Menu::draw(RenderWindow &window){
	window.draw(spriteBackground);
    for(int i=0;i<6;i++){
    	window.draw(rectangle[i]);
		window.draw(menu[i]);
	}
	window.draw(spriteAbout);
	window.draw(menu[6]);
}
void Menu::drawAbout(RenderWindow &window){
	window.draw(spriteBackgroundAbout);
	window.draw(spriteLogo);
	window.draw(spriteArrow);
    int R, G, B;
    srand(time(NULL));
	for(int i=0;i<7;i++){
		if(i==4 || i==5){
			R = rand() % 255;
	    	G = rand() % 255;
	   		B = rand() % 255;
	   		about[i].setFillColor(Color ( R, G, B ));
		}
		window.draw(about[i]);
	}
}

