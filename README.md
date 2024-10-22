
```markdown
# Data Structures and Algorithms in C

This repository contains implementations of various data structures and algorithms in C, aimed at helping students and enthusiasts learn and practice DSA concepts. Each implementation is designed to be clear, concise, and easy to understand, making it suitable for beginners and intermediate learners.

## Table of Contents

- [Introduction](#introduction)
- [Data Structures](#data-structures)
  - [Stack](#stack)
  - [Queue](#queue)
  - [Linked List](#linked-list)
  - [Doubly Linked List](#doubly-linked-list)
- [Searching Algorithms](#searching-algorithms)
  - [Linear Search](#linear-search)
  - [Binary Search](#binary-search)
- [Sorting Algorithms](#sorting-algorithms)
  - [Bubble Sort](#bubble-sort)
  - [Insertion Sort](#insertion-sort)
  - [Selection Sort](#selection-sort)
  - [Merge Sort](#merge-sort)
- [Contributing](#contributing)
- [License](#license)

## Introduction

Data Structures and Algorithms (DSA) form the backbone of efficient programming and problem-solving. This repository serves as a practical guide to implementing fundamental DSA concepts using the C programming language.

## Data Structures

### Stack

A stack is a linear data structure that follows the Last In First Out (LIFO) principle. This section includes implementations of basic stack operations such as `push`, `pop`, `peek`, and `display`.

### Queue

A queue is a linear data structure that follows the First In First Out (FIFO) principle. The queue implementation provided uses circular logic, and it includes operations such as `enqueue`, `dequeue`, `peek`, and `display`.

### Linked List

A linked list is a data structure consisting of nodes where each node points to the next. This section includes operations for inserting, deleting, and displaying nodes in the linked list.

### Doubly Linked List

A doubly linked list is an extension of the linked list where each node has pointers to both the next and previous nodes. Implementations include insertion, deletion, and display operations.

## Searching Algorithms

### Linear Search

Linear search is a simple searching algorithm that checks each element in the array sequentially until the desired element is found.

### Binary Search

Binary search is a more efficient searching algorithm that works on sorted arrays. It divides the search interval in half repeatedly, allowing for quicker searches.

## Sorting Algorithms

### Bubble Sort

Bubble sort is a simple sorting algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order.

### Insertion Sort

Insertion sort builds the final sorted array one item at a time. It is much less efficient on large lists than more advanced algorithms.

### Selection Sort

Selection sort is a simple comparison-based sorting algorithm that divides the input list into two parts: the sorted part and the unsorted part.

### Merge Sort

Merge sort is a divide-and-conquer algorithm that divides the array into halves, recursively sorts them, and then merges the sorted halves back together.

## Usage

To use any of the implementations, follow these steps:

1. **Clone the Repository:**
   ```bash
   git clone https://github.com/yourusername/dsa-in-c.git
   cd dsa-in-c
   ```

2. **Compile the Desired Program:**
   Use a C compiler to compile the specific program you wish to run, for example:
   ```bash
   gcc merge_sort.c -o merge_sort
   ```

3. **Run the Executable:**
   Execute the program:
   ```bash
   ./merge_sort
   ```

4. **Input:**
   Follow the prompts to enter data for the algorithm or data structure you are testing.

## Contributing

Contributions are welcome! If you have suggestions for improvements, additional algorithms, or data structures to implement, feel free to create an issue or submit a pull request.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
