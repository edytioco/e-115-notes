// author: Ethan DyTioco
// homework 7: vending machine demo
// I pledge my honor that I have abided by the Stevens Honor System :)

#include <iostream>
#include <string>
#include <unordered_map>
#include <stdlib.h>

using namespace std;
// should be able to select an item from a simple menu
// let the user enter a dollar amount
// print success message + correct change, OR say insufficient funds, OR say out of stock + refund

class VendingMachine{
private:
	// string = name, int = how many available
	unordered_map<string, uint32_t> stock;
public:
	VendingMachine(){ // start us off with a default amount of drinks
		stock["Sprite Cranberry"] = {3};
		stock["Nuka Cola"] = {3};
		stock["Sunset Sarsaparilla"] = {3};
		stock["Liquid Uranium"] = {3};
	}
	
	void start(){
		int choice;
		while (true){
			cout << "\n======== Ethan's black market vending machine ========\n";
			cout << "1 - sprite cranberry ...................." << stock.at("Sprite Cranberry") << " remaining" << endl;
			cout << "2 - nuka cola (+2 rads) ................." << stock.at("Nuka Cola") << " remaining" << endl;
			cout << "3 - sunset sarsaparilla (+2 rads) ......." << stock.at("Sunset Sarsaparilla") << " remaining" << endl;
			cout << "4 - liquid uranium (brewed in Prypiat) .." << stock.at("Liquid Uranium") << " remaining" << endl;
			cout << "drink choice: ";
			cin >> choice;
			drinkSelect(choice);
		}
	}
	
	void drinkSelect (int drink){
		switch(drink){
			case -1:
				maintenance();
				break;
			case 1:
				sprite();
				break;
			case 2:
				nukaCola();
				break;
			case 3:
				sunset();
				break;
			case 4:
				liquidU();
				break;
			default:
				cout << "[ERROR] " << drink << " is not a valid entry...\n";
		}
	}
	
	void sprite(){
		if (stock.at("Sprite Cranberry") < 1){
			cout << "[FAIL] out of stock. please notify the lads" << "\n\n\n";
			return;
		}
		double money;
		cout << "Sprite: $2.50." << endl;
		cout << "Please enter money in USD: ";
		cin >> money;
		vend(money, 1);
	}
	
	void nukaCola(){
		if (stock.at("Nuka Cola") < 1){
			cout << "[FAIL] out of nuka cola, that's new :O" << "\n\n\n";
			return;
		}
		int money;
		cout << "Nuka Cola: 12 bottlecaps" << endl;
		cout << "Please enter money in bottlecaps (int): ";
		cin >> money;
		vend(money, 2);
	}
	
	void sunset(){
		if (stock.at("Sunset Sarsaparilla") < 1){
			cout << "[FAIL] out of sunset sarsaparilla, go see Festus XwX" << "\n\n\n";
			return;
		}
		int money;
		cout << "Sunset Sarsaparilla: 15 bottlecaps" << endl;
		cout << "Please enter money in bottlecaps (int): ";
		cin >> money;
		vend(money, 3);
	}
	
	void liquidU(){
		if (stock.at("Liquid Uranium") < 1){
			cout << "[FAIL] out of Liquid Uranium, but that's 15,000 less Roentgen in you OwO" << "\n\n\n";
			return;
		}
		double money;
		cout << "Liquid Uranium: $89.99." << endl;
		cout << "Please enter money in USD: ";
		cin >> money;
		vend(money, 4);
	}
	
	void vend(double money, int drink){
		double change;
		if (drink == 1){
			if (money > 2.50){
				change = money - 2.50;
				stock.at("Sprite Cranberry")--;
				cout << "[SUCCESS]\tvending 1 Sprite Cranberry..." << endl;
				cout << "\t\tchange: $" << change << "..." << endl;
			}
			else
				cout << "[FAIL]\tinsufficient funds. returning $" << money << " ..." << endl;
		}
		else if (drink == 2){
			if (int(money) > 12){
				change = int(money) - 12;
				stock.at("Nuka Cola")--;
				cout << "[SUCCESS]\tvending 1 Nuka Cola..." << endl;
				cout << "\t\tchange: $" << change << "..." << endl;
			}
			else
				cout << "[FAIL]\tinsufficient funds. returning $" << money << " ..." << endl;
		}
		else if (drink == 3){
			if (int(money) > 15){
				change = int(money) - 15;
				stock.at("Sunset Sarsaparilla")--;
				cout << "[SUCCESS]\tvending 1 Sunset Sarsaparilla..." << endl;
				cout << "\t\tchange: $" << change << "..." << endl;
			}
			else
				cout << "[FAIL]\tinsufficient funds. returning $" << money << " ..." << endl;
		}
		else if (drink == 4){
			if (money > 89.99){
				change = money - 89.99;
				stock.at("Liquid Uranium")--;
				cout << "[SUCCESS]\tvending 1 LiQU-..$%^AB [ERRO-]*# RAD##TIoN_CORRU-tED" << endl;
				cout << "\t\tchange: $" << change << "..." << endl;
			}
			else
				cout << "[FAIL]\tinsufficient funds. returning $" << money << " ..." << endl;
		}
	}
	
	// 11-10-2019: you can definitely restock a negative value to steal soda lol. negative stock underflows since it's uint_32t
	void maintenance(){
		cin.ignore();
		string password = "NCR is best CR";
		string input;
		int nRestock;
		cout << "\nmaintenance operator, enter company-provided password: ";
		getline(cin, input);
		if (input.compare(password) != 0)
			cout << "[ERROR] wrong password.\n\n\n\n";
		else{
			cout << "\n\n\n\n######## Maintenance ########\n";
			cout << "[Sprite Cranberry]\tenter amount to restock: ";
			cin >> nRestock;
			stock.at("Sprite Cranberry") += nRestock;
			
			cout << "[Nuka Cola]\t\tenter amount to restock: ";
			cin >> nRestock;
			stock.at("Nuka Cola") += nRestock;
			
			cout << "[Sunset Sarsaparilla]\tenter amount to restock: ";
			cin >> nRestock;
			stock.at("Sunset Sarsaparilla") += nRestock;
			
			cout << "[Liquid Uranium]\tenter amount to restock: ";
			cin >> nRestock;
			stock.at("Liquid Uranium") += nRestock;
			
			cout << "Thank you :)\n.\n.\n.\n.";
		}
	}
};


int main(){
	VendingMachine babbio1;
	
	babbio1.start();
	
	
	return 0;
}