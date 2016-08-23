
def golden_max_slice(A):
    max_ending = max_slice = 0;
    for a in A:
        max_ending = max(0, max_ending + a);
        max_slice = max(max_slice, a);
    return max_slice;

A = [5,-7, 3,5,-2,4,-1];
res = golden_max_slice(A);
print res;
print "what the fuck";
