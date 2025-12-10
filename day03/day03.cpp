#include <iostream>
#include <fstream>

int part1() {
	// Create ifstream object to read in the input
	std::ifstream file("./input.txt");
	// String to hold the line
	std::string str;
	// Store the total sum
	int total_output_joltage = 0;

	// Loop through each line
	while (std::getline(file, str)) {
		// Initalize the 3 indices
		int tens = 0;
		int ones = 1;
		// Get length of the line
		int len_str = str.length();
		// Loop until next is out of bounds
		for (int next = 1; next < len_str; next++) {
			int tens_val = str[tens] - '0';
			int ones_val = str[ones] - '0';
			int next_val = str[next] - '0';
			// If next_val > tens_val, then we will move tens_val to be equal with next_val
			if (next_val > tens_val && next != len_str - 1) {
				tens = next;
				// The ones must be the next value
				ones = tens + 1;
			}
			// Else, if next_val > ones_val, then we will move ones val to be equal to next_val
			else if (next_val > ones_val) {
				ones = next;
			}
		}
		// Now, we have found the tens and ones index
		int final_tens = str[tens] - '0';
		int final_ones = str[ones] - '0';
		int output_joltage = 10 * final_tens + final_ones;
		total_output_joltage += output_joltage;
	}
	return total_output_joltage;
}

int part2() {
	// Create ifstream object to read in the input
	std::ifstream file("./input.txt");
	// String to hold the line
	std::string str;
	// Store the total sum
	int total_output_joltage = 0;
	const int NUM_DIGITS = 12;

	// Loop through each line
	while (std::getline(file, str)) {
		// Get length of string
		int str_len = str.length();
		// Initialize start index
		int start_index = 0;
		// Loop 12 times because we will find the max value for each digit
		for (int i = 0; i < NUM_DIGITS; i++) {
			// Determine the range that we will search in
			int end_index = str_len - NUM_DIGITS + i;
			// Let's find the maximum value and index from start index to end index
			int max_value = -1;
			int max_idx = -1;
			for (int j = start_index; j < end_index; j++) {
				int cur_val = str[j] - '0';
				if (cur_val > max_value) {
					max_value = cur_val;
					max_idx = j;
				}
			}
			// Append this character
			// Now, we have found the max value in this range, so we will update the start index
			// for the next digit
			start_index = max_idx + 1;
		}
	}
}

int main() {
	std::cout << part1() << std::endl;
	return 0;
}
