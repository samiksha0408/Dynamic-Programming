#include "stdc++.h"
using namespace std;

int dp[1000][1000];
int i,j;


string print_scs(string x, string y, int n, int m)
{
    string ans;

    for(i = 0; i<= n; i++)
    {
        for(j = 0; j<= m;j++)
        {
            if(i == 0 or j == 0) dp[i][j] = 0;
            if( i > 0 and j > 0)
            {
                if(x[i-1] == y[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

//i = n; j = m;

    while(i > 0 and j > 0)
    {
        if(x[i-1] == y[j-1])
        {
            ans.push_back(x[i-1]); i--;j--;
        }
        else if(dp[i-1][j] > dp[i][j-1])
        {
            ans.push_back(x[i-1]);
            i--;
        } 
        else 
        {
            ans.push_back(y[j-1]);
            j--;
        }
    }
    while(i > 0)
    {
        ans.push_back(x[i-1]); i--;
    }
    while(j > 0)
    {
        ans.push_back(y[j-1]); j--;
    }

    reverse(ans.begin(), ans.end());    
    return ans;

}

int main(){
    string x,y;
    printf("Enter the two strings\n");
    cin >> x >> y;

    string s = print_scs(x,y,x.length(), y.length());
    cout << "Shortest common supersequence is " << s << endl;

}