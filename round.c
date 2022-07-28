#include<stdio.h>  
void main()  
{  
    int i, n, sum=0,count=0, y, quant, wt=0, tat=0, at[10], bt[10], temp[10];  
    float avg_wt=0, avg_tat=0;  
    printf(" Total number of process : ");  
    scanf("%d", &n);  
    y = n;
   
for(i=0; i<n; i++)  
{  
printf("\n Enter the Arrival and Burst time of the Process[%d];\t", i+1);  
//printf("enter Arrival time,burst time is: \t");  
scanf("%d %d", &at[i],&bt[i]); 
temp[i] = bt[i]; 
}    
printf("Enter the Time Quantum for the process: \t");  
scanf("%d", &quant);  
printf("\n Process No \t\t arrival Time\t\t Burst Time\t\t ct \t\t\t TAT \t\t\t Waiting Time ");  
for(sum=0, i = 0; y!=0; )  
{  
if(temp[i] <= quant && temp[i] > 0)
{  
    sum = sum + temp[i];  
    temp[i] = 0;  
    count=1;  
    }     
    else if(temp[i] > 0)  
    {  
        temp[i] = temp[i] - quant;  
        sum = sum + quant;    
    }  
    if(temp[i]==0 && count==1)  
    {  
        y--;
        tat=sum-at[i];
        wt=tat-bt[i];
        printf("\nProcess No[%d] \t\t %d\t\t\t %d\t\t\t%d\t\t\t %d\t\t\t %d", i+1,at[i], bt[i], sum, tat, wt);  
        avg_wt = avg_wt+wt;  
        avg_tat = avg_tat+tat;  
        count =0;     
    }  
    if(i==n-1)  
    {  
        i=0;  
    }  
    else if(at[i+1]<=sum)  
    {  
        i++;  
    }  
    else  
    {  
        i=0;  
    }  
}  
avg_wt = avg_wt/n;  
avg_tat = avg_tat/n;  
printf("\n Average Turn Around Time: \t%f", avg_wt);  
printf("\n Average Waiting Time: \t%f", avg_tat);   
}  