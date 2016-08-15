// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    // write your code in C++11 (g++ 4.8.2)
    int N = S.size();
    int M = P.size();
    if (N == 1) {
    	if (S[0] == 'A') return {1};
    	if (S[0] == 'C') return {2};
    	if (S[0] == 'G') return {3};
    	if (S[0] == 'T') return {4};
    }
    vector<vector<int>> DNA(N, vector<int>(4, 0));
    for (int i = 0; i < N; ++i) {
    	if (S[i] == 'A') DNA[i][0] = 1;
    	if (S[i] == 'C') DNA[i][1] = 1;
    	if (S[i] == 'G') DNA[i][2] = 1;
    	if (S[i] == 'T') DNA[i][3] = 1;
    }
    for (int i = 1; i < N; ++i) {
    	for (int j = 0; j < 4; ++j) {
    		DNA[i][j] += DNA[i-1][j];
    	}
    }
    vector<int> sols;
    for (int i = 0; i < M; ++i) {
		int x = P[i];
		int y = Q[i];
		int sub 
		for(int j = 0; j < 4; ++j) {
			if (x >= 1 && DNA[x-1][j] < DNA[y][j]) {
				sols.push_back(j+1);
				break;
			} else if (x == 0 && DNA[y][j] > 0) {
				sols.push_back(j+1);
				break;
			}
		}
    }
    return sols;
}