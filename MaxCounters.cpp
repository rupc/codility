// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <vector>
#include <algorithm>
using namespace std;
vector<int> solution(int N, vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
	vector<int> counters(N+1, 0);
	int sz = A.size();
	int max_ctr = 0, min_ctr = 0;
	for (int i = 0; i < sz; ++i) {
		if (A[i] > N) {
			min_ctr = max_ctr;
		} else {
			if (counters[A[i]] <= min_ctr) {
				counters[A[i]] = min_ctr + 1;
			} else {
				counters[A[i]]++;
			}
			if (max_ctr < counters[A[i]]) {
				max_ctr = counters[A[i]];
			}
		}
		// cout << min_ctr << " " << max_ctr << endl;
	}
	counters.erase(counters.begin());

	for (int i = 0; i < N; ++i) {
		if (counters[i] < min_ctr)
			counters[i] = min_ctr;
	}
	return counters;
}