#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+7;
const int maxm = 2e6+7;
const ll mod = 1e9+7;

int ar[100];
int main()
{
    char ch[10];
    scanf("%s", ch);
    for(int i=0;i<4;i++){
        ar[ch[i]-'A']++;
    }
    int ins=0;
    for(int i=0;i<26;i++){
        if(ar[i]==2)ins++;
    }
    printf("%s\n", ins==2?"Yes":"No");

    return 0;
}
