#include <string.h>
#include <stdio.h>
#include <memory>
#include <thread>
#include <iostream>

using namespace std;

typedef int Resourse;

shared_ptr<Resourse> g_resourse;

void thread_a() {
    g_resourse = make_shared<Resourse>(1);

    this_thread::sleep_for(chrono::seconds(3));

    g_resourse = nullptr;
    cout << "free resourse, thread A exit." << endl;
}

void thread_b() {
    this_thread::sleep_for(chrono::milliseconds(100));

    weak_ptr<Resourse> pw(g_resourse);

    int i = 0;
    while(1){
        i++;

        auto res(pw.lock());

        if(res){
            cout << i << ":success read resourse from thread B." << endl;
            this_thread::sleep_for(chrono::seconds(1));
        }
        else {
            cout << "Fail read resourse from thread B, exit." << endl;
            return ;
        }
    }
}

int main(){
    std::thread t_a(thread_a);

    std::thread t_b(thread_b);

    t_a.join();
    t_b.join();
    return 0;
}
