#include <algorithm>
#include <iostream>

using namespace std;

int solution(int N) {
	unsigned i = 0x1;
	bool one_start = false;
	unsigned cnt = 0, maxcnt = 0;

	while (i != 0x80000000) {
		if (one_start) {
			++cnt;
		}
		if ((N & i) && !one_start) {
			one_start = true;
		}
		// if ((N & i) && one_start) {
		// 	maxcnt = (maxcnt > cnt) : maxcnt ? cnt;
		// }

		i = i << 1;
		if ((N & i)) {
			one_start = false;
			if (maxcnt < cnt) 
				maxcnt = cnt;
			cnt = 0;
		}
	}
	return maxcnt;
}