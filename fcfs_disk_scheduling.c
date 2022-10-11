//FCFS Disk scheduling algorithm
#include<stdio.h>
#include<stdlib.h>
void main()
{
    int req_q[30],req_no,ini_pos,i,head,total_movement=0;
    printf("Enter the number of requests:");
    scanf("%d",&req_no);
    printf("Enter the initial position of head:");
    scanf("%d",&ini_pos);
    printf("Enter Request Queue:");
    for(i=0;i<req_no;i++)
        scanf("%d",&req_q[i]);
    head=ini_pos;
    for(i=0;i<req_no;i++)
    {
        total_movement=total_movement+abs(head-req_q[i]);
        head=req_q[i];
    }
    printf("Total head movement=%d",total_movement);
}