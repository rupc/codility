// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <algorithm>
#include <vector>
#include <numeric>
#include <cmath>
#include <iostream>
using namespace std;

int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    int total = accumulate(A.begin(), A.end(), 0);
    int left_sum = A[0], right_sum = total - A[0];
    int diff, min_diff = 999999999;
    int sz = A.size();
    for(int i = 1; i < sz; ++i) {
    	diff = abs(left_sum - right_sum);
    	// cout << diff << endl;
    	if (min_diff > diff)
    		min_diff = diff;
    	left_sum += A[i];
    	right_sum -= A[i];
    }
    return min_diff;
}