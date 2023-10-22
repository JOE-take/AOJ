#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;

struct list{
    list* forward;
    list* back;
    int key;
};

list* current;
list* first_element;

void initializelist(){
    list *firstlist = new list;
    firstlist->back = nullptr;
    firstlist->forward = nullptr;
    firstlist->key = 0;
    current = firstlist;
    first_element = firstlist;
}


void mknewlist(int key){
    list *new_list = new list;

    current->forward = new_list;
    new_list->forward = nullptr;
    new_list->back = current;
    new_list->key = key;
    current = new_list;
}


void deletelist(int key){
    list* itr = current;
    while(itr->back != nullptr){
        if(itr->key == key){
        if(itr == current){
            itr->back->forward = nullptr;
            current = itr->back;
        } else {
            itr->forward->back = itr->back;
            itr->back->forward = itr->forward;
        }
        break;
        }
        itr = itr->back;
    }
}

void deleteLast(){
    
    list* First = first_element->forward;
    if(First->forward == nullptr){
        first_element->forward = nullptr;
        current = first_element;
    } else {
        first_element->forward = First->forward;
        First->forward->back = first_element;
        }
}


void deleteFirst(){
    current->back->forward = nullptr;
    current = current->back;
}

int main(){
    int n;
    cin >> n;
    initializelist(); 

    for(int i = 0; i < n; i++){
        int key;
        char command[12];
        scanf("%s",&command);
        if( strcmp(command,"insert") == 0){
            scanf("%d", &key);
            mknewlist(key);
        }
        else if( strcmp(command,"delete") == 0){
            scanf("%d", &key);
            deletelist(key);
        }
        else if( strcmp(command,"deleteFirst") == 0){
            deleteFirst();
        }
        else if( strcmp(command,"deleteLast") == 0){
            deleteLast();
        }

    }
    list* itr = current;
    while(itr->back != nullptr){
        cout << itr->key;
        itr = itr->back;
        if(itr != first_element)
            cout << " ";
    }
    cout << "\n";
    return 0;
}