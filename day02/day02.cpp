#include <fstream>
#include <string>
#include <iostream>
#include <unordered_map>

long part1() {
	// Create ifstream object to read in the input
	std::ifstream file("./input.txt");
	// Declare string to read in the line
	std::string str;
	// Hold the sum of the repeating IDs
	long repeatingSum = 0;

	while (std::getline(file, str, ',')) {
		// Find the position of the dash to split the range
		size_t dashPos = str.find('-');
		// Extract the two numbers as substrings
		long num1 = std::stol(str.substr(0, dashPos));
		long num2 = std::stol(str.substr(dashPos + 1));
		// Loop from num1 to num2 and check if it is repeating
		for (long i = num1; i <= num2; i++) {
			// Determine the number of digits
			std::string i_str = std::to_string(i);
			int num_chars = i_str.length();
			// If num_chars is odd, then we can continue since this will not have repeating
			if (num_chars % 2) {
				continue;
			}
			// Now, we will have two pointers. One starts at 0, and one starts at half index
			int half_index = num_chars / 2;
			// Loop until we have found a non-repeating character
			int j = 0;
			int k = half_index;
			bool isRepeating = true;
			while (j < half_index) {
				char first_char = i_str[j];
				char second_char = i_str[k];
				// Check if first and second char are not equal; if so, we can exit the loop
				if (first_char != second_char) {
					isRepeating = false;
					break;
				}
				// Increment j and k
				j++;
				k++;
			}
			// If this was repeating, then we will add it to the sum
			if (isRepeating) {
				repeatingSum += i;
			}
		}
	}
	return repeatingSum;
}

// Helper: check if string is composed of repeated substrings
bool isRepeatingPattern(const std::string& s) {
    int n = s.size();
    for (int len = 1; len <= n/2; ++len) {
        if (n % len != 0) continue; // must divide evenly
        std::string block = s.substr(0, len);
        bool ok = true;
        for (int i = len; i < n; i += len) {
            if (s.substr(i, len) != block) {
                ok = false;
                break;
            }
        }
        if (ok) return true;
    }
    return false;
}

long part2() {
    std::ifstream file("./input.txt");
    std::string str;
    long repeatingSum = 0;

    while (std::getline(file, str, ',')) {
        size_t dashPos = str.find('-');
        long num1 = std::stol(str.substr(0, dashPos));
        long num2 = std::stol(str.substr(dashPos + 1));

        for (long i = num1; i <= num2; i++) {
            std::string i_str = std::to_string(i);

            // Use the helper instead of hashmap logic
            if (isRepeatingPattern(i_str)) {
                // std::cout << "is repeating for " << i << std::endl;
                repeatingSum += i;
            }
        }
    }
    return repeatingSum;
}

int main() {
	std::cout << part1() << std::endl;
	std::cout << part2() << std::endl;
}
