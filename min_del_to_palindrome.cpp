#include "stdc++.h"

using namespace std;

int dp[1000][1000];



int min_del_topalindrome(string x, string y, int n, int m)
{
    
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
                }
                
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
               
            }
        }
    }
    int f = n - dp[n][m];

    return f;
}

int main()
{
   // memset(dp, -1, sizeof(dp));
    string x;
    printf("Enter the string\n");
    cin >> x;
    string x_rev = x;
    reverse(x_rev.begin(), x_rev.end());
;
    int ans = min_del_topalindrome(x, x_rev, x.length(), x.length());

    cout << "Min deletions to make a given string palindrome : " << ans << endl;
}