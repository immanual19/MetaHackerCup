#include <bits/stdc++.h>
typedef long long int lld;
using namespace std;

class Data{
public:
    int count;
    char ch;
    int flag;
};
int main() {

    ios_base::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);
    
    int t,i,j,tc=1;
    cin>>t;
    while(t--){
        string s;
        vector<Data>v1;
        cin>>s;
        if(s[0]=='A' || s[0]=='E' || s[0]=='I' || s[0]=='O' || s[0]=='U'){
            v1.push_back({1,s[0],1});
        }
        else{
            v1.push_back({1,s[0],0});
        }
        
        for( i=1;i<s.size();i++){
            int flag1=0;
            if(s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
                flag1=1;
                 }
                 else{
                     flag1=0;
                 }
            int flag=0;
                for( j=0;j<v1.size();j++){
                    if(v1[j].ch==s[i]){
                        flag=1;
                        break;
                    }
                }
            if(flag){
                v1[j].count++;
            }
            else{
                v1.push_back({1,s[i],flag1});
            }
        }
        sort(v1.rbegin(),v1.rend(),[](const Data &c1,const Data &c2){
            return c1.count<c2.count;
        });
        vector<int>v2;
        int res=0;
        for(int i=0;i<v1.size();i++){
            for(int j=0;j<v1.size();j++){
                if(i==j){
                    continue;
                }
                else{
                    if((v1[i].flag==1 && v1[j].flag==1)||(v1[i].flag==0 && v1[j].flag==0)){
                        res=res+2*v1[j].count;
                        
                    }
                    else{
                        res=res+v1[j].count;
                    }
                    
                }
            }
            v2.push_back(res);
            res=0;
        }
        int flagAgain1=0,flagAgain2=0;
        for(int i=0;i<v1.size();i++){
            if(v1[i].flag==0){
                flagAgain1=flagAgain1+v1[i].count;
            }
            else{
                flagAgain2=flagAgain2+v1[i].count;
            }
        }
        if((flagAgain1==s.length() || flagAgain2==s.length()) && s.length()>1){
            cout<<"Case #"<<tc<<": "<<s.length()<<endl;
        }
        else{
            sort(v2.begin(),v2.end());
            cout<<"Case #"<<tc<<": "<<v2[0]<<endl;
        }
        
        tc++;
    }
    return 0;
}
