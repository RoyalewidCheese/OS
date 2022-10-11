//FIFO Page replacement Algorithm
#include<stdio.h>
void main()
{
    int page_no,i,rs[100],frame_no,frame[30],j,hit=0,fault=0,pos=0;
    printf("Enter the number of pages:");
    scanf("%d",&page_no);
    printf("Enter the refernce string:");
    for(i=0;i<page_no;i++)
        scanf("%d",&rs[i]);
    printf("Enter the number of frames:");
    scanf("%d",&frame_no);
    for(i=0;i<frame_no;i++)
        frame[i]=-1;
    for(i=0;i<page_no;i++)
    {
        for(j=0;j<frame_no;j++)
        {
           if(rs[i]==frame[j])
            {
                hit++;
                break;
            }
            else if(frame[j]==-1)
            {
                frame[j]=rs[i];
                fault++;
                break;
            }
            else
            {
                if(j==frame_no-1)
                {
                    frame[pos]=rs[i];
                    pos++;
                    if(pos==frame_no)
                        pos=0;
                    fault++;
                    break;
                }
            }
        }
    }
    printf("Page fault=%d\n",fault);
    printf("Page hit=%d",hit);

}