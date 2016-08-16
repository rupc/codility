// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <algorithm>

using namespace std;

int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    std::sort(A.begin(), A.end());
    int N = A.size();

    long long t;
    for (int i = 2; i < N; i++) {
        t = (long long)A[i-2] + (long long)A[i-1];
        if (t > A[i]) {
            return 1;
        }
    }
    return 0;
}
