#include <iostream>

using namespace std ;

class Zoo{
private:
    int age;
    int health;
    int numberOfPaws;
    string name;
    string kind;
    string location;
    bool isShow;
    int count;
public:
    Zoo (){

        name = "";
        kind = "" ;
        location = "";
        age = 0;
        numberOfPaws = 0;
        health = 0;
        isShow = false;

    }
    void set (){

        cout << "Name:";
        cin >> name;
        cout << "Kind:";
        cin >> kind;
        cout << "Age:";
        cin >> age;
        cout << "Number of paws:";
        cin >> numberOfPaws;
        cout <<"Health:";
        cin >> health;
        cout << "Choose where to put the animal: cage or exhibition "<<endl;
        cin >> location;
        if (location == "cage"){
            isShow = true;
        }
        else{
            isShow = false;
        }

    }

    void show(){

        if(isShow == true){
            cout << "Animal in a cage"<<endl;
        }
        else{
            cout << "Animal at the show"<<endl;
        }
    }

    void get (int j){

        cout<<"|------------------------------|"<<endl;
        cout <<j<<"Name:";
        cout << name <<endl;
        cout << "Kind:";
        cout << kind <<endl;
        cout << "Age:";
        cout << age << endl;
        cout << "Number of paws:";
        cout << numberOfPaws <<endl;
        cout <<"Health:";
        cout << health <<endl;
        show();
        cout<<"|------------------------------|"<<endl;

    }

    string getName(){

        cout << "Name:";
        cout << name <<endl;
        return name;
    }



};
class Administration{
   private:
    int select ;
    int i = 0;
    int j;
    Zoo animal [20];

public:

    void remove(int index){

        if (index <= i) {
            while (index < i) {
                animal[index] = animal[index + 1];
                index++;
            }
            i--;
        }

    }

void operationWithTheZoo(){

    do
{
    cout <<"1:Add animal"<<endl<<"2:View all animal"<<endl<<"3:See all information about animals"<<endl<<"4:Edit information"<<endl<<"5:Delete animal"<<endl<<"6:Exit"<<endl ;
    do
    {
        cout << "Your choose:   " ;
        cin >> select ;
        if (select < 1 || select > 6)
            cout << "Wrong choose...Try again \n" << endl ;
    }   while (select < 1 || select > 6 );
    switch (select)
    {
    case 1:
        i++ ;
        animal[i].set() ;
        break;
    case 2:
        for (int j = 1; j <= i; j++ ){
            animal[j].getName() ;
        }
        break;

    case 3:
        for (int j = 1; j <= i; j++ ){
            animal[j].get(j) ;
        }
        break;

    case 4:
        cout<<"Which animal do you want to change?"<<endl;
        cin >> j;
        animal[j].set();
        break;

    case 5:
        cout<<"Which animal do you want to remove?"<<endl;
        cin >> j;
        remove(j);
        break;
    }
}while (select != 6 );
}
};

int main (){

    Administration manager ;
    manager.operationWithTheZoo();
    return 0;
}




    









