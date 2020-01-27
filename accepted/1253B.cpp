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
int n;
int arr[MAXN];
int visit[MAXN * 10];
int cntt[MAXN * 10];
vector<int> ans;
set<int> _set;
 
 
int main(){
#ifdef LOCAL
   freopen("in.txt","r",stdin);
#endif
   
   scanf("%d",&n);
 
   for(int i = 0;i < n;i++){
       scanf("%d",&arr[i]);
   }
 
   
   if(n % 2 != 0 || arr[n - 1] > 0){
       printf("-1");
       return 0;
   }
 
   int cnt = 0;
   for(int i = 0; i < n;i++){
       if(arr[i] < 0){
          cntt[-arr[i]]--;
          if(cntt[-arr[i]] != 0){
              printf("-1");
              return 0;
          }else{
              cnt--;
          }
 
          if(!cnt){        
             for(int k : _set) visit[k] = 0;
             _set.clear();
             ans.push_back(i + 1);
          }
 
       }else{
          visit[arr[i]]++;
          cntt[arr[i]]++;
          cnt++;
          if(visit[arr[i]] > 1){
              printf("-1");
              return 0;
          }
       }
 
       _set.insert(abs(arr[i]));
 
   }
 
 
 
   printf("%d\n",ans.size());
   printf("%d ",ans[0]);
   for(int k = 1;k < ans.size();k++){
       printf("%d ",ans[k] - ans[k - 1]);
   }
   
   return 0;
}