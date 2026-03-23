#ifndef HYPERLIB_SORT_H
#define HYPERLIB_SORT_H

/**
 * This global function sorts n elements at the end of int *arr using heap sort.
 * @brief H_sort
 * @param int_ptr arr
 * @param u_int n
*/
static inline void Heap_sort(int *arr, unsigned int n);

/**
 * @brief Quick Sort
 * @details Uses a divide-and-conquer strategy. Typically the fastest
 * general-purpose sort for large datasets.
 * @param arr Pointer to the integer array
 * @param n Number of elements
 */
static inline void Quick_sort(int *arr, unsigned int n);

/**
 * @brief Merge Sort
 * @details A stable, divide-and-conquer algorithm. Requires O(n) extra space.
 * Guarantees O(n log n) performance.
 * @param arr Pointer to the integer array
 * @param n Number of elements
 */
static inline void Merge_sort(int *arr, unsigned int n);

/**
 * @brief Insertion Sort
 * @details Efficient for small data sets (n < 16) and nearly sorted arrays.
 * It is a stable sorting algorithm with O(n^2) worst-case complexity.
 * @param arr Pointer to the integer array
 * @param n Number of elements
 */
static inline void Insertion_sort(int *arr, unsigned int n);

/**
 * @brief Bubble Sort
 * @details Repeatedly steps through the list, compares adjacent elements and swaps them if they are in the wrong order.
 * High complexity O(n^2), primarily used for educational purposes.
 * @param arr Pointer to the integer array
 * @param n Number of elements
 */
static inline void Bubble_sort(int *arr, unsigned int n);

/**
 * @brief Selection Sort
 * @details Divides the input list into two parts: a sorted sublist and an unsorted sublist.
 * It repeatedly finds the minimum element from the unsorted part and puts it at the beginning.
 * Performance is O(n^2), but it minimizes the number of swaps.
 * @param arr Pointer to the integer array
 * @param n Number of elements
 */
static inline void Selection_sort(int *arr, unsigned int n);

/**
 * @brief Shell Sort
 * @details An optimization of insertion sort that allows the exchange of
 * items that are far apart.
 * @param arr Pointer to the integer array
 * @param n Number of elements
 */
static inline void Shell_sort(int *arr, unsigned int n);

/**
 * @brief Counting Sort
 * @details A non-comparative sorting algorithm. Extremely fast O(n + k)
 * when the range of input data (max_val) is not significantly larger than n.
 * @param arr Pointer to the integer array
 * @param n Number of elements
 * @param max_val The maximum value present in the array
 */
static inline void Counting_sort(int *arr, unsigned int n, int max_val);

/**
 * @brief Radix Sort
 * @details Sorts integers by processing individual digits.
 * Avoids comparisons by using counting sort as a subroutine.
 * @param arr Pointer to the integer array
 * @param n Number of elements
 */
static inline void Radix_sort(int *arr, unsigned int n);
#endif