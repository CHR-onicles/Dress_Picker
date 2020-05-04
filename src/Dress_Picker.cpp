/********************************
*Author: CHR-onicles
*Date/Time: 29/03/2020, 20:00 GMT
*Update Version 2.2 04/05/2020
********************************/

#include <iostream>
#include <vector>
#include <ctime>
#include <cstring>
#include <string>
#include <limits>
#include <sstream>
#include <conio.h>
using namespace std;

void picker(vector<string>& tops, vector<string>& pants, int& tops_num, int& pants_num) {
	srand(time(NULL));
	unsigned int r = rand() % tops_num;
	unsigned int s = rand() % pants_num;

	cout << "\n===> You are wearing the " << tops.at(r) << " with the " << pants.at(s) << " today! <===" << endl;
}

 inline void clearandIgnore() {
	cin.clear();	//reset input error flags
	cin.ignore(numeric_limits<streamsize>::max(), '\n');	//ignore garbage in buffer from last input
 }

int main() {
	cout << "Welcome to the program that helps you decide on what to wear..." << endl;
	cout << "because apparently you have better things doing... :)" << endl;
	cout << "***************************************************************" << endl;

	vector<string> tops;
	int tops_num;
	string entry;
	bool isValidNum = false;
	do {
		cout << "How many tops do you want to input?: ";
		cin >> entry;
		istringstream iss{ entry };

		if (iss >> tops_num) {
			iss >> tops_num;
			if (tops_num > 0) isValidNum = true;
			else {
				cerr << "Number must be greater than zero!" << endl;
				clearandIgnore();
			} 
		}
		else {
			cerr << "Invalid number value!" << endl;
			clearandIgnore();
		}
	} while (!isValidNum);

	clearandIgnore();
	for (size_t i{ 1 }; i <= tops_num; ++i) {
			string temp;
			cout << "Enter the name of shirt[" << i << "]: ";
			getline(cin, temp);
			tops.push_back(temp);
	}

	vector <string> pants;
	isValidNum = false;
	int pants_num;
		
	do{
		cout << "\nHow many pants do you want to input?: ";
		cin >> entry;
		istringstream iss{ entry };
		if (iss >> pants_num) {
			iss >> pants_num;
			if (pants_num > 0) isValidNum = true;
			else {
				cerr << "Number must be greater than zero!" << endl;
				clearandIgnore();
			}
		}
		else {
			cerr << "Invalid number value!" << endl;
			clearandIgnore();
		}
	} while (!isValidNum);

	clearandIgnore();
	for (size_t i{ 1 }; i <= pants_num; ++i) {
		cout << "Enter the name of pant[" << i << "]: ";
		string temp;
		getline(cin, temp);
		pants.push_back(temp);

	}

	char response{};

	do {
		picker(tops, pants, tops_num, pants_num);
		cout << "Are you satisfied with your result? [Y/N]: ";
		response = _getch();
		response = toupper(response);

	} while (response != 'Y');
	cout << "\nExcellent choice!" << endl;
	
	cout << "\nGoodbye!" << endl;
	system("pause");
	return 0;
}