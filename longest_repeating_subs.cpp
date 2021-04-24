#include "stdc++.h"

using namespace std;

int dp[1000][1000];

vector<int> lengths;

int lrs(string x, string y, int n, int m)
{
    
    for(int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 or j == 0) dp[i][j] = 0;

            if (i > 0 and j > 0)
            {
                if(x[i - 1] == y[j - 1] and i!= j) 
                {
                     dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
               
            }
        }
    }


    return dp[n][m];
}

int main()
{
   // memset(dp, -1, sizeof(dp));
    string x;
    printf("Enter the string\n");
    cin >> x; 
    string y = x;

    int ans = lrs(x, y, x.length(), y.length());

    cout << "Length of longest repeating subsequence : " << ans << endl;
}