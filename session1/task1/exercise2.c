#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PI 3.14159

double rectangle_area(int height, int width) {
  return width * height;
}

double find_circle_area(double radius) {
  return PI * radius * radius;
}

double triangle_area(double base, double height) {
  return 0.5 * base * height;
}

int main(int argc, char *argv[]) {
  if (argc < 3) {
    printf("Usage:\n");
    printf("  ./shapes rectangle width height\n");
    printf("  ./shapes triangle base height\n");
    printf("  ./shapes circle radius\n");
    return 1;
  }

  char *shape = argv[1];

  if (strcmp(shape, "rectangle") == 0) {
    if (argc != 4) {
      printf("Error: Rectangle needs width and height.\n");
      return 1;
    }
    double width = strtod(argv[2], NULL);
    double height = strtod(argv[3], NULL);
    printf("Rectangle Area: %.2f\n", rectangle_area(width, height));
  }
  
  else if (strcmp(shape, "triangle") == 0) {
    if (argc != 4) {
      printf("Error: Triangle needs base and height.\n");
      return 1;
    }
    double base = strtod(argv[2], NULL);
    double height = strtod(argv[3], NULL);
    printf("Triangle Area: %.2f\n", triangle_area(base, height));
  }
  
  else if (strcmp(shape, "circle") == 0) {
    if (argc != 3) {
      printf("Error: Circle needs radius.\n");
      return 1;
    }
    double radius = strtod(argv[2], NULL);
    printf("Circle Area: %.2f\n", find_circle_area(radius));
  } else {
    printf("Error: Unknown shape '%s'. Use rectangle, triangle, or circle.\n",
           shape);
    return 1;
  }

  return 0;
}