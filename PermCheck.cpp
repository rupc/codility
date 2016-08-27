// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <unordered_set>
int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    int sz = A.size();
    unordered_set<int> S;
    for(int i = 1; i <= sz; ++i) {
    	S.insert(i);
    }
    for (int i = 0; i < sz; ++i) {
    	S.erase(A[i]);
    }
    return S.empty();
}
