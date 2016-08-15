// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int A, int B, int K) {
    // write your code in C++11 (g++ 4.8.2)
	if (A == B) {
		if (A % K == 0) return 1;
		else return 0;
	}
    A = A - (A % K) + K;
    B = B - (B % K) + K;
    int res = B/K - A/K + 1;
    if(A == 0) --res;
    return res;
}