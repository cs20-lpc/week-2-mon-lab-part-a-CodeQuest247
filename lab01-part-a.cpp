#include <cstddef>
#include <iostream>
#include <string>
#include <limits>

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

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // TODO: create the dynamic memory
    dynArr = new string[userSize]; 

    // call the functions
    populate(dynArr, userSize);
    printFoods(dynArr, userSize);

    // TODO: release the dynamic memory to avoid a memory leak
    delete[] dynArr; 
    dynArr = nullptr; 

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
    for (unsigned i = 0; i < ARR_SIZE; ++i) {
        cout << "\nEnter food order #" << (i + 1) << ": "; 
        getline(cin, arrPtr[i]); // sotres the input into the i-th element 
    }
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
    cout << endl; // space between last input and first list 
    for (unsigned i = 0; i < ARR_SIZE; ++i) {
        cout << "****************************************" << endl; 
        cout << "Food Order #" << (i + 1) << endl; 
        cout << arrPtr[i] << endl; 
        cout << "(sent from address " 
             << static_cast<const void*>(&arrPtr[i]) 
             << ")" << endl; 
        cout << "****************************************" << endl;
        cout << endl; 
    }
}
