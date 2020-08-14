#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5+7;
const ll mod = 1e9+7;
 
int n,m;
int ar[maxn];
vector<int> v[maxn];
int out[maxn];
char ch[maxn];
int main()
{
    vector<int> div;
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        if(n%i==0)div.push_back(i);
    }
    for(int x : div){
        v[x] = vector<int>(x, 0);
    }
    scanf("%s", ch+1);
    for(int i=1;i<=n;i++){
        if(ch[i]=='1'){
            for(int x:div){
                v[x][i%x]++;
            }
        }
    }
    for(int x:div)out[x]=1;
    for(int x:div){
        for(int i=0;i<x;i++){
            if(v[x][i]&1){
                out[x]=0;
                break;
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        int d = __gcd(n, i);
        ans += out[d];
    }
    printf("%d\n", ans);
    
    return 0;
}