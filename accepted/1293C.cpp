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
int t;
int n; 
pair<int,int> pr[MAXN];
map<int,int> _map;//row1 
map<int,int> _map2;// row2
int block = 0;
int d[] = {-1,0,1};
 
int main(){
#ifdef LOCAL
   freopen("in.txt","r",stdin);
#endif
   int n,q;
   int cnt = 0;
   scanf("%d%d",&n,&q);
 
   for(int i = 1;i <= q;i++){
       scanf("%d%d",&pr[i].first,&pr[i].second);
   }
 
   for(int i = 1;i <= q;i++){
       int r = pr[i].first;
       int c = pr[i].second;
 
       for(int j = 0;j < 3;j++){
          int sum;
          if(r == 1){
             sum = _map[c] + (c + d[j] >= 1 && c + d[j] <= n?_map2[c+d[j]]:0);
          }else{
             sum = _map2[c] + (c + d[j] >= 1 && c + d[j] <= n?_map[c+d[j]]:0);
          }
 
          if(sum == 2) block--;
       }
 
       if(r == 1){
           if(_map[c] == 0) _map[c] = 1;
           else _map[c] = 0;
       }else{
           if(_map2[c] == 0) _map2[c] = 1;
           else _map2[c] = 0;
       }
 
       for(int j = 0;j < 3;j++){
          int sum;
          if(r == 1){
             sum = _map[c] + (c + d[j] >= 1 && c + d[j] <= n?_map2[c+d[j]]:0);
          }else{
             sum = _map2[c] + (c + d[j] >= 1 && c + d[j] <= n?_map[c+d[j]]:0);
          }
 
          if(sum == 2) block++;
       }
 
       if(!block) printf("Yes\n");
       else printf("No\n");
   }
}