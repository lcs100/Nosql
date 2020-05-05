#include <string.h>
#include <stdio.h>
#include <memory>
#include <functional>
#include <iostream>

using namespace std;

int main(){
    int r = 0;

    auto updateLambda = [](int* res) { (*res)++; };

    std::function<void ()> callback = std::bind(updateLambda, &r);

    callback();

    cout << "From main: r = " << r << endl;

    return 0;
}