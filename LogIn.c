#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include<ctype.h>

void myPage(char username[64]);

void wait() {
	int bbuff;
	fflush(stdin);
	scanf("%c", &bbuff);
}

void fail() {
	system("cls");
	printf("Invalid username or password.");
	wait();
	printf("Please try again.");
	wait();
	main();
}

void line(int len) {
	for (int i = 0; i < len; i++) printf("=");
	printf("\n");
}

int validCheck(char string[64], int len, int ls) {
	int valid = 0;
	//Username
	if (ls == 0) {
		int userLen = 5;
		int alphaNum = 3;

		for (int i = 0; i < len; i++) {
			if (isalnum(string[i])) alphaNum--;
			userLen--;
		}
		if (userLen <= 0 && alphaNum <= 0) valid = 1;
		else valid = 0;
	}
	else if (ls == 1) {
		int passLen = 5, upper = 1, lower = 2, num = 2;

		for (int i = 0; i < len; i++) {
			if (isupper(string[i])) upper--;
			else if (islower(string[i])) lower--;
			else if (isdigit(string[i])) num--;
			passLen--;
		}
		if (passLen <= 0 && upper <= 0 && lower <= 0 && num <= 0) valid = 1;
		else valid = 0;
	}

	return valid;
}

void edit(char username[64]) {
	char filename[68];
	char password[64];
	int pass_len, passValid;
	strcpy(filename, username);
	strcat(filename, ".txt");

	FILE* fp = NULL;

	system("cls");
	printf("Password must include at least 1 uppercase, 2 lowercases, 2 numbers and be longer than 5 characters.\n");
	printf("New Password: ");
	gets_s(password, sizeof(password));
	pass_len = strlen(password);
	passValid = validCheck(password, pass_len, 1);

	if (passValid == 1) {
		fp = fopen(filename, "w");
		fprintf(fp, "%s", password);
		fclose(fp);
		system("cls");
		printf("Changes Saved.");
		wait();
		myPage(username);
	}
	else {
		system("cls");
		printf("New password does not meet the requirements.");
		wait();
		printf("Changes Not Saved.");
		wait();
		myPage(username);
	}
}

void del(char username[64]) {
	char filename[68];
	char input;

	strcpy(filename, username);
	strcat(filename, ".txt");

	system("cls");

	printf("Are you sure you want to delete this account? (Y/N)\n");
	while (1) {
		if (_kbhit()) {
			input = _getch();
			if (input == 'Y' || input == 'y') {
				system("cls");
				remove(filename);
				printf("Succesfully removed.");
				wait();
				main();
			}
			else if (input == 'N' || input == 'n') {
				system("cls");
				printf("Task Aborted.");
				wait();
				myPage(username);
			}
			else {
				system("cls");
				printf("Unknown Input: %c", input);
				wait();
				myPage(username);
			}
		}
	}
}

void myPage(char username[64]) {
	FILE* fp = NULL;
	int lineLen = 0;
	char input;
	char filename[68];
	char password[64];
	int user_len, pass_len;

	strcpy(filename, username);
	strcat(filename, ".txt");

	fp = fopen(filename, "r");
	fscanf(fp, "%s", password);
	fclose(fp);

	user_len = strlen(username);
	pass_len = strlen(password);

	if (user_len >= pass_len) lineLen = user_len;
	else if (user_len < pass_len) lineLen = pass_len;
	lineLen += 12;
RE:
	system("cls");
	line(lineLen);
	printf(" Username: %s\n", username);
	printf(" Password: %s\n", password);
	line(lineLen);
	printf("\nX - Exit   E - Edit   D - Delete\n");
	while (1) {
		if (_kbhit()) {
			input = _getch();
			if (input == 'X' || input == 'x') main();
			else if (input == 'E' || input == 'e') edit(username);
			else if (input == 'D' || input == 'd') del(username);
			else {
				system("cls");
				printf("Unknown Input: %c", input);
				wait();
				goto RE;
			}
		}
	}
}

void logIn() {
	FILE* fp = NULL;
	char username[64];
	char filename[68];
	char password[64];
	char filepass[64];
	char user_len, pass_len;

	system("cls");
	printf("Username: ");
	gets_s(username, sizeof(username));
	strcpy(filename, username);
	strcat(filename, ".txt");
	user_len = strlen(username);
	printf("Password: ");
	gets_s(password, sizeof(password));
	pass_len = strlen(password);

	fp = fopen(filename, "r");
	if (fp == NULL) {
		fail();
	}
	fscanf(fp, "%s", filepass);
	fclose(fp);

	if (strcmp(password, filepass) == 0) {
		system("cls");
		printf("Login Successful.\n");
		printf("Welcome, %s", username);
		wait();
		myPage(username);
	}
	else fail();
}

void signUp() {
	FILE* fp = NULL;
	char username[64];
	char password[64];
	char userFile[68];
	int user_len, pass_len, file_len, filePass_len;
	int userValid = 0, passValid = 0;

	system("cls");
	printf("Username must include more than 3 letters and be longer than 5 characters.\n");
	printf("Username: ");
	gets_s(username, sizeof(username));
	user_len = strlen(username);
	userValid = validCheck(username, user_len, 0);
	file_len = strlen(username) + 4;
	printf("Password must include at least 1 uppercase, 2 lowercases, 2 numbers and be longer than 5 characters.\n");
	printf("Password: ");
	gets_s(password, sizeof(password));
	pass_len = strlen(password);
	passValid = validCheck(password, pass_len, 1);
	filePass_len = pass_len + 2;

	strcpy(userFile, username);
	strcat(userFile, ".txt");

	if (userValid == 1 && passValid == 1) {
		system("cls");
		fp = fopen(userFile, "w");
		fprintf(fp, "%s", password);
		fclose(fp);

		printf("\nRegistration Succesful.");
		wait();
		main();
	}
	else {
		system("cls");
		printf("Username or password does not meet the requirements.");
		wait();
		main();
	}
}

int main() {
	char input;

START:
	system("cls");
	line(38);
	printf(" L - Log In   S - Sign Up   C - Close\n");
	line(38);
	printf("> ");
	while (1) {
		if (_kbhit()) {
			input = _getch();
			if (input == 'L' || input == 'l') logIn();
			else if (input == 'S' || input == 's') signUp();
			else if (input == 'C' || input == 'c') return 0;
			else {
				system("cls");
				printf("Unknown Input: %c", input);
				wait();
				goto START;
			}
		}
	}
}
