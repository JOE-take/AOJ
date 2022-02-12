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
    return head == tail;
}


bool IS_full(vector<process>& list){
    return head == (tail + 1) % list.size();
}


void enqueue(process inq, vector<process>& list){
    if(IS_full(list)){
        cout <<"is full";
        exit(1);
    }

    if(tail == list.size())
        tail = 0;
    list[tail] = inq;
    tail++;
}


process dequeue(vector<process>& list){
    if(IS_empty){
        cout << "error! : requested dequeue but queue were empty" << "\n";
        cout << "head = " << head << " " << "tail = " << tail << "\n";
        exit(1);
    }

   head++;
   if(head == list.size()){
        head == 0;
        return list[list.size() - 1];
   }
   else
        return list[head - 1];

}

void run(int qtime, vector<process>& list){
    if(list[head].time > qtime){
        //プロセスタイムが残っている場合
        list[head].time -= qtime;
        TIME += qtime;
        enqueue(list[head], list);
        dequeue(list);
    }
    else{
        //終了する場合
        TIME += list[head].time;
        list[head].time = 0;
        cout << dequeue(list).time << " " << TIME << "\n";
    }
}


void roundrobin(int qtime, vector<process>& list){
    while(!IS_empty()){
        cout << "run" << "\n";
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
    for(auto it : list){
        cout << it.name << " " << it.time << "\n";
    }
    cout << "\n" << "head = " << head << "\n" << "tail = " << tail;
    roundrobin(qtime, list);
    return 0;
}