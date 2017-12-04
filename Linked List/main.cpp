#include <iostream>
using namespace std ;

class Node{
public:

    Node* nextNode;
    int data;

    Node(int data){
        this->data = data;
        nextNode = NULL;
    }
};


class LinkedList {
public:
    Node* newNode = NULL;
    Node* lastNode = NULL;
    Node* nowNode = NULL;
    Node* prevNode = NULL;
    Node* tmpNode = NULL;
    int sizeList;
    int counter;

void add(int data, Node* node = NULL){

        if(node == NULL){
            node = new Node(data);
            newNode = node;
            return;
        }
        if(node->nextNode != NULL){
            add(data, node->nextNode);
            return;
        }
        Node* newNode = new Node(data);
        node->nextNode = newNode;
        sizeList++;
    }

void get(int index, Node* node, int counter = 0) {
        if (index < 0 || index > sizeList){
            return;
        }
        if(index == counter){
            cout<<"Index "<<index<<" = "<< node->data<<endl;
        }
         else{
            counter++;
            get(index,node->nextNode,counter);
        }

}

void addByIndex(int data, int index){

    if (index < 0 || index > sizeList) {
        return;
        }
        if(counter == 0){
            tmpNode = new Node(data);
            tmpNode->data = data;
            nowNode = newNode;
        }
        if(index == 0){
            tmpNode->nextNode = newNode;
            newNode = tmpNode;
            counter = 0;
            return;
        }


        if(counter == index-1){
            tmpNode->nextNode = nowNode->nextNode;
            nowNode->nextNode = tmpNode;
            counter = 0;
            return;
        }

        counter++;
        nowNode = nowNode->nextNode;
        addByIndex(data, index);
        sizeList++;
    }

void remove(int index, int counter=0){

        if (index < 0 || index > sizeList){
            return;
        }
        if (counter == 0){
            nowNode = newNode;
        }
        if (index == 0){
            newNode = newNode->nextNode;
            return;
        }
        if (counter == index-1){
            prevNode = nowNode;
        }
        if (counter == index){
            prevNode->nextNode = nowNode->nextNode;
            delete nowNode;
            return;
        }
        if (nowNode->nextNode == NULL){
            return;
        }
        nowNode = nowNode->nextNode;
        counter++;
        remove(index, counter);
    }

void show(Node* node){
        cout<<node->data<<endl;
        if (node->nextNode != NULL){
            show (node->nextNode);
        }
    }
};

int main() {

    LinkedList list;
    list.add(1,list.newNode);
    list.add(2,list.newNode);
    list.add(3,list.newNode);
    list.add(4,list.newNode);
    list.add(5,list.newNode);
    list.add(6,list.newNode);
    list.add(7,list.newNode);
    list.show(list.newNode);
    cout<<endl;
    list.remove(6);
    list.show(list.newNode);
    cout<<endl;
    list.show(list.newNode);
    list.get(3,list.newNode);
    list.addByIndex(10, 4);
    cout<<endl;
    list.show(list.newNode);
    return 0;
}
