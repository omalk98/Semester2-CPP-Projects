//==============================================
// Name:           Omar Hussein
// Student Number: 118073204
// Email:          ohussein2@myseneca.ca
// Section:        NAA
// Final Project:  Milestone 1
// Date:		   Mar 13, 2021
//==============================================
// I decalre that all the code included in this module
// including the header have been written by myself.
// No content was copied other than the code provided
// in the workshop file by the professor.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include "utils.h"
#include "Time.h"
using namespace std;
namespace sdds {
	bool debug = false;  // made global in utils.h
	int getTime() {
		int mins = -1;
		if (debug) {
			Time t(0);
			cout << "Enter current time: ";
			do {
				cin.clear();
				cin >> t;   // needs extraction operator overloaded for Time
				if (!cin) {
					cout << "Invlid time, try agian (HH:MM): ";
					cin.clear();
				}
				else {
					mins = int(t);
				}
				cin.ignore(1000, '\n');
			} while (mins < 0);
		}
		else {
			time_t t = time(NULL);
			tm lt = *localtime(&t);
			mins = lt.tm_hour * 60 + lt.tm_min;
		}
		return mins;
	}
	int validateNum(const char* numstr, bool negative) {
		int state = 0;
		for (unsigned i = 0; i < strlen(numstr); ++i) {
			if (i == 0) if (numstr[i] == '-' && negative) continue;
			if (numstr[i] < 48 || numstr[i] > 57) {
				state = 1;
				if (i > 0) state = 2;
				break;
			}
		}
		return state;
	}
	int getInt(const char* prompt) {
		char entry[128] = "\0";
		bool valid = false;
		if (prompt) cout << prompt;
		while (!valid) {
			cin.getline(entry, 127, '\n');
			switch (validateNum(entry)) {
			case 0:
				valid = true;
				break;
			case 1:
				cout << "Bad integer value, try again: ";
				cin.clear();
				break;
			case 2:
				cout << "Enter only an integer, try again: ";
				cin.clear();
				break;
			}
		}
		return stoi(entry);
	}
	int getInt(int min, int max, const char* prompt,
		const char* errorMessage, bool showRangeAtError) {
		const char* ifPrompt[2]{ prompt, nullptr };
		bool displayed = false;
		int inRange = 0;
		bool valid = false;
		while (!valid) {
			inRange = getInt(displayed ? ifPrompt[1] : ifPrompt[0]);
			displayed = true;
			if (inRange >= min && inRange <= max) valid = true;
			if (!valid) {
				if (errorMessage) cout << errorMessage;
				if (showRangeAtError) cout << "[" << min << " <= value <= " << max << "]: ";
			}
		}
		return inRange;
	}
	// using string class implementation
	/*char* getcstr(const char* prompt, std::istream& istr, char delimiter) {
		if (prompt) cout << prompt;
		string line;
		char* line_cstr = nullptr;
		getline(istr, line, delimiter);
		line_cstr = new char[strlen(line.c_str()) + 1];
		strcpy(line_cstr, line.c_str());
		return line_cstr;
	}
	//version 1 of getcstr without using string class
	char* getcstr(const char* prompt, std::istream& istr, char delimiter) {
		const char t_file[] = "_temp.txt";
		char* line{ nullptr }, ch = '\0';
		int len = 0;
		if (prompt) cout << prompt;
		ofstream temp(t_file);
		while (ch != delimiter) {
			istr.get(ch);
			if (ch != delimiter) {
				temp << ch;
				++len;
			}
		}
		temp.close();
		line = new char[len + 1];
		ifstream input(t_file);
		if (input) {
			for (auto i = 0; i < len; ++i) {
				input.get(ch);
				line[i] = ch;
			}
			line[len] = '\0';
			input.close();
		}
		remove(t_file);
		return line;
	}*/
	char* getcstr(const char* prompt, std::istream& istr, char delimiter) {
		char* line = nullptr, * temp = nullptr, buff = '\0';
		int count = 0;
		if (prompt) cout << prompt;
		while (buff != delimiter && istr) {
			istr.get(buff);
			if (buff != delimiter) {
				temp = new char[++count + 1];
				if (line) strcpy(temp, line);
				temp[count - 1] = buff;
				temp[count] = '\0';
				delete[] line;
				line = temp;
			}
		}
		return line;
	}
}