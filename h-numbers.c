#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Be reasonably careful and sensible. */
/* Author: Jordan Kettles 2147684
 * Date 28/03/21 */

void *emalloc(size_t t) {
  void * result = malloc(t);
  if(result == NULL){
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

int * find_divisors(int n) {
  /*find the divisors of n.*/
  /* Upper bound for amount of divisors.*/
  int * divisors = emalloc(sizeof(int) * round(n * 1.0/3.0 + 1));
  int divisor_count = 0;
  int d = 2;
  /* Should this be ceil? */
  for(d = 2; d < n / 2; d++) {
    if (n % d == 0) {
      printf("%d\n", n/d);
      divisors[divisor_count++] = n / d;
      printf("%d\n", d);
      divisors[divisor_count++] = d;
    }
  }
  divisors = realloc(divisors, sizeof(int) * divisor_count);
  return divisors;
}


int main() {
  int * six_divisors = find_divisors(6);
  free(six_divisors);
  /* starting at i = 4, find all divisors of that number excluding 1 and sum them. Then find
  // all divisors of that number and sum those. If that sum is equal to i, then
  // print out both numbers. Add one to i. */
  return EXIT_SUCCESS;
}
