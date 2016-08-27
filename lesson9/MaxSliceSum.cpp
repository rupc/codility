#include <climits>
#include <algorithm>
int maxSubArraySum(vector<int> &a, int size)
{
    int max_so_far = a[0], max_ending_here = a[0];
    for (int i = 1; i < size; i++) {
        max_ending_here = std::max(a[i], max_ending_here + a[i]);
        max_so_far = std::max(max_so_far, max_ending_here);
    }
    return max_so_far;
}
int solution(vector<int> &A) {
    return maxSubArraySum(A, A.size());
}
