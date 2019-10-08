#include <iostream>
#include <string>
using namespace std;

int main() {
	string key = "yeet";
	string ans = "";
	int a = 2, b = 3;

	// ans == "yeet"
	while (ans.compare("yeet") != 0) {
		cout << "yoinks :)" << endl;
		cout << "say yeet if you want to exit: ";
		getline(cin, ans);
	}

	int hwSum = 0, hwAvg, input;

	// for (counter init; conditional; increment)
	// for ("who is counting"; "what is it counting to"; "how is it counting up")
	for (int i = 0; i < 4; i++) {
		cout << "enter your homework (1 of 4): ";
		cin >> input;
		hwSum += input;
	}

	hwAvg = hwSum / 4;
	cout << "homework avg grade: " << hwAvg << endl;

	return 0; // Unix convention
}