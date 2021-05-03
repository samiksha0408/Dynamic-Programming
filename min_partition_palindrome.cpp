#include "stdc++.h"

using namespace std;



bool isSubstringPalindrome(string s, int st, int en)
{
    int i = st; int j = en;
    bool yes = true;
    while(i <= j)
    {
        if(s[i] ==  s[j])
        {
            i++;
            j--;
        }
        else
        {
            yes = false;
            break;
        }  
    }

    return yes;
}

int min_partition(string s, int i, int j)
{

    if(isSubstringPalindrome(s,i,j)) return 0;
    

    if (i >= j)
        return 0;


        int temp = INT_MAX;

    
    for (int k = i; k < j; k++)
    {
        int tempans = min_partition(s, i, k) + min_partition(s, k + 1, j) + 1;
        // cout << "index" << i << " and" << k << endl;
        //         cout << "index" << k+1 << " and" << j << endl;


        temp = min(tempans, temp);
    }

    return temp;
}

int main()
{
    string s;
    cout << "Enter the string" << endl;
    cin >> s;
    int ans;
    int n = s.length();
    ans = min_partition(s, 0, n - 1);
    cout << "Minimum number of partitions is :" << ans << endl;

}