#include"HashTable.h"

HashTable::HashTable() {
    for (int i = 0; i < hashGroups; i++) {
	    headTable[i] = nullptr;
	   	tailTable[i] = nullptr;
	   	countElements[i] = 0;
	}
	readFile();
}
HashTable::~HashTable() {
	
}
void HashTable::readFile() {
	ifstream FileIn;
<<<<<<< HEAD
    FileIn.open("F:\\PBL2-english-app\\Data\\data.txt", ios_base::in);
=======
    FileIn.open("E:\\PBL2-english-app\\data.txt", ios_base::in);
>>>>>>> 3732847387e0eb00eac0a413d2f1925eaea0c0bc
    if (FileIn.fail()) {
        cout << "Open file failed!" << endl;
    }
    WordEng word = new Word;
    string line;
    while (!FileIn.eof()) {
        getline(FileIn, line);
        if(line != "") {
        	word = formatWord(line);
			insertWord(word);
		}
    }
    FileIn.close();
}
void HashTable::updateFile() {
	ofstream FileOut;
<<<<<<< HEAD
	FileOut.open("F:\\PBL2-english-app\\Data\\data.txt", ios::out);
	WordEng run = new Word;
	for(int i = 0; i < hashGroups; i++) {
		if(headTable[i] != nullptr) {
			run = headTable[i];
			for(int j = 0; j < countElements[i]; j++) {
				FileOut<<run->getEnglish()<<"@"<<run->getType()<<"@"<<run->getMeaning()<<"@"<<endl;
           		run = run->getNext();
=======
	FileOut.open("E:\\PBL2-english-app\\data.txt", ios::out);
	while(i < hashGroups)
	{
		Word *run = table[i];
        while(run != nullptr) {
           	FileOut<<run->eng<<"@"<<run->type<<"@"<<run->meaning<<"@"<<endl;
           	run = run->right;
		}
		i++;
	}
	FileOut.close();
}
bool HashTable::isEmpty() const {
    if(wordCount == 0)	return true;
    else return false;
}

int HashTable::hashFunction(string eng) { 
    if (eng != "") {
        char x = eng[0];
        if ((x > 96) && (x < 123)) { //Ascii tu a-z
            return (int)x - 97;
        }
    }
    return -1;
}

void HashTable::insertWord(string eng, string type, string meaning) {
	Word* newWord = new Word;
	newWord->eng = eng;
	newWord->type = type;
	newWord->meaning = meaning;
	newWord->left = nullptr;
	newWord->right = nullptr;
    int key = hashFunction(newWord->eng);
    Word* run  = table[key];
    
    if(table[key] == nullptr) {
    	table[key] = newWord;
    	table[key]->left = nullptr;
    	table[key]->right = nullptr;
	}
	else if(newWord->eng < run->eng) {
		newWord->right = run;
		run->left = newWord;
		table[key] = newWord;
	}
	else {
		Word* temp;
		while(run->eng < newWord->eng) {
			if(run->right == nullptr)	break;
			run = run->right;
		}	
		if(run->eng < newWord->eng && run->right == nullptr) {
			run->right = newWord;
			newWord->left = run;
		}
		else {
			temp = run->left;
			newWord->right = run;
			newWord->left = temp;
			temp->right = newWord;
			run->left = newWord;
		}
	}
	countElements[key]++;
	wordCount++;
}
void HashTable::removeWord(string eng) {
    int key = hashFunction(eng);
    if(table[key] == nullptr)
    	cout<<"Khong ton tai word can xoa"<<endl;
    else {
    	Word* run  = table[key];
    	if(run->eng == eng) {
    		if(run->right == nullptr) 	run = nullptr;
			else	run = run->right;
			table[key] = run;
		}
		else {
			bool check = false;
			while(run != nullptr) {
				if(run->right == nullptr) {
					break;
				}
				if(run->right->eng == eng) {
					run->right = run->right->right;
					check = true;
					wordCount--;
					break;
				}
				run = run->right;
>>>>>>> 3732847387e0eb00eac0a413d2f1925eaea0c0bc
			}
		}
	}
	delete run;
	FileOut.close();
}
WordEng HashTable::formatWord(string line) {
	WordEng word = new Word;
	string eng, type, meaning;
	string s = "";
	int i = 0;
	while(line[i] != '@') {
        s += line[i];
        i++;
	}
	i++;
	eng = s;
	s = "";
	while(line[i] != '@') {
        s += line[i];
        i++;
	}
	i++;
	type = s;
	s = "";
	while(line[i] != '@') {
      	s += line[i];
       	i++;
	}
	meaning = s;
	word->setWord(eng, type, meaning);
	return word;
}

bool HashTable::isEmpty() {
    if(wordCount == 0)	return true;
    return false;
}

int HashTable::hashFunction(string eng) { 
    if (eng != "") {
        char x = eng[0];
        if ((x > 96) && (x < 123)) { //Ascii tu a-z
            return (int)x - 97;
        }
    }
    return -1;
}

int HashTable::findViewWord(WordEng word[], WordEng tempWord) {
	if(tempWord == nullptr) {
		return 0;
	}
	int countReadWord = 0;
	WordEng run = tempWord;
	int key = hashFunction(tempWord->getEnglish());
	for(int i = 0; i < 7; i++) {
		if(run == nullptr) {
			key++;
			if(key > 25)	break;
			run = headTable[key];
			i--;
		}
		else {
			word[i] = run;
			countReadWord++;
			run = run->getNext();
		}
	}
	for(int i = countReadWord; i < 7; i++) {
		word[i] = nullptr;
	}
	return countReadWord;
}
WordEng HashTable::findFirstWord() { 
	for(int i = 0; i < hashGroups; i++) {
		if(headTable[i] != nullptr) {
			return headTable[i];
		}
	}
}
WordEng HashTable::findWord(string eng) {
	if(eng == "") {
		return findFirstWord();
	}
	
	int key;
	WordEng run = new Word;
	key = hashFunction(eng);
	run = headTable[key];
	if(headTable[key] == nullptr) {
		while(headTable[key++] == nullptr) {
			if(key > 25) {
				return nullptr;
			}
		}
		return headTable[key-1];
	}
	else {
		while(run != nullptr && run->getEnglish() < eng) {
			run = run->getNext();
		}
		if(run == nullptr) {
			while(headTable[key++] == nullptr) {
				if(key > 25) {
					return nullptr;
				}
			}
			return headTable[key];
		}
		else return run;
	}
}
WordEng HashTable::findLeftWord(WordEng eng) {
	if(eng->getEnglish() == findFirstWord()->getEnglish()) {
		return findFirstWord();
	}
	
	if(eng->getPrev() == nullptr) {
		int key = hashFunction(eng->getEnglish());
		while(headTable[--key] == nullptr) {
			if(key < 0)		break;
		}
		return tailTable[key];
	}
	else {
		eng->getPrev();
	}
}
WordEng HashTable::findRightWord(WordEng eng) {
	WordEng tail = new Word;
	for(int i = hashGroups - 1; i >= 0; i--) {
		if(tailTable[i] != nullptr) {
			tail = headTable[i];
			break;
		}
	}
	if(eng->getEnglish() == tail->getEnglish()) {
		return tail;
	}
	
	if(eng->getNext() == nullptr) {
		int key = hashFunction(eng->getEnglish());
		while(headTable[++key] == nullptr) {
			if(key > 25)		break;
		}
		return headTable[key];
	}
	else {
		return eng->getNext();
	}
}
        
bool HashTable::insertWord(WordEng word) {
	int key = hashFunction(word->getEnglish());
	word->setKey(key);
	if(headTable[key] == nullptr) {
		headTable[key] = word;
		tailTable[key] = word;
		headTable[key]->setPrev(nullptr);
		tailTable[key]->setNext(nullptr);
	}
	else if(word->getEnglish() < headTable[key]->getEnglish()) {
		word->setNext(headTable[key]);
		word->setPrev(nullptr);
		headTable[key]->setPrev(word);
		headTable[key] = word;
	}
	else {
		WordEng run = headTable[key];
		while(run->getEnglish() < word->getEnglish()) {
			if(run->getNext() == nullptr) {
				tailTable[key]->setNext(word);
				word->setNext(nullptr);
				
				tailTable[key] = word;
				countElements[key]++;
				wordCount++;
				return true;
			}
			run = run->getNext();
		}
		if(run->getEnglish() == word->getEnglish())
			return false;	
		else {
			WordEng prev = run->getPrev();
			word->setNext(run);
			word->setPrev(prev);
		}
	}
	countElements[key]++;
	wordCount++;
	return true;
}
void HashTable::removeWord(WordEng word) {
    int key = hashFunction(word->getEnglish());
    WordEng head = headTable[key];
    WordEng tail = tailTable[key];
    if(head->getEnglish() == word->getEnglish()) {
    	if(head->getNext() == nullptr) {
    		headTable[key] = nullptr;
    		tailTable[key] = nullptr;
		}
		else {
			headTable[key] = headTable[key]->getNext();
			headTable[key]->setPrev(nullptr);
		}
	}
	else if(tail->getEnglish() == word->getEnglish()) {
		tail = tailTable[key];
		tailTable[key] = tailTable[key]->getPrev();
		tailTable[key]->setNext(nullptr);
		delete tail;
	}
	else {
		WordEng prev = word->getPrev();
		WordEng next = word->getNext();
		prev->setNext(next);
	}
	countElements[key]--;
	wordCount--;
}

void HashTable::editWord(WordEng oldWord, WordEng newWord) {
	removeWord(oldWord);
	insertWord(newWord);
}
 
int HashTable::getCountWord() {
	return wordCount;
}

WordEng HashTable::randomWord() const {
	srand(time(NULL));
	int indexTable = 0;
	do {
		indexTable = rand() % hashGroups;
	} while(countElements[indexTable] == 0);
	
	int indexWord = rand() % countElements[indexTable]; // 0 -> countElenmts - 1
	WordEng run = headTable[indexTable];
	for(int i = 0; i < indexWord; i++) {
		run = run->getNext();
	}
	return run;
}

void HashTable::printTable() {
	WordEng run = new Word;
    for (int i = 0; i < hashGroups; i++) {
		if(countElements[i] != 0){
			run = headTable[i];
			for(int j = 0; j < countElements[i]; j++) {
				cout<<setw(20)<<run->getEnglish()<<setw(15)<<run->getType()<<setw(20)<<run->getMeaning()<<endl;
           		run = run->getNext();
			}
		}
    }
    delete run;
}


