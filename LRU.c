//LRU Page replacement Algorithm
#include<stdio.h>
void main()
{
    int page_no,i,rs[100],frame_no,frame[30],j,hit=0,fault=0,pos,k,l,replace;
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
                    pos=-1;
                    for(l=0;l<frame_no;l++)
                    {
                        for(k=i-1;k>=0;k--)
                        {
                            if(frame[l]==rs[k])
                            {
                                if(pos==-1)
                                    pos=k;
                                else if(pos>k)
                                    pos=k;
                                break;
                            }
                        }
                    }
                    for(k=0;k<frame_no;k++)
                    {
                        if(frame[k]==rs[pos])
                        {
                            frame[k]=rs[i];
                            fault++;
                            break;
                        }
                    }
                }
            }
        }
    }
    printf("\nPage fault=%d\n",fault);
    printf("Page hit=%d",hit);
}