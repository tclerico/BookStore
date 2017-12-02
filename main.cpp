#include <iostream>
#include "BookStore.h"


int main() {

    BookStore* inventory = new BookStore();

    inventory->add("Hatchet", 3, 7);

    std::cout << inventory->printInventory() << std::endl;

    std::cout << "\n adding new book... \n" << std::endl;

    inventory->add("Of Mice and Men", 6, 4);

    std::cout << inventory->printInventory() << std::endl;

    std::cout << "\n adding existing book... \n" << std::endl;

    inventory->add("Of Mice and Men", 6, 4);

    return 0;
}