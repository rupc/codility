// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <vector>
#include <numeric>
int solution(int X, vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
	vector<bool> visit(X+1, false);
	auto sz = A.size();
	int sum = 0;
	for (int i = 1; i <= X; ++i) sum += i;
	bool reachable = false;
	int reach_point;
	for (int i = 0; i < sz; ++i) {
		if (A[i] <= X) {
			if (visit[A[i]] == false) {
				visit[A[i]] = true;
				sum -= A[i];
				if(sum == 0) {
					reachable = true;
					reach_point = i;
					break;
				}		
			}
		}

	}
	if (reachable) {
		return reach_point;
	} else {
		return -1;
	}
}