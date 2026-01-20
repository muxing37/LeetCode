#include <stdio.h>
#include <string.h>
int numOfSubarrays(int* arr, int arrSize, int k, int threshold) {
    int i,j,c,s,m;
	s=0;
	c=0;
    for (i=0;i<k;i++) {
        s+=arr[i];
    }
    m=s/k;
    if(m>=threshold) {
    	c++;
	}
    for(i=k;i<arrSize;i++) {
        s=s-arr[i-k]+arr[i];
        m=s/k;
        if(m>=threshold) {
            c++;
        }
    }
	return c;
}
