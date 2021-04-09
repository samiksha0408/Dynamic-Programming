/* 0 1 knapsack recursive approach solution 
given = wt[] array of weights of items, val[] array of price of each item, W = capacity of knapsack */

#include "stdc++.h"

using namespace std;

int dp[102][102]; // depending on the problem constraints. 

int knapsack(int wt[], int price[], int W, int n)
{
    if(n == 0 || W == 0)  // base condition for recursion   
        return 0;         // answer for base condition 
    
    if(dp[n][W] != -1)
        return dp[n][W];

    if(wt[n-1] <= W) // two choices, to include wt[n-1] or not, take max of those to find optimal 
         return dp[n][W] = max(price[n-1]+ knapsack(wt,price,W-wt[n-1],n-1),knapsack(wt,price,W,n-1));
        
    else 
        return dp[n][W] =  knapsack(wt,price,W,n-1);
    
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