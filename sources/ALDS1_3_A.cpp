//逆ポーランド記号（後置記法）の数式を計算、割り算には非対応
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;


vector<int> stack;

void push_int(int x){
    stack.push_back(x);
}


int pop_int(){
    int popped = stack.back();
    stack.pop_back();
    return popped;
}

void operation(string::iterator symbol){
    int op1 = pop_int();
    int op2 = pop_int();
    int result;
    switch(*symbol){
        case '+' :
            result = op2 + op1;
            break;

        case '-' :
            result = op2 - op1;
            break;

        case '*' :
            result = op2 * op1;
            break;
    }
    push_int(result);
}

void parse(string A){
    auto it = A.begin();
    while( it != A.end() ){
        if(*it == ' ' ){
            it++;
            continue;
        }
        if(isdigit(*it)){
            int temp = 0;
            while(isdigit(*it)){ 
                temp = temp*10 + int(*it - '0');
                it++;
           }
           push_int(temp);
        }
        else operation(it++);
    }
    cout << stack.front() << "\n";
}

int main(){
    string IN;
    getline(cin, IN);
    parse(IN); 
    return 0;
}