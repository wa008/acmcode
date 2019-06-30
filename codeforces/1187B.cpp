#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5+7;
const int maxm = 2e6+7;
const int sz = 26;
const ll mod = 1e9+7;
int n,m,k;

char s[maxn], t[maxn];
int arr[maxn][sz];
int main()
{ 
    scanf("%d", &n);
    scanf("%s", s+1);
    for(int i=1;i<=n;i++){
        for(int j=0;j<sz;j++)arr[i][j] = arr[i-1][j];
        arr[i][s[i]-'a']++;
    }
    scanf("%d", &m);
    int now[30];
    while(m--){
        scanf("%s", t+1);
        k = strlen(t+1);
        for(int i=0;i<sz;i++)now[i]=0;
        for(int i=1;i<=k;i++){
            now[t[i]-'a']++;
        }
        int l=1,r=n;
        while(l<r){
            int mid = l+r>>1;
            int flag=1;
            for(int i=0;i<sz;i++){
                if(arr[mid][i] < now[i]){
                    flag=0;
                    break;
                }
            }
            if(flag)r=mid;
            else l=mid+1;
        }
        printf("%d\n", l);
    }
    

    return 0;
}
