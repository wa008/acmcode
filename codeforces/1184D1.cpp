#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5+7;
const ll mod = 1e9+7;
 
int n,m;
int ar[maxn];
vector<int> v;
int main()
{
    int k,t;
    scanf("%d%d%d%d", &n, &k, &m, &t);
    while(t--){
        int mark, x;
        scanf("%d%d", &mark, &x);
        if(mark==0){
            if(k<=x){
                n=x;
            }
            else{
                n -= x;
                k -= x;
            }
        }
        else{
            if(k<x)n++;
            else{
                n++;
                k++;
            }
        }
        printf("%d %d\n", n,k);
    }
    return 0;
}