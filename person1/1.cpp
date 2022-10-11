#include <iostream>
#include <algorithm>

using namespace std;

int pow(int num, int exp) {
	int res = 1;
	for (int i = 1; i <= exp; i++)
		res *= num;
	return res;
}

void reverse(string *str) {
	char tmp;
	int len = (*str).length();
	for (int i = 0; i < len / 2; i++) {
		tmp = (*str)[i];
		(*str)[i] = (*str)[len - 1 - i];
		(*str)[len - 1 - i] = tmp;
	}
}

string dec_to_hex(int num) {
	string str = "";
	while (num != 0) {
		if (num % 16 < 10)
			str += num % 16 + '0';
		else
			str += num % 16 + '0' + 7;
		num /= 16;
	}
	reverse(&str);
	string zeros = "";
	for (int i = 0; i < 8 - str.length(); i++)
		zeros += "0";
	return zeros + str;
}

int main() {
	string inp_name = "";
	string inp_price;
	string inp_CashBack;
	string inp_temp;

	getline(cin, inp_name);
	getline(cin, inp_price);
	getline(cin, inp_CashBack);
	getline(cin, inp_temp);
	
	//name
	string out_name = "";
	for (int i = 16; i < inp_name.length(); i++)
		out_name += inp_name[i];
	cout << out_name << "\n";
	
	//price
	string out_price = "Price:...........";
	int price = 0;
	for (int i = inp_price.length() - 1; i >= 17; i--)
		price += (inp_price[i] - '0') * pow(10, inp_price.length() - 1 - i);
	out_price += dec_to_hex(price);
	cout << out_price << "\n";
	
	//CashBack
	string out_CashBack = "";
	for (int i = 53; i < inp_CashBack.length(); i++)
		out_CashBack += inp_CashBack[i];
	if (out_CashBack.length() == 4)
		cout << "Has cash-back:......." << out_CashBack << "\n";
	else
		cout << "Has cash-back:......" << out_CashBack << "\n";

	//temp
	int pos = 0;
	string out_temp = "Max temperature:";
	for (pos = inp_temp.length() - 1; inp_temp[pos - 1] != ' '; pos--);
	for (int i = 0; i < 8 - inp_temp.length() + pos; i++)
		out_temp += ".";
	if (inp_temp[pos] != '-')
		out_temp += "+";
	for (; pos < inp_temp.length(); pos++)
		out_temp += inp_temp[pos];
	cout << out_temp << "\n";

	return 0;
}
