#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int perform_mod(int a, int b) {
	int mod = a % b;
	if (mod < 0) {
		mod += b;
	}
	return mod;
}

int part1() {
	// Create ifstream object to read in the input
	ifstream file("./input.txt");
	// Declare str to read in the line
	string str;
	// Initialize the starting point for the dial, which is 50
	int dialValue = 50;
	// Initialize the password to 0
	int password = 0;

	// Open the file and read line by line
	while (getline(file, str)) {
		// cout << str << endl;
		// Get the first character to determine if we are moving to the left (L) or right (R)
		char leftOrRight = str[0];
		// Get the value that we will be moving the dial
		int valueToMove = stoi(str.substr(1));
		// If leftOrRight is left, then we will subtract
		if (leftOrRight == 'L') {
			valueToMove *= -1;
		}
		// Now, add the value to move to the dial value
		dialValue = perform_mod(dialValue + valueToMove, 100);
		// Check if dialValue is 0. If so, then we will increment the count
		if (dialValue == 0) {
			password++;
		}
	}
    // Finally, return the password
	return password;
}

int part2() {
    ifstream file("input.txt");
    string str;

    int dialValue = 50;   // starting position
    int password = 0;

    while (getline(file, str)) {
        char dir = str[0];                // 'L' or 'R'
        int steps = stoi(str.substr(1));  // number of clicks

        if (dir == 'L') steps *= -1;

        int start = dialValue;
        int end = dialValue + steps;

        // Count crossings
        int crossings = abs(start / 100 - end / 100);
		// If we cross from positive to negative or vice versa, we need to add an extra crossing
		if (start * end < 0) crossings++;

        // If we land exactly on 0, count that too
        if (end == 0) crossings++;

        password += crossings;
        dialValue = perform_mod(end, 100);
    }

    return password;
}


int main() {
	// Get password from part 1
	int password_1 = part1();
	cout << "Password 1 = " << password_1 << endl;
	// Get password from part 2
	int password_2 = part2();
	cout << "Password 2 = " << password_2 << endl;
}
