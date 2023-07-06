#include <algorithm>
#include <cstring>
#include <exception>
#include <iostream>
#include <numeric>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <typeinfo>
#include <numbers>
#include <unordered_map>
#include <string.h>

using namespace std;
vector<string> matchup;
int score;

int getTurnScore(string round) {
	// Set scores for base turn selection
	unordered_map<string, int> base_scores;
	base_scores["A X"] = 3 + 1;
	base_scores["A Y"] = 6 + 2;
	base_scores["A Z"] = 0 + 3;

	base_scores["B X"] = 0 + 1;
	base_scores["B Y"] = 3 + 2;
	base_scores["B Z"] = 6 + 3;

	base_scores["C X"] = 6 + 1;
	base_scores["C Y"] = 0 + 2;
	base_scores["C Z"] = 3 + 3;

	unordered_map<string, char> responses_map;
	responses_map["A X"] = 'Z';
	responses_map["A Y"] = 'X';
	responses_map["A Z"] = 'Y';

	responses_map["B X"] = 'X';
	responses_map["B Y"] = 'Y';
	responses_map["B Z"] = 'Z';

	responses_map["C X"] = 'Y';
	responses_map["C Y"] = 'Z';
	responses_map["C Z"] = 'X';

	char score_lookup[3];
	char response[2];
	strncpy (response, 'q', 1);
	try {
	} catch (exception) {
		cout << "error";
	};
	strcat (score_lookup, response);
	cout << score_lookup;
	//score = score + base_scores.at(score_lookup);
	return -1;
}

int main() {
	fstream new_file;

	new_file.open("day2-input.txt", ios::in);
	
	if (new_file.is_open()) { 
    string turn;
        // Read data from the file object and put it into a string.
        while (getline(new_file, turn)) {
            // Print the data of the string.
						getTurnScore(turn);
        }
				cout << score;
        // Close the file object.
        new_file.close();
	}
}
