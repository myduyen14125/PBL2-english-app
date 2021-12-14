#ifndef FORM_H
#define FORM_H

#include "Base.h"
#include "Word.h"

class Form: public Base {
	private:
		RectangleShape form, row[3], rowConfirm, marker;
		Text text[4], confirm, title;
		Text wordText[3];
		string wordString[3];
		WordEng word;
		int positionInput;
		Time time;
		Clock clock;
	public:
		Form();
		~Form();
		
		void loadResource();
		WordEng getWord();
		
		void setTitle(string titleString, string confirmString);
		int handle(RenderWindow& window) {}
		int handle(RenderWindow &window, int keypressed, bool isKeyPressed);
		void draw(RenderWindow& window);
		
		void resetForm();
		void setPositionForm(float x, float y);
		float getPositionXForm();
		float getPositionYForm();
};
#endif



