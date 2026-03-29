#include <stdio.h>

int main() {
    int refer[50],frame[50],i,j,n,fsize,flag=0,c=0,fault = 0,k,recent[50],temp,flag1=0;
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
        fault++;
        frame[i] = refer[i];
        recent[i] = refer[i];
        c++;
    }
    recent[c] = 0;
    for(i=fsize;i<n;i++){
        for(k=0;k<c;k++){
            if(refer[i]==recent[k]){
                flag1 =1;
                break;
            }
        }
        if(flag1==1){
            temp = recent[k];
            for(j=k;j<c;j++)
                recent[j] = recent[j+1];
            recent[c-1] = temp;
        }else{
            recent[c] = refer[i];
            c++;
            recent[c] = 0;
        }
        flag1=0;
        for(j=0;j<fsize;j++){
            if(frame[j]==refer[i]){
                flag = 1;
            }
        }
        if(flag != 1){
            fault++;
            for(k=0;k<c;k++){
                for(j=0;j<fsize;j++){
                    if(recent[k]==frame[j]){
                        frame[j]=refer[i];
                        goto end;
                    }
                }
            }
        }
        end:
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