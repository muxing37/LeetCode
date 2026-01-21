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
int main() {
    // 测试用例1
    int cardPoints1[] = {1,2,3,4,5,6,1};
    int k1 = 3;
    int result1 = maxScore(cardPoints1, sizeof(cardPoints1)/sizeof(cardPoints1[0]), k1);
    printf("测试1结果: %d (期望: 12)\n", result1);
    
    // 测试用例2
    int cardPoints2[] = {2,2,2};
    int k2 = 2;
    int result2 = maxScore(cardPoints2, sizeof(cardPoints2)/sizeof(cardPoints2[0]), k2);
    printf("测试2结果: %d (期望: 4)\n", result2);
    
    // 测试用例3
    int cardPoints3[] = {9,7,7,9,7,7,9};
    int k3 = 7;
    int result3 = maxScore(cardPoints3, sizeof(cardPoints3)/sizeof(cardPoints3[0]), k3);
    printf("测试3结果: %d (期望: 55)\n", result3);
    
    // 测试用例4
    int cardPoints4[] = {1,1000,1};
    int k4 = 1;
    int result4 = maxScore(cardPoints4, sizeof(cardPoints4)/sizeof(cardPoints4[0]), k4);
    printf("测试4结果: %d (期望: 1)\n", result4);
    
    // 测试用例5
    int cardPoints5[] = {1,79,80,1,1,1,200,1};
    int k5 = 3;
    int result5 = maxScore(cardPoints5, sizeof(cardPoints5)/sizeof(cardPoints5[0]), k5);
    printf("测试5结果: %d (期望: 202)\n", result5);
    
    return 0;
}
