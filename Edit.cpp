#include "Edit.h"

EditDictionary::EditDictionary() {
	loadResource();
	// Head
	head.setFont(font[3]);
	head.setString("EDIT DICTIONARY");
	head.setPosition(270, 10);
	head.setCharacterSize(50);
	
	// Rectangle
	rectangle.setSize(Vector2f(750.f, 80.f));
	rectangle.setFillColor(Color(220,220,220));
	
	// marker
	marker.setSize(Vector2f(15.f, 5.f));
	marker.setPosition(320, 133);
	marker.setFillColor(Color::Black);
	
	for(int i = 0; i <= 6; i++) {
		eng[i].setCharacterSize(30);
		eng[i].setFont(font[2]);
		eng[i].setFillColor(Color::Black);
		eng[i].setPosition(50, 100*(i+2));
		type[i].setCharacterSize(30);
		type[i].setFont(font[2]);
		type[i].setFillColor(Color::Black);
		type[i].setPosition(320, 100*(i+2));
		meaning[i].setCharacterSize(30);
		meaning[i].setFont(font[2]);
		meaning[i].setFillColor(Color::Black);
		meaning[i].setPosition(500, 100*(i+2));
	}
}
EditDictionary::~EditDictionary() {
	
}

