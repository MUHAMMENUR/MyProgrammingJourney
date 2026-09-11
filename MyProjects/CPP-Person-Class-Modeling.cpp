#include <iostream>
using namespace std;

class clsPerson {
private:
	int _ID;
	string _FirstName;
	string _LastName;
	string _Email;
	string _Phone;

public:
	clsPerson(int ID, string FirstName, string LastName, string Email, string Phone) {
		_ID = ID;
		_FirstName = FirstName;
		_LastName = LastName;
		_Email = Email;
		_Phone = Phone;
	}

	int GetID() {
		return _ID;
	}

	void setFirstName(string FirstName) {
		_FirstName = FirstName;
	}

	void setLastName(string LastName) {
		_LastName = LastName;
	}

	void setEmail(string Email) {
		_Email = Email;
	}
	

	void setPhone(string Phone) {
		_Phone = Phone;
	}

	string getFirstName() {
		return _FirstName;
	}

	string getLastName() {
		return _LastName;
	}

	string FullName() {
		return _FirstName + " " + _LastName;
	}

	string getEmail() {
		return _Email;
	}

	string getPhone() {
		return _Phone;
	}

	void Print() {
		cout << "ID: " << _ID << endl;
		cout << "First Name: " << _FirstName << endl;
		cout << "Last Name: " << _LastName << endl;
		cout << "Full Name: " << FullName() << endl;
		cout << "Email: " << _Email << endl;
		cout << "Phone: " << _Phone << endl;
	}

	void SendEmail(string subject, string body) {
		cout << "Sending email to: " + _Email + "\nSubject: " + subject + "\nBody: " + body << endl;
	}

	void Sendsms(string Message) {
		cout << "The Following message has been sent to: " + _Phone + "\nMessage: " + Message << endl;
	}

	




};

int main() {
	clsPerson Person(1, "Muhammed", "Sanda", "muhammed.sanda@example.com", "123-456-7890");
	Person.Print();

	Person.SendEmail("Hello Mmuhammed", "This is the first email sent to you");
	Person.Sendsms("This is the first Message sent to you");
}
