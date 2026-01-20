#include <stdio.h>
#include <string.h>
double findMaxAverage(int* nums, int numsSize, int k) {
    int i,j;
	double a,m;
	int s=0;
    for (i=0;i<k;i++) {
        s+=nums[i];
    }
    m=(double)s/k;
    for(int i=k;i<numsSize;i++) {
        s=s-nums[i-k]+nums[i];
        a=(double)s/k;
        if(a>m) {
            m=a;
        }
    }
	return m;
}
