// 
//

#include <iostream>
#include "HashList.h"

int main()
{
    // Create a HashList object with size 10
    HashList hashList(2);

    // Add some values to the HashList
    hashList.add("apple");
    hashList.add("banana");
    hashList.add("cherry");
    hashList.add("date");
    hashList.add("elderberry");

    // Display the elements in the HashList
    hashList.display();

    // Delete the node with value "date"
    cout << "\nDelete the node with value \"date\"";
    hashList.del("date");

    // Display the elements in the HashList after deletion
    hashList.display();

}