# DAA-LAB

# Lab Day 1: Revision of Data Structures

This repository contains four programs focused on data structures. Each program performs different operations on arrays and demonstrates fundamental concepts in programming.

## Programs

### 1. Program to Find Second Smallest and Second Largest Element in an Array

**Aim:** Write a program to find out the second smallest and second largest element stored in an array of `n` integers. The size of the array is `n`, and `n` number of elements are read from a disc file.

**Input:** 
- Size of the array `n`
- `n` number of elements from a disc file

**Output:**
- Second smallest element
- Second largest element

### 2. Program to Find Prefix Sum of an Array

**Aim:** Given an array `arr[]` of size `N`, find the prefix sum of the array. A prefix sum array is another array `prefixSum[]` of the same size, such that the value of `prefixSum[i]` is `arr[0] + arr[1] + arr[2] ... + arr[i]`.

**Input:**
- Array: `3, 4, 5, 1, 2`

**Output:**
- Prefix Sum Array: `3, 7, 12, 13, 15`

### 3. Program to Perform Operations on an Array with Duplicate Values

**Aim:** Write a program to read `n` integers from a disc file that must contain some duplicate values and store them into an array. Perform the following operations on the array:
- Find out the total number of duplicate elements.
- Find out the most repeating element in the array.

**Input:**
- Number of elements to read: `15`

**Output:**
- The content of the array: `10, 40, 35, 47, 68, 22, 40, 10, 98, 10, 50, 35, 68, 40, 10`
- Total number of duplicate values: `4`
- The most repeating element in the array: `10`

### 4. Program to Rotate an Array to the Right

**Aim:** Write a function to `ROTATE_RIGHT(p1, p2)` an array for the first `p2` elements by 1 position using `EXCHANGE(p, q)` function that swaps/exchanges the numbers `p` and `q`. Parameter `p1` is the starting address of the array and `p2` is the number of elements to be rotated.

**Input:**
- Array of size `N` (9): `11, 22, 33, 44, 55, 66, 77, 88, 99`
- Call the function `ROTATE_RIGHT(A, 5)`

**Output:**
- Before ROTATE: `11, 22, 33, 44, 55, 66, 77, 88, 99`
- After ROTATE: `55, 11, 22, 33, 44, 66, 77, 88, 99`



# Lab Day 2: Fundamentals of Algorithmic Problem Solving

## Program 1: Convert Decimal to Binary using Recursion

### Aim of the Program
Write a program in C to convert the first ‘n’ decimal numbers from a disc file to binary using recursion. Store the binary values in a separate disc file.

### Notes
- Read the value of ‘n’, source file name, and destination file name from command line arguments.
- Display the decimal numbers and their equivalent binary numbers from the output file.

### Example Input File: `inDec.dat`
```
30 75 2564 ...
```

### Example Output File: `outBin.dat`
```
The binary equivalent of 30 is 0000000000011110
The binary equivalent of 75 is 0000000001001011
The binary equivalent of 2564 is 0000101000000100
```

### Terminal Commands
```sh
$ gcc lab2q1.c -o lab2q1
$ ./lab2q1 150 inDec.dat outBin.dat
```

### Expected Output
Content of the first ‘n’ decimal numbers and their equivalent binary numbers.

## Program 2: Find GCD of Two Numbers using Recursion

### Aim of the Program
Write a program in C to find the GCD of two numbers using recursion. Read all pairs of numbers from a file and store the result in a separate file.

### Notes
- Source file name and destination file name are taken from command line arguments.
- The source file must contain at least 20 pairs of numbers.

### Example Input File: `inGcd.dat`
```
8 12 20 45 30 80 ...
```

### Example Output File: `outGcd.dat`
```
The GCD of 8 and 12 is 4
The GCD of 20 and 45 is 5
The GCD of 30 and 80 is 10
```

### Terminal Commands
```sh
$ gcc lab2q2.c -o lab2q2
$ ./lab2q2 inGcd.dat outGcd.dat
```

### Expected Output
Display the GCD stored in the output file `outGcd.dat`.


---

# Divide and Conquer Method - Lab Day 3

## Overview

This lab exercise consists of two primary tasks that demonstrate sorting techniques using the Divide and Conquer method. The tasks involve implementing Merge Sort and Quick Sort algorithms, reading input data from files, and evaluating the performance of these algorithms based on execution time and the number of comparisons made during the sorting process.

---

## Task 1: Merge Sort Implementation

### Objective:
- Write a menu-driven program to sort a list of array elements using the Merge Sort technique.
- Calculate and display the execution time required to sort the elements.
- Count and display the number of comparisons made during sorting.

### Input Files:
- **inAsce.dat**: Contains data in ascending order (e.g., `10 20 30 40 ...`).
- **inDesc.dat**: Contains data in descending order (e.g., `90 80 70 60 ...`).
- **inRand.dat**: Contains random data (e.g., `55 66 33 11 44 ...`).

### Output Files:
- **outMergeAsce.dat**: Stores sorted output for ascending data.
- **outMergeDesc.dat**: Stores sorted output for descending data.
- **outMergeRand.dat**: Stores sorted output for random data.

### Main Menu:
```
MAIN MENU (MERGE SORT)
1. Ascending Data
2. Descending Data
3. Random Data
4. ERROR (EXIT)
```

### Expected Output:
- Display the content of the input file before sorting.
- Display the content of the output file after sorting.
- Display the number of comparisons made during sorting.
- Display the execution time in nanoseconds.

---

## Task 2: Quick Sort Implementation

### Objective:
- Write a menu-driven program to sort a list of array elements in ascending order using the Quick Sort technique.
- Calculate and display the number of comparisons made during sorting.
- Determine and display whether the partitioning scenario is the best-case or worst-case scenario.

### Input Files:
- **inAsce.dat**: Contains data in ascending order (e.g., `10 20 30 40 ...`).
- **inDesc.dat**: Contains data in descending order (e.g., `90 80 70 60 ...`).
- **inRand.dat**: Contains random data (e.g., `55 66 33 11 44 ...`).

### Output Files:
- **outQuickAsce.dat**: Stores sorted output for ascending data.
- **outQuickDesc.dat**: Stores sorted output for descending data.
- **outQuickRand.dat**: Stores sorted output for random data.

### Main Menu:
```
MAIN MENU (QUICK SORT)
1. Ascending Data
2. Descending Data
3. Random Data
4. ERROR (EXIT)
```

### Expected Output:
- Display the content of the input file before sorting.
- Display the content of the output file after sorting.
- Display the number of comparisons made during sorting.
- Display whether the partitioning scenario is best-case or worst-case based on the partitioning behavior.

### Partitioning Scenarios:
- **Best-case**: The partitioning routine produces two subproblems, each of size no more than n/2.
- **Worst-case**: The partitioning routine produces one subproblem with n-1 elements and one with 0 elements.

---

## Notes:
- Ensure that each input file contains between 300 to 500 entries.
- For the Quick Sort, partitioning scenarios must be carefully evaluated to determine the nature of the input data's impact on the sorting process.

# Task 3: Find MIN_MAX Using Divide & Conquer Rule 


# Lab Day 4: Heap

## 4.1 Aim of the Program

The aim of this program is to define a `struct person` and implement a menu-driven program that reads the data of `n` students from a file, stores them in a dynamically allocated array of struct `person`, and implements heap operations.

### Definition of `struct person`:

```c
struct person {
    int id;
    char *name;
    int age;
    int height;
    int weight;
};
```

### Menu-Driven Program:

The program allows the user to perform various operations on the heap:

- **Option 1:** Read Data from a file and store it in a dynamically allocated array of struct `person`.
- **Option 2:** Create a Min-heap based on the `age` of the person.
- **Option 3:** Create a Max-heap based on the `weight` of the person.
- **Option 4:** Display the `weight` of the youngest person in the heap.
- **Option 5:** Insert a new person into the Min-heap.
- **Option 6:** Delete the oldest person from the heap.
- **Option 7:** Exit the program.

### Sample Input/Output:

```
MAIN MENU (HEAP)
1. Read Data
2. Create a Min-heap based on the age
3. Create a Max-heap based on the weight
4. Display weight of the youngest person
5. Insert a new person into the Min-heap
6. Delete the oldest person
7. Exit

Enter option: 1 

Id    Name                Age  Height  Weight (pound)
0     Adarsh Hota         39   77      231
1     Levi Maier          56   77      129
2     Priya Kumari        63   78      240
3     Dorothy Helton      47   72      229
4     Florence Smith      24   75      171
5     Erica Anyan         38   73      102
6     Norma Webster       23   75      145

Enter option: 4
Weight of the youngest person: 65.77 kg
```

**Note**: Other menu choices are similarly verified based on the user's input and the heap operations.
