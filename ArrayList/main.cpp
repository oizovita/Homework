#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define FIXED_SIZE 5
using namespace std;

class ArrayList {
private:
    int* array;
    int count;
    int allocSize;
public:
    ArrayList(){
        array = new int[FIXED_SIZE];
        count = 0;
        allocSize = FIXED_SIZE;
    }

    void add(int number) {
        if(count < allocSize) {
            array[count] = number;
            count++;
        } else {
            int* newArray = new int[allocSize * 2];
            allocSize = allocSize * 2;

            for(int i = 0; i < count; i++) {
                newArray[i] = array[i];
            }

            delete array;
            array = newArray;
            array[count] = number;
            count++;
        }
    }

    void set(int index, int number) {
        if(count < allocSize) {
            count++;
            for(int i = count - 1; i != index - 1; i--) {
                array[i] = array[i - 1];
            }
            array[index] = number;
        }
    }

    void remove(int index) {
        if (index < count) {
            while (index < count) {
                array[index] = array[index + 1];
                index++;
            }
            count--;
        }
    }

    void trimToSize() {
        int* newArray = new int[count];

        for(int i = 0; i < count; i++) {
            newArray[i] = array[i];
        }

        delete array;
        array = newArray;

        for(int i = 0; i < count; i++) {
            cout << newArray[i]<<endl;

        }
        cout << endl;
    }

    void show() {
        for(int i = 0; i < allocSize; i++) {
            cout << array[i]<<endl;

        }
        cout << endl;
    }
};

int main() {
    ArrayList* dynamicalArray = new ArrayList();

    dynamicalArray->add(4);
    dynamicalArray->add(5);
    dynamicalArray->add(7);
    dynamicalArray->add(12);
    dynamicalArray->add(3);
    dynamicalArray->add(9);
    dynamicalArray->add(78);
    dynamicalArray->add(10);
    dynamicalArray->add(15);
    dynamicalArray->show();
    dynamicalArray->set(2,6);
    dynamicalArray->show();
    dynamicalArray->remove(6);
    dynamicalArray->show();
    dynamicalArray->trimToSize();
    delete dynamicalArray;
}
