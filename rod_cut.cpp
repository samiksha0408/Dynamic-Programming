#include "stdc++.h"

using namespace std;

int dp[1000][1000];

int rod_cut(int len[],int price[], int n)
{
    for(int i = 0; i < n+1; i++)
    {
        for(int j = 0; j < n+1;j++)
        {
            if(i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }

            if(i > 0 and j > 0)
            {
                if(len[i-1] <= j)
                {
                    dp[i][j] = max(price[i-1] + dp[i][j-len[i-1]], dp[i-1][j]);
                }

                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    }

    return dp[n][n];

}



int main()
{
    int n;
    printf("Enter length of complete rod\n");
    cin >> n;  // max length of a piece of rod 

    int len[n]; int price[n];
    for(int i = 0; i < n; i++)
    {
        len[i] = i+1;
    }
    printf("Enter price array");
    for(int i = 0; i < n; i++)
    {
        cin >> price[i];
    }

    int ans = rod_cut(len, price,n);
    cout <<"Max profit:" << ans << endl;


}