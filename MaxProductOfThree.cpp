// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <algorithm>
using namespace std;

int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    std::sort(A.begin(), A.end());
    
    int last = A.size() - 1;
    int right = A[last] * A[last - 1] * A[last - 2];
    int left = A[0] * A[1] * A[last];
    return std::max(right, left);
}
