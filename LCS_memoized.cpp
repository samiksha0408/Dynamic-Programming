#include "stdc++.h"

using namespace std;
int dp[1000][1000];


int LCS_memoized(string x, string y, int n, int m)
{
    if(n == 0 or m == 0)
        return 0;

    if(dp[n][m] != -1)
        return dp[n][m];

    if(x[n-1] == y[m-1]) // two choices, to include wt[n-1] or not, take max of those to find optimal 
         return dp[n][m] = 1 + LCS_memoized(x,y,n-1,m-1);

    else 
        return dp[n][m] =  max(LCS_memoized(x,y,n-1,m),LCS_memoized(x,y,n,m-1));

}


int main()
{
    memset(dp,-1,sizeof(dp));
    string x,y;
    printf("enter the two strings\n");
 

    cin >> x>>y; 

    int ans = LCS_memoized(x,y,x.length(), y.length());
   


    cout << "Length of longest common subsequence : " << ans << endl;
}