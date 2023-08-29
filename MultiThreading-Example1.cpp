#include<iostream>
#include<thread>
#include<chrono>
#include<algorithm>

using namespace std;
typedef unsigned long long int uul;

uul oddSum=0;
uul evenSum=0;

void GetEvenSum(uul low,uul high){
    for(uul it=low;it<=high;it++){
        if(it%2==0){
            evenSum+=it;
        }
    }
}

void GetOddSum(uul low,uul high){
    for(uul it=low;it<=high;it++){
        if(it%2==1){
            oddSum+=it;
        }
    }
}

int main(){
    uul low=0,high=10000000007;
    auto start=std::chrono::high_resolution_clock::now();
    // GetOddSum(low,high);
    // GetEvenSum(low,high);
    thread t1(GetEvenSum,low,high);
    thread t2(GetOddSum,low,high);
    t1.join();
    t2.join();
    auto end=std::chrono::high_resolution_clock::now();
    auto duration=std::chrono::duration_cast<std::chrono::microseconds>(end-start);
    cout<<"evenSum"<<" "<<evenSum<<endl;
    cout<<"oddSum"<<" "<<oddSum<<endl;
    cout<<"Sec: "<<duration.count()/1000000<<endl;
    return  0;
}