#include <iostream>
#include <Windows.h>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

string userChoice();
string usersChoice;

void decisionTree();
void multiplication();
void division();
void addition();
void subtraction();
void exponent();
void goAgain();

bool checkAgain = false;
bool playAgain = true;

float counter = 0;
float number1 = 9;
float number2 = 3;
float number3 = 0;
float *n1 = &number1;
float *n2 = &number2;
float *n3 = &number3;

void decisionTree()
{
	do
	{
		if (counter == 0)
		{
			system("cls");
			cout << "Welcome to my simple calculator!\n\n";
			cout << "Press the corresponding number/letter:\n";
			cout << "1: Multiplication\t2: Division\n";
			cout << "3: Addition\t\t4: Subtraction\n";
			cout << "5: Exponent\t\tQ/QUIT: leave program\n\n";
		}

		else if (counter > 0)
		{
			system("cls");
			cout << "Press the corresponding number/letter:\n";
			cout << "1: Multiplication\t2: Division\n";
			cout << "3: Addition\t4: Subtraction\n";
			cout << "5: Exponent\tQ/QUIT: leave program\n\n";
		}

		userChoice();

		if (usersChoice == "1")
		{
			multiplication();
			++counter;
			checkAgain = true;
			system("pause");
		}
		else if (usersChoice == "2")
		{
			division();
			++counter;
			checkAgain = true;
			system("pause");
		}
		else if (usersChoice == "3")
		{
			addition();
			++counter;
			checkAgain = true;
			system("pause");
		}
		else if (usersChoice == "4")
		{
			subtraction();
			++counter;
			checkAgain = true;
			system("pause");
		}
		else if (usersChoice == "5")
		{
			exponent();
			++counter;
			checkAgain = true;
			system("pause");
		}
		else if (usersChoice == "QUIT" || usersChoice == "Q")
		{
			cout << "\nAll right. Have a good day and thanks for using this\nsimple calculator!\n\n";
			checkAgain = false;
			playAgain = false;
		}

		/*
		else //informs user that their choice was invalid
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //sets color for text to red
			cout << "\nI am sorry I do not understand your command" << endl; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2); //resets to green
			system("pause");
			checkAgain = true;
		} couldn't get this error catch to work properly
		*/
	} while (checkAgain);
}

void multiplication()
{
	cout << "Give me your first number: "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	cin >> *n1;  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	cout << "Now give me your second number: "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	cin >> *n2; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	*n3 = *n1 * *n2;
	cout << "Here's the final product of the multiplication: " << *n3 << "\n\n";
}

void division()
{
	cout << "Give me your first number: "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	cin >> *n1;  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	cout << "Now give me your second number: "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	cin >> *n2; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	*n3 = *n1 / *n2;
	cout << "Here's the final product of the division: " << *n3 << "\n\n";
}

void addition()
{
	cout << "Give me your first number: "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	cin >> *n1;  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	cout << "Now give me your second number: "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	cin >> *n2; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	*n3 = *n1 + *n2;
	cout << "Here's the final product of the addition: " << *n3 << "\n\n";
}

void subtraction()
{
	cout << "Give me your first number: "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	cin >> *n1;  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	cout << "Now give me your second number: "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	cin >> *n2; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	*n3 = *n1 - *n2;
	cout << "Here's the final product of the subtraction: " << *n3 << "\n\n";
}

void exponent()
{
	cout << "Give me your first number: "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	cin >> *n1;  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	cout << "Now give me your second number: "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	cin >> *n2; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	*n3 = pow(*n1, *n2);
	cout << "Here's the final product of the exponents: " << *n3 << "\n\n";
}

void goAgain() // Replay Loop Confirmation
{
	if (playAgain == true) //triggers this if playAgain is true when reaching the loop
	{
		do
		{
			cout << "\n\nWant to initialize another simulation? Y/N: ";
			userChoice();

			if (usersChoice == "YES" || usersChoice == "Y")
			{
				playAgain = true; //replay program
				checkAgain = false; //leave current loop
				system("cls"); //clears console for new playthrough
			}
			else if (usersChoice == "NO" || usersChoice == "N")
			{
				cout << "\n\nThanks for playing. Please come again.\n\n";
				playAgain = false; //leave program altogether
				checkAgain = false; //leaves this loop
				system("pause");
			}
			else //error catcher
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //sets color for text to red
				cout << "\nInvalid response. Please enter a valid response.\n";
				checkAgain = true; //resets current loop for proper guess
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2); //sets color for text back to green
			}
		} while (checkAgain); //boolean for this do while loop
	}

	else if (playAgain == false) //triggered if playAgain is false when reaching this loop
	{
		//cout << "\n\nThanks for using this simple calculator.\n\n";
		system("pause");
	}
}

string userChoice() //small function for user input
{
	usersChoice; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3); //sets color for text only to aqua
	getline(cin, usersChoice); //gets input from user
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2); //sets color for text back to green
	for (int i = 0; usersChoice[i] != '\0'; i++) //this loop capitalizes input for decisions.
	{
		usersChoice[i] = toupper(usersChoice[i]);
	}
	return usersChoice;
}

int main()
{
	system("color 02");
	do
	{
		//resets values
		decisionTree();
		goAgain(); //function run for confirmation on playing again

	} while (playAgain);
	return 0;
}