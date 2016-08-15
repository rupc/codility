#include <cmath>
using namespace std;
int solution(int X, int Y, int D) {
	return ceil((double)(Y - X) / D);
}