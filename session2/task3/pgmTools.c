#include <stdlib.h>
#include <stdio.h>

int getUserInput(unsigned char *message);
void menu(void);
unsigned char **allocateArray(int height, int width);
unsigned char **read(unsigned char *fn, int *a, int *b);
void printImage(unsigned char **p, int a, int b);

int main(int argc, unsigned char **argv) {
  if (argc != 2) {
    printf("Usage: ./pgmTools image_path\n"); // error message if the user does not provdie the required number of arguments
    return 0;
  }

  int a, b;
  unsigned char **i;
  i = read(argv[1], &a, &b); 

  int c = -1;

  do {
    c = -1;
    menu();
    while (c < 1)
      c = getUserInput("Enter choice"); //get user input and validate it, if the user input is not a number or is less than 1, it will keep asking for input until a valid input is provided

    switch (c) {
    case 1:
      printImage(i, a, b);
      break;
    case 2:
      break;
    case 3:
      break;
    case 4:
      break;
    case 5:
      return 0;
    default:
      printf("Bad choice\n");
      break;
    }
  } while (1);
}

int getUserInput(unsigned char *message) {
  unsigned char buffer[100];
  int choice;
  printf("%s: ", message);
  fgets(buffer, 100, stdin);
  int check = sscanf(buffer, "%d", &choice);
  if (!check) {
    return -1;
  }
  return choice;
}

void menu(void) {
  printf("1 - View PGM Image\n");
  printf("2 - Invert Image\n");
  printf("3 - Rotate Image\n");
  printf("4 - Scale Image\n");
  printf("5 - quit\n");
}

unsigned char **allocateArray(int height, int width) {
  unsigned char **array = calloc(height, sizeof(unsigned char *));
  for (int i = 0; i < height; i++) {
    array[i] = calloc(width, sizeof(unsigned char));
  }

  return array;
}

unsigned char **read(unsigned char *fn, int *a, int *b) {
  unsigned char temp[10];
  int h, w;
  FILE *f = fopen(fn, "r");
  fscanf(f, "%s ", temp);
  fscanf(f, "%d %d", &h, &w);
  fscanf(f, "%s ", temp);
  unsigned char **p = allocateArray(h, w);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      fscanf(f, "%hhd", &p[i][j]);
    }
  }
  *a = h;
  *b = w;
  return p;
}

void printImage(unsigned char **p, int a, int b) {
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < b; j++) {
      printf("%d%s", p[i][j],
             (p[i][j] < 100) ? (p[i][j] < 10) ? "   " : "  " : " ");
    }
    printf("\n");
  }

}

void invertImage(unsigned char **p, int a, int b) {
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < b; j++) {
      p[i][j] = 255 - p[i][j];
    }
    printf("\n");
  }
}

void rotateImage(unsigned char **p, int a, int b) {
  unsigned char **temp = allocateArray(b, a);
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < b; j++) {
      temp[j][a - 1 - i] = p[i][j];
    }
  }
  for (int i = 0; i < b; i++) {
    for (int j = 0; j < a; j++) {
      p[i][j] = temp[i][j];
    }
    printf("\n");
  }
}

void scaleImage(unsigned char **p, int a, int b) {
  unsigned char **temp = allocateArray(a * 2, b * 2);
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < b; j++) {
      temp[i * 2][j * 2] = p[i][j];
      temp[i * 2 + 1][j * 2] = p[i][j];
      temp[i * 2][j * 2 + 1] = p[i][j];
      temp[i * 2 + 1][j * 2 + 1] = p[i][j];
    }
  }
  for (int i = 0; i < a * 2; i++) {
    for (int j = 0; j < b * 2; j++) {
      p[i][j] = temp[i][j];
    }
    printf("\n");
  }
}