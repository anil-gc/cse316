
#include <stdio.h>
#include <stdbool.h>

int main()
{
    int allocation[3][3] = {{0,0,1},{3,2,0},{2,1,1}};//allocation
    int maxNeed[3][3] = {{8,4,3},{6,2,0},{3,3,3}};
    int available[3]={3,2,2}; //work
    int remaningNeed[3][3];
    int request[3][2];
    bool temp = true;
    int counter=0;
    int counter2=0;

// this is for remaning need

    for(int i = 0;i<3;i++)
    {
        for(int j = 0;j<3;j++)
        {
            remaningNeed[i][j] = maxNeed[i][j] - allocation[i][j];
        }
    }
// remaning need end
    
//for request
    for (int i=0;i<2; i++) {
        for (int j=0; j<3; j++) {
            printf("enters request for p%d \n",i);
            scanf("%d",&request[i][j]);
        }
    }

//end request
    
// resource request algorithms
    
    for (int i=0; i<2; i++) {
        for (int j=0; j<3; j++) {
            if (request[i][j]<=remaningNeed[i][j]) {
                if(request[i][j] <= available[j])
                {
                    available[j] = available[j] - request[i][j];
                    allocation[i][j] = allocation[i][j] + request[i][j];
                    remaningNeed[i][j] = remaningNeed[i][j] - request[i][j];
                }
                else
                {
                    printf("wait");
                }
            }
            else
            {
                printf("error occurs system cant allocate the resources");
                break;
            }
        }
    }



// end of resource request algorithms


    // safety algorithms (bankers algorithms)
while(temp != false)
{
       for (int i=0; i<2; i++)
       {
           for (int j=0; j<3; j++)
           {
               if(counter == 3 || counter2 ==3)
               {
                   temp = false;
                   break;
               }
               if (remaningNeed[i][j]<=available[j])
               {
                   available[j] += allocation[i][j];
                   counter +=1;
               }
               else
               {
                   counter2 +=1;
                   continue;
               }
           }
       }
}
if(counter==3)
{
    printf("system is in safe state \n");
}
else{
    printf("system is stuck in deadlock or unsafe state");
}
}
