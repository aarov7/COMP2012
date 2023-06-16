#include "swiss.h"
#include "match.h"

namespace util{
    struct pair{
        int first,second;
    };
    int firstOccurrence(const int score, const PlayerList& list){
        int low=0,high=list.getNumPlayers()-1,res=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(list.getPlayer(mid)->getScore()>score){
                low=mid+1;
            }
            else if(list.getPlayer(mid)->getScore()<score){
                high=mid-1;
            }
            else{
                res=mid;
                high=mid-1;
            }
        }
        return res;
    }
    int lastOccurrence(const int score, const PlayerList& list){
        int low=0,high=list.getNumPlayers()-1,res=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(list.getPlayer(mid)->getScore()>score){
                low=mid+1;
            }
            else if(list.getPlayer(mid)->getScore()<score){
                high=mid-1;
            }
            else{
                res=mid;
                low=mid+1;
            }
        }
        return res;
    }
}

Swiss::Swiss(const int numRounds , const PlayerList& list) 
    : numRounds(numRounds), list(list), curRound(0) {
    this->list.sort();
}
Swiss::~Swiss(){
}
void Swiss::play(){
    for(curRound=1;curRound<=numRounds;curRound++){
        PlayerList** playerListArr = new PlayerList*[2*curRound-1]; 
        // std::cout<<"DEBUGGING"<<std::endl;
        // for(int i=0;i<2*curRound-1;i++){
        //     std::cout<<playerListArr[i]->getNumPlayers()<<std::endl;
        // }
        for(int i=0;i<2*curRound-1;i++){
            util::pair positions={-1,-1};
            positions.first=util::firstOccurrence(i,this->list);
            positions.second=util::lastOccurrence(i,this->list);
            //Q:what if there are no players with the score of i; A: In that case, splice will return a playerlist with numplayers=0 and players=nullptr
            playerListArr[i]=list.splice(positions.first,positions.second+1);//memory is allocated here
        }
        for(int i=2*curRound-2;i>=0;i--){ //2*curRound-2 because the number of elements in playerListArr is 2*curRound-1
            PlayerList* currPlayerList=playerListArr[i];
            if(!currPlayerList->getNumPlayers())
                continue;
            currPlayerList->sort();
            int midIdx=currPlayerList->getNumPlayers()/2;
            for(int j=0;j<midIdx;j++){
                Match curr_match {currPlayerList->getPlayer(j), currPlayerList->getPlayer(j+midIdx)};
                curr_match.play();
            }
            if(currPlayerList->getNumPlayers()%2){ //if theres an odd number of players
                if(i==0){
                    currPlayerList->getPlayer(currPlayerList->getNumPlayers()-1)->addScore(2);
                }
                else{
                    //not sure if i have to remove the last player from currPlayerList 
                    playerListArr[i-1]->addPlayer(currPlayerList->getPlayer(currPlayerList->getNumPlayers()-1));
                }
            }
        }
        this->list.sort();
        printLeaderboard();
        for(int i=0;i<2*curRound-1;i++){
            delete playerListArr[i];
            playerListArr[i]=nullptr;
        }
        delete[] playerListArr;
        playerListArr=nullptr;
    }
}   


