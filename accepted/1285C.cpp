#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <stack>
#include <cmath>
#include <algorithm>
//#define LOCAL
#define MAXN 100005
#define pb push_back
#define ull long long int
 
using namespace std;
ull n;
 
 
int main(){
#ifdef LOCAL
   freopen("in.txt","r",stdin);
#endif
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   
   cin >> n;
   int f = sqrt(n);
 
   for(ull i = f;i >= 1;i--){
       if(n % i == 0 && __gcd(i,n/i) == 1){
           cout << i  << " " << n/i;
           break;
       }
   }
  
   return 0;
}