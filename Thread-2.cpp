// race condition
#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

int c=0;
mutex foo,bar;
void Task();
int main(){
    thread t1(Task);
    thread t2(Task);
    t1.join();
    t2.join();
    cout<<c<<endl;
    return 0;
}
void Task(){
    for(int i=0;i<100;i++){
        c+=1;
    }
}