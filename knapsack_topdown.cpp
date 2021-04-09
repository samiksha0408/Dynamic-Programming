#include "stdc++.h"

using namespace std;

int dp[102][102]; // depending on the problem constraints. 

int knapsack(int wt[], int price[], int W, int n)
{
    for(int i = 0; i< 102; i++)  //change recursive function to iterative 
        for(int j = 0; j < 102;j++)
            if(i==0|| j==0) dp[i][j] = 0;
        
    for(int i = 1; i< 102; i++)
    {
        for(int j = 1; j < 102; j++)
        {
            if(wt[i-1] <= W)
            {
                 dp[i][j] =max(val[i-1]+ dp[i-1][W-wt[i-1]], dp[i-1][j]);
            }
            else 
            {
                dp[i][j] = dp[i-1][j];
            }
        }
        
    }
    return dp[n][W];
    
}

int main()
{
    memset(dp,-1,sizeof(dp));
    int n;
    printf("Enter number of items");
    cin >>n;

    int wt[n];
    int price[n];
    int W;
    printf("Enter the weights of items\n");
    for(int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }  

    printf("Enter the prices of items\n");
    for(int i = 0; i < n; i++)
    {
        cin >> price[i];
    }  
    printf("Enter capacity of knapsack\n");
    cin >> W;

    int ans = knapsack(wt, price, W, n);
    cout << "Max profit for given knapsack is :" << ans << "."<<endl;

    

    return 0;


}
