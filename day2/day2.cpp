#include <algorithm>
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

	//Add the base score
	try {
		score = score + base_scores.at(round);
	} catch (exception) {
		return -1;
	}
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
