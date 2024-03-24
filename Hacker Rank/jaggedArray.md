# Jagged Array Query Processor

This C++ program is designed to handle queries on a jagged array. A jagged array is an array of arrays where each array can have a different size. The program reads input data representing a jagged array, processes queries on that array, and prints the results.

## Problem Description

Given a jagged array and a set of queries in the form of (x, y) pairs, where x represents the index of the sub-array within the jagged array and y represents the index within that sub-array, the program aims to retrieve the value at the specified index.

## Usage

### Input Format:

The input consists of the following:
- The first line contains an integer representing the size of the jagged array.
- The second line contains an integer representing the number of queries.
- The next 'size of jagged array' lines contain space-separated integers representing the elements of each sub-array in the jagged array.

### Output Format:

The program outputs the result of each query on a new line.

### Example:

#### Input:

3
2
1 2 3
4 5
6 7 8 9
0 1
2 2


#### Output:

2
8


### Error Handling:

The program provides error handling for the following scenarios:
- Invalid size for the jagged array (must be positive).
- Negative number of queries.
- Empty strings in the input.
- Out-of-bounds access during queries.

## Running the Program

To run the program, compile the source code (`jaggedArray.cpp`) using a C++ compiler, then execute the compiled binary.

