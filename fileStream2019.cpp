// Ethan DyTioco
// E 115: file input and output

#include <iostream>
#include <fstream>
#include <string>
using namespace std;



class Contacts{
private:
	string name, number, email;
	
public:
	Contacts(){
		name = "", number = "", email = "";
	}
	
	void open(){
		int choice;
		while(true){
			cout << "\n\n======== Contacts ========\n";
			cout << "1 - create contact" << endl;
			cout << "2 - search contact" << endl;
			cout << "3 - display all contacts" << endl;
			cout << "enter choice: ";
			cin >> choice;
			
			if (choice == 1)
				create();
			else if (choice == 2)
				search();
			else if (choice == 3)
				displayAll();
			else
				cout << "[ERROR] invalid entry." << endl;
		}
	}
	
	void create(){
		ofstream writer;
		cout << "\n\n======== Create New Contact ========\n";
		cout << "enter the name of your new contact (first last): ";
		cin.ignore();		// makes sure that the first getline doesn't get ignored
		getline(cin, name);
		
		cout << "enter the phone number of your new contact (xxx.xxx.xxxx): ";
		getline(cin, number);
		
		cout << "enter the email of your new contact (user@website.com): ";
		getline(cin, email);
		
		writer.open("contacts2019.txt", ios::app);
		writer << name << "\t" << number << "\t" << email << "\n";
		writer.close();
	}
	
	void search(){
		ifstream reader;
		string line, search;
		size_t found; 			// return -1 if we don't find the string
		bool found2 = false;	// used for checking if the contact isn't found at all
		reader.open("contacts2019.txt");
		if (reader.is_open()){
			cout << "\n\n======== Search Contact ========\n";
			cout << "Enter the name, number, or email of the person you're looking for: ";
			cin.ignore();
			getline(cin, search);
			
			while(!reader.eof()){
				getline(reader, line);
				found = line.find(search);	// see if the line contains the string search.
				if (found != string::npos){	// if found is NOT -1, then line contains our search string! :D
					cout << line << endl;
					found2 = true;
				}
			}
			if (!found2){
				cout << "contact not found." << endl;
			}
		}
		else
			cout << "[ERROR] File not found" << endl;
		
		reader.close();
	}
	
	void displayAll(){
		ifstream reader;
		string line;
		reader.open("contacts2019.txt");
		if (reader.is_open()) {
			cout << "\n\n ======== All Contacts ========\n";
			while (!reader.eof()) { 	// while the reader is NOT at the end of the file, keep outputting
				getline(reader, line);
				cout << line << endl;
			}
			
			cout << "\n\n";
		}
		else
			cout << "[ERROR] File not found" << endl;
		
		reader.close();
	}
	
	
};


int main(){
	Contacts book1;
	book1.open();	// open behaves like the menu
	
	
	
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