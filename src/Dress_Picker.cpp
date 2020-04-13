/********************************
*Author: CHR-onicles
*Date/Time: 29/03/2020, 20:00 GMT
*Version 2.0 13/04/2020
********************************/

#include <iostream>
#include <vector>
#include <ctime>
#include <cstring>
#include <string>
#include <limits>
using namespace std;

void picker(vector<string>& tops, vector<string>& pants, int& tops_num, int& pants_num) {
	srand(time(0));
	unsigned int r = rand() % tops_num;
	unsigned int s = rand() % pants_num;

	cout << "\n===> You are wearing the " << tops.at(r) << " with the " << pants.at(s) << " today! <===" << endl;
}

int main() {
	cout << "Welcome to the program that helps you decide on what to wear..." << endl;
	cout << "because apparently you have better things doing... :)" << endl;
	cout << "***************************************************************" << endl;

	vector<string> tops;
	cout << "How many tops do you want to input?: ";
	int tops_num;
	cin >> tops_num;

	if (tops_num > 0) {
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		for (size_t i{ 1 }; i <= tops_num; ++i) {
			string temp;
			cout << "Enter the name of shirt[" << i << "]: ";
			getline(cin, temp);
			tops.push_back(temp);
		}

		vector <string> pants;
		cout << "\nHow many pants do you want to input?: ";
		int pants_num;
		cin >> pants_num;	

		if (pants_num > 0) {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
				cin >> response;
				response = toupper(response);

			} while (response != 'Y');
			cout << "\nExcellent choice!" << endl;
		}
		else cerr << "Invalid value!" << endl;
		
	}
	else cerr << "Invalid value!" << endl;
	
	
	cout << "\nGoodbye!" << endl;
	system("pause");
	return 0;
}