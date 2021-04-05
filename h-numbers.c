#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX 2000000

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

/* Find divisors finds all the divisors of a given int and the sum of those
 * divisors.
 * @param int n Number to find the divisors of.
 * @return int The sum of the divisors.
 */
int find_sum_of_divisors(int n) {
  int sum = 0;
  int d;
  for(d = sqrt(n)+1; d > 1; d--) {
    if (n % d == 0) {
      sum += n / d;
      if (n/d != d) {
        sum += d;
      }
    }
  }
  return sum;
}

/* Starting point of the program.*/
int main() {
  int i, j, sum_of_j;
  time_t start_time, end_time;
  time(&start_time);
  for(i = 1; i < MAX; i++) {
    j = find_sum_of_divisors(i);
    if (j < i) {
      continue;
    }
    sum_of_j = find_sum_of_divisors(j);
    if(sum_of_j == i) {
      printf("%d %d\n", i, j);
    }
  }
  /* starting at i = 4, find all divisors of that number excluding 1 and sum them. Then find
  all divisors of that number and sum those. If that sum is equal to i, then
  print out both numbers. Add one to i. */
  time(&end_time);
  printf("%.2f\n", difftime(end_time, start_time));

  return EXIT_SUCCESS;
}
