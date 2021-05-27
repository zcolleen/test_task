
#include "Synchronizer.hpp"

Synchronizer::Synchronizer() : gen(std::random_device()()) {}


bool Synchronizer::checkVectorSize(int16_t i, std::multimap<int16_t, int16_t> &temp_map) {

    if (i == (int16_t )vector.size()) {
        auto it = --temp_map.end();

        while (temp_map.size() != vector.size()) {
            map.erase(it->second);
            it = --temp_map.erase(it);
        }
        return true;
    }
    return false;
}


void Synchronizer::checkIfOk() {

    std::vector<int16_t> temp_vector;
    int16_t vector_size = temp_vector.size();

    for (auto &elem : map) {
        temp_vector.push_back(elem.second);
    }
    std::sort(temp_vector.begin(), temp_vector.end());
    for (int16_t i = 0; i < vector_size; ++i) {
        if (temp_vector[i] != vector[i]) {
            std::cout << "Not OK" << std::endl;
            return;
        }
    }
    std::cout << "OK" << std::endl;
}


void Synchronizer::sync() {

    std::multimap<int16_t, int16_t> temp_map;

    // rewriting map to multimap with values as key so it will be sorted
    for (auto elem : map) {
        temp_map.insert(std::make_pair(elem.second, elem.first));
    }
    //sorting vector
    std::sort(vector.begin(), vector.end());

    auto it = temp_map.begin();
    int16_t i = 0;
    while (it != temp_map.end()) {
        if (checkVectorSize(i, temp_map))
            break;
        // if element in vector is greater than in map deleting element from vector
        if (it->first > vector[i]) {
            vector.erase(vector.begin() + i);
            continue;
        }
        // if element in map is greater than in vector deleting element from our first map and from temporary multimap
        else if (it->first < vector[i]) {
            map.erase(it->second);
            it = temp_map.erase(it);
            continue;
        }
        // else going to next pair of elements
        ++it;
        ++i;
    }
    while (temp_map.size() != vector.size()) {
        vector.pop_back();
    }
}

void Synchronizer::print() {

    std::cout << "Vector: ";
    for (auto &elem : vector) {
        std::cout << elem << " ";
    }
    std::cout << std::endl << "Map:    ";
    for (auto &elem : map) {
        std::cout << elem.second << " ";
    }
    std::cout << std::endl;
}

void Synchronizer::deletePart() {

    std::uniform_int_distribution<int8_t > range_distribution(1, 15);
    int8_t delete_range = range_distribution(gen);

    for (int8_t i = 0; i < delete_range; ++i) {

        vector.pop_back();
        map.erase(--map.end());
    }
}

void Synchronizer::fillWithNumbers() {

    std::uniform_int_distribution<int16_t > range_distribution(50, 100);
    std::uniform_int_distribution<int16_t > numbers_distribution(1, 9);


    int16_t range = range_distribution(gen);
    for (int16_t i = 0; i < range; ++i) {
        vector.push_back(numbers_distribution(gen));
        map.insert(std::make_pair(i, numbers_distribution(gen)));
    }
}
