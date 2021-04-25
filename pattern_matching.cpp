#include "stdc++.h"

using namespace std;

int dp[1000][1000];

bool isPatternPresent(string x, string y, int n,int m)
{
    for(int i = 0; i <= n; i++)
    {
        for(int j =0;j<= m;j++)
        {
            if(i == 0 or j == 0)
            {
                dp[i][j] = 0;
            }

            if( i > 0 and j > 0)
            {
                if(x[i-1] == y[j-1])
                {
                    dp[i][j] = 1+ dp[i-1][j-1];
                }

                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

if(dp[n][m] == n)
    return true;
    else return false;
    
}

int main(){
    string x,y;
    cout << "Enter the pattern" << endl;
    cin >> x; 
    cout << "Enter the string " << endl;
    cin >> y;

    int n = x.length(); int m = y.length();
    if(isPatternPresent(x,y,n,m))
    {
        cout << "Pattern x is present in string y"<< endl;
    }
    else cout << "pattern x is not present in string y" << endl;

    return 0;
}
   
