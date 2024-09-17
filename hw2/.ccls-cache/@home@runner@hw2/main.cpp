#include <iostream>
#include <fstream>
#include <random>
#include <chrono>
#include <climits>
#include "ArgumentManager.h"

using namespace std;

// swap function to move two longs
void swap(long &l, long &r) {
  long temp = l;
  l = r;
  r = temp;
}

// partitioning to avoid swapping... pivot is always right-most value
int partition(long arr[], int low, int high, int& partitions) {
  long pivot = arr[high];
  int l = low;
  int r = high - 1; // high is the pivot

  // putting lower values to left of pivot and higher values to the right
  while (l <= r) {
    while (arr[l] < pivot) {
      l++;
    }
    while (r >= low && arr[r] >= pivot) {
      r--;
    }
    if (l <= r) {
      swap(arr[l], arr[r]);
    }
  }
  swap (arr[l], arr[high]);
  partitions++;
  return l;
}

long findMedian(long arr[], int low, int high, int index, int& partitions) {
  if (low <= high) {
    int pivot = partition(arr, low, high, partitions);
    if (pivot == index)
      return arr[pivot];
    else if (pivot < index)
      return findMedian(arr, pivot + 1, high, index, partitions);
    else
      return findMedian(arr, low, pivot - 1, index, partitions);
  }
  return arr[low];
}

int main(int argc, char* argv[]) {
  ArgumentManager am(argc, argv);
  auto start = chrono::steady_clock::now();
  ifstream fin(am.get("input"));
  ofstream fout(am.get("output"));
  //ifstream fin("input3.txt");
  //ofstream fout("output3.txt");
    
  int seed, count;
  int partitions = 0;
  fin >> seed >> count;
  long result = 0;
  mt19937_64 generator(seed);
  uniform_int_distribution<long> distribution(0, LONG_MAX);

  long* values = new long[count];

  for (int i = 0; i < count; i++) {
    values[i] = distribution(generator);
    //cout << values[i] << endl;
  }

  // finding and printing the median
  int medianIndex = count / 2; // if the count is odd, the median index is already rounded down
  // if the count is even, the median index should be 1 less than count/2 since index starts at 0
  if (count % 2 == 0) {
    medianIndex--;
  }
  //cout << "Index: " << medianIndex << endl;
  long median = findMedian(values, 0, count - 1, medianIndex, partitions);
  //cout << "Median: " << median << endl;
  fout << median << endl;

  // printing the runtime
  auto end = chrono::steady_clock::now();
  // Store the time difference between start and end
  auto diff = end - start;
  //cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;

  // printing the number of partitions
  //fout << partitions << endl;

  // freeing up memory
  delete[] values;
	return 0;
}
