#include <algorithm>
#include <exception>
#include <iostream>
#include <numeric>
#include <string>
#include <fstream>
#include <vector>
#include <typeinfo>
#include <numbers>

using namespace std;

int getNumber(string string) {
	vector<int> elf;
	try {
		return stoi(string);
	} catch (exception) {
		return -1;
	}
}

int main() {
	fstream new_file;

	new_file.open("day1-input.txt", ios::in);
	
	if (new_file.is_open()) { 
    string calories;
        // Read data from the file object and put it into a string.
				vector<int> elves;
				vector<int> elf;
        while (getline(new_file, calories)) {
            // Print the data of the string.
            int numCalories = getNumber(calories);
						if (numCalories > 0) {
							elf.push_back(numCalories);
						} else {
							int total = accumulate(elf.begin(), elf.end(), 0);
							elves.push_back(total);
							elf.clear();
						}
        }
				//Sort the elves by calories
				sort(elves.begin(), elves.end());
				auto max = max_element(elves.begin(), elves.end());

				auto topThree = accumulate((elves.end() - 3), elves.end(), 0);
				cout << topThree;
        // Close the file object.
        new_file.close();
	}
}



