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

int parseMoves(string line) {
	stringstream ss(line);
	string move;
	while (ss >> move) {
		matchup.push_back(move);
	}
}

int getTurnScore(string round) {
	// Set scores for base turn selection
	unordered_map<string, int> base_scores;
	base_scores["X"] = 1;
	base_scores["Y"] = 2;
	base_scores["Z"] = 3;
	
	matchup.clear();
	parseMoves(round);

	score = score + base_scores.at(matchup[1]);
	cout << score << "\n";
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
        // Close the file object.
        new_file.close();
	}
}
