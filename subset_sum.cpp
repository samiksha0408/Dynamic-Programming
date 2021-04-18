#include "stdc++.h"

using namespace std;

int dp[102][102]; // depending on the problem constraints.  dp[n+1][w+1] = dp[n+1][sum+1] 



bool subset_sum(int arr[],  int sum, int n)
{


    for(int i = 0; i< n+1; i++) 
    {
        for(int j = 0; j <sum+1;j++)
        {
            if(j == 0) dp[i][j] = true;
            else if(j > 0 and i == 0) dp[i][j] = false; 

            if(i > 0 and j > 0)
            {
                 if(arr[i-1] <=  j)
                 {
                    dp[i][j] = dp[i-1][j] or dp[i-1][j - arr[i-1]];
                 }
                 else
                 {
                     dp[i][j] = dp[i-1][j];
                 }
            }
        }

    } 
    //change recursive function to iterative 
        
    
    return dp[n][sum];
    
}

int main()
{
    memset(dp,-1,sizeof(dp));
    int n;
    printf("Enter number of items");
    cin >> n;

    int arr[n];
   
    int sum;
    printf("Enter the array\n");
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }  

     
    printf("Enter sum\n");
    cin >> sum;

     if(subset_sum(arr,sum, n))
     {
         cout << "Subset present"<<endl;
     }

     else
     {
         cout << "Subset not present" << endl;
     }
   
    return 0;


}
