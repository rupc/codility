// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <algorithm>
int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    int N = A.size();
    std::vector<int> K1(N, 0);
    std::vector<int> K2(N, 0);
    // find maximum sum to index i from left
    for (int i = 1; i < N-1; i++) {
        K1[i] = std::max(K1[i-1] + A[i], 0);
    }
    // find maximum sum to index i from right
    for (int i = N-2; i > 0; i--) {
        K2[i] = std::max(K2[i+1] + A[i], 0);
    }
    int maxin = 0 ;
    // find Y's position which slices both part
    for (int i = 1; i < N-1; i++) {
        maxin = std::max(maxin, K1[i-1]+K2[i+1]);
    }
    return maxin;
}
