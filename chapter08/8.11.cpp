/*
 * Exercise 8.11: The program in this section defined its istringstream object
 * inside the outer while loop. What changes would you need to make if record
 * were defined outside that loop? Rewrite the program, moving the definition
 * of record outside the 
 * 
 * Answer: first, declare the unbound stream record outside the outer loop,
 * than copy the string line into the stream at every iteration of the otter
 * loop, and, finally, clear the stream just before looping back so it will be
 * in a valid state on the next line copy.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

struct PersonInfo {
	std::string name;
	std::vector<std::string> phones;
};

int main()
{
	std::string line, word;
	std::vector<PersonInfo> people;
	std::istringstream record;     // unbound istringstream

	while (getline(std::cin, line)) {
		PersonInfo info;
		record.str(line);          // copy line to stream
		record >> info.name;
		while (record >> word)
			info.phones.push_back(word);
		people.push_back(info);
		record.clear();            // rest stream back to valid state
	}

	// print vector
	for (const auto &person : people) {
		std::cout << person.name << " ";
		for (const auto &number : person.phones)
			std::cout << number << " ";
		std::cout << '\n';
	}
	return 0;
}
