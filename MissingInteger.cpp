// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_set>
#include <climits>
using namespace std;
int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    int sz = A.size();
    unordered_set<int> S;
    // O(n)
    for (int i = 0; i <sz; ++i) {
    	if (A[i] > 0) S.insert(A[i]);
    }
    int res;
    // O(1)
    for (long i = 1; i <= LONG_MAX; ++i) {
    	if (S.find(i) == S.end()) {
    		res = i;
    		break;
    	}
    }
    return res;
}