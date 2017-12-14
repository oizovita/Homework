#include <iostream>
#include<string.h>

using namespace std;

const int SIZE = 501;
const int SIZE_ARRAY =100000000;

class Map{
public:
    int *array;

    Map(){
        array = new int[SIZE_ARRAY];
    }


    int hash (char* str){
        int seed = 131;
        unsigned long hash = 0;

        for(int i = 0; i < strlen(str); i++){
            hash = (hash * seed) + str[i];
        }
        return hash % SIZE;
    }

    void add(char* str, int value){
        array[hash(str)] = value;
    }

    int get(char* str){
        return array[hash(str)];
    }

    ~Map(){
        delete []array;
    }
};

int main()
{
    Map map;

    map.add("I", 27);
    map.add("am", 9);
    map.add("Batman", 1939);

    cout<<map.get("Batman")<<endl;
    cout<<map.get("I")<<endl;
}

