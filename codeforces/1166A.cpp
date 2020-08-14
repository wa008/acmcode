#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+7;
const int maxm = 2e1+7;
const int mod = 1e9+7;
typedef long long ll;
typedef unsigned long long ull;

int n,m,k;
int ar[maxn];
char ch[maxn];
int main()
{
    int ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",ch);
        ar[ch[0]-'a']++;
    }
    for(int i=0;i<26;i++){
        int x = ar[i]/2;
        ans += x*(x-1)/2;
        x = ar[i]-x;
        ans += x*(x-1)/2;
    }
    printf("%d\n",ans);


    return 0;
}