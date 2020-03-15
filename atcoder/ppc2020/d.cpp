#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+7;
typedef long long ll;
int n, m, k;

char ch[maxn];
multiset<char> ms;
multiset<char>::iterator it;
void dfs(int x, char c){
    ch[x] = c;
    ms.insert(c);
    if(x == n - 1){
        ch[n] = '\0';
        printf("%s\n", ch);
        ms.erase(ms.find(c));
        return ;
    }
    it = ms.end();
    it--;
    char mid_c = *it;
    //cout << "mid_c : " << mid_c << "\n";
    for(char next = 'a'; next <= 'z' && next <= mid_c + 1; next += 1){
        dfs(x + 1, next);
    }
    ms.erase(ms.find(c));
}
int main()
{
    scanf("%d", &n);
    dfs(0, 'a');

    return 0;
}
