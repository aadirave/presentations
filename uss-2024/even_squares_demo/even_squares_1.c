#include <stdio.h>
#include <stdlib.h>

int is_even(int x) { return (x % 2 == 0); }

int square(int x) { return x * x; }

int sum_squares_of_evens(int *arr, int len) {
  int sum = 0;

  for (int i = 0; i < len; i++) {
    if (is_even(arr[i])) {
      sum += square(arr[i]);
    }
  }

  return sum;
}

int main(void) {
  int arr[] = {1, 2, 3, 4, 5};

  int sum = sum_squares_of_evens(arr, 5);

  fprintf(stdout, "Sum of squares of even numbers: %d\n", sum);

  return EXIT_SUCCESS;
}
