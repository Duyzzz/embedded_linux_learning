#include <iostream>
#include <memory>


using namespace std;
void test(void);


int main(){
    test();
    return 0;
}

void test(){
    unique_ptr<int> hi = make_unique<int>(10);
    cout << *hi << endl;
}