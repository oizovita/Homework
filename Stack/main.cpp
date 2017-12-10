#include <iostream>

using namespace std;
const int SIZE_OF_ARRAY = 20;

class Stack{
public:
    int stack[SIZE_OF_ARRAY];
    int* top;
    int counter;

    Stack(){
        top = stack;
        counter = 0;
    }

    void add(int value){
        *top = value;
        top++;
        counter++;
    }

    int get(){

        if (*top == 0){
            top--;
        }
        int value = *top;
        top--;
        counter--;
        return value;
    }

    bool test(){
        bool end;
        if (counter == 0){
            end= true;
        }else{
            end = false;
        }
        return end;
    }

};

int main(){
    Stack stack;

    cout<<"Is stack null? "<<stack.test()<<endl;

    stack.add(1);
    stack.add(2);
    stack.add(3);
    stack.add(4);
    stack.add(5);
    stack.add(6);
    stack.add(7);

    cout<<stack.get()<<endl;
    cout<<stack.get()<<endl;
    cout<<stack.get()<<endl;
    cout<<stack.get()<<endl;
    cout<<stack.get()<<endl;
    cout<<stack.get()<<endl;
    cout<<stack.get()<<endl;

}
