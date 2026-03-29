#include <stdio.h>

int main() {
    int refer[50],frame[50],fsize,i,j,flag = 0, c = 0,n,fault = 0;
    float miss,hit;
    printf("No of refer\n");
    scanf("%d",&n);
    printf("enter the ref \n");
    for(i=0;i<n;i++){
        scanf("%d",&refer[i]);
    }
    printf("fsize = ");
    scanf("%d",&fsize);
    for(i=0;i<fsize;i++){
        frame[i] = -1;
    }
    for(i=0;i<n;i++){
        for(j=0;j<fsize;j++){
            if(frame[j]==refer[i])
                flag = 1;
        }
        if(flag!=1){
            fault++;
            frame[c] = refer[i];
            c++;
        }
        if(c==fsize)
            c=0;
        flag = 0;
    }

    printf("No of faults = %d\n",fault);
    printf("No of hits = %d\n",n-fault);
    miss = ((float)fault/n)*100;
    hit = ((float)(n-fault)/n)*100;
    printf("miss = %f%%\n",miss);
    printf("hit = %f%%\n",hit);
    return 0;
}