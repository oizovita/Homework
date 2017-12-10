#include <iostream>
#include<string.h>

using namespace std;
const int SIZE_OF_ARRAY = 20;
const int SIZE = 501;

class Map{
public:

    int array[SIZE_OF_ARRAY];

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

