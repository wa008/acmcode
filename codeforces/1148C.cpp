#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e5+7;
const ll mod = 1000000000000037;

int n,m,ar[maxn];
int s[maxn];
int xx[maxn*5],yy[maxn*5],cnt=0;
void swap2(int a,int b){
    xx[++cnt] = a;
    yy[cnt] = b;
    int s1=ar[a], s2=ar[b];
    swap(s[s1], s[s2]);
    swap(ar[a], ar[b]);
}
void swap3(int a,int b,int c){
    swap2(a,b);
    swap2(a,c);
    swap2(a,b);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d", ar+i);
    for(int i=1;i<=n;i++){
        s[ar[i]] = i;
    }
    for(int i=1;i<=n;i++){
        if(ar[i]==i)continue;
        int a = i, b = s[i];
        if(abs(a-b)>=n/2){
            swap2(a,b);
        }
        else if(b<=n/2){
            swap2(b,n);
            swap2(a,n);
        }
        else if(a>n/2){
            swap3(1,a,b);
        }
        else{
            swap3(1,b,n);
            swap2(a,n);
        }
        assert(ar[i]==i);
    }
    for(int i=1;i<=n;i++)assert(ar[i]==i);
    assert(cnt<=n*5);
    printf("%d\n",cnt);
    for(int i=1;i<=cnt;i++)printf("%d %d\n",xx[i],yy[i]);


    return 0;
}