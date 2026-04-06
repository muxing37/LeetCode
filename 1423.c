#include <stdio.h>
int maxScore(int* cardPoints, int cardPointsSize, int k) {
    int i,j,max;
    int sum=0;
    for(i=0;i<k;i++) {
    	sum=sum+cardPoints[i];
	}
	max=sum;
    for(j=cardPointsSize-1,i=k-1;i>=0;i--,j--) {
    	sum=sum+cardPoints[j]-cardPoints[i];
    	if(sum>max) {
    		max=sum;
		}
	}
	return max;
}
