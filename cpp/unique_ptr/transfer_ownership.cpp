#include <iostream>
#include <memory>

using namespace std;

unique_ptr<int> create(int intializeNumber);
void consume(unique_ptr<int> ptr);
void tryCopy(void);

int main(){
    unique_ptr<int> hi = create(102);
    consume(move(hi));
    return 0;
}

unique_ptr<int> create(int intializeNumber){
    unique_ptr<int> newPtr = make_unique<int>(intializeNumber);
    return newPtr;
}
void consume(unique_ptr<int> ptr){
    cout << *ptr << endl;
}

void tryCopy(){
    auto a = make_unique<int>(102);
    auto b = move(a);
}