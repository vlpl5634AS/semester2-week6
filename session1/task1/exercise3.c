#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Prints all values from the numbers array
 *
 * @param count number of values in the array
 * @param numbers the array of values
 */
void print_all(int count, int *numbers) {
  for (int i = 0; i < count; i++) {
    printf("%d%c", numbers[i], (i == count - 1) ? '\n' : ' ');
  }
}

/**
 * @brief calculates and returns the sum of values in an array
 *
 * @param count the number of values in numbers
 * @param numbers the array
 * @return int the sum of values
 */
int sum_all(int count, int *numbers) {
  int total = 0;

  for (int i = 0; i < count; i++) {
    total += numbers[i];
  }

  return total;
}
/**
 * @brief calculates and returns the minimum value in an array
 *
 * @param count the number of values in numbers
 * @param numbers the array
 * @return int the minimum value in numbers
 */
int min_all(int count, int *numbers) {
  int min = numbers[0];
  for (int i = 1; i < count; i++) {
    if (numbers[i] < min) {
      min = numbers[i];
    }
  }
  return min;
}
/**
 * @brief calculates and returns the maximum value in an array
 *
 * @param count the number of values in numbers
 * @param numbers the array
 * @return int the maximum value in numbers
 */
int max_all(int count, int *numbers) {
  int max = numbers[0];
  for (int i = 1; i < count; i++) {
    if (numbers[i] > max) {
      max = numbers[i];
    }
  }
  return max;
}
/**
 * @brief calculates and returns the range of values in an array
 *
 * @param count the number of values in numbers
 * @param numbers the array
 * @return int the range of values in numbers
 */
int range_all(int count, int *numbers) {
  int min = min_all(count, numbers);
  int max = max_all(count, numbers);

  return max - min;
}
/**
 * @brief calculates and returns the most recurring value in an array
 * 
 * @param count the number of values in numbers
 * @param numbers the array
 * @return int the most recurring value in numbers
 */
int mode_all(int count, int *numbers) {
  int max_count = 0;
  int mode = numbers[0];

  for (int i = 0; i < count; i++) {
    int current_count = 0;

    for (int j = 0; j < count; j++) {
      if (numbers[j] == numbers[i]) {
        current_count++;
      }
    }

    if (current_count > max_count) {
      max_count = current_count;
      mode = numbers[i];
    }
  }

  return mode;
}
  /**
   *@brief sort the array from smallest to largest
    *
    *@param count the number of values in numbers
    *@param numbers the array
    *@return sorted array
   */
  int *sort_all(int count, int *numbers) {
    int *sorted = malloc(count * sizeof(int));
    for (int i = 0; i < count; i++) {
      sorted[i] = numbers[i];
    }

    for (int i = 0; i < count - 1; i++) {
      for (int j = 0; j < count - i - 1; j++) {
        if (sorted[j] > sorted[j + 1]) {
          int temp = sorted[j];
          sorted[j] = sorted[j + 1];
          sorted[j + 1] = temp;
        }
      }
    }

    return sorted;

}
/**
 * @brief calculates and returns the median value in an array
 * 
 * @param count the number of values in numbers
 * @param numbers the array
 * @return float the median value in numbers
 */
float median_all(int count, int *numbers) {
  int *sorted = sort_all(count, numbers);
  float median;

  if (count % 2 == 0) {
    median = (sorted[count / 2 - 1] + sorted[count / 2]) / 2.0;
  } else {
    median = sorted[count / 2];
  }

  free(sorted);
  return median;
}
/**
 * @brief Calculates the mean average of values in an array
 *
 * @param count the number of values in the array
 * @param numbers the array
 * @return float the mean average of the values
 */
float average_all(int count, int *numbers) {
  // re-using sum_all()
  int total = sum_all(count, numbers);

  return (float)total / count;
}

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("Usage: ./averages num1 ... numx\n");
    return 0;
  }

  int *numbers;
  int count = argc - 1;
  char buffer[50];
  int choice = 0;
  int total = 0;
  float mean;

  numbers = calloc(count, sizeof(int));

  for (int i = 0; i < count; i++) {
    int check = sscanf(argv[i + 1], "%d", &numbers[i]);

    if (check != 1) {
      printf("Error: Non-numerical Argument\n");
      return 1;
    }
  }

  do {
    printf("1 - Show all values\n");
    printf("2 - Calculate sum\n");
    printf("3 - Calculate mean\n");
    printf("4 - Calculate median\n");
    printf("5 - Calculate mode\n");
    printf("6 - Calculate range\n");
    printf("7 - sort values\n");
    printf("8 - exit\n");

    printf("Enter choice: ");
    fgets(buffer, sizeof(buffer), stdin);
    int check = sscanf(buffer, "%d ", &choice);

    if (check != 1) {
      printf("Error: Invalid choice\n");
      continue;
    }

    switch (choice) {
    case 1:
      print_all(count, numbers);
      break;
    case 2:
      total = sum_all(count, numbers);
      printf("Total is: %d\n", total);
      break;
    case 3:
      mean = average_all(count, numbers);
      printf("Average is: %.2f\n", mean);
      break;
    case 4:
      printf("Median is: %.2f\n", median_all(count, numbers));
      break;
    case 5:
      printf("Mode is: %d\n", mode_all(count, numbers));
      break;
    case 6:
      printf("Range is: %d\n", range_all(count, numbers));
      break;
    case 7: {
      int *sorted = sort_all(count, numbers);
      print_all(count, sorted);
      free(sorted);
      break;
    }
    case 8:
      printf("Exiting...\n");
      break;
    
      default:
      printf("Error: Invalid choice\n");
      break;
    }
  } while (choice != 8);

  free(numbers);
  return 0;
}