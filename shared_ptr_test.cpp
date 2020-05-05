#include <string.h>
#include <stdio.h>
#include <memory>
#include <thread>
#include <iostream>

using namespace std;

typedef int Resourse;

shared_ptr<Resourse> CreateResourse() {
    return make_shared<Resourse>(1);
}

void User1(shared_ptr<Resourse> p) {
    if(p)
        cout << "use p in user1 thread." << endl;

    return ;
}

void User2(shared_ptr<Resourse> p) {
    this_thread::sleep_for(chrono::milliseconds(10));

    if(p)
        cout << "use p in user2 thread." << endl;

    return ;
}

int main(){
    shared_ptr<Resourse> res = CreateResourse();

    thread t1(User1, res);
    thread t2(User2, res);

    t1.join();
    t2.join();
    return 0;
}