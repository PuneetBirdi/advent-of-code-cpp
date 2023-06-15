#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <typeinfo>
#include <numbers>

using namespace std;

int getNumber(string string) {
	return stoi(string);
}

int main() {
	fstream new_file;

	new_file.open("day1-input.txt", ios::in);
	
	if (new_file.is_open()) { 
    string calories;
        // Read data from the file object and put it into a string.
        while (getline(new_file, calories)) { 
            // Print the data of the string.
            cout << getNumber(calories) << "\n";
        }
        
        // Close the file object.
        new_file.close();
	}
}



