#include <stdio.h>
#include <stdlib.h>
int maxSatisfied(int* customers, int customersSize, int* grumpy, int grumpySize, int minutes) {
    int sum=0,max=0;
    int i,j;
    for(i=0;i<customersSize;i++) {
        if(grumpy[i]==0) {
            sum=sum+customers[i];
        }
    }
    for(i=0;i<minutes;i++) {
        if(grumpy[i]==1) {
            sum=sum+customers[i];
        }
    }
    max=sum;
    for(i=1;i+minutes<=grumpySize;i++) {
        if(grumpy[i+minutes-1]==1) {
            sum=sum+customers[i+minutes-1];
        }
        if(grumpy[i-1]==1) {
            sum=sum-customers[i-1];
        }
        if(sum>max) {
            max=sum;
        }
    }
    return max;
}
