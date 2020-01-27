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
int n,m;
int b[MAXN];
int nums[MAXN];
 
int main(){
#ifdef LOCAL
   freopen("in.txt","r",stdin);
#endif
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
 
   cin >> t;
 
   while(t--){
      memset(nums,-1,sizeof(nums));
      cin >> n >> m;
      for(int i = 0;i < n;i++){
         int tmp;
         cin >> tmp;
         nums[tmp] = i;
      }
 
      for(int i = 0;i < m;i++) cin >> b[i];
 
      
      int cnt = 0;
      int range = -1;
      unsigned long long int ans = 0;
      for(int i = 0;i < m;i++){
         if(range > nums[b[i]]){
            ans += 1;
         }else{
            range = nums[b[i]];
            ans += 2 * (nums[b[i]] - cnt) + 1;
         }
         cnt++;
      }
 
      cout << ans << endl;
 
   }
   
   return 0;
}