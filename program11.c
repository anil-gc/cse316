#include <stdio.h>
#include <stdbool.h>

int main()
{
    int allocation[3][3] = {{0,0,1},{3,2,0},{2,1,1}};//allocation
    int maxNeed[3][3] = {{8,4,3},{6,2,0},{3,3,3}};
    int work[3]={3,2,2}; //available
    int remaningNeed[3][3];
    int safe;
    bool final[3] = {false,false,false};

// this is for remaning need

    for(int i = 0;i<3;i++)
    {
        for(int j = 0;j<3;j++)
        {
            remaningNeed[i][j] = maxNeed[i][j] + work[i][j];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        if(final == false)
        {   int checking = 0;
            for (int j = 0; j < 3; j++)
            {
                if(remaningNeed[i][j] <= work[j]) //checking steps 2
                {
                    continue;
                }
                else
                {
                    break;
                }
                checking += 1;
                
            }
            if(checking == 3)
            {
                
            }
            
        }
        else
        {
            
        }
        
    }


}
