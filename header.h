#pragma once
#include <iostream>
#include <string>

//using namespace std;

enum class ClerkType { JUNIOR = 1, SENIOR = 2, EXPERT };
enum class Gender {male, female};

class Clerk {
private:
	std::string username = "";
	std::string password = "";
	std::string firstName = "";
	std::string lastName = "";
	int department = 0;
	bool isLoggedIn = false;
	ClerkType type = ClerkType::JUNIOR;

public:
	static const int MIN_NAME = 2;
	static const int FIRST_DEPARTMENT = 1;
	static const int LAST_DEPARTMENT = 5;

	Clerk(std:: string firstName, std::string lastName, int department) {
		this->firstName = firstName;
		this->lastName = lastName;
		this->department = department;
	}

	Clerk() {

	}

	std::string getUsername() {
		return this->username;
	}

	std::string getPassword() {
		return this->password;
	}

	std::string getFirstName() {
		return this->firstName;
	}

	std::string getLastName() {
		return this->lastName;
	}

	int getDepartment() {
		return this->department;
	}

	bool getLogin() {
		return this->isLoggedIn;
	}

	ClerkType getType() {
		return this->type;
	}

	void setUsername(std::string newUsername) {
		this->username = newUsername;
	}

	void setPassword(std::string newPassword) {
		this->password = newPassword;
	}

	void setUsername2() {
		std::string newUsername;
		std::cin >> newUsername;
		this->username = newUsername;
	}

	void setPassword2() {
		std::string newPassword;
		std::cin >> newPassword;
		this->password = newPassword;
	}

	void setFirstname(std::string newFirstName) {
		if (newFirstName.size() <= MIN_NAME)
			throw std::exception("Name too short...");
		this->firstName = newFirstName;
	}

	void setLastName(std::string newLastName) {
		if (newLastName.size() <= MIN_NAME)
			throw std::exception("Name too short...");
		this->lastName = newLastName;
	}

	void setDepartment(int value) {
		if (value >= FIRST_DEPARTMENT && value <= LAST_DEPARTMENT) {
			this->department = value;
		}
		else {
			throw new std::exception("Wrong value!");
		}
	}

	void setIsLoggedIn(bool value) {
		this->isLoggedIn = value;
	}

	void setType(ClerkType value) {
		this->type = value;
	}
};

class Member {
private:
	std::string username = "";
	std::string password = "";
	std::string firstName = "";
	std::string lastName = "";
	int age = 0;
	bool isLoggedIn = false;
	int numberOfBooks = 0;
	bool isPastDeadline = false;
	char* faculty = nullptr;
	char* university = nullptr;
	Gender memberGender = Gender::female;

public:
	static const int MIN_NAME = 2;
	static const int FIRST_DEPARTMENT = 1;
	static const int LAST_DEPARTMENT = 5;
	static const int MIN_AGE = 10;
	static const int MAX_AGE = 100;

	Member(std::string username, std::string password) {
		this->setUsername(username);
		this->setPassword(password);
	}

	Member() {

	}

	std::string getUsername() {
		return this->username;
	}

	std::string getPassword() {
		return this->password;
	}

	std::string getFirstName() {
		return this->firstName;
	}

	std::string getLastName() {
		return this->lastName;
	}

	int getAge() {
		return this->age;
	}

	bool getIsLoggedIn() {
		return this->isLoggedIn;
	}

	int getNumberOfBooks() {
		return this->numberOfBooks;
	}

	bool getIsPastDeadline() {
		return this->isPastDeadline;
	}

	char* getFaculty() {
		char* facultyCopy = new char[strlen(this->faculty) + 1];
		strcpy_s(facultyCopy, strlen(this->faculty) + 1, this->university);
		return facultyCopy;
	}

	char* getUniversity() {
		char* univCopy = new char[strlen(this->university) + 1];
		strcpy_s(univCopy, strlen(this->university) + 1, this->university);
		return univCopy;
	}

	Gender getGender() {
		return this->memberGender;
	}

	void setUsername(std::string newUsername) {
		this->username = newUsername;
	}

	void setPassword(std::string newPassword) {
		this->password = newPassword;
	}

	void setUsername2() {
		std::string newUsername;
		std::cin >> newUsername;
		this->username = newUsername;
	}

	void setPassword2() {
		std::string newPassword;
		std::cin >> newPassword;
		this->password = newPassword;
	}

	void setFirstName(std::string newFirstName) {
		if (newFirstName.size() <= MIN_NAME)
			throw std::exception("Name too short...");
		this->firstName = newFirstName;
	}

	void setLastName(std::string newLastName) {
		if (newLastName.size() <= MIN_NAME)
			throw std::exception("Name too short...");
		this->lastName = newLastName;
	}

	void setAge(int newAge) {
		if (newAge < MIN_AGE || newAge > MAX_AGE) {
			throw std::exception("Age invalid!");
		}
		this->age = newAge;
	}

	void setIsLoggedIn(bool value) {
		this->isLoggedIn = value;
	}

	void setNumberOfBooks(int newNumberOfBooks) {
		this->numberOfBooks = newNumberOfBooks;
	}

	bool setIsPastDeadline(bool value) {
		this->isPastDeadline = value;
	}

	char* setUniversity(char* newUniversity) {
		this->university = newUniversity;
	}

	char* setFaculty(char* newFaculty) {
		this->faculty = newFaculty;
	}
};

class Admin {
private:
	std::string username = "";
	std::string password = "";
	std::string firstName = "";
	std::string lastName = "";
	bool isLoggedIn = false;

public:
	Admin(std::string username, std::string password) {
		this->setUsername(username);
		this->setPassword(password);
	}

	Admin() {

	}

	std::string getUsername() {
		return this->username;
	}

	std::string getPassword() {
		return this->password;
	}

	std::string getfirstName() {
		return this->firstName;
	}

	std::string getLastName() {
		return this->lastName;
	}

	void setUsername(std::string newUsername) {
		this->username = newUsername;
	}

	void setPassword(std::string newPassword) {
		this->password = newPassword;
	}

	void setUsername2() {
		std::string newUsername;
		std::cin >> newUsername;
		this->username = newUsername;
	}

	void setPassword2() {
		std::string newPassword;
		std::cin >> newPassword;
		this->password = newPassword;
	}

	void setFirstName(std::string newFirstName) {
		this->firstName = newFirstName;
	}

	void setLastName(std::string newLastName) {
		this->lastName = newLastName;
	}
};

class Book {
private:
	std::string title = "";
	std::string author = "";
	/*int* aisle = nullptr;
	char lastDateBooked[11] = "";*/

public:
	void setTitle() {
		std::string newTitle;
		std::cin >> newTitle;
		this->title = newTitle;
	}

	void setAuthor() {
		std::string newAuthor;
		std::cin >> newAuthor;
		this->author = newAuthor;
	}
	
	std::string getTitle() {
		return this->title;
	}

	std::string getAuthor() {
		return this->author;
	}
};