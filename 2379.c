#include <stdio.h>
#include <string.h>
int minimumRecolors(char* blocks, int k) {
    int i;
    int c=0;
    for(i=0;i<k;i++) {
        if (blocks[i]=='B') {
            c++;
        }
    }
    int max=c;
    for(i=k;i<strlen(blocks);i++) {
        if(blocks[i-k]=='B') {
            c--;
        }
        if(blocks[i]=='B') {
            c++;
        }
        if(c>max) {
            max=c;
        }
    }
    //printf("%d\n",k-max);
    return k-max;
}
