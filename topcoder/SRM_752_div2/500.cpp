#include<bits/stdc++.h>

using namespace std;
class LiteratureOptimal{
public:
    int minTurns(int n,vector<int> t, vector<int> h){
        vector<int> vis(n*3+3,0);
        for(int i=0;i<t.size();i++)vis[t[i]]=1;
        int a=0,b=0,ans;
        for(int i=0;;i++){
            if(i<(int)h.size()-1){
                if(i%3==1 && !vis[h[i]]){
                    vis[h[i]]=1;
                    a++;
                }
                else if(i%3==2 && !vis[h[i]]){
                    b++;
                    vis[h[i]]=1;
                }
            }
            else if(i==(int)h.size()-1){
                if(i%3==1 && !vis[h[i]]){
                    a++;
                }
                else if(i%3==2 && !vis[h[i]])b++;
                if(a>=n || b>=n){
                    ans=i-(int)h.size()+1;
                    break;
                }
            }
            else{
                if(i%3==1)a++;
                else if(i%3==2)b++;
                if(a>=n || b>=n){
                    ans=i-(int)h.size()+1;
                    break;
                }
            }
        }
        return ans;
    }
};

int main()
{
    LiteratureOptimal l;
    vector<int> v1,v2;
    v1.push_back(1);
    v1.push_back(4);
    cout<<l.minTurns(2,v1,v2)<<"\n";
    return 0;
}
