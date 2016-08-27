//Keyword:stack,queue,fish
#include <stack>
#include <utility>
#include <vector>
#include <queue>

using namespace std;
int solution(vector<int> &A, vector<int> &B) {
    #define UPSTREAM 0
    #define DOWNSTREAM 1
    auto bulkOf = [&](std::pair<int, int> fish){
        return A[fish.first];
    };
    auto hasMeet = [](std::pair<int, int> &s, std::pair<int, int> &q) -> bool {
        return (s.second == DOWNSTREAM) && (q.second == UPSTREAM);
    };
    auto hasEat = [&](std::pair<int, int> &q, std::pair<int, int> &s) -> bool {
        return (bulkOf(s) < bulkOf(q));
    };
    std::queue<std::pair<int, int>> Q;
    std::stack<std::pair<int, int>> S;
    int N = A.size();
    for (int i = 0; i < N; i++) {
        Q.push({i, B[i]});
    }
    // push first fish a[0]
    // assume Q > 0
    S.push(Q.front());
    Q.pop();
    while (!Q.empty()) {
        std::pair<int, int> Qfish = Q.front();
        std::pair<int, int> Sfish = S.top();
        Q.pop();
        // two fishes meet
        while (hasMeet(Sfish, Qfish) && hasEat(Qfish, Sfish)) {
            S.pop();
            if (!S.empty()) Sfish = S.top();
            else {
                S.push(Qfish);
                break;
            }
        }
        if (!hasMeet(Sfish, Qfish)) {
            S.push(Qfish);
        }
    }


    return (int)S.size();
}
