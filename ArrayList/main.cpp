#include "stdio.h"
#include "iostream"
#define FIXED_SIZE 5
using namespace std;

class ArrayList {
private:
    int count = 0;
    int *array;

public:
    ArrayList(){
        array = new int[FIXED_SIZE];
    }

    int get(int index) {
        if (index < count) {
            return array[index];
        }
    }

    void add(int obj) {
        if (sizeof(array) - count <= sizeof(array) / 2) {
            reSizeArray(obj);
        }

        array[count++] = obj;
    }

    void set(int element, int index){
        array[index]=element;
    }

    int remove(int index) {
        if (index < count) {
            int obj = array[index];
            int temp = index;
            array[index] = NULL;

            while (temp < count) {
                array[temp] = array[temp + 1];
                array[temp + 1] =NULL;
                temp++;
            }

            count--;
            return obj;
        }
    }

    int trimToSize(int index) {
        int *newArray= new int[index];
        for(int i=0; i<index; i++){
            newArray[i]= array[i];
        }

        array = newArray;
        return index;
    }

    void reSizeArray(int obj) {
        int *newArray= new int[count*2];
        for(int i=0; i<count; i++){
            newArray[i]= array[i];
        }

        newArray[count]= obj;
        array=newArray;
    }

    int size() {
        return count;
    }
};
int main() {
    ArrayList *dynamicalArray = new ArrayList();

    dynamicalArray->add(2);
    dynamicalArray->add(4);
    dynamicalArray->add(7);
    dynamicalArray->add(9);
    dynamicalArray->add(7);
    dynamicalArray->add(8);
    dynamicalArray->add(3);
    dynamicalArray->add(6);

    for (int i = 0; i < dynamicalArray->size(); i++) {
        cout<< dynamicalArray->get(i)<<endl;
    }
    cout<<"-----------------------------------------------------"<<endl;
    dynamicalArray->set(45,4);
    dynamicalArray->remove(3);

    for (int i = 0; i < dynamicalArray->size(); i++) {
        cout<<dynamicalArray->get(i)<<endl;
    }
    cout<<"-----------------------------------------------------"<<endl;
    dynamicalArray->trimToSize(3);
    for (int i = 0; i < dynamicalArray->trimToSize(3); i++) {
        cout<<dynamicalArray->get(i)<<endl;
    }
    delete dynamicalArray;
}






