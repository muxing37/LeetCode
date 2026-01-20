int maxFreeTime(int eventTime, int k, int* startTime, int startTimeSize, int* endTime, int endTimeSize) {
    int w=k+1,sum=startTime[0],max=0;
    int i;
    for(i=0;i<w && i<startTimeSize;i++) {
        if(i==startTimeSize-1) {
            sum=sum+eventTime-endTime[endTimeSize-1];
            break;
        } else {
            sum=sum+startTime[i+1]-endTime[i];
        }
    }
    max=sum;
    if(k>=startTimeSize) {
        max=sum+eventTime-endTime[startTimeSize-1];
    }
    for(i=1;i+w<startTimeSize-1;i++) {
        if(i+k==startTimeSize-1) {
            sum=sum+eventTime-endTime[i+k];
            sum=sum-(startTime[i]-endTime[i-1]);
        } else {
            sum=sum+startTime[i+k]-endTime[i+k-1];
            sum=sum-(startTime[i]-endTime[i-1]);
        }
        if(sum>max) {
            max=sum;
        }
    }
    return max;
}