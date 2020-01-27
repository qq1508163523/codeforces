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
 
using namespace std;
int t,n;
int arr[MAXN];
 
 
int main(){
#ifdef LOCAL
   freopen("in.txt","r",stdin);
#endif
   scanf("%d",&t);
   
   while(t--){
      scanf("%d",&n);
      int ans = 0x3f3f3f3f;
      memset(arr,-1,sizeof(arr));
      for(int i = 0;i < n;i++){
          int tp;
          scanf("%d",&tp);
          if(arr[tp] != -1) ans = min(ans,i - arr[tp] + 1);
          arr[tp] = i;
      }
      
      printf("%d\n",ans==0x3f3f3f3f?-1:ans);
 
   }
   return 0;
}