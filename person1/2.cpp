#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

enum Units {
	N,
	token
};

const unordered_map<string, Units> matcher = {
	{
		"N",
		Units::N
	},

	{
		"<token>",
		Units::token
	}
};

const double g = 9.81;

string format_input(string str) {
	string formatted = "";
	for (char ch : str)
		if ((ch >= 48 && ch <= 57) || ch == 44 || ch == 46 || (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122))
			formatted += ch;
	return formatted;
}

int main() {
	string input;
	getline(cin, input);
	
	input = format_input(input);

	int pos = 0;
	for (; input[pos] - '0' < 10 && pos < input.length(); pos++);
	string token = input.substr(pos);
	
	cout << input << endl;

	auto iter = matcher.find(token);
	if (iter == matcher.end()) {
		cout << "No such unit" << endl;
		return 1;
	}

	double num = stod(input.substr(0, pos));
	
	switch(iter->second) {
		case Units::N:
			cout << num / g << " kgf";
			break;
		case Units::token:
			//calculations + output
			break;
		default:
			cout << "Raw number!" << endl;
			cout << num;
			break;
	}
	
	cout << endl;

	return 0;
}
