// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    const size_t N = A.size();
    std::vector<int> lowers(N);
    std::vector<int> uppers(N);
    for (int i = 0; i < N; i++) {
        lowers[i] = i - A[i];
        uppers[i] = i + A[i];
    }
    std::sort(lowers.begin(), lowers.end());
    std::sort(uppers.begin(), uppers.end());

    int intersect_cnt = 0;
    for (int i = 0; i < N; i++) {
        int j = 0;
        while (j < N && uppers[i] >= lowers[j]) {
            ++j;
        }
        intersect_cnt += j - i - 1;
        if (j > 10000000) {
            return -1;
        }
    }
    return intersect_cnt;
}
