#include <stdio.h>
int main()
{
    int i,n,q,temp,c=0,timer=0;
    int bt[30],rt[30],wt[30],tat[30];
    float avg_tat, avg_wt;
    printf("Enter the no of proc\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("bt = ");
        scanf("%d", &bt[i]);
        rt[i] = bt[i]; 
    }
    printf("Enter the time quantum\n");
    scanf("%d", &q);
    while (c < n)
    {
        for (i = 0; i < n; i++)
        {
            if (rt[i] > 0)
            {
                if (rt[i] > q)
                {
                    timer += q;
                    rt[i] -= q;
                }
                else
                {
                    timer += rt[i];
                    wt[i] = timer - bt[i];
                    rt[i] = 0;
                    c++;
                    tat[i] = timer;
                }
            }
        }
    }
    printf("pid\tbt\twt\ttat\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]);
        avg_wt += wt[i];
        avg_tat += tat[i];
    }
    printf("avg wt = %f\n", avg_wt / n);
    printf("avg tat = %f\n", avg_tat / n);
    return 0;

}