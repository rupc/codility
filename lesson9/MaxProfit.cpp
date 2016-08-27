#include <algorithm>
int maxSubArraySum(vector<int> &a, int size)
{
    int max_so_far = 0, max_ending_here = 0;
 
    for (int i = 0; i < size; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_ending_here < 0)
            max_ending_here = 0;
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
    }
    return max_so_far;
}
int solution(vector<int> &A) {
    int N = A.size();
    // I saw this techinque at CLRS's divide and conquer chapter
    for (int i = 0; i < N - 1; i++) {
        A[i] = A[i+1] - A[i];
        //S[i] = A[i+1] - A[i];
    }
    int res = maxSubArraySum(A, A.size()-1);
    return (res > 0) ? (res) : (0);
}
