
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <chrono>
#include <cstring>

using namespace std;

int n, m, k;
typedef long long ll;

int main() 
{
    ll a, b, c;
    scanf("%lld%lld%lld", &a, &b, &c);
    if(c - a - b >= 0 && 4 * a * b < (c - a - b) * (c - a - b))printf("Yes\n");
    else printf("No\n");


    return 0;
}
