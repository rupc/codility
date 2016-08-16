// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <algorithm>
using namespace std;
int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    if (A.size() == 0) {
        return 0;
    }
    std::sort(A.begin(), A.end());
    int cnt = 1;
    for (unsigned i = 1; i < A.size(); i++) {
        if (A[i-1] != A[i]) {
            ++cnt;
        }
    }
    return cnt;
}
