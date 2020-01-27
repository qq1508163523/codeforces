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
 
using namespace std;
typedef long long int ll;
int t;
int n,coin;
int arr[MAXN];
ll nums[MAXN];
 
 
void solve(){
 
}
 
int main(){
#ifdef LOCAL
   freopen("in.txt","r",stdin);
#endif
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
 
   cin >> t;
 
   while(t--){
      cin >> n >> coin;
      for(int i = 1;i <= n;i++){
           cin >> arr[i];
           nums[i] = arr[i] + nums[i - 1];
      }
 
      if(nums[n] <= coin){
         cout << 0 << endl;
         continue;
      }
 
      int maxn = 0;
      int ans = 1;
      arr[0] = -1;
      arr[n+1] = -1;
 
      for(int i = 1;i <= n;i++){
         if(!(arr[i - 1] < arr[i])) continue;
         int j = i + 1;
         for(;j <= n;j++){
             if(nums[j] - arr[i] > coin) break;            
         }
         if(maxn < j && nums[j - 1] - arr[i] <= coin){
             maxn = j;
             ans = i;
         }
      }
 
      cout << ans << endl;
 
   }
   
   return 0;
}