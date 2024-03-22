#include <iostream>
#include "AProblem.h"

using namespace std;
TTD::AProblem* uploadDataAndCreateProblem();

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
// Function to read data from a text file and create a new instance of AProblem
TTD::AProblem* uploadDataAndCreateProblem() {
    string filename;
    cout << "Enter the filename: ";
    cin >> filename;

    ifstream file(filename);
    if (!file) {
        cout << "Error: Unable to open file." << endl;
        return nullptr;
    }

    // Buffer to hold loaded data
    vector<TTD::City> cities;
    vector<TTD::Item> items;
    TTD::Thief thief;

    // Read thief data
    float max_velocity, backpack_capacity;
    file >> max_velocity >> backpack_capacity;
    thief = {max_velocity, backpack_capacity};

    // Read cities data
    int city_id, city_x, city_y;
    int i = 0;
    while (file >> city_x >> city_y) {
        cities.push_back({city_id, city_x, city_y});
    }

    // Read items data
    int item_id, item_value, item_weight, item_city_id;
    while (file >> item_id >> item_value >> item_weight >> item_city_id) {
        items.push_back({item_id, item_value, item_weight, item_city_id});
    }

    // Close the file
    file.close();

    // Create a new instance of AProblem using the buffered data
    AProblem* problem = new AProblem(cities, items, thief);
    return problem;
}
