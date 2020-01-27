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
 
using namespace std;
char pin[15][5];
int t;
int hash[10000];
int num[4] = {1000,100,10,1};
vector<int> vt;
set<int> _set;
 
int hasher(int i){
    int hashcode = 0;
    for(int k = 0;k < 4;k++) hashcode += num[k] * (pin[i][k] - '0');
    return hashcode;
}
 
int main(){
#ifdef LOCAL
   freopen("in.txt","r",stdin);
#endif
   scanf("%d",&t);
 
   while(t--){
       int n;
       scanf("%d",&n);
       for(int i = 0;i < n;i++){
           scanf("%s",pin[i]);
       }
 
       for(int i = 0;i < n;i++){
           if(!_set.count(hasher(i))){
               _set.insert(hasher(i));
           }else{
               vt.push_back(i);
           }
       }
 
       for(int i = 0;i < vt.size();i++){
           for(int k = 0;k < 4;k++){
               bool flag = 0;
               for(int j = 0;j <= 9;j++){
                   char tmp = pin[vt[i]][k];
                   pin[vt[i]][k] = j + '0';
                   if(!_set.count(hasher(vt[i]))){
                       _set.insert(hasher(vt[i]));
                       flag = 1;
                       break;
                   }else{
                       pin[vt[i]][k] = tmp;
                   }
               }
               if(flag){
                   break;
               }
           }
       }
 
       printf("%d\n",vt.size());
       for(int i = 0;i < n;i++){
           cout << pin[i] << endl;
       }
       vt.clear();  
       _set.clear(); 
   }
   
   return 0;
}