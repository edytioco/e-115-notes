// authors: Mark Freeman, Ethan DyTioco

#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

class ContactsBook {
	private:
		struct Contact {
			string firstName;
			string lastName;
			string phone;
			string email;
		};
		string fileName;
		vector<Contact> contacts;
		
		string serialize(Contact contact) {
			return contact.firstName + " " + contact.lastName + " " + contact.phone + " " + contact.email;
		}

		Contact deserialize(string contact) {
			Contact curContact;
			istringstream iss(contact);
			string curWord;
			iss >> curContact.firstName;
			
			iss >> curContact.lastName;
			
			iss >> curContact.phone;
			
			iss >> curContact.email;
			
			return curContact;
		}
		
		void readContactsFromFile() {
			string line;
			ifstream input(this->fileName);
			
			while(!input.eof()) {
				getline(input, line);
				contacts.push_back(deserialize(line));
			}
		}
		
	public:
		ContactsBook() {
			this->fileName = "contacts LF.txt";
			this->contacts = vector<Contact>();
			
			readContactsFromFile();
		}

		void menu(){
			int choice;
			
			while (true){
				cout << "\n\n================ Contacts ================\n";
				cout << "1 - create new contact" << endl;
				cout << "2 - search contact by name" << endl;
				cout << "3 - search contact by phone" << endl;
				cout << "4 - display saved contacts" << endl;
				cout << "5 - save to file" << endl;
				cout << "enter choice: ";
				cin >> choice;
				cin.ignore();
				
				if (choice == 1)
					newContact();
				else if (choice == 2)
					searchContactByName();
				else if (choice == 3)
					searchContactByPhone();
				else if (choice == 4)
					displayAll();
				else if (choice == 5)
					exit();
				else
					cout << "[ERROR] invalid choice." << endl;
			}
		}
	
		void newContact() {
			Contact temp;
			string input;
			cout << "\n======== Add New Contact ========\n";
			cout << "Enter first name: ";
			getline(cin, input);
			temp.firstName = input;
			
			cout << "Enter last name: ";
			getline(cin, input);
			temp.lastName = input;
			
			cout << "Enter phone number (xxx.xxx.xxxx): ";
			getline(cin, input);
			temp.phone = input;
			
			cout << "Enter email (username@website.com): ";
			getline(cin, input);
			temp.email = input;
			
			contacts.push_back(temp);
		}
		
		void searchContactByName() {
			// iterate over the vector and find a
			// contact where the name matches.
			string input;
			bool isFound = false;
			cout << "\n======== Search by Name ========\n";
			cout << "Enter the first name you want to search: ";
			getline(cin, input);

			for (Contact contact : contacts){
				if (contact.firstName == input){
					cout << endl << "found: " << serialize(contact) << endl << endl;
					isFound = true;
				}
			}
			if (!isFound)
				cout << "contact not found.\n\n";
		}
		
		void searchContactByPhone() {
			string input;
			bool isFound = false;
			cout << "\n======== Search by Name ========\n";
			cout << "Enter the phone number you want to search (xxx.xxx.xxxx): ";
			getline(cin, input);

			for (Contact contact : contacts){
				if (contact.phone == input){
					cout << endl << "found: " << serialize(contact) << endl << endl;
					isFound = true;
				}
			}
			
			if (!isFound)
				cout << "contact not found.\n\n";
		}
		
		void displayAll(){
			cout << "\n\n======== All Contacts ========\n";
			for (Contact contact : contacts)
				cout << serialize(contact) << endl;
			
			cout << "\n\n";
		}
		
		void exit() {
			ofstream output(this->fileName, ios::app);
			for (Contact contact : contacts) {
				output << serialize(contact) << endl;
			}
		}		
};



int main(){
	ContactsBook book1;
	book1.menu();
	
	
	return 0;
}





