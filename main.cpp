#include <iostream>
#include "BookStore.h"
#include "LinkedQueue.h"
//#include "Person.h"

int main() {
    /**
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

    //LinkedQueue* queue = new LinkedQueue(); //i tried to create a linkedqueue but it didnt let me becuase of an error and linkedNode
    **/

    Person* test = new Person("name","email","phone","email");
    std::cout<<test->getName()<<std::endl;

    return 0;
}