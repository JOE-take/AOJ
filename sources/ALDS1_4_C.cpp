#define M 11111117
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<queue>
using namespace std;

vector<long long int> T(M,0); 
queue<string> Q;

int h1(long long int A){
    return A % M;
}

int h2(long long int A){
    return 1 + (A % M - 1);
}

int h(long long int A, int i){
    return (h1(A) + i*h2(A)) % M;
}

long long int strtoint(string str){
    long long int  number;
    int digit = str.length() - 1;
    for(int i=0; i<str.length(); i++){
        switch(str[i]){
            case 'A':
                number += 1*pow(10,digit);
                break;
            case 'C':
                number += 2*pow(10,digit);
                break;
            case 'G':
                number += 3*pow(10,digit);
                break;
            case 'T':
                number += 4*pow(10,digit);
                break;
        }
        digit--; 
    }
    return number;
}

void do_find(long long int strint){
    int i = 0;
    while(1){
        int j = h(strint,i);
        if(T[j] == strint){
            Q.push("yes");
            break;
        }else if(T[j] == 0 || i >= M){
            Q.push("no");
            break;
        }else ++i;
    }

}

void do_insert(long long int strint){
    int i=0;
    while(1){
        if(T[h(strint,i)] == 0){
            T[h(strint,i)] = strint;
            break;
        } 
       ++i; 
    }
}


int main(){
    int n;
    cin >> n;
    string order;
    string strIN;
    while(n){
        n--;
        cin >> order >> strIN;
        long long int strnumber = strtoint(strIN); 
        if(order == "insert") do_insert(strnumber);
        else if (order == "find") do_find(strnumber);
    }

    while(!Q.empty()){
        cout << Q.front() << "\n";
        Q.pop();
    }

    return 0;
}