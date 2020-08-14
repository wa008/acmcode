#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e6+7;
const ll mod = 1e9+7;
int n,m;
int ar[maxn];

char ch[maxn];
int main()
{
    scanf("%s",ch);
    n=strlen(ch)/3;
    for(int i=0; i<n*3; i++){
        int x = ch[i];
        for(int j=0;j<8;j++){
            ar[i*8+j] = x&1;
            x >>= 1;
        }
    }
    vector<int> ans(n*4,0);
    for(int i=0;i<n*4;i++){
        int ins=0;
        for(int j=5;j>=0;j--){
            if(ar[i*6+j])ans[i] |= (1<<ins);
            ins++;
        }
    }
    for(int i=0; i<n*4; i++){
        printf("%d",ans[i]);
        if(i<n*4)printf(" ");
    }

    return 0;
}
