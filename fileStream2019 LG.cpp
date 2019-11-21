#include <iostream>
#include <fstream>
#include <string>
using namespace std;





class ContactsBook{
private:
	void addContact(){
		string name, number, email, gamertag;
		cout << "\n\n======== Adding New Contact ========\n";
		cout << "Enter the person's full name (first last): ";
		getline(cin, name); // cin >> name, but it can hold spaces
		cout << "Enter the person's number (xxx.xxx.xxxx): ";
		getline(cin, number);
		cout << "Enter the person's email: ";
		getline(cin, email);
		cout << "GAMERS ONLY - enter the person's gamertag (\"N/A\" for non-gamers): ";
		getline(cin, gamertag);
		
		string full = name + "\t" + number + "\t" + email + "\t" + gamertag;
		
		ofstream writer;
		writer.open("contacts LG.txt", ios::app);
		writer << full << endl;
		writer.close();
	}
	
	void searchContact(){
		ifstream reader;
		string lineBuf, search;
		size_t found; 			// return -1 if we don't find the string
		bool isFound = false;	// used for checking if the contact isn't found at all
		reader.open("contacts LG.txt");
		
		cout << "\n\n======== Search Contact ========\n";
		cout << "Supports name, phone number, email, and gamertag search." << endl << endl;
		cout << "Enter the contact you want to look up: ";
		getline(cin, search);
		
		while (!reader.eof()){
			getline(reader, lineBuf);
			found = lineBuf.find(search);
			if (found != string::npos){
				cout << endl << "found contact: " << lineBuf << endl << endl;
				isFound = true;
			}
		}
		if (!isFound){
			cout << endl << "contact not found :(" << "\n\n";
		}
		reader.close();
	}
	
	void displayAll(){
		ifstream reader;
		string lineBuf;
		reader.open("contacts LG.txt");
		while(!reader.eof()){
			getline(reader, lineBuf);
			cout << lineBuf << endl;
		}
		reader.close();
	}
public:
	ContactsBook(){}
	
	void menu(){
		int choice;
		while(true){
			cout << "\n\n================ Contacts Book ================\n";
			cout << "1 - add new contact" << endl;
			cout << "2 - search contacts" << endl;
			cout << "3 - display all contacts" << endl;
			cout << "4 - exit" << endl;
			// bonus: checking for duplicate contacts
			// bonus: loading from a file, where the user gives the file name
			cout << "enter you choice: ";
			cin >> choice;
			cin.ignore();
			
			if (choice == 1)
				addContact();
			else if (choice == 2)
				searchContact();
			else if (choice == 3)
				displayAll();
			else if (choice == 4)
				return;
		}
	}
};




int main(){
	ContactsBook book1;
	book1.menu();
	
	return 0;
}

/*
Create a "ContactsBook" application that allows the user to create, search and display their contacts on a screen. Your program must store all contact information on a file. Contact details can include attributes like First name, Last name, Phone, Email etc., Your program must allow the user to:
(i) Create and store new contact information,
(ii) Search for a contact using details such as name/phone-number, and
(iii) Display all your contacts on the terminal.


Assignment requirements:
(1) create a Class called ContactsBook,
(2) use functions() to perform the required actions, and
(2) store contact details on a physical file using ifstream/ofstream objects.
*/