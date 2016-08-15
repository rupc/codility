// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> solution(vector<int> &A, int K) {
    // write your code in C++11 (g++ 4.8.2)
    if (A.empty()) return A;
	int size = A.size();
	K = K % size;
	if (K == 0) return A;
	vector<int> sols(size);
	copy(A.begin() + size - K, A.end(), sols.begin());
	copy(A.begin(), A.begin() + size - K, sols.begin() + K);
	return sols;
}