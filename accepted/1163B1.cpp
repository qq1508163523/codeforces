#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>
#include <cstring>
#include <map>
#include <string>
#include <set>
#include <algorithm>
#include <functional>
#include <queue>
//#define LOCAL
#define MAXN 100005
 
using namespace std;
 
typedef long long int ll;
int n;
int arr[15];
 
int main(){
#ifdef LOCAL
   freopen("in.txt","r",stdin);
#endif
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
 
   cin >> n;
   int maxn = -1;
   int ans = 1;
   for(int i = 1;i <= n;i++){
	  int tmp;
      cin >> tmp;
      arr[tmp]++;
	  maxn = max(maxn,arr[tmp]);
	  if(maxn == 1 || maxn == i){ans = i;continue;}
	  
	  set<int> _set;
      for(int j = 1;j <= 10;j++){
          if(arr[j]) _set.insert(arr[j]);	  
      }
	  
	  if(_set.size() == 2){
		  int maxnn = -1;
		  int minnn = 19260817;
		  for(auto v : _set){
			 maxnn = max(maxnn,v);
			 minnn = min(minnn,v);
		  }
		  
          int cnt1 = 0,cnt2 = 0;
          for(int j = 1;j <= 10;j++){
              if(arr[j] == maxnn) cnt1++;
			  if(arr[j] == minnn) cnt2++;
          }
          if(cnt2 == 1 && minnn == 1) ans = i;
          else if(cnt1 == 1 && maxnn - minnn == 1) ans = i;		  
	  }
   }
   
   cout << ans;
   
   return 0;
}