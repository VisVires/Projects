#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

struct node{
    int val;
    node *next;
};

node* initList();
void addNode(node*, int val);
node deleteLink();
void outputList(node* head);
node searchLink();
int getSize(node*);



int main(){

    node* head = initList();
    addNode(head, 5);
    addNode(head, 6);
    addNode(head, 7);
    outputList(head);
    cout << "The list is " << getSize(head) << " nodes long." << endl;
    return 0;
}

node* initList(){
    node* head = new node;
    head->next = NULL;
    return head;
}

void addNode(node* head, int num){
    //move to end of list
    node* iter = head;
    if (iter->next == NULL){
        iter->val = num;
    }
    node* newLink = new node;
    while (iter->next != NULL){
        iter = iter->next;
    }
    iter->next = newLink;
    newLink->val = num;
    newLink->next = NULL;
}

void outputList(node* head){
    node* iter = head;
    while (iter->next != NULL){
        iter = iter->next;
        if (iter->next == NULL)
            cout << iter->val << endl;
        else
            cout << iter->val << "->";
    }
}

int getSize(node *head)
{
    int sum = 0;
    node* iter = head;
    while (iter->next != NULL){
        iter = iter->next;
        sum++;
    }
    return sum;
}
