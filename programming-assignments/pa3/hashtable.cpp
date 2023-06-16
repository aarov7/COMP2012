#include "hashtable.h"

BoardOptimalMove BoardHashTable::getHashedMove(const unsigned long long id, const int depth){
    unsigned long long pos=id%TABLE_SIZE;
    if(!table[pos])
        return BoardOptimalMove();
    //loop through the linked list and compare both id and depth
    BoardHashNode* curr=table[pos];
    while(curr){
        if(curr->id==id&&curr->depth>=depth){
            return curr->optimalMove;
        }
        curr=curr->next;
    }
    return BoardOptimalMove();
}

void BoardHashTable::updateTable(const unsigned long long id, const int depth, const BoardOptimalMove& optimalMove){
    unsigned long long pos=id%TABLE_SIZE;
    if(!table[pos]){
        table[pos]=new BoardHashNode(id, depth, optimalMove);
        return;
    }
    //if there is a linked list at position pos, search the linked list for the board id
    BoardHashNode* curr=table[pos];
    while(curr->next){
        if(curr->id==id&&curr->depth<depth){
            curr->depth=depth;
            curr->optimalMove=optimalMove;
            return;
        }
        curr=curr->next;
    }
    //curr is now at the last element, so can insert at the end
    if(curr->id==id&&curr->depth<depth){
        curr->depth=depth;
        curr->optimalMove=optimalMove;
        return;
    }
    curr->next=new BoardHashNode(id, depth, optimalMove);
}

void BoardHashTable::clearTable(){
    for(int i=0;i<TABLE_SIZE;i++){
        if(!table[i])
            continue;
        else{
            BoardHashNode* curr=table[i];
            while(curr){
                BoardHashNode* next=curr->next;
                delete curr;
                curr=next;
            }
            table[i]=nullptr;
        }
    }
}