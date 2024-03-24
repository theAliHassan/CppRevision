#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include<vector>

std::string decode(const std::string& message_file) {
    std::ifstream file(message_file);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << message_file << std::endl;
        return "";
    }

    std::string line;
    std::unordered_map<int, std::string> pyramid_map;
    std::vector<int> pyramid_numbers;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int number;
        iss >> number;
        pyramid_numbers.push_back(number);

        std::string word;
        while (iss >> word) {
            // Store the mapping of pyramid number to word
            pyramid_map[pyramid_numbers.back()] = word;
        }

        if (pyramid_map.size() == pyramid_numbers.back()) {
            // If the condition is met, add the corresponding word to the decoded_message vector
            std::cout << pyramid_map[pyramid_numbers.back()] << " ";
        }
    }

    file.close();

    // Output a newline to separate the results
    std::cout << std::endl;

    return "";
}

int main() {
    std::string message_file = "encoded_message.txt";
    decode(message_file);

    return 0;
}
