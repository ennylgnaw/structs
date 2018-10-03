#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//prototype
struct menu {int price; char *food;};
char *foods[] = {"caviar", "chocolate", "sushi", "ramen", "sandwich"};

struct menu retMenu(struct menu x) {
  x.food = foods[rand() % 5];
  x.price = rand() % (100) + 1;
  return x;
}

void printMenu(struct menu x) {
  printf("Food: %s, Price: $%d\n\n", x.food, x.price);
}

void raisePrice(struct menu *x, int amount) {
  x->price += amount;
}

void lowerPrice(struct menu *x, int amount) {
  x->price -= amount;
}

void changeItem(struct menu *x, char *newFood) {
  x->food = newFood;
}

int main() {
  srand( time(NULL) );
  struct menu hungry;
  printf("Original menu:\n");
  hungry = retMenu(hungry);
  printMenu(hungry);
  printf("New menu:\n");
  hungry = retMenu(hungry);
  printMenu(hungry);
  printf("Raise price by $10:\n");
  raisePrice(&hungry, 10);
  printMenu(hungry);
  printf("Lower price by $5:\n");
  lowerPrice(&hungry, 5);
  printMenu(hungry);
  printf("Change menu item after surplus in cricket harvest:\n");
  changeItem(&hungry, "fried crickets");
  printMenu(hungry);
}
