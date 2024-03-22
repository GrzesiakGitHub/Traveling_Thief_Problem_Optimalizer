#include "AProblem.h"
#include <algorithm>
#include <cmath>

using namespace std;

namespace TTD {

    AProblem::AProblem(const vector<City>& cities, const vector<Item>& items, const Thief& thief)
            : cities(cities), items(items), thief(thief) {
        calculateDistances(); // Calculate distances between cities upon object creation
    }

    const vector<City>& AProblem::getCities() const {
        return cities;
    }

    const vector<Item>& AProblem::getItems() const {
        return items;
    }

    const vector<vector<float>>& AProblem::getDistances() const {
        return distances;
    }

    const float& AProblem::getDistancesBeetwen() const {

    }

    void AProblem::sortByValue() {
        sort(items.begin(), items.end(), [](const Item& item1, const Item& item2) {
            return item1.value > item2.value;
        });
    }

    void AProblem::sortByWeight() {
        sort(items.begin(), items.end(), [](const Item& item1, const Item& item2) {
            return item1.weight < item2.weight;
        });
    }

    void AProblem::calculateDistances() {
        distances.resize(cities.size(), vector<float>(cities.size(), 0));
        // Resize matrix to hold distances

        for (size_t i = 0; i < cities.size(); ++i) {
            for (size_t j = i + 1; j < cities.size(); ++j) {
                float distance = sqrt(pow(cities[i].x - cities[j].x, 2) + pow(cities[i].y - cities[j].y, 2));
                //using pitagoras theorem
                distances[i][j] = distances[j][i] = distance; // Store distances in two equal places in matrix
            }
        }
    }

} // namespace TTD
