#include<bits/stdc++.h>
using namespace std;


class KerimJavati{
public:
    int howLong(string s){
        int n = s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            ans += (s[i]-'a')*2+1;
        }
        return ans;
    }   
};

int main()
{
    

    return 0;
}
