

#ifndef UNTITLED1_SYNCHRONIZER_HPP
#define UNTITLED1_SYNCHRONIZER_HPP

#include <iostream>
#include <vector>
#include <map>
#include <random>
#define RED "\e[31m"
#define GREEN "\e[32m"
#define RESET "\e[0m"
#define YELLOW "\e[33m"


class Synchronizer {

private:
    std::mt19937 gen;
    std::vector<int16_t> vector;
    std::map<int16_t, int16_t> map;

    bool checkVectorSize(int16_t i, std::multimap<int16_t, int16_t> &temp_map);
public:
    Synchronizer();
    void deletePart();
    void fillWithNumbers();
    void print(); // printing map and vector
    void sync(); // main algoritm
    void checkIfOk(); // Check if task is done correctly
};


#endif
