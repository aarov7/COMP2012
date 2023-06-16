#include<iostream>
#include<queue>

#include "btree.h"

int main(){
    BTnode<int>* node5 = new BTnode<int>(5);
    BTnode<int>* node9 = new BTnode<int>(9);
    BTnode<int>* node8 = new BTnode<int>(8, node5, node9);
    // Create the right subtree
    BTnode<int>* node12 = new BTnode<int>(12);
    BTnode<int>* node17 = new BTnode<int>(17);
    BTnode<int>* node15 = new BTnode<int>(15, node12, node17);
    // Create the root node
    BTnode<int>* root = new BTnode<int>(10, node8, node15);

    std::queue<int> q;
    q.push(root->get_data());
    while(!q.empty()){
        

    }

    delete root;
}