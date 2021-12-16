#include <omp.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <cstdlib>
#include <chrono>
using namespace std;
int main(int argc, char* argv[]) {
  int n = atoi(argv[1]);
  int numThreads=atoi(argv[2]);
  double* vector = new double[n];
  for (long int i = 0; i < n; i++) {
    vector[i] = (double)rand() / RAND_MAX;
	  //printf("vector[%d] = %f\n", i, vector[i]);
  }
  printf("\nNum of threads %d \t", numThreads); 
  double max_element = vector[0];
  double itime, ftime, exec_time;
  omp_set_dynamic(0);     // Explicitly disable dynamic teams
  omp_set_num_threads(numThreads); // Use numThreads threads for all consecutive parallel regions
  itime = omp_get_wtime();
  #pragma omp parallel 
  {
    #pragma for reduction(max : max_element) 
    for (int idx = 0; idx < n; idx++)
        max_element = max_element > vector[idx] ? max_element : vector[idx];
  }
  ftime = omp_get_wtime();
  exec_time = ftime - itime;
  printf("Time taken %f\t", exec_time);
  printf(" Max value %f ", max_element);
  delete[] vector;  
}