// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
	int sz = A.size();
	int zeros = 0;
	int we_pairs = 0;
    for (int i = 0; i < sz; ++i) {
    	if (A[i] == 0) {
    		zeros++;
    	} else {
    		if (we_pairs + zeros > 1000000000) return -1;
    		we_pairs += zeros;
    	}
    }

    return we_pairs;
}