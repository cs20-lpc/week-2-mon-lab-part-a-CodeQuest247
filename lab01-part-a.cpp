#include <cstddef> // Aditi Menon
#include <iostream>
#include <string>
#include <limits> // for clearing input buffer after cin

using namespace std;

/*******************************************************************************
 * Function prototypes
*******************************************************************************/
//Functions prototypes declares the functions and their parameters 

void populate(string*, const unsigned); // string* parameter allows the function to access the dynamic array created in main 
void printFoods(string*, const unsigned); // const unsigned represents the array size and is marked const to prevent any changes to it inside the function

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
    string*  dynArr   = nullptr; // dynArr is a pointer that will later point to a dynamically alloacted array of strings
    unsigned userSize = 0; // Stores the size of the array chosen by the user 

    // get the size for the array from user
    // validation: must not exceed 10
    do {
        cout << "Enter your desired array size: "; // Asks the user for an array size
        cin >> userSize; 
    } while (userSize > 10); // This part makes sure that the size of the array is in between 1 and 10

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clears the leftover newline so that getline can work properly... mixing cin and getline without this would make the program skip the first input line

    // TODO: create the dynamic memory
    dynArr = new string[userSize];// assigns dynArr to point to the first element of the array which the user inputs

    // call the functions
    populate(dynArr, userSize); // Fills the array with the user's input
    printFoods(dynArr, userSize); // Prints the food orders and their memory addresses 

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

// This functions fills the dynamic array with food orders entered by the user 
// arrPtr is a pointer to the first element of the dynamically allocated array
// ARR_SIZE represents how many elements the array contains 
void populate(string* arrPtr, const unsigned ARR_SIZE) {
    for (unsigned i = 0; i < ARR_SIZE; ++i) { // Loops through each position in the array 
        cout << "\nEnter food order #" << (i + 1) << ": "; // asks user to input food item, and (i + 1) is used to make sure the food order number starts from 1 instead of 0
        getline(cin, arrPtr[i]); // arrPtr[i] accesses the string element at index i of the array, and getline stores the user's input into that specific position of the array. 
    }
}

// The populate function prints prompts to guide the user while entering data, while the printFoods function displays the stored data after the array has been filled.
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

// This function prints each food order stored in the dynamic array 
// and print the memory address where each element is stored 
void printFoods(string* arrPtr, const unsigned ARR_SIZE) {
    cout << endl; // space between last input and first list 
    for (unsigned i = 0; i < ARR_SIZE; ++i) { // loops through each element in the array
        cout << "****************************************" << endl; 
        cout << "Food Order #" << (i + 1) << endl; // It first prints the food order number starting from 1 
        cout << arrPtr[i] << endl; // Prints the food order stored at index i of the array 
        cout << "(sent from address " 
             << static_cast<const void*>(&arrPtr[i]) // static_cast makes sure the exact location in memory is printed for each element 
             << ")" << endl; 
        cout << "****************************************" << endl;
        cout << endl; 
    }
}
