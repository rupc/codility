// Keyword:stack,parentheses
#include <stack>
#include <string>
#include <set>

int solution(string &S) {
    if (S.empty()) return 1;
    std::stack<char> chStk; // character stack

    std::set<char> op_paren = {'(','{', '['};
    std::set<char> cl_paren = {')','}', ']'};
    auto isOpen = [](char c, std::set<char> &parens){
        return (parens.find(c) != parens.end());
    };
    auto isMatched = [](char op, char cl){
        if ((op == '(' && cl == ')') || (op == ')' && cl == '(') ||
            (op == '{' && cl == '}') || (op == '}' && cl == '{') ||
            (op == '[' && cl == ']') || (op == ']' && cl == '[')) {
            return true;
        } else return false;
    };
    for (auto &p : S) {
        if (isOpen(p, op_paren)) {
            chStk.push(p);
        } else {
            if (chStk.empty()) return 0;
            // if p is closed paren
            char q = chStk.top();
            if (isMatched(p, q)) {
                chStk.pop();
            } else return 0;
        }
    }
    return (chStk.empty() ? 1 : 0);
}
