# Week 2 Mon Lab (part-a)

## Directions

You will be reviewing the basic operations regarding pointers by creating a food ordering system. This file in this repository contains a `main` function along with two other functions. In the `main` function, there are two **TODO** tasks:

1. Allocate dynamic memory for the array (stored in the `dynArr` variable)
1. Release the dynamic memory you created for `dynArr`

The `populate` function needs to use a loop to get input from the user. Store the input to the appropriate location in the array pointer. The `printFood` function needs to also use a loop to traverse the array pointer and display the food orders that the user placed. Additionally, for each element, display the memory address it is stored in.

## Sample Run

The following is a sample run of my solution. You can use this as a model to aim for with your program. Note, it's likely that you will have different memory addresses being displayed than mine.

```
Enter your desired array size: 3

Enter food order #1: Bean Burrito
Enter food order #2: Spicy Pho
Enter food order #3: Orange chicken with white rice

****************************************
Food Order #1
Bean Burrito
(sent from address 0x800012988)
****************************************

****************************************
Food Order #2
Spicy Pho
(sent from address 0x800012990)
****************************************

****************************************
Food Order #3
Orange chicken with white rice
(sent from address 0x800012998)
****************************************
```


