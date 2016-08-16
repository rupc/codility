// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    if (A.size() == 2) {
        return 0;
    }
    int N = A.size();
    double min_avg = (A[0] + A[1]) / 2.0;
    int min_idx = 0;
    for (int i = 2; i < N; i++) {
        double t1 = (A[i-1] + A[i]) / 2.0;
        double t2 = (A[i-2] + A[i-1] + A[i]) / 3.0;

        if (min_avg > t1) {
            min_avg = t1;
            min_idx = i - 1;
        }

        if (min_avg > t2) {
            min_avg = t2;
            min_idx = i - 2;
        }
        
    }
    return min_idx;
}
