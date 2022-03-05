//“r’†
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<stack>
using namespace std;

int main(){
    string in;
    stack<int> st1;
    cin >> in; 
    int area = 0;
    for(int i=0; i<in.size(); i++){
        if(in[i] == '\\'){
           st1.push(i); 
       } else if (in[i] == '/'){
          area += i - st1.top(); 
          st1.pop();
       } else if (in[i] == '_'){
        ;
       }
    }
    cout << area;
    return 0;
}