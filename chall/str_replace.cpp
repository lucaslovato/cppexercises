#include <iostream>
#include <string>
using namespace std;

string replace_string(string subject, const string& search, const string& replace) {
	size_t pos = 0;
	while ((pos = subject.find(search, pos)) != string::npos) {
		subject.replace(pos, search.length(), replace);
		pos += replace.length();
	}
	return subject;
}

int main() {
	string solution = "I found the solution of this challenge!";
	string str_to_replace = "solution";
	cout << "Your output must be: '" << solution << "' to win:" << endl;
	char str[100];
	cin.getline(str, sizeof(str));
	string output = replace_string(str, str_to_replace, "");
	cout << "Your output is:" << endl;
	cout << output << endl;

	string msg {""};
	if (solution == output) {
		msg = "Congratulations, you completed this chall";
	}
	else {
		msg = "You fail";
	}

	cout << msg << endl;
}