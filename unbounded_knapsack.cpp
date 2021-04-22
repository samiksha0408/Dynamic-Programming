#include "stdc++.h"

using namespace std;

int dp[102][102]; // depending on the problem constraints. 

int knapsack(int wt[], int price[], int W, int n)
{
    for(int i = 0; i< n+1; i++) 
    {
        for(int j = 0; j < W+1;j++)
        {
            if(i==0|| j==0) dp[i][j] = 0;
        
    
            if(i > 0 and j > 0){
                if(wt[i-1] <= W)
                {
                    dp[i][j] = max(price[i-1]+ dp[i][j-wt[i-1]], dp[i-1][j]);
                }
                else 
                {
                    dp[i][j] = dp[i-1][j];
                }

            }
        }

    } //change recursive function to iterative 
        
    
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
