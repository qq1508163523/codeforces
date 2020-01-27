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
#define MAXN 200005
#define ull unsigned long long int
 
using namespace std;
char str[MAXN];
bool checker[150];
int n,k;
 
int main(){
#ifdef LOCAL
   freopen("in.txt","r",stdin);
#endif
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
  
   cin >> n >> k;
   cin >> str;
   for(int i = 0;i < k;i++){
      char tmp;
      cin >> tmp;
      checker[tmp] = 1;
   }
 
   ull cnt = 0;
   unsigned long long int ans = 0;
   for(int i = 0;i < n;i++){
       if(checker[str[i]]){
          cnt++;
       }else{
          if(cnt){
             ans += ((cnt * (cnt + 1))/2);
          }
          cnt = 0;
       }
   }
   
   if(cnt) ans += (cnt * (cnt + 1))/2;
   cout << ans;
 
   return 0;
}