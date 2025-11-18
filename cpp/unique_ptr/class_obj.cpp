#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Backpack {
    private:
        int capacity;
        int currentItems = 0;
    public:
        Backpack(int capacity){
            this->capacity = capacity;
        }
        void add(int newItems){
            int leftSlots = this->capacity - this->currentItems;
            if (leftSlots > newItems){
                cout << "added " << newItems << endl; 
                this->currentItems = this->currentItems + newItems;
            }else {
                cout << "maximun exceed, added " << leftSlots << endl;
                this->currentItems = this->capacity;
            }
        }
        void show(){
            cout << "Current number of items " << this-> currentItems << endl;
        }
};
class PigBackPack : public Backpack {
    public:
        PigBackPack(int capacity) : Backpack(capacity){}
};

// unique_ptr <PigBackPack> fillBackPack(unique_ptr<PigBackPack> backPackToFill, int items);
void fillBackPack(PigBackPack &bp, int items);
int main(){
    vector <unique_ptr<PigBackPack>> ourPacks;
    ourPacks.push_back(make_unique<PigBackPack>(5));
    ourPacks.push_back(make_unique<PigBackPack>(25));
    ourPacks.push_back(make_unique<PigBackPack>(15));
    for(int i = 0; i < ourPacks.size(); i++){
        fillBackPack(*ourPacks[i], i*5 + 1);
    }
    ourPacks[0]->show();
    ourPacks[1]->show();
    ourPacks[2]->show();
    return 0;
}

// unique_ptr <PigBackPack> fillBackPack(unique_ptr<PigBackPack> backPackToFill, int items){
//     unique_ptr <PigBackPack> output = move(backPackToFill);
//     output->add(items);
//     return output;
// }
void fillBackPack(PigBackPack &bp, int items){
    bp.add(items);
}