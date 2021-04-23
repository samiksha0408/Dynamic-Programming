#include "stdc++.h"

using namespace std;


int LCS_recursive(string x, string y, int n, int m)
{
    if( n == 0 || m == 0)
        return 0;

    if(x[n-1] == y[m-1])
    {
        return 1 + LCS_recursive(x,y,n-1,m-1);
    }
    else
        return max(LCS_recursive(x,y,n-1,m), LCS_recursive(x,y,n,m-1));

}


int main()
{
    string x,y;
        printf("enter the two strings\n");
 

    cin >> x>>y; 

    int ans = LCS_recursive(x,y,x.length(), y.length());
   


    cout << "Length of longest common subsequence : " << ans << endl;
}