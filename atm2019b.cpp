#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class PNC {
private:
	int cents;

public:
	PNC(){
		cents = 100000; // equ. to $1,000
	}
	
	void menu(){
		int x;
		while(true){
			cout << "\n================ PNC Banking ================\n";
			cout << "Welcome, user :)" << endl;
			cout << "1 - withdraw"  << endl;
			cout << "2 - deposit" << endl;
			cout << "3 - check balance" << endl;
			cout << "enter your choice: ";
			cin >> x;
			
			if (x < 1 || x > 3)
				cout << "[ERROR] invalid entry >:(" << endl;
			else if (x == 1)
				withdraw();
			else if (x == 2)
				deposit();
			else if (x == 3)
				checkBal();
		}
	}
	
	void withdraw(){
		double withdraw;
		cout << "\n======== Withdraw ========\n";
		cout << "Current Balance: $" << cents/100 << "." << cents%100 << endl;
		cout << "Enter the amount (USD) that you want to withdraw: ";
		cin >> withdraw;
		if (withdraw > cents/100){
			cout << "[ERROR] you don't have enough money, fam T-T" << endl;
		}
		else{
			cout << "[SUCCESS] dispensing $" << withdraw << "..." << endl;
			cents -= int(withdraw*100);
		}
	}
	
	void deposit(){
		int choice;
		double deposit;
		cout << "\n======== Deposit ========\n";
		cout << "Current Balance: $" << cents/100 << "." << cents%100 << endl;
		cout << "1 - cash deposit (less than $100)" << endl;
		cout << "2 - check deposit (any amount)" << endl;
		cout << "enter deposit option: ";
		cin >> choice;
		
		if (choice == 1){
			cout << "Enter cash deposit (less than $100): ";
			cin >> deposit;
			if (deposit*100 > 10000){
				cout << "[ERROR] cash deposit amount is too large" << endl;
			}
			else{
				cout << "[SUCCESS] deposited $" << deposit << "..." << endl;
				cents += int(deposit*100);
				cout << "balance: $" << cents/100 << "." << cents%100 << endl;
			}
		}
		else if (choice == 2){
			cout << "Enter check deposit (any amount): ";
			cin >> deposit;
			
			cout << "[SUCCESS] deposited $" << deposit << "..." << endl;
			cents += int(deposit*100);
			cout << "balance: $" << cents/100 << "." << cents%100 << endl;
		}
		else
			cout << "[ERROR] invalid entry. going back to main menu..." << endl;
	}
	
	void checkBal(){
		cout << "\n======== Balance ========\n";
		cout << "Current Balance: $" << cents/100 << "." << cents%100 << endl << endl;
	}
};


int main(){
	PNC ethan;
	ethan.menu();
	return 0;
}





