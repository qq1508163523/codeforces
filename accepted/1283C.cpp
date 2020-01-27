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
int n;
priority_queue<int,vector<int>,greater<int>> pq;
priority_queue<int,vector<int>> pq2;
set<int> _set;
int arr[MAXN];
int ans[MAXN];
 
int main(){
#ifdef LOCAL
   freopen("in.txt","r",stdin);
#endif
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
  
   cin >> n;
   for(int i = 1;i <= n;i++){
       cin >> arr[i];
       ans[i] = arr[i];
       _set.insert(arr[i]);
   }
 
   for(int i = 1;i <= n;i++){
      if(!_set.count(i)){
          pq.push(i);
          pq2.push(i);
      }
   }
 
   int flg = 0;
   for(int i = 1;i <= n;i++){
      if(!arr[i]){
         vector<int> tmp;
         int flag = 0;
         while(!pq.empty()){
            int gift = pq.top();
            pq.pop();
            if(gift == i){
               tmp.push_back(gift);
            }else{
               arr[i] = gift;
               flag = 1;
               break;
            }
         }
         if(!flag){
            flg = 1;
            break;
         }
         for(int i = 0;i < tmp.size();i++){
             pq.push(tmp[i]);
         }
      }
   }
 
   if(flg){
      memcpy(arr,ans,sizeof(ans));
      for(int i = 1;i <= n;i++){
      if(!arr[i]){
         vector<int> tmp;
         while(!pq2.empty()){
            int gift = pq2.top();
            pq2.pop();
            if(gift == i){
               tmp.push_back(gift);
            }else{
               arr[i] = gift;
               break;
            }
         }
         for(int i = 0;i < tmp.size();i++){
             pq2.push(tmp[i]);
         }
      }
      }
   }
 
   memcpy(ans,arr,sizeof(arr));
   for(int i = 1;i <= n;i++){
      cout << ans[i] << " ";
   }
 
   return 0;
}