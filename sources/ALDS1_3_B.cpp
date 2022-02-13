#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;

struct process{
    string name;
    int time;
};

int n;
int TIME = 0;
int head = 0;
int tail = 0;


void initialize(){
    head = 0;
    tail = 0;
}


bool IS_empty(){
    return (head == tail);
}


bool IS_full(vector<process>& list){
    return head == (tail + 1) % list.size();
}


void enqueue(process inq, vector<process>& list){
    list[tail] =inq;
    tail = (tail + 1) % list.size();
}


process dequeue(vector<process>& list){
    process retp = list[head];
    head = (head + 1) % list.size();
    return retp;
}

void run(int qtime, vector<process>& list){
    if(list[head].time > qtime){
        //プロセスタイムが残っている場合
        list[head].time -= qtime;
        TIME += qtime;
        process temp = dequeue(list);
        enqueue(temp, list);
    }
    else{
        //終了する場合
        TIME += list[head].time;
        list[head].time = 0;
        process tmp = dequeue(list);
        cout << tmp.name << " " << TIME << "\n";
    }
}


void roundrobin(int qtime, vector<process>& list){
    while(!IS_empty()){
        run(qtime, list);
    }
}


int main(){
    int qtime;
    cin >> n;
    cin >> qtime;
    vector<process> list(n+2);
    initialize(); 
    for(int i=0; i < n; i++){
        process inq;
        cin >> inq.name;
        cin >> inq.time;
        enqueue(inq, list);
    }
    roundrobin(qtime, list);
    return 0;
}