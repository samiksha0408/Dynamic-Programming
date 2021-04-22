#include "stdc++.h"

using namespace std;

int dp[1000][1000];


int coin_change2(int coin[], int sum, int n)
{
    for(int i = 0; i < n+1; i++)
    {
        for(int j = 0; j < sum+1; j++)
        {
            
            if(j == 0) dp[i][j] = 0;
            if(i == 0 and j > 0) dp[i][j] = INT_MAX;

            if( i > 0 and j > 0)
            {
                if(coin[i-1] <= j)
                {
                    
                    dp[i][j] = min(1 + dp[i][j-coin[i-1]],dp[i-1][j]);
                    
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

    }

    return dp[n][sum];

}

int main()
{
    int n;
    printf("Enter number of coins\n");
    cin >> n;

    int coin[n];
    printf("Enter coin array\n");
    for(int i = 0; i < n;i++)
    {
        cin >>coin[i];
    }

    int sum;
    printf("Enter maximum sum required\n");
    cin >> sum;

    int ans = coin_change2(coin, sum, n);
    cout << "Total  number of ways for minimum number of coins" << ans << endl;
    return 0;



}