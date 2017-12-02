#include <iostream>
#include "BookStore.h"
#include "Book.h"

int main() {

    BookStore* inventory = new BookStore();

    inventory->add("Hatchet", 3, 7);

    std::cout << inventory->printInventory() << std::endl;

    return 0;
}