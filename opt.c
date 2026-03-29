#include <stdio.h>

int main() {
    int n,fsize,frame[40],refer[40],i,j,flag,k,fault = 0,temp[40];
    int max,index,empt_f;
    float hit, miss;

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
        flag = 0;
        for(j=0;j<fsize;j++){
            if(frame[j]==refer[i]){
                flag =1;
                break;
            }
        }
        if(flag==0){
            fault++;
            empt_f = 0;
            for(j=0;j<fsize;j++){
                if(frame[j]==-1){
                    frame[j]=refer[i];
                    empt_f = 1;
                    break;
                }
            }
            if(!empt_f){
                for(j=0;j<fsize;j++){
                    temp[j] = -1;
                    for(k=i+1;k<n;k++){
                        if(frame[j]==refer[k]){
                            temp[j]=k;
                            break;
                        }
                    }
                }
                max = -1;
                index = 0;
                for(j=0;j<fsize;j++){
                    if(temp[j] == -1){
                        index=j;
                        break;
                    }
                    if(temp[j]>max){
                        max=temp[j];
                        index=j;
                    }
                }
                frame[index] = refer[i];
            }
        }
    }
    printf("No of faults = %d\n",fault);
    printf("No of hits = %d\n",n-fault);
    miss = ((float)fault/n)*100;
    hit = ((float)(n-fault)/n)*100;
    printf("miss = %f%%\n",miss);
    printf("hit = %f%%\n",hit);
    return 0;
}