#include <iostream>
#include <string>

using namespace std;

class Person
{
//private class members for adress book
	string m_firstName;
	string m_lastName;
	string m_phone;
	string m_state;
	string m_city;



public:
	
	Person() {};
	//parametrized constructor
	Person(string firstName, string lastName, string phone, string state, string city)
	{
		m_firstName = firstName;
		m_lastName = lastName;
		m_phone = phone;
		m_state = state;
		m_city = city;

	}
	//destructor
	~Person() {};

	// Setter
	void setFirstName(string firstName) {
		m_firstName = firstName;
	}
	// Getter
	string getFirstName() {
		return m_firstName;
	}

	// Setter
	void setLastName(string lastName) {
		m_lastName = lastName;
	}
	// Getter
	string getLastName() {
		return m_lastName;
	}
	// Setter
	void setPhone(string phone) {
		m_phone = phone;
	}
	// Getter
	string getPhone() {
		return m_phone;
	}
	// Setter
	void setState(string state) {
		m_state = state;
	}
	// Getter
	string getState() {
		return m_state;
	}
	// Setter
	void setCity(string city) {
		m_city = city;
	}
	// Getter
	string getCity() {
		return m_city;
	}
	//method used to print data
	void showPersons()
	{
		cout << "First Name: " << getFirstName() << endl;
		cout << "Last Name: " << getLastName() << endl;
		cout << "Phone: " << getPhone() << endl;
		cout << "State: " << getState() << endl;
		cout << "City: " << getCity() << endl;
		cout << endl << endl;

	}


};
