# Program to Find the k-th Smallest Value

## Purpose
The purpose of this program is to find the k-th smallest value in a given dataset as quickly as possible. The program demonstrates an understanding of Binary Search Trees and recursion to lower the speed as much as possible.

## Inputs
To run the program, use the makefile command 'make run'. The program prompts the user to enter the following inputs:

Whether the user wants to use the default dataset or not. If not, the user can choose their own data in the sortArray Vector
An integer value k for the k-th smallest value. The limit will be printed for the user's convenience.

## Outputs
The program outputs the following:

- The binary tree representation of the dataset using an in-order traversal, with values printed in numeric order.
- The k-th smallest value in the dataset.
- Post Order Destroy (to deallocate the data stored on the Heap)

## Usage
To run the program, simply use the makefile command 'make run'. Follow the instructions in the prompt to input the necessary values.

## Changes : File -> [`KthSmallestElement`](/kthSmallestElementAlt.cpp)

My professor was teaching us about exceptions in software design, and I thought I could use exceptions to exit from recursion stacks instead of having a base condition. 
This is a simpler version of the kth smallest element, which is much easier to understand. 



## Future Improvements
This program could be further improved by implementing other data structures, such as heaps or priority queues, to improve the efficiency and speed of finding the k-th smallest value in a dataset.
