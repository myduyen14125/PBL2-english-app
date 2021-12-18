#include "Edit.h" 

Edit::Edit() {
	oldWord = new Word;
	newWord = new Word;
	buttonAdd.setSize(Vector2f(160.f, 50.f));
	buttonAdd.setTexture(&button);
	buttonAdd.setPosition(700, 100);
	
	textAdd.setString("Add Word");
	textAdd.setFillColor(Color::Black);
	textAdd.setFont(font[2]);
	rect = textAdd.getLocalBounds();
	textAdd.setOrigin(rect.width/2, rect.height/2);
	rect = buttonAdd.getLocalBounds();
	textAdd.setPosition(buttonAdd.getPosition().x + rect.width/2, buttonAdd.getPosition().y + rect.height/2 - 5);
	
	notification.setFont(font[2]);
	notification.setString("");
	notification.setCharacterSize(35);
	
	
	for(int i = 0; i < 3; i++) {
		newWordText[i].setString("");
		newWordText[i].setFont(font[4]);
		newWordText[i].setCharacterSize(30);
		newWordText[i].setString("");
		oldWordText[i].setFont(font[4]);
		oldWordText[i].setCharacterSize(30);
		oldWordText[i].setFillColor(Color::Black);
		oldWordText[i].setPosition(100 + 170 * i, 130);
	}
	spriteImageNewWord.setScale(0.25, 0.25);
	spriteSpeakNewWord.setTexture(speak);
	spriteSpeakNewWord.setScale(0.02, 0.02);
	
	spriteImageOldWord.setScale(0.25, 0.25);
	spriteImageOldWord.setPosition(750, 110);
	spriteSpeakOldWord.setTexture(speak);
	spriteSpeakOldWord.setScale(0.02, 0.02);
	spriteSpeakOldWord.setPosition(650, 130);
	
	confirmDeleteWordText.setString("Do you want to delete?");
	confirmDeleteWordText.setFont(font[2]);
	confirmDeleteWordText.setFillColor(Color::Black);
	confirmDeleteWordText.setCharacterSize(50);
	confirmDeleteWordText.setPosition(450, 350);
	rect = confirmDeleteWordText.getLocalBounds();
	confirmDeleteWordText.setOrigin(rect.width/2, rect.height/2);
	
	blurred_background.setSize(Vector2f(900.f, 900.f));
	blurred_background.setFillColor(Color(0, 0, 0, 90));
	
	bulletin_board_image.loadFromFile("F:\\Project\\Resource\\Image\\Note.png");
	bulletin_board_rectangle.setSize(Vector2f(900.f, 500.f));
	bulletin_board_rectangle.setTexture(&bulletin_board_image);
	bulletin_board_rectangle.setFillColor(Color::White);
	bulletin_board_rectangle.setPosition(5, 170);
	
	confirmDeleteWord.setSize(Vector2f(100.f, 50.f));
	confirmDeleteWord.setTexture(&button);
	confirmDeleteWord.setPosition(500, 450);
	
	confirmNotDeleteWord.setSize(Vector2f(100.f, 50.f));
	confirmNotDeleteWord.setTexture(&button);
	confirmNotDeleteWord.setPosition(300, 450);
	
	yes.setString("Yes");
	yes.setFont(font[2]);
	yes.setFillColor(Color::Black);
	yes.setCharacterSize(40);
	rect = confirmDeleteWord.getLocalBounds();
	yes.setPosition(confirmDeleteWord.getPosition().x + rect.width/2, confirmDeleteWord.getPosition().y + rect.height/2 - 10);
	rect = yes.getLocalBounds();
	yes.setOrigin(rect.width/2, rect.height/2);
	
	no.setString("No");
	no.setFont(font[2]);
	no.setFillColor(Color::Black);
	no.setCharacterSize(40);
	rect = confirmNotDeleteWord.getLocalBounds();
	no.setPosition(confirmNotDeleteWord.getPosition().x + rect.width/2, confirmNotDeleteWord.getPosition().y + rect.height/2 - 10);
	rect = no.getLocalBounds();
	no.setOrigin(rect.width/2, rect.height/2);
	
}

Edit::~Edit() {
	
}

int Edit::handle(RenderWindow &window, int keypressed, bool isKeyPressed, HashTable &table) {
	view.setTitle("EDIT DICTIONARY");
	if(isKeyPressed) {
		if(keypressed == Keyboard::Return) { // edit Word
			isView = false;
			isAddWord = false;
			oldWord = view.getWord();
			oldWordText[0].setString(oldWord->getEnglish());
			oldWordText[1].setString(oldWord->getType());
			oldWordText[2].setString(oldWord->getMeaning());
			spriteImageOldWord.setTexture(oldWord->getImage());
			form.setTitle("Edition Word", "Edit Word");
			form.setPositionForm(200, 200);
		}
		else if(keypressed == Keyboard::Delete) {
			oldWord = view.getWord();
			if(table.getCountWord() == 0) { // delete Word
				return 3;
			}
			isDeleteWord = true;
		}
	}
	if(buttonAdd.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y)) {
		buttonAdd.setTexture(&buttonHover);
		textAdd.setFillColor(Color::White);
		if(Mouse::isButtonPressed(Mouse::Left)) {
			isView = false;
			isAddWord = true;
			form.setTitle("Addition Word", "Add Word");
			form.setPositionForm(200, 150);
		}
	}
	else {
		buttonAdd.setTexture(&button);
		textAdd.setFillColor(Color::Black);
	}
	

	if(isView) {
		if(isDeleteWord) {
			if(confirmDeleteWord.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y)) {
				confirmDeleteWord.setTexture(&buttonHover);
				yes.setFillColor(Color::White);
				if(Mouse::isButtonPressed(Mouse::Left)) {
					table.removeWord(oldWord);
					table.updateFile();
					if(oldWord->getEnglish() == view.getFirstWordCurrent()->getEnglish()) {
						view.setFirstWordCurrent(table);
					}
					isDeleteWord = false;
				}
			}
			else {
				yes.setFillColor(Color::Black);
				confirmDeleteWord.setTexture(&button);
			}
			
			if(confirmNotDeleteWord.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y)) {
				confirmNotDeleteWord.setTexture(&buttonHover);
				no.setFillColor(Color::White);
				if(Mouse::isButtonPressed(Mouse::Left)) {
					isDeleteWord = false;
				}
			}
			else {
				no.setFillColor(Color::Black);
				confirmNotDeleteWord.setTexture(&button);
			}
			
		}
		else if(view.handle(window, keypressed, isKeyPressed, table) == 0) {
			isAddWord = false;
			isView = true;
			newWord = new Word;
			oldWord = new Word;
			view.setTitle("VIEW DICTIONARY");
			return 0;
		}
	}
	else {
		checkForm = form.handle(window, keypressed, isKeyPressed);
		if(!isAddWord && table.getCountWord() == 0) {
			isView = true;
			return 3;
		}
		if(checkForm == 0) {
			notification.setString("");
			newWord = new Word;
			oldWord = new Word;
			for(int i = 0; i < 3; i++) {
				newWordText[i].setString("");
				oldWordText[i].setString("");
			}
			isView = true;
			isNotification = false;
			form.resetForm();
			Sleep(150);
		}
		else if(checkForm == 1) {
			isNotification = true;
			newWord = form.getWord();
			string type = newWord->getType();
			if(type[0] >= 'a' && type[0] <= 'z')	type[0] -= 32;
			string meaning = newWord->getMeaning();
			if(meaning[0] >= 'a' && meaning[0] <= 'z')	meaning[0] -= 32;
			newWord->setWord(newWord->getEnglish(), type, meaning);
			if(isAddWord) 		setFormAdd(table);
			else {
				if(table.getCountWord() == 0)	return 3;
				string temp;
				oldWordText[0].setString(oldWord->getEnglish());
				oldWordText[1].setString(oldWord->getType());
				oldWordText[2].setString(oldWord->getMeaning());
				spriteImageOldWord.setTexture(oldWord->getImage());
				
				setFormEdit(table);
			}

			newWordText[0].setString(newWord->getEnglish());
			newWordText[1].setString(newWord->getType());
			newWordText[2].setString(newWord->getMeaning());
			
			Sleep(100);
		}
	}
	return 3;
}
void Edit::setFormAdd(HashTable &table) {
	if(table.insertWord(newWord)) {
		notification.setString("Addition word is successfull");
		form.resetForm();
		notification.setFillColor(Color(0, 128, 0));
		for(int i = 0; i < 3; i++) {
			newWordText[i].setFillColor(Color(0, 128, 0));	
			newWordText[i].setPosition(100 + 170 * i, form.getPositionYForm() + 620);
		} 
		if(view.getFirstWordCurrent() == nullptr) {
			view.setFirstWordCurrent(table);
		}			
		else if(newWord->getEnglish() < view.getFirstWordCurrent()->getEnglish()) {
			view.setFirstWordCurrent(table);
		}
		table.updateFile();
	}
	else{
		notification.setString("Addition word is failure. Word already exist");
		notification.setFillColor(Color::Red);
		newWord = table.findWord(newWord->getEnglish());
		for(int i = 0; i < 3; i++) {
			newWordText[i].setPosition(100 + 170 * i, form.getPositionYForm() + 620);
			newWordText[i].setFillColor(Color::Red);
		} 		
	} 	
	rect = notification.getLocalBounds();
	notification.setOrigin(rect.width/2, rect.height/2);
	notification.setPosition(450, form.getPositionYForm() + 550);
	
	spriteImageNewWord.setTexture(newWord->getImage());
	spriteImageNewWord.setPosition(750, form.getPositionYForm() + 595);
	spriteSpeakNewWord.setPosition(650, form.getPositionYForm() + 620);
}
void Edit::setFormEdit(HashTable &table) {
	table.editWord(oldWord, newWord);
	if(oldWord == view.getFirstWordCurrent())
		view.setFirstWordCurrent(table);
	notification.setString("Edition word is successfull");
	form.resetForm();
	notification.setFillColor(Color(0, 128, 0));
	for(int i = 0; i < 3; i++) {
		newWordText[i].setFillColor(Color(0, 128, 0));	
		newWordText[i].setPosition(100 + 170 * i, form.getPositionYForm() + 620);
	} 			
	if(newWord->getEnglish() < view.getFirstWordCurrent()->getEnglish()) {
		view.setFirstWordCurrent(table);
	}
	
	rect = notification.getLocalBounds();
	notification.setOrigin(rect.width/2, rect.height/2);
	notification.setPosition(450, form.getPositionYForm() + 550);
	
	spriteImageNewWord.setTexture(newWord->getImage());
	spriteImageNewWord.setPosition(750, form.getPositionYForm() + 595);
	spriteSpeakNewWord.setPosition(650, form.getPositionYForm() + 620);
	
	oldWord = newWord;
}
void Edit::draw(RenderWindow &window) {
	if(isView) {
		view.draw(window);
		window.draw(buttonAdd);
		window.draw(textAdd);
		if(isDeleteWord) {
			window.draw(blurred_background);
    		window.draw(bulletin_board_rectangle);
    		window.draw(confirmDeleteWordText);
    		window.draw(confirmDeleteWord);
			window.draw(confirmNotDeleteWord);
			window.draw(yes);
			window.draw(no);	
		}
	}
	else {
		form.draw(window);
		window.draw(notification);
		if(isAddWord && isNotification) {
			for(int i = 0; i < 3; i++) {
				window.draw(newWordText[i]);
			}
			window.draw(spriteImageNewWord);
			window.draw(spriteSpeakNewWord);
			if(spriteSpeakNewWord.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y)) {
				spriteSpeakNewWord.setTexture(speakHover);
				if(Mouse::isButtonPressed(Mouse::Left))
					newWord->playMusic();
			}
			else spriteSpeakNewWord.setTexture(speak);
		}
		if(!isAddWord) {
			window.draw(spriteImageOldWord);
			window.draw(spriteSpeakOldWord);
			for(int i = 0; i < 3; i++) {
				window.draw(oldWordText[i]);
				window.draw(newWordText[i]);
			}
			if(isNotification == 1) {
				window.draw(spriteImageNewWord);
				window.draw(spriteSpeakNewWord);
				if(spriteSpeakNewWord.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y)) {
					spriteSpeakNewWord.setTexture(speakHover);
					if(Mouse::isButtonPressed(Mouse::Left))		newWord->playMusic();
				}
				else spriteSpeakNewWord.setTexture(speak);
			}
			
			if(spriteSpeakOldWord.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y)) {
				spriteSpeakOldWord.setTexture(speakHover);
				if(Mouse::isButtonPressed(Mouse::Left))		oldWord->playMusic();
			}
			else spriteSpeakOldWord.setTexture(speak);
		}
	}
}
