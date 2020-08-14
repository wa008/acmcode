#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 7;
const int mod = 1e9 + 7;
typedef long long ll;
int n, m, k;

int main()
{
    int t;scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        if(n == 1)printf("-1\n");
        else{
            for(int i=0;i<n-1;i++)printf("7");
            printf("8\n");
        }
    }

 
    return 0;
}
