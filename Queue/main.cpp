#include <iostream>

using namespace std;
const int SIZE_OF_ARRAY = 20;

class Queue{
public:
    int q[SIZE_OF_ARRAY];
    int* first;
    int* last;

    Queue(){
        first = q;
        last = q;
    }
    void add(int value){
        *last = value;
        last++;
    }
    int get(){
        int data = *first;
        first++;
        return data;
    }


    bool test(){
        bool end;
        if (first == last){
            end = true;
        }else{
            end = false;
        }
        return end;
    }
};

int main() {

    Queue queue;

    cout<<"The queue is over? = "<<queue.test()<<endl;

    queue.add(1);
    queue.add(2);
    queue.add(3);
    queue.add(4);
    queue.add(5);

    cout<<queue.get()<<endl;
    cout<<queue.get()<<endl;
    cout<<queue.get()<<endl;
    cout<<queue.get()<<endl;
    cout<<"The queue is over? =  "<<queue.test()<<endl;

}
