#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main() {
    // Load the JSON file
    std::ifstream inputFile("data.json");
    if (!inputFile.is_open()) {
        std::cerr << "Could not open the file!" << std::endl;
        return 1;
    }

    // Parse the JSON file
    json jsonData;
    inputFile >> jsonData;
    
    // Added debug print to check if parsing was successful
    std::cout << "JSON data loaded successfully." << std::endl;

    inputFile.close();

    // Accessing data from the JSON object
    if (jsonData.contains("name") && jsonData.contains("age")) {
        std::string name = jsonData["name"];
        int age = jsonData["age"];
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    } else {
        std::cerr << "JSON does not contain expected keys." << std::endl;
    }

    return 0;
}