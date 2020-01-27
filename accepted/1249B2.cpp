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
int n,m;
int arr[MAXN];
int dp[MAXN];
int cnt = 0;
 
void dfs(int i,int j){
    cnt++;
    if(arr[i] == j){
       dp[i] = cnt;
       return;
    }else{
       dfs(arr[i],j);
       dp[i] = cnt;
    }
}
 
int main(){
#ifdef LOCAL
   freopen("in.txt","r",stdin);
#endif
   scanf("%d",&m);
 
   while(m--){
       scanf("%d",&n);
       for(int i = 1;i <= n;i++){
           scanf("%d",&arr[i]);
           dp[i] = 0;
       }
 
       for(int i = 1;i <= n;i++){
           //printf("%d ",find_root(i));
           if(!dp[i]){
               cnt = 0;
               dfs(i,i);
           }
       }
 
       for(int i = 1;i <= n;i++){
           printf("%d ",dp[i]);
       }
       printf("\n");
   }
 
   
   return 0;
}