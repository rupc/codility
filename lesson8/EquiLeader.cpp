// Keyword:stack,leader

#include <vector>
#include <stack>
#include <algorithm>
int get_leader(std::vector<int> &A) {
    std::stack<int> iStk;

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
        return 0;
    } else {
        return iStk.top();
    }
}
int solution(vector<int> &A) {
    //if (A.size() == 2) return 0;
    std::stack<int> iStk;
    int ctr = 0, leader, nLeader = 0, N = A.size();
    iStk.push(A[0]);
    // O(n)
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
        return 0;
    }
    leader = iStk.top();

    // O(n)
    nLeader = std::count(A.begin(), A.end(), leader);
    int nOthers = N - nLeader; // N = number of leaders + number of others

    //std::cout << leader << " " << nLeader;
    // clear stack
    while(!iStk.empty()) iStk.pop();
    auto isLeader = [&](int n){
        return (n == leader);
    };
    for (int i = 0; i < N; i++) {
        if (isLeader(A[i])) {
            --nLeader;
            if (!iStk.empty() && iStk.top() != leader) {
                iStk.pop();
            } else {
                iStk.push(A[i]);
            }
        } else {
            --nOthers;
            if (!iStk.empty() && iStk.top() == leader) {
                iStk.pop();
            } else {
                iStk.push(A[i]);
            }
        }
        const bool isRlead = (nLeader > nOthers);
        const bool isLlead = (!iStk.empty() && iStk.top() == leader);
        if (isRlead && isLlead) {
            ++ctr;
        }
    }
    return ctr;
}
