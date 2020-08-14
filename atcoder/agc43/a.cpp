#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 1e2 + 7;

int n, m, k;

int arr[maxn][maxn];
char ch[maxn][maxn];

int main()
{
    scanf("%d%d", &n, &m);
    for(int i=0;i<n;i++){
        scanf("%s", ch[i]);
        for(int j=0;j<m;j++)arr[i][j] = 200;
    }
    arr[0][0] = ch[0][0] == '#';
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i + 1 < n)arr[i + 1][j] = min(arr[i + 1][j], arr[i][j] + (ch[i + 1][j] != ch[i][j] && 
                        ch[i + 1][j] == '#'));
            if(j + 1 < m)arr[i][j + 1] = min(arr[i][j + 1], arr[i][j] + (ch[i][j + 1] != ch[i][j] &&
                        ch[i][j + 1] == '#'));
        }
    }
    printf("%d\n", arr[n - 1][m - 1]);

    return 0;
}
