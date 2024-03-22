#ifndef TTD_APROBLEM_H
#define TTD_APROBLEM_H

#include <vector>
#include "City.h"
#include "Item.h"
#include "Thief.h"

namespace TTD {

    class AProblem {
    private:
        std::vector<City> cities;
        std::vector<Item> items;
        Thief thief;
        std::vector<std::vector<float>> distances; // Matrix to store distances between cities

    public:
        AProblem(const std::vector<City>& cities, const std::vector<Item>& items, const Thief& thief);
        const std::vector<City>& getCities() const;
        const std::vector<Item>& getItems() const;
        const std::vector<std::vector<float>>& getDistances() const;
        const float& getDistancesBeetwen () const;
        void sortByValue();
        void sortByWeight();

    private:
        void calculateDistances(); // Helper function to calculate distances between cities
    };

} // namespace TTD

#endif //TTD_APROBLEM_H
