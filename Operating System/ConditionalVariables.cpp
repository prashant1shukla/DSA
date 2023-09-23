#include <iostream>
#include <condition_variable>
#include <mutex>
#include <thread>
using namespace std;


// mutex mutex_;
// condition_variable condVar;

// unique_lock<mutex> lck(mutex_);
// condVar.wait(lck);

// condVar.notify_one();


// int main(){
// thread t1(waitingForWork);  //fun1
//   thread t2(setDataReady);  //fun2

//   t1.join();
//   t2.join();


mutex mutex_;
condition_variable condVar;

void doTheWork(){
  cout << "Processing shared data." << endl;
}
void waitingForWork(){
    cout << "Worker: Waiting for work." << endl;
    unique_lock<mutex> lck(mutex_);
    condVar.wait(lck);
    doTheWork();
    cout << "Work done." << endl;
}
void setDataReady(){
    cout << "Sender: Data is ready."  << endl;
    condVar.notify_one();
}
int main(){

  cout << endl;

  thread t1(waitingForWork);
  thread t2(setDataReady);

  t1.join();
  t2.join();

  cout << endl;
  
}

