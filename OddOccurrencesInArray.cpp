// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <algorithm>
#include <unordered_set>
using namespace std;
int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
	unordered_set<int> S;
	for(int i = 0; i < A.size(); ++i) {
		if (S.find(A[i]) == S.end()) {
			S.insert(A[i]);
		} else {
			S.erase(A[i]);
		}
	}
	return *S.begin();
}