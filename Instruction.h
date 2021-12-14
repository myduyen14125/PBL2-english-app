#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "Base.h"
class Instruction: public Base{
	private:
		Texture instructionImages[3];
		Sprite spriteInstructionImages[3];
		RectangleShape previous, next;
		Text previousText, nextText;
		int position = 0;
		Time timeSeconds;
		Clock clock;
		bool check = true;
	public: 
		Instruction();
		~Instruction();
		int handle(RenderWindow& window);
		void draw(RenderWindow& window);
};
#endif
