#include "stdc++.h"
#include<unordered_map>
using namespace std;

unordered_map<string,bool> mp; 
bool scramble(string s1, string s2)
{
    if(s1.length() != s2.length()) return false;
    if(s1.compare(s2) == 0) return true;
    if(s1.length() < 0) return false;

    bool ans = false;
    int n = s1.length();
    for(int i = 1; i < n;i++){

        string a1 = s1.substr(0,i) + " " + s2.substr(n-i,i);
        string a2 = s1.substr(i,n-1) + " " + s2.substr(0,n-1);
        string b1 = s1.substr(0,i) + " " + s2.substr(0,i);
        string b2 = s1.substr(i,n-i) + " " + s2.substr(i,n-i);

        bool an1, an2, an3,an4;
        if(mp.find(a1) != mp.end()) an1 = mp[a1]; 
        else mp[a1] = scramble(s1.substr(0,i),s2.substr(n-i,i));

        if(mp.find(a1) != mp.end()) an2 = mp[a2]; 
        else mp[a2] = scramble(s1.substr(i,n-i),s2.substr(0,n-i));

        if(mp.find(b1) != mp.end()) an3 = mp[b1]; 
        else mp[b1] = scramble(s1.substr(0,i),s2.substr(0,i));

        if(mp.find(b2) != mp.end()) an4 = mp[b2]; 
        else mp[b2] = scramble(s1.substr(i,n-i),s2.substr(i,n-i));


        ans = ((mp[a1] and mp[a2]) ||(mp[b1] and mp[b2])); 
        if(ans)
        {
            break;
        }
    }

    return ans;


}


// great grate
//

int main()
{
    string s1,s2;
    cout << "enter the two strings" << endl;
    cin >> s1 >> s2;
    if(scramble(s1,s2)) 
    {
        cout << "Strings are scrambled" << endl;
    }
    else 
        cout << "Strings are not scrambled" << endl;


    
}