#include <bits/stdc++.h>
using namespace std;
#define max_length 1000
int main() {
    int t,c=1;
    cin>>t;
    getchar();
    while(t--){
        string s="";
        map<char,int>m;
        while(1){
            char ch;
            scanf("%c",&ch);
            if(ch=='\n'){
                break;
            }
            else{
                if(ch!=' '){
                    s+=ch;
                }
            }
        }
        for(int i=0;i<s.size();++i){
            if(s[i]=='H' || s[i]=='A' || s[i]=='C' || s[i]=='K' || s[i]=='E' || s[i]=='R'  || s[i]=='U'  || s[i]=='P')
            m[s[i]]++;
        }
        int numberOfC=m['C'];
        int minCharacter=1000;
        for(auto value:m){
            if(value.second<minCharacter){
                minCharacter=value.second;
            }
        }
        if(m.size()<8 || numberOfC<2 || minCharacter==0){
            cout<<"Case #"<<c<<": 0"<<endl;
            
        }
        else{
            if(minCharacter==1){
                cout<<"Case #"<<c<<": 1"<<endl;
            }
            else{
                while(minCharacter*2>numberOfC){
                    minCharacter--;
                }
                cout<<"Case #"<<c<<": "<<minCharacter--<<endl;
            }
        }
        c++;
    }
    return 0;
}
