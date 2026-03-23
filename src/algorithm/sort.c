#include <stdlib.h>
#include "../../core.h"

static inline void Heap_sort(int *arr, unsigned int n) {
    unsigned int i, j, l, r, largest;

    for (i = n / 2; i-- > 0;) {
        for (j = i;; j = largest) {
            l = 2 * j + 1;
            r = l + 1;
            largest = j;

            if (l < n && arr[l] > arr[largest]) {
                largest = l;
            }

            if (r < n && arr[r] > arr[largest]) {
                largest = r;
            }

            if (largest == j) {
                break;
            }

            swap(arr[j], arr[largest]);
        }
    }

    while (n-- > 1) {
        swap(arr[0], arr[n]);

        for (j = 0;; j = largest) {
            l = 2*j + 1;
            r = l + 1;
            largest = j;

            if (l < n && arr[l] > arr[largest]) {
                largest = l;
            }

            if (r < n && arr[r] > arr[largest]) {
                largest = r;
            }

            if (largest == j) {
                break;
            }

            swap(arr[j], arr[largest]);
        }
    }
}

static inline void Quick_sort(int *arr, unsigned int n) {
    if (n < 2) {
        return;
    }

    int pivot = arr[n / 2];
    int *left = arr;
    int *right = arr + n - 1;

    while (left <= right) {
        while (*left < pivot) {
            left++;
        }

        while (*right > pivot) {
            right--;
        }

        if (left <= right) {
            int temp = *left;
            *left = *right;
            *right = temp;
            left++;
            right--;
        }
    }

    Quick_sort(arr, right - arr + 1);
    Quick_sort(left, (arr + n) - left);
}

static inline void Merge_sort(int *arr, unsigned int n) {
    if (n < 2) return;

    unsigned int mid = n / 2;
    Merge_sort(arr, mid);
    Merge_sort(arr + mid, n - mid);

    int *temp = (int *)malloc(n * sizeof(int));
    unsigned int i = 0, j = mid, k = 0;

    while (i < mid && j < n) {
        if (arr[i] <= arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }

    while (i < mid) temp[k++] = arr[i++];
    while (j < n) temp[k++] = arr[j++];

    for (i = 0; i < n; i++) arr[i] = temp[i];
    free(temp);
}

static inline void Insertion_sort(int *arr, unsigned int n) {
    for (unsigned int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

static inline void Bubble_sort(int *arr, unsigned int n) {
    for (unsigned int i = 0; i < n - 1; i++) {
        for (unsigned int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

static inline void Selection_sort(int *arr, unsigned int n) {
    for (unsigned int i = 0; i < n - 1; i++) {
        unsigned int min_idx = i;
        for (unsigned int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) min_idx = j;
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

static inline void Shell_sort(int *arr, unsigned int n) {
    for (unsigned int gap = n / 2; gap > 0; gap /= 2) {
        for (unsigned int i = gap; i < n; i++) {
            int temp = arr[i];
            unsigned int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

static inline void Counting_sort(int *arr, unsigned int n, int max_val) {
    int *count = (int *)calloc(max_val + 1, sizeof(int));
    int *output = (int *)malloc(n * sizeof(int));

    for (unsigned int i = 0; i < n; i++) count[arr[i]]++;
    for (int i = 1; i <= max_val; i++) count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (unsigned int i = 0; i < n; i++) arr[i] = output[i];

    free(count);
    free(output);
}

static inline void Radix_sort(int *arr, unsigned int n) {
    int max = arr[0];
    for (unsigned int i = 1; i < n; i++) if (arr[i] > max) max = arr[i];

    int *output = (int *)malloc(n * sizeof(int));
    if (!output) return;

    for (int exp = 1; max / exp > 0; exp *= 10) {
        int count[10] = {0};

        for (unsigned int i = 0; i < n; i++) count[(arr[i] / exp) % 10]++;
        for (int i = 1; i < 10; i++) count[i] += count[i - 1];

        for (int i = n - 1; i >= 0; i--) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }
        for (unsigned int i = 0; i < n; i++) arr[i] = output[i];
    }

    free(output);
}