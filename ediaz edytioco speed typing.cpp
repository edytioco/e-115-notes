// Author: Emmanuel Diaz
// cite 1 - Ethan DyTioco
// I pledge my honor that I have abided by the Stevens Honor System

#include <ctime>
#include <conio.h> // for _getche()
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <windows.h>
using namespace std;

// TODO: class
//		- menu
//		- .txt file for writing prompts
//		- score board
class SpeedTyper{
private:


public:
	SpeedTyper(){}

	void menu(){
		int choice;
		while(true){
			cout << "\n================ Speed Typer ================\n\n";
			cout << "1 - normal test" << endl;
			cout << "2 - \"sight writing\" test" << endl;
			cout << "3 - scoreboard [coming soon]" << endl;
			cin >> choice;
			
			if (choice > 0 && choice < 3)
				test(choice);
			else if (choice == 3)
				scoreboard();
		}
		
	}
	
	void test(int x){
		char ch;
		string input = "", test, inputWord, testWord;
		clock_t c1, c2;
		double deltaSeconds, wpm, accuracy;
		int correctChar = 0, testSpace = 0, inputSpace = 0, wordCount = 0;
		
		test = "The quick brown fox jumped over the lazy dog. I like my dog, his name is Moose.";
		
		
		if (x == 1){		// normal
			cout << "\n";
			cout << test << endl;
			cout << "Type to begin. Press [ENTER] to finish:\n";
			ch = _getche();
			
			// at the first keystroke, start timer.
			if (ch >= 32 && ch <= 126)
				c1 = clock();
		}
		else if (x == 2){	// sight writing
			cout << "\n";
			cout << "3" << endl;
			Sleep(1000);
			cout << "2" << endl;
			Sleep(1000);
			cout << "1" << endl;
			Sleep(1000);
			cout << test << endl;
			cout << "Start typing now. Press [ENTER] to finish:\n";
			c1 = clock();
		}
		cin.ignore();
		getline(cin, input);
		
		// after getline, the user hits [ENTER]. stop timer.
		c2 = clock();
		deltaSeconds = double(c2 -c1)/CLOCKS_PER_SEC;
		
		
		// start comparing input to the test
		if (x == 1)
			input = ch + input;
		
		istringstream inputCheck(input);
		istringstream testCheck(test);
		
		while(testCheck >> testWord){
			wordCount++;
			inputCheck >> inputWord;
			for (int i = 0; i < testWord.length(); i++){
				if (inputWord[i] == testWord[i])
					correctChar++;
			}
		}
		
		for (int i = 0; i < test.length(); i++){
			if (test[i] == ' ')
				testSpace++;
			if (input[i] == ' ')
				inputSpace++;
		}
		
		wpm = (wordCount / deltaSeconds) * 60.0;
		
		accuracy = 100 * (double(correctChar) / (test.length() - testSpace) - abs(double(inputSpace - testSpace) / test.length()));
		
		cout << "\n\nYou typed:" << endl;
		cout << input << endl << endl;
		
		cout << "words typed:            " << wordCount << endl;
		cout << "time elpased (seconds): " << deltaSeconds << endl;
		cout << "words per minute:       " << wpm << endl;
		cout << "word accuracy:          " << accuracy << "%" << endl;
		
	}
	
	void scoreboard(){
		;
	}
};




int main(){
	SpeedTyper game;
	game.menu();
	return 0;
}




