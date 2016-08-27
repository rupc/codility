// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <numeric>
#include <vector>
using namespace std;
int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    int total = 0;
    int sz = A.size();
    for(int i = 1; i <= sz + 1; ++i) {
    	total += i;
    } 
    int sum = accumulate(A.begin(), A.end(), 0);
    return total - sum;
}