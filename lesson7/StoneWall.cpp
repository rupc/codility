// Keyword:stack,building,height
#include <vector>
#include <stack>
int solution(vector<int> &H) {
    std::stack<int> iStk;
    unsigned ctr = 0;
    int sz = H.size();

    auto topOf = [&](){
        return iStk.top();
    };

    iStk.push(H.front());
    ++ctr;

    for (int i = 1; i < sz; i++) {
#ifdef DEBUG
        std::cout << "At i: " << i << std::endl;
#endif
        if (H[i] == topOf()) {
            // remain ctr
            #ifdef DEBUG
                std::cout << "\tequals : " << H[i] << " == " << topOf() << std::endl;
            #endif
        } else if (H[i] > topOf()) {
            ++ctr;
            iStk.push(H[i]);
            #ifdef DEBUG
                std::cout << "\tH[i]>topOf : " << H[i] << " > " << topOf() << std::endl;
            #endif
        } else {
            //std::cout << "\tH[i]<topOf : " << H[i] << " < " << topOf() << std::endl;
            while (!iStk.empty() && H[i] < topOf()) {
                iStk.pop();
            }
            //std::cout << "\tAfter pop and size : " << iStk.size() << std::endl;
            if (iStk.empty() || H[i] > topOf()) {
                ++ctr;
            }
            iStk.push(H[i]);
        }
        //std::cout << "\tcounter : " << ctr << std::endl;
    }

    return ctr;
}
