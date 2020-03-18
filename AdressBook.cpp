#include <iostream>
#include <list>
#include "Person.cpp"
#include <fstream>

using namespace std;

//list to hold objects of type Person
list <Person> listpers;

//methods declaration
void addContact();
void editContact(string);
void printContacts();
void deleteContact(string);
void readfile();
void writeFile(string, string, string, string, string);
bool validNumber(string);
bool validInput(string);
void rewriteFile();
string firstLetter(string);

//method to read content from file
void readfile()
{
	ifstream file;
	string fn, ln, ph, st, ct;
	file.open("Contacts.txt");
	string word;
	char singleCharacter;
	int counter = 1;
	word.clear();
	listpers.clear();

	while (!file.eof())
	{
		if (counter == 6)
		{
			counter = 1;
			Person pers = Person(fn, ln, ph, st, ct);
			listpers.push_back(pers);
		}
		singleCharacter = file.get();

		while ((singleCharacter != ' ') && (singleCharacter != 'ÿ'))
		{
			if (singleCharacter == '\n') break;
			word = word + singleCharacter;
			singleCharacter = file.get();
		}
		

		switch (counter)
		{
		case 1:
			fn = word;
			break;
		case 2:
			ln = word;
			break;
		case 3:
			ph = word;
			break;
		case 4:
			st = word;
			break;
		case 5:
			ct = word;
			break;
		default:
			break;
		}

		word.clear();
		counter++;

	}
	if (singleCharacter != 'ÿ')
	{
		Person pers = Person(fn, ln, ph, st, ct);
		listpers.push_back(pers);
	}

}

//method to write to file
void writeFile(string fn, string ln, string ph, string st, string ct)
{
	ofstream myfile;
	myfile.open("Contacts.txt", ios::app);
	myfile << fn << " " << ln << " " << ph << " " << st << " " << ct << endl;
	myfile.close();
}

//method to update the content of the file with the list's elements
void rewriteFile()
{
	
	ofstream myfile;
	myfile.open("Contacts.txt", ios::trunc);
	for (std::list<Person>::iterator it = listpers.begin(); it != listpers.end(); ++it)
	{
		Person contact = *it;
	    myfile << contact.getFirstName() << " " << contact.getLastName() << " " << contact.getPhone() << " " << contact.getState() << " " << contact.getCity() << endl;
		
	}
	myfile.close();

}

//validate phone number entered by user
bool validNumber(string phone)
{
	int index = 0, digitCounter = 0;
	char number[20];
	strcpy_s(number, phone.c_str());
	if (strlen(number) == 10)
	{
		while (number[index] != NULL)
		{
			if (isdigit(number[index]))
				digitCounter++;
			    index++;
		}
		if (number == " ")
		{
			cout << endl << "Enter without space!";
			return false;
		}
		else if (digitCounter == 10) return true;
		else return false;
	}
	else return false;
}

//validate character input entered by user
bool validInput(string word)
{
	int index = 0, alphaCounter = 0;
	char character[32];
	strcpy_s(character, word.c_str());
	if ((strlen(character) <= 20) && (strlen(character) > 2))
	{
		while (character[index] != NULL)
		{
			if (isalpha(character[index])) alphaCounter++;
			else if (character[index] == ' ')
			{
				cout << endl << "Enter without space!";
				return false;
			}
			index++;
		}

		if (alphaCounter == strlen(character)) return true;
		else return false;
	}
	else return false;
}

//method to add new contact
void addContact()
{
	string fn, ln, ph, st, ct;
	cout << "Insert first name: " << endl;
	cin.ignore();
	getline(cin, fn);
	while (!validInput(fn)) {

		cout << "First Name is not valid! Enter first name again :\n";
		getline(cin, fn);
	}
	cout << "Insert last name: " << endl;
	getline(cin, ln);
	while (!validInput(ln)) {

		cout << "Last Name is not valid! Enter last name again :\n";
		getline(cin, ln);
	}
	cout << "Insert phone number: " << endl;
	getline(cin, ph);
	while(!validNumber(ph)) {

		cout << "Number must contain 10 digits! Enter number again :\n";
		getline(cin, ph);
	}
	cout << "Insert state: " << endl;
	getline(cin, st);
	while (!validInput(st)) {

		cout << "State is not valid! Enter state again :\n";
		getline(cin, st);
	}
	cout << "Insert city: " << endl;
	getline(cin, ct);
	while (!validInput(ct)) {

		cout << "City is not valid! Enter city again :\n";
		getline(cin, ct);
	}
	//add contacts into list 
	Person pers = Person(firstLetter(fn), firstLetter(ln), ph, firstLetter(st), firstLetter(ct));
	listpers.push_back(pers);
	writeFile(firstLetter(fn), firstLetter(ln), ph, firstLetter(st), firstLetter(ct));
}

//method to print existing contacts
void printContacts()
{
	for (std::list<Person>::iterator it = listpers.begin(); it != listpers.end(); ++it)
	{
		Person contact = *it;
		contact.showPersons();
	}
}

//edit contact
void editContact(string nameaux)
{
	Person contact;
	string fn, ln, ph, st, ct;
	for (std::list<Person>::iterator it = listpers.begin(); it != listpers.end(); ++it)
	{
		contact = *it;
		int option = 0, counter = 0;
		string aux;
		if (strcmp(contact.getFirstName().c_str(), nameaux.c_str()) == 0)
		{
			cout << endl << "###########Contact###########" << endl;
			contact.showPersons();
			cout << "1.Edit first name" << endl;
			cout << "2.Edit last name" << endl;
			cout << "3.Edit phone number" << endl;
			cout << "4.Edit state" << endl;
			cout << "5.Edit city" << endl;
			cout << "6.Back" << endl;
			cin >> option;

			switch (option)
			{
			case 1: 
				cout << "Enter the new first name: " << endl;
				cin.ignore();
				getline(cin, aux);
				while (!validInput(aux)) {

					cout << "First Name is not valid! Enter first name again :\n";
					getline(cin, aux);
				}
				contact.setFirstName(firstLetter(aux));
				
				break;
			case 2:
				cout << "Enter the new last name: " << endl;
				cin.ignore();
				getline(cin, aux);
				while (!validInput(aux)) {

					cout << "Last Name is not valid! Enter last name again :\n";
					getline(cin, aux);
				}
				contact.setLastName(firstLetter(aux));
				
				break;
			case 3:
				cout << "Enter the new phone number: " << endl;
				cin.ignore();
				getline(cin, aux);
				while (!validNumber(aux)) {
					cout << "Phone number is not valid! Enter phone number again :\n";
					getline(cin, aux);
				}
				contact.setPhone(aux);
				break;
			case 4:
				cout << "Enter the new state: " << endl;
				cin.ignore();
				getline(cin, aux);
				while (!validInput(aux)) {

					cout << "State is not valid! Enter state again :\n";
					getline(cin, aux);
				}
				contact.setState(firstLetter(aux));
				break;
			case 5:
				cout << "Enter the new city: " << endl;
				cin.ignore();
				getline(cin, aux);
				while (!validInput(aux)) {

					cout << "City is not valid! Enter city again :\n";
					getline(cin, aux);
				}
				contact.setCity(firstLetter(aux));
				break;
			case 6: 
				break;
			default:
				cout << "Option unavailable!" << endl;
				break;
			}
			if (option == 6) break;
			else
			{
				listpers.erase(it);
				rewriteFile();
				writeFile(contact.getFirstName(), contact.getLastName(), contact.getPhone(), contact.getState(), contact.getCity());//sriere obct editat inapoi in fisier
				listpers.clear();
				readfile();
				counter++;
			}
			
			
		}
		if (counter == 1) break;
		
	}

}

//method to delete a contact
void deleteContact(string nameaux)
{
	Person contact;
	string decision;
	cout << "\nAre you sure you want to delete this contact?(yes/no)";
	cin >> decision;
	if (decision == "yes")
	{
		for (std::list<Person>::iterator it = listpers.begin(); it != listpers.end(); ++it)
		{
			contact = *it;
			int option = 0, counter = 0;
			string aux;

			if (strcmp(contact.getFirstName().c_str(), nameaux.c_str()) == 0)
			{
				cout << endl << "###########Contact#########" << endl;
				contact.showPersons();
				listpers.erase(it);
				rewriteFile();
				counter++;
				cout << endl << "Contact deleted!" << endl;
			}
			if (counter == 1) break;

		}
	}
}

//first letter to uppercase
string firstLetter(string character)
{
	char letter[32];
	strcpy(letter, character.c_str());
	for (int i = 1; i <= strlen(letter); i++)
	{
		letter[i] = tolower(letter[i]);
	}
	letter[0] = toupper(letter[0]);

	return (string)letter;
}

int main()
{
	int option = 0;
	string nameaux; 
	readfile();
	cout << endl << "Welcome to your adress book!" << endl;
	while (option != 5)
	{
		cout << endl << "Please choose an option from below:" << endl;
		cout << "1.Enter a new contact to address book" << endl;
		cout << "2.Show all contacts" << endl;
		cout << "3.Edit a contact" << endl;
		cout << "4.Delete a contact" << endl;
		cout << "5.EXIT" << endl;
		cin >> option;

		switch (option)
		{
		case 1: 
			addContact();
			break;
		case 2:
			printContacts();
			break;
		case 3: 
			cout << "Please enter first name: " << endl;
			cin >> nameaux;
			nameaux = firstLetter(nameaux);
			editContact(nameaux);
			break;
		case 4:
			cout << "Please enter first name: " << endl;
			cin >> nameaux;
			nameaux = firstLetter(nameaux);
			deleteContact(nameaux);
			break;
		case 5: 
			break;
		default:
			cout << "Invalid option, please try again!" << endl;
			break;
		}
	}
	return 0;
}