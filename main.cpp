
#include "Synchronizer.hpp"

int main() {

    Synchronizer synchronizer;
    synchronizer.fillWithNumbers();
    std::cout << RED << "Starting arrays " << std::endl;
    synchronizer.print();
    synchronizer.deletePart();
    std::cout << GREEN << "After deletion " << std::endl;
    synchronizer.print();
    synchronizer.sync();
    std::cout << YELLOW << "After synchronization " << std::endl;
    synchronizer.print();
    std::cout << RESET << "Check if synchronized: ";
    synchronizer.checkIfOk();
    std::cout << std::endl;
    return 0;
}