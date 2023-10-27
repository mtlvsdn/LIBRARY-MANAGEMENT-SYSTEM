#include <iostream>
#include "header.h"
#include <fstream>
#include <string>
#include <Windows.h>
#include <conio.h>

void menuSetupForClerks() {
	system("cls");
	std::cout << "\t\t\t\t\tLibrary Management System";
	std::cout << std::endl << "\t1.View Book List";
	std::cout << std::endl << "\t2.Add Book";
	std::cout << std::endl << "\t3.Modify Book Entry";
	std::cout << std::endl << "\t4.Delete Book Entry";
	std::cout << std::endl << "\t5. Quit";
	std::cout << std::endl << "\t-> ";
}

void menuSetupForMembers() {
	system("cls");
	std::cout << "\t\t\t\t\tLibrary Management System";
	std::cout << std::endl << "\t1.View Book List";
	std::cout << std::endl << "\t2. Search for Book";
	std::cout << std::endl << "\t3. Quit";
	std::cout << std::endl << "\t-> ";
}

void menuSetupForAdmins() {
	system("cls");
	std::cout << "\t\t\t\t\tLibrary Management System";
	std::cout << std::endl << "\t1. Add Clerk Account";
	std::cout << std::endl << "\t2. Delete Clerk Account";
	std::cout << std::endl << "\t3. Add Member Account";
	std::cout << std::endl << "\t4. Delete Member Account";
	std::cout << std::endl << "\t5. Add Admin Account";
	std::cout << std::endl << "\t6. Delete Admin Account";
	std::cout << std::endl << "\t7. Quit";
	std::cout << std::endl << "\t-> ";
}

int welcomeScreen() {
	std::cout << "\t\t\t\t\tLibrary Management System";
	std::cout << std::endl << "\tWhat are you?";
	std::cout << std::endl << "\t1.Member";
	std::cout << std::endl << "\t2.Clerk";
	std::cout << std::endl << "\t3.Admin";

	int selection = 0;

	while (selection != 1 && selection != 2 && selection != 3) {
		std::cout << std::endl << "\t-> ";
		std::cin >> selection;
		return selection;
	}
}

void securityCheck(Clerk user) {
	system("cls");
	std::string username, password;
	std::cout << "\t\tUsername: ";
	std::cin >> username;
	user.setUsername(username);
	std::cout << "\t\tPassword: ";
	std::cin >> password;
	user.setPassword(password);
}

bool checkPasswordMembers(std::string username, std::string password) {
	std::ifstream credentialsFile("credentialsMembers.csv");
	
	credentialsFile.seekg(0, std::ios::beg);
	std::string usernameFile, passwordFile;
	credentialsFile >> usernameFile;
	credentialsFile >> passwordFile;
	while (username != usernameFile && password != passwordFile && credentialsFile >> usernameFile) {
		
		credentialsFile >> passwordFile;
	}
	credentialsFile.close();
	if (username == usernameFile && password == passwordFile)
		return true;
	return false;
}

bool checkPasswordClerks(std::string username, std::string password) {
	std::ifstream credentialsFile("credentialsClerks.csv");

	credentialsFile.seekg(0, std::ios::beg);
	std::string usernameFile, passwordFile;
	credentialsFile >> usernameFile;
	credentialsFile >> passwordFile;
	while (username != usernameFile && password != passwordFile && credentialsFile >> usernameFile) {

		credentialsFile >> passwordFile;
	}
	credentialsFile.close();
	if (username == usernameFile && password == passwordFile)
		return true;
	return false;
}

bool checkPasswordAdmins(std::string username, std::string password) {
	std::ifstream credentialsFile("credentialsAdmins.csv");

	credentialsFile.seekg(0, std::ios::beg);
	std::string usernameFile, passwordFile;
	credentialsFile >> usernameFile;
	credentialsFile >> passwordFile;
	while (username != usernameFile && password != passwordFile && credentialsFile >> usernameFile) {

		credentialsFile >> passwordFile;
	}
	credentialsFile.close();
	if (username == usernameFile && password == passwordFile)
		return true;
	return false;
}

void addClerkAccount(Clerk user) {
	std::ofstream credentialsFile("credentialsClerks.csv", std::ios::app);

	system("cls");
	std::cout << "\t\t- New User Data -";
	std::cout << std::endl << std::endl << "\t\tUsername: ";
	user.setUsername2();
	credentialsFile << std::endl << user.getUsername() << " ";
	std::cout << "\t\tPassword: ";
	user.setPassword2();
	credentialsFile << user.getPassword();

	credentialsFile.close();
}

void addMemberAccount(Member user) {
	std::ofstream credentialsFile("credentialsMembers.csv", std::ios::app);

	system("cls");
	std::cout << "\t\t- New User Data -";
	std::cout << std::endl << std::endl << "\t\tUsername: ";
	user.setUsername2();
	credentialsFile << std::endl << user.getUsername() << " ";
	std::cout << "\t\tPassword: ";
	user.setPassword2();
	credentialsFile << user.getPassword();

	credentialsFile.close();
}

void addAdminAccount(Admin user) {
	std::ofstream credentialsFile("credentialsAdmins.csv", std::ios::app);

	system("cls");
	std::cout << "\t\t- New User Data -";
	std::cout << std::endl << std::endl << "\t\tUsername: ";
	user.setUsername2();
	credentialsFile << std::endl << user.getUsername() << " ";
	std::cout << "\t\tPassword: ";
	user.setPassword2();
	credentialsFile << user.getPassword();

	credentialsFile.close();
}

//void deleteClerkAccount(Clerk user) {
//	std::string usernameFile = "", word;
//	//std::ofstream credentialsFileWrite("credentialsClerks.csv");
//	std::ifstream credentialsFileRead("credentialsClerks.csv");
//	std::ofstream file("tempFile.csv");
//
//	std::cout << "\t\tDelete User Account";
//	std::cout << std::endl << "Username of the account you want to delete: ";
//	user.setUsername2();
//
//	//credentialsFileRead.seekg(0, std::ios::beg);
//	//std::cout << std::endl << user.getUsername();
//	while (credentialsFileRead >> word) {
//		std::cout << word << " ";
//		if (user.getUsername() == word) {
//			//credentialsFileRead >> word;
//			continue;
//		}
//		else {
//			file << word << " ";
//			credentialsFileRead >> word;
//			file << word << std::endl;
//		}
//	}
//
//	/*file.close();
//	credentialsFileRead.close();
//
//	std::ifstream fileWrite("tempFile.csv");
//	while (fileWrite >> word) {
//		credentialsFileWrite << word << " ";
//		fileWrite >> word;
//		credentialsFileWrite << std::endl;
//	}*/
//}

void deleteClerkAccount(Clerk user) {
	std::ifstream fileRead("credentialsClerks.csv");
	std::ofstream fileNew("tempFile.csv");
	std::string word;

	system("cls");
	std::cout << "\t\tType the username of the user you wish to delete: ";
	user.setUsername2();

	while (fileRead >> word) {
		if (word == user.getUsername()) {
			fileRead >> word;
		}
		else
		{
			fileNew << std::endl << word << " ";
			fileRead >> word;
			fileNew << word;
		}
	}

	fileRead.close();
	fileNew.close();

	std::ifstream newFile("tempFile.csv");
	std::ofstream originalFile("credentialsClerks.csv");
	while (newFile >> word) {
		originalFile << std::endl << word << " ";
		newFile >> word;
		originalFile << word;
	}

	newFile.close();
	originalFile.close();
}

void deleteMemberAccount(Member user) {
	std::ifstream fileRead("credentialsMembers.csv");
	std::ofstream fileNew("tempFile.csv");
	std::string word;

	system("cls");
	std::cout << "\t\tType the username of the user you wish to delete: ";
	user.setUsername2();

	while (fileRead >> word) {
		if (word == user.getUsername()) {
			fileRead >> word;
		}
		else
		{
			fileNew << std::endl << word << " ";
			fileRead >> word;
			fileNew << word;
		}
	}

	fileRead.close();
	fileNew.close();

	std::ifstream newFile("tempFile.csv");
	std::ofstream originalFile("credentialsMembers.csv");
	while (newFile >> word) {
		originalFile << std::endl << word << " ";
		newFile >> word;
		originalFile << word;
	}

	newFile.close();
	originalFile.close();
}

void deleteAdminAccount(Admin user) {
	std::ifstream fileRead("credentialsAdmins.csv");
	std::ofstream fileNew("tempFile.csv");
	std::string word;

	system("cls");
	std::cout << "\t\tType the username of the user you wish to delete: ";
	user.setUsername2();

	while (fileRead >> word) {
		if (word == user.getUsername()) {
			fileRead >> word;
		}
		else
		{
			fileNew << std::endl << word << " ";
			fileRead >> word;
			fileNew << word;
		}
	}

	fileRead.close();
	fileNew.close();

	std::ifstream newFile("tempFile.csv");
	std::ofstream originalFile("credentialsAdmins.csv");
	while (newFile >> word) {
		originalFile << std::endl << word << " ";
		newFile >> word;
		originalFile << word;
	}

	newFile.close();
	originalFile.close();
}


//MAIN FUNCTION !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
int main() {
	system("color 70");
	std::string firstName, lastName, username, password;
	int department = 0, menuFunction;
	bool isCredentialsCorrect = false;

	int selection = welcomeScreen();
	
	if (selection == 1) {
		Member memberAccount(username, password);
		while (isCredentialsCorrect == false) {
			system("cls");
			std::cout << "\t\tUsername: ";
			std::cin >> username;
			std::cout << "\t\tPassword: ";
			std::cin >> password;
			Member memberAccount(username, password);

			isCredentialsCorrect = checkPasswordMembers(username, password);
		}
		while (true) {
			menuSetupForMembers();
			std::cin >> menuFunction;
			switch (menuFunction) {
			case 1:
				//viewBookList();
				break;
			case 2:
				//addBookEntry();
				break;
			case 3:
				//modifyBookEntry();
				break;
			case 4:
				//deleteBookEntry();
				break;
			case 5:
				break;
			}
		}
	} else if(selection == 2) {
		Clerk clerkAccount(firstName, lastName, department);
		while (isCredentialsCorrect == false) {
			system("cls");
			std::cout << "\t\tUsername: ";
			std::cin >> username;
			clerkAccount.setUsername(username);
			std::cout << "\t\tPassword: ";
			std::cin >> password;
			clerkAccount.setPassword(password);

			isCredentialsCorrect = checkPasswordClerks(username, password);
		}
		while (true) {
			menuSetupForClerks();
			std::cin >> menuFunction;
			switch (menuFunction) {
			case 1:
				//viewBookList();
				break;
			case 2:
				//serachBook();
				break;
			case 3:
				break;
			}
		}
	}
	else if (selection == 3) {
		Admin adminAccount(username, password);
		Clerk newClerk;
		Member newMember;
		Admin newAdmin;
		while (isCredentialsCorrect == false) {
			system("cls");
			std::cout << "\t\tUsername: ";
			std::cin >> username;
			adminAccount.setUsername(username);
			std::cout << "\t\tPassword: ";
			std::cin >> password;
			adminAccount.setPassword(password);

			isCredentialsCorrect = checkPasswordAdmins(username, password);
		}
		while (true) {
			menuSetupForAdmins();
			std::cin >> menuFunction;
			switch (menuFunction) {
			case 1:
				addClerkAccount(newClerk);
				break;
			case 2:
				deleteClerkAccount(newClerk);
				break;
			case 3:
				addMemberAccount(newMember);
				break;
			case 4:
				deleteMemberAccount(newMember);
				break;
			case 5:
				addAdminAccount(newAdmin);
				break;
			case 6:
				deleteAdminAccount(newAdmin);
				break;
			case 7:
				break;
			}
			if (menuFunction == 7)
				break;
		}
	}
	
	/*std::cout << std::endl << "First Name: ";
	std::cin >> firstName;
	std::cout << "Last Name: ";
	std::cin >> lastName;
	std::cout << "Department: ";
	std::cin >> department;*/

	//Clerk clerkAccount(firstName, lastName, department);
	//std::cout << std::endl << clerkAccount.Clerk();
	//std::cout << clerkAccount.getFirstName();

	system("pause>0");
}
