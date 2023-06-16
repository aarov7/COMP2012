#include <cstring>

#include "player.h"

Player::Player(const char* const name, const int elo) 
    : elo(elo), score(0){
    this->name=new char[strlen(name)+1];
    strcpy(this->name,name);
}
Player::~Player(){
    delete[] this->name;
}

PlayerList::PlayerList()
    : numPlayers(0), players(nullptr){
}
PlayerList::PlayerList(const PlayerList& list) 
    : numPlayers(list.numPlayers){
    players=new Player*[numPlayers];
    for(int i=0;i<numPlayers;i++){
        players[i]=list.players[i];
    }
}
PlayerList::~PlayerList(){
    delete[] players;
    players=nullptr;
}
void PlayerList::addPlayer(Player* const player){
    //insert at the end
    Player** newPlayers=new Player*[++numPlayers];
    for(int i=0;i<numPlayers-1;i++){
        newPlayers[i]=players[i];
    }
    newPlayers[numPlayers-1]=player;
    delete[] players;
    players=newPlayers;
}//seems fine
void PlayerList::sort(){
    //sort based on scores, if scores are same sort based on elo
    for(int i=0;i<numPlayers-1;i++){
        for(int j=0;j<numPlayers-1-i;j++){
            if(players[j]->getScore()<players[j+1]->getScore()){
                Player* temp=players[j];
                players[j]=players[j+1];
                players[j+1]=temp;
            }
            else if(players[j]->getScore()==players[j+1]->getScore()){
                if(players[j]->getELO()<players[j+1]->getELO()){
                    Player* temp=players[j];
                    players[j]=players[j+1];
                    players[j+1]=temp;
                }
            }
        }
    }
}
PlayerList* PlayerList::splice(const int startIndex, const int endIndex) const{
    PlayerList* newPlayerList=new PlayerList();
    if(startIndex<0||endIndex>numPlayers||startIndex>=endIndex)
        return newPlayerList;
    newPlayerList->numPlayers=endIndex-startIndex;
    newPlayerList->players=new Player*[newPlayerList->numPlayers];
    for(int i=0;i<newPlayerList->numPlayers;i++){
        newPlayerList->players[i]=this->players[i+startIndex];
    }
    return newPlayerList;
}