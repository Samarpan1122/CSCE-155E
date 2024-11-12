/**
 * Author: Samarpan Mohanty
 * Date: 2024/08/13
 *
 * A simple hello world program in C
 *
 */
// #include <stdlib.h>
// #include <stdio.h>

// int main(int argc, char **argv) {

//   printf("Hello World!\n");

//   return 0;
// }


//use PEMDAS=parenthesis,exponents, multiplication,division,addition,substraction
//integer/integer is integer (trancate)


// a/ (double) b;
//use gcc hello.c -lm to use math lbrary'
//use astyle hello.c for formatting
// %d for int
// %f for double
// %c for char
// %.10f for 10 decimals of accuracy
// %10.2f for 10 decimals of accuracy with 6 spaces



#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {
  for (int i = 1; i <= 100; i++) {
    if (i%3 == 0 && i%5 == 0){
      printf("FizzBuzz\n");
    } else if(i%3==0) {
      printf("Fizz\n");
    } else if(i%3==0) {
      printf("Buzz\n");
    } else {
      printf("%d\n", i);
    }
  }
  return 0;
}
