#include <stdio.h>
#include <stdlib.h>
int maxFreeTime(int eventTime, int k, int* startTime, int startTimeSize, int* endTime, int endTimeSize) {
    int w=k+1,sum=startTime[0],max=0,n=startTimeSize+1;
    int i;
    int jiange[n];
    jiange[0]=startTime[0];
    jiange[n-1]=eventTime-endTime[endTimeSize-1];
    for(i=1;i<startTimeSize;i++) {
        jiange[i]=startTime[i]-endTime[i-1];
    }
    for(i=0;i<w;i++) {
        sum=sum+jiange[i];
    }
    max=sum;
    for(i=1;i<=endTimeSize-w;i++) {
        sum=sum+jiange[i+k];
        sum=sum-jiange[i-1];
        if(sum>max) {
            max=sum;
        }
    }
    return max;
}

int main() {
    // 测试用例 1（你提供的示例）
    int eventTime1 = 21;
    int k1 = 1;
    int start1[] = {7, 10, 16};
    int end1[]   = {10, 14, 18};
    int n1 = sizeof(start1) / sizeof(int);

    printf("Test 1 result = %d (Expected 7)\n",
           maxFreeTime(eventTime1, k1, start1, n1, end1, n1));

    // 测试用例 2（验证合并区间）
    int eventTime2 = 30;
    int k2 = 1;
    int start2[] = {10, 15, 20};
    int end2[]   = {12, 17, 22};
    int n2 = sizeof(start2) / sizeof(int);

    printf("Test 2 result = %d (Expected 18)\n",
           maxFreeTime(eventTime2, k2, start2, n2, end2, n2));

    // 测试用例 3（k = 0，不允许跳过会议）
    int eventTime3 = 25;
    int k3 = 0;
    int start3[] = {5, 10, 15};
    int end3[]   = {7, 11, 20};
    int n3 = sizeof(start3) / sizeof(int);

    printf("Test 3 result = %d (Expected 5 + 3 + 10 = 18)\n",
           maxFreeTime(eventTime3, k3, start3, n3, end3, n3));

    // 测试用例 4（空闲区很大，中间会议干扰）
    int eventTime4 = 50;
    int k4 = 1;
    int start4[] = {5, 10, 12, 48};
    int end4[]   = {6, 11, 13, 49};
    int n4 = sizeof(start4) / sizeof(int);

    printf("Test 4 result = %d (Expected 43)\n",
           maxFreeTime(eventTime4, k4, start4, n4, end4, n4));

    return 0;
}