#include <string.h>
#include <stdio.h>
#include <memory>
#include <iostream>

using namespace std;

class Student {
    public:
        Student(){
            cout << "Construct student" << endl;
        }

        ~Student(){
            cout << "Destruct student" << endl;
        }

        bool Register(){
            return true;
        }

        bool Enroll(){
            return true;
        }
};

int main(){
    unique_ptr<Student> p(new Student());

    if(!p->Register())
        return -1;
    
    if(!p->Enroll())
        return -2;

    return 0;
}