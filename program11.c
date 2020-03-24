
#include <stdio.h>
#include <stdbool.h>

int main()
{
    int allocation[3][3] = {{0,0,1},{3,2,0},{2,1,1}};//allocation
    int maxNeed[3][3] = {{8,4,3},{6,2,0},{3,3,3}};
    int available[3]={3,2,2}; //work
    int remaningNeed[3][3];
    int request[3][2];
    bool final[3] = {false,false,false};

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
            }
        }
    }

}

// safety algorithms


