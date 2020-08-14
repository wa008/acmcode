#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5+7;
const ll mod = 1e9+7;
 
int n,m;
int r[maxn],c[maxn];
int main()
{
    scanf("%d", &n);
    vector<int> aa,bb;
    for(int i=1;i<=4*n+1;i++){
        int a,b;scanf("%d%d", &a, &b);
        aa.push_back(a);
        bb.push_back(b);
        r[a]++;
        c[b]++;
    }
    int mxr=0,mnr=100,mxc=0,mnc=100;
    for(int i=0;i<100;i++){
        if(r[i]>=2){
            mxr = max(mxr, i);
            mnr = min(mnr, i);
        }
    }
    for(int i=0;i<100;i++){
        if(c[i]>=2){
            mxc = max(mxc, i);
            mnc = min(mnc, i);
        }
    }
    for(int i=0;i<aa.size();i++){
        int x=aa[i], y=bb[i];
        int flag=1;
        if(x==mxr || x==mnr){
            if(y<mnc || y>mxc){
                flag=0;
            }
        }
        else if(y==mxc || y==mnc){
            if(x<mnr || x>mxr){
                flag=0;
            }
        }
        else flag=0;
        if(flag==0){
            printf("%d %d\n", x, y);
            return 0;
        }
    }
    return 0;
}