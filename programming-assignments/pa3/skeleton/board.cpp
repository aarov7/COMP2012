#include "board.h"
//helper functions and variables:

// //returns X if X has a match, O if O has a match and EMPTY if there is no match on the board
// Cell checkMatch(const Cell(&cells)[BOARD_SIZE][BOARD_SIZE]){ //passing by reference to array
//     //can assume that there will never be a state where both players have a match
//     //use lastPlayedMove to efficiently find matches
//     if(lastPlayedMove.val==Cell::EMPTY){
//         //Board::getBoardScore() should return 0 if no move has been played 
//         return Cell::EMPTY;
//     }
//     int x=lastPlayedMove.coords.row, y=lastPlayedMove.coords.col;
//     //check columns
//     int col=0, row=0, diag=0, rdiag=0;
//     for(int i=0;i<BOARD_SIZE;i++){
//         if(cells[x][i]==lastPlayedMove.val) col++;
//         if(cells[i][y]==lastPlayedMove.val) row++;
//         if(cells[i][i]==lastPlayedMove.val) diag++;
//         if(cells[i][BOARD_SIZE-1-i]==lastPlayedMove.val) rdiag++;
//     }
//     if(col==BOARD_SIZE||row==BOARD_SIZE||diag==BOARD_SIZE||rdiag==BOARD_SIZE)
//         return lastPlayedMove.val;
//     return Cell::EMPTY;
// }


//class Board member functions:

Board::Board(const int score[][BOARD_SIZE])
    :curPlayer(Cell::X), id(0) {
    for(int i=0;i<BOARD_SIZE;i++){
        for(int j=0;j<BOARD_SIZE;j++){
            cells[i][j]=Cell::EMPTY;
            this->score[i][j]=score[i][j];
        }
    }
}

bool Board::isFull() const{
    for(int i=0;i<BOARD_SIZE;i++){
        for(int j=0;j<BOARD_SIZE;j++){
            if(cells[i][j]==Cell::EMPTY)
                return false;
        }
    }
    return true;
}

bool Board::isFinished() const{
    int score=getBoardScore();
    return score==WIN_SCORE||score==-WIN_SCORE||isFull();
}

int Board::getBoardScore() const{
    for(int i=0;i<BOARD_SIZE;i++){
        int row=0;
        for(int j=0;j<BOARD_SIZE;j++){
            row+=static_cast<int>(cells[i][j]);
        }
        if(row==BOARD_SIZE)
            return WIN_SCORE;
        else if(row==-BOARD_SIZE)
            return -WIN_SCORE;
    }
    for(int i=0;i<BOARD_SIZE;i++){
        int col=0;
        for(int j=0;j<BOARD_SIZE;j++){
            col+=static_cast<int>(cells[j][i]);
        }
        if(col==BOARD_SIZE)
            return WIN_SCORE;
        else if(col==-BOARD_SIZE)
            return -WIN_SCORE;
    }
    int diag=0;
    for(int i=0;i<BOARD_SIZE;i++){
        diag+=static_cast<int>(cells[i][i]);
        if(diag==BOARD_SIZE)
            return WIN_SCORE;
        else if(diag==-BOARD_SIZE)
            return -WIN_SCORE;
    }
    int rdiag=0;
    for(int i=0;i<BOARD_SIZE;i++){
        rdiag+=static_cast<int>(cells[i][BOARD_SIZE-i-1]);
        if(rdiag==BOARD_SIZE)
            return WIN_SCORE;
        else if(rdiag==-BOARD_SIZE)
            return -WIN_SCORE;
    }
    int xScore=0, oScore=0;
    for(int i=0;i<BOARD_SIZE;i++){
        for(int j=0;j<BOARD_SIZE;j++){
            if(cells[i][j]==Cell::X)
                xScore+=score[i][j];
            else if(cells[i][j]==Cell::O)
                oScore+=score[i][j];
        }
    }
    // std::cout << "no match" << std::endl;
    return xScore*getCellWeight(Cell::X)-oScore*getCellWeight(Cell::O);
}

bool Board::play(const BoardCoordinate& coords){
    if(!coords.isValid())
        return false;
    if(cells[coords.row][coords.col]!=Cell::EMPTY)
        return false;
    cells[coords.row][coords.col]=curPlayer;
    curPlayer=static_cast<Cell>(static_cast<int>(curPlayer)*(-1));
    //update id

    // id=0;
    // for(int i=0;i<BOARD_SIZE;i++){
    //     for(int j=0;j<BOARD_SIZE;j++){
    //         int cellValue=(static_cast<int>(cells[i][j]+3)%3);
    //         id+=cellValue*(pow(3,(i*3+j)));
    //     }
    // }

    int cellValue=((static_cast<int>(cells[coords.row][coords.col])+3)%3);
    id+=cellValue*pow(3,(coords.row*BOARD_SIZE+coords.col));
    return true;
}