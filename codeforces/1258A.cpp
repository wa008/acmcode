#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+7;
typedef long long ll;
int n,m;
char c[maxn];
int main()
{
    scanf("%d", &n);
    scanf("%s", c);
    int a = 0 , b = 0;
    for(int i=0;i<n;i++){
        a += c[i] == 'L';
        b += c[i] == 'R';
    }
    printf("%d\n", a+b+1);
    return 0;
}