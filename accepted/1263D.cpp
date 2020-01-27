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
#define MAXN 55
 
using namespace std;
int parent[150],n;
char str[MAXN];
int ans = 0;
 
 
int main(){
#ifdef LOCAL
   freopen("in.txt","r",stdin);
#endif
   memset(parent,-1,sizeof(parent));
   scanf("%d",&n);
   while(n--){
      scanf("%s",str);
      int len = strlen(str);
      int flag = 0;
      for(int i = 0;i < len;i++){
          if(parent[str[i]] != -1){
              flag = 1;
              break;
          }
      }
 
      if(!flag){
         ans++;
         for(int i = 0;i < len;i++) parent[str[i]] = ans;
      }else{
         bool flg = 0;
         int ch = str[0];
         set<int> _set;
         for(int i = 0;i < len;i++){
             if(parent[str[i]] != -1){
                 _set.insert(parent[str[i]]);
             }
             if(ch != str[i]) flg = 1;
         }
         
         if(flg){
             for(int i = 0;i < len;i++) parent[str[i]] = ans;
             if(_set.size() != 1){
                 ans -=  _set.size() - 1;
             }
         }
      }
   }
 
   printf("%d",ans);
   
   return 0;
}