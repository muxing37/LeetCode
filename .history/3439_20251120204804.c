int maxFreeTime(int eventTime, int k, int* startTime, int startTimeSize, int* endTime, int endTimeSize) {
    int w=k+1,sum=0,max=0,n=startTimeSize+1;
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
    for(i=1;i<n-k;i++) {
        sum=sum+jiange[i+k];
        sum=sum-jiange[i-1];
        if(sum>max) {
            max=sum;
        }
    }
    return max;
}