#include <iostream>
#include <string>
using namespace std;

int main(){
	bool choice = true;
	string choiceYN;
	while (choice){
		// math and strings... do it here :)
		
		
		
		
		cout << "do you want to keep going? [Y]yes / [N]no: ";
		cin >> choiceYN;
		
		if (choiceYN.compare("Y") == 0)
			choice = true;
		else if (choiceYN.compare("N") == 0)
			choice = false;
	}
	
	cout << "exiting..." << endl;
	
	
	
	return 0;