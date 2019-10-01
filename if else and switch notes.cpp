// author: Ethan DyTioco
// cite: Mark Freeman's general ideas
//
// I pledge my honor that I have abided by the Stevens Honor System

#include<iostream>
#include<string>
using namespace std;

int main() {
#if 0
	string s1 = "meme ";
	string s2 = "machine.";
	string combo = s1 + s2;		// IS string concat

	cout << s1 + s2 << endl;	// IS string concat
	cout << s1 << s2 << endl;	// NOT string concat
#endif

	int choice = 0;		// choice IS zero
	cout << "you have a choice between 1 and 3. enter your choice: ";
	cin >> choice;

	// a == b
	// a != b
	// a < b
	// a <= b
	// a > b
	// a >= b

	// (a > b) && (a < c) AND
	// (a > b) || (a < c) OR


	// the compiler runs this sequentially.
	if (choice == 1) {	// is choice zero? (true or false)
		cout << "well done my guy" << endl;
	}
	else if (choice == 2) {
		cout << "o b e d i e n c e   i s   a   v i r t u e" << endl;
	}
	else if (choice == 3){
		cout << "rolling high, I see" << endl;
	}
	else {
		cout << "my guy why don't you follow the rules >:(" << endl;
	}

	// switch cases
	// generates a tree form to store this condition (more memory, but it's faster!)
	switch (choice) {
		case 1: // if (choice == 1)
			cout << "you're number one :)" << endl;
			cout << "keep up the good work!";
			break;
		case 2: // else if (choice == 2)
			cout << "two stuff" << endl;
			cout << "yeet" << endl;
			break;
		default:
			cout << "my guy why don't you follow the rules >:(" << endl;
			break;
	}



	return 0; // Unix convention
}