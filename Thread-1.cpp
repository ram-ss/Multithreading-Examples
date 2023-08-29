#include<iostream>
#include<thread>
#include<unistd.h>

using namespace std;

void TaskA(){
    for(int i=0;i<10;i++){
        sleep(1);
        cout<<"Task A: "<<i<<endl;
        cout.flush();
    }
}

void TaskB(){
    for(int i=0;i<10;i++){
        sleep(1);
        cout<<"Task B: "<<i<<endl;
        cout.flush();
    }
}

int main(){
    thread t1(TaskA);
    thread t2(TaskB);
    t1.join();
    t2.join();
    return 0;
}