//TAKE INPUT IN ALL UPPERCASE

#include<iostream>
#include<vector>
#include<string>
using namespace std;


string encryption(vector<vector<char>>&a,string s,string key)
{
    string encrypt="";
   for(int i=0;i<s.size();i++){
        encrypt+= a[s[i]-'A'][key[i]-'A'];
    }
    return encrypt;
}

string decryption(vector<vector<char>>&a,string s,string key)
{
    int n=26;
    string decrypt;
    for(int i=0;i<s.size();i++){
        for(int j=0;j<n;j++){
            if(a[j][key[i]-'A']==s[i]){
                decrypt += 'A'+j;
                break;
            }
        }
    }
    return decrypt;
}
int main(){
    vector<vector<char> > a(26,vector<char>(26));
    int i,j,k,n;
    k=0;
    n=26;
    for(i=0;i<n;i++){
        k=i;
        for(j=0;j<n;j++){
            a[i][j]='A'+k;
            k++;
            if(k==26)
                k=0;
        }
    }
    cout<<"Enter the message\n";
    string s;
    cin>>s;
    cout<<"Enter the key\n";
    string key;
    cin>>key;
    k=0;
    int mod = key.size();
    for(i=key.size();i<s.size();i++){
        key+=key[k%mod];
        k++;
    }
    string encrypt=encryption(a,s,key);
    cout<<"Encrypted message: "<<encrypt<<'\n';  
    string decrypt=decryption(a,encrypt,key);
    cout<<"Message after decryption: "<<decrypt;
}
