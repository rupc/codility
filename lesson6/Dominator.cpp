#include <vector>
#include <stack>
#include <algorithm>
//https://codility.com/demo/results/trainingUKEVAA-BCF/
int get_leader(std::vector<int> &A) {
    std::stack<int> iStk;
    const int N = A.size();
    iStk.push(A[0]);
    for (int i = 1; i < N; i++) {
        if (iStk.empty()) {iStk.push(A[i]); continue;}
        if (iStk.top() == A[i]) {
            iStk.push(A[i]);
        } else {
            iStk.pop();
        }
    }
    // assumes leader always exist in A --> WRONG!!!
    if (iStk.empty()) {
        return -1;
    } else {
        return iStk.top();
    }

}
int solution(vector<int> &A) {
    if (A.empty() || A.size() == 2) return -1;
    // get the most ocurrent number
    int leader = get_leader(A);
    // if leader dosen't exist, then dominator also doesn't exist
    if (leader == -1) {
        return -1;
    }
    const int N = A.size();
    int ctr = std::count(A.begin(), A.end(), leader);
    if (ctr > N/2) {
        for (int i = 0; i < N; i++) {
            if (A[i] == leader) {
                return i;
            }
        }
    } else {
        return -1;
    }
}
