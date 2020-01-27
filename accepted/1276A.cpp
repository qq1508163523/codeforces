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
#define MAXN 1500005 
 
using namespace std;
int t;
char str[MAXN];
 
int main(){
#ifdef LOCAL
   freopen("in.txt","r",stdin);
#endif
   scanf("%d",&t);
 
   while(t--){
       scanf("%s",str);
       int n = strlen(str);
       vector<int> ans;
       vector<int> vt;
       for(int i = 0;i < n;i++) 
          if(str[i] == 'n' || str[i] == 'w') vt.push_back(i);
 
       for(auto v : vt){
           if(str[v] == 'n' && v > 0 && v < n - 1){
               if(str[v - 1] == 'o' && str[v + 1] == 'e'){
                    str[v] = '-';
                    ans.push_back(v+1);
               }
           }else if(str[v] == 'w' && v > 0 && v < n - 1){
               if(str[v - 1] == 't' && str[v + 1] == 'o'){
                    if(v + 2 < n && str[v+2] == 'n'){
                        str[v+1] = '-';
                        ans.push_back(v+2);
                    }else{
                        str[v] = '-';
                        ans.push_back(v+1);
                    }
               }
           }
       }
 
       printf("%d\n",ans.size());
       for(auto v : ans){
           printf("%d ",v);
       }
       printf("\n");      
   }
   
   return 0;
}