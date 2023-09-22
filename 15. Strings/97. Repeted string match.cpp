#include<bits/stdc++.h>
using namespace std;

int repeatedStringMatch(string a, string b) {
        string A = a;
        int repeat = b.length()/a.length();
        int count = 0;
        for(int i=0;i< repeat + 2; i++){
            if(a.find(b) != std::string::npos){
                return count+1;
            }
            a = a + A;
            count++;
        }
        return -1;
}

int main(){
    string a = "a";
    string b = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    cout<<repeatedStringMatch(a,b);
}