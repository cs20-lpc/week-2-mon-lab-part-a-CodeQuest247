#include <cstddef>
#include <iostream>
#include <string>

using namespace std;

/*******************************************************************************
 * Function prototypes
*******************************************************************************/

void populate(string*, const unsigned);
void printFoods(string*, const unsigned);

/*******************************************************************************
 * Description:
 * Starting point of the program. Creates a dynamic array of strings. User gets
 * to specify their desired size. Calls functions. Releases dynamic memory.
 * 
 * Input:
 * N/A
 *
 * Output:
 * An integer to signal to the OS the exit code.
*******************************************************************************/

int main() {
    // variables
    string*  dynArr   = nullptr;
    unsigned userSize = 0;

    // get the size for the array from user
    // validation: must not exceed 10
    do {
        cout << "Enter your desired array size: ";
        cin >> userSize;
    } while (userSize > 10);

    // TODO: create the dynamic memory

    // call the functions
    populate(dynArr, userSize);
    printFoods(dynArr, userSize);

    // TODO: release the dynamic memory to avoid a memory leak

    // terminate
    return 0;
}

/*******************************************************************************
 * Description:
 * Gets data from the user to populate the array pointed to by `arrPtr`.
 * 
 * Input:
 * arrPtr   - a pointer to the beginning of a string array
 * ARR_SIZE - a constant unsigned integer containing the size of the array
 *            pointed to by `arrPtr` (the number of elements)
 *
 * Output:
 * N/A
*******************************************************************************/

void populate(string* arrPtr, const unsigned ARR_SIZE) {
    // TODO
}

/*******************************************************************************
 * Description:
 * Displays the information stored in the array pointed to by `arrPtr`. Also
 * prints what memory address each element is stored in.
 * 
 * Input:
 * arrPtr   - a pointer to the beginning of a string array
 * ARR_SIZE - a constant unsigned integer containing the size of the array
 *            pointed to by `arrPtr` (the number of elements)
 *
 * Output:
 * N/A
*******************************************************************************/

void printFoods(string* arrPtr, const unsigned ARR_SIZE) {
    // TODO
}
