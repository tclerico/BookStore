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

    std::cout << "\n adding more books... \n" << std::endl;

    inventory->add("To Kill a Mockingbird", 2, 5);

    inventory->add("It", 1, 3);

    inventory->add("Harry Potter", 4, 2);

    std::cout << inventory->printInventory() << std::endl;

    return 0;
}