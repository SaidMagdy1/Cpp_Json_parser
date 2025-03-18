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
    inputFile.close();

    // Accessing data from the JSON object
    std::string name = jsonData["name"];
    int age = jsonData["age"];
    std::cout << "Name: " << name << ", Age: " << age << std::endl;

    return 0;
}