#include <iostream>
#include <string>		// strings :)
using namespace std;

int main() {
	int x = 0; // 16 bits (2 bytes)
	long int y = 1; // 4 bytes
	long long int z = 1; // 8 bytes
	string realName = "";
	string nickName = "";
	string everything = "";

	cout << endl << endl << "======== Numbers and Strings :) ========" << endl << endl;
	cout << "gimme an int for fun: ";
	cin >> x; // number inputs

	cin.ignore(); // flush out the <ENTER> from the last cin
	cout << "gimme your real name: ";
	getline(cin, realName); // string inputs

	cout << "enter your nickname: ";
	getline(cin, nickName);

	everything = realName + '\n' + nickName;

	cout << "now, you typed: " << everything << endl << endl;
	cout << "What do you like to do?";

	return 0;
}