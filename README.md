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

