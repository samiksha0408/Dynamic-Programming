#include "stdc++.h"

using namespace std;

int dp[1000][1000];


int LC_substring(string x, string y, int n, int m)
{
    
    int ans = 0;
    for(int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 or j == 0) dp[i][j] = 0;

            if (i > 0 and j > 0)
            {
                if(x[i - 1] == y[j - 1]) 
                {
                     dp[i][j] = dp[i - 1][j - 1] + 1;
                     ans = max(ans,dp[i][j]);
                }
                
                else dp[i][j] = 0;
               
            }
        }
    }


    return ans;
}

int main()
{
   // memset(dp, -1, sizeof(dp));
    string x, y;
    printf("Enter the two strings\n");
    cin >> x >> y;

    int ans = LC_substring(x, y, x.length(), y.length());

    cout << "Length of longest common substring is: " << ans << endl;
}