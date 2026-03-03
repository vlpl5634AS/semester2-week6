#include <stdlib.h>
#include <stdio.h>

/**
 * @brief recursively calculates the factorial of an integer n.
 * 
 * @param n number to find factorial of.
 * @return int n factorial.
 */
int factorial(int n) {
  // the base case - this determines when the recursion should stop
  if (n == 0) {
    return 1;
  }

  return n * factorial(n - 1);
}

/**
 * @brief calculate n factorial
 * 
 * @param n number to find factorial of.
 * @return int n factorial.
 */
int n_factorial(int n) {
  if (n < 0) {
    return -1; // error case for negative numbers
  }
  return factorial(n);
}

/**
 * @brief calculate r factorial
 * 
 * @param r number to find factorial of.
 * @return int r factorial.
 */
int r_factorial(int r) {
  if (r < 0) {
    return -1; // error case for negative numbers
  }
  return factorial(r);
}

int main(int argc, char **argv) {
  /*
  The program should accept a command line argument as follows:
  ./combinatorials n C r
  ./combinatorials n P r

  where n and r are both positive integers, and r is always less than or equal to n.

  for example:
  ./combinatorials 7 C 2

  Your program should then calculate and print out the correct result

  nCr should return the total combinations of r items out of n.
  This is calculated by: n! / (r! (n - r)!)

  nPr should return the total permutations of r items out of n.
  This is calculated by: n! / (n-r)!

  Add appropriate validation to your program to make your code robust.

  You should try and use functions to write your program.

  */
  if (argc != 4) {
    printf("Usage: ./combinatorials n C|P r\n");
    return 1;
  }
  else if (argc == 4) {
    int n = atoi(argv[1]);
    char operation = argv[2][0];
    int r = atoi(argv[3]);

    if (n < 0 || r < 0 || r > n) {
      printf("Error: n and r must be positive integers, and r must be less than or equal to n.\n");
      return 1;
    }

    if (operation == 'C') {
      int result = n_factorial(n) / (r_factorial(r) * factorial(n - r));
      printf("nCr: %d\n", result);

    } else if (operation == 'P') {
      int result = n_factorial(n) / factorial(n - r);
      printf("nPr: %d\n", result);

    } else {
      printf("Error: Operation must be 'C' for combinations or 'P' for permutations.\n");
      return 1;
    }
  {
    /* code */
  }
  return 0;
}
}