#include "boardtree.h"

BoardTree::BoardTree(const Board& board)
    : root(new BoardNode(board)){
    //all of root->subTree[i][j] have been initilaized to empty boardTrees by the default constructor, i.e root->subTree[i][j].root==nullptr
}

BoardTree::~BoardTree(){
    delete root; //recursive
}

// BoardTree* BoardTree::getSubTree(const BoardCoordinate& coords) {
//     // Check if coordinates are within the bounds of the board
//     if (coords.row < 0 || coords.row >= BOARD_SIZE || coords.col < 0 || coords.col >= BOARD_SIZE) {
//         return nullptr;
//     }

//     // Allocate a new BoardNode object and assign it to the subtree if it does not already exist
//     if (root->subTree[coords.row][coords.col].root == nullptr) {
//         Board newBoard = root->board;
//         if (newBoard.play(coords)) {
//             root->subTree[coords.row][coords.col].root = new BoardNode(newBoard);
//         }
//     }

//     // Return a pointer to the subtree rooted at the specified coordinates
//     return &(root->subTree[coords.row][coords.col]);
// }

BoardTree* BoardTree::getSubTree(const BoardCoordinate& coords){
    if(root==nullptr)
        return nullptr; 
    if(root->subTree[coords.row][coords.col].root==nullptr){
        Board newBoard=root->board;
        if(newBoard.play(coords)){
            root->subTree[coords.row][coords.col].root=new BoardNode(newBoard);
        }
    }
    return &(root->subTree[coords.row][coords.col]);
}



BoardOptimalMove BoardTree::getOptimalMove(const unsigned int depth){
    // if(this==nullptr){
    //     std::cout<<"THIS IS NULLPTR"<<std::endl;
    // }
    if(root==nullptr){
        //std::cout<<"root is empty"<<std::endl;
        return BoardOptimalMove();
    }
    if(depth==0||root->board.isFinished()){
        // If depth is 0 or if the game has already finished, we cannot search further
        // return the score of this board with any move coordinate since we will not use it
        return BoardOptimalMove(root->board.getBoardScore(), BoardCoordinate{0,0});
    }

    //TASK 3:
    BoardOptimalMove optMove=BoardHashTable::getInstance().getHashedMove(root->board.getID(), depth);
    if(optMove.score!=ILLEGAL){
        return optMove;
    }

    //std::cout<<"depth: "<<depth<<std::endl;
    int estimatedScore=(root->board.getCurPlayer()==Cell::X)?-1000000:1000000;
    BoardOptimalMove bestMove;

    for(int i=0;i<BOARD_SIZE;++i){
        for(int j=0;j<BOARD_SIZE;++j){
            if(root->subTree[i][j].root==nullptr){
                Board newBoard=root->board;
                if(newBoard.play(BoardCoordinate{i,j})){
                    root->subTree[i][j].root=new BoardNode(newBoard);
                }
            }
            BoardOptimalMove childMove=root->subTree[i][j].getOptimalMove(depth-1);
            
            if(childMove.score==ILLEGAL)
                continue;
            //maximize socre for x, minimize score for o
            //std::cout<<"childmove score: "<<childMove.score<<std::endl;
            if((root->board.getCurPlayer()==Cell::X&&childMove.score>estimatedScore)||(root->board.getCurPlayer()==Cell::O&&childMove.score<estimatedScore)){
                estimatedScore=childMove.score;
                bestMove=BoardOptimalMove(estimatedScore,BoardCoordinate{i,j});
            }
        }
    }
    //TASK 3:
    BoardHashTable::getInstance().updateTable(root->board.getID(), depth, bestMove);
    return bestMove;
}

BoardOptimalMove BoardTree::getOptimalMoveAlphaBeta(const unsigned int depth, int alpha, int beta){
    // if(this==nullptr){
    //     std::cout<<"THIS IS NULLPTR"<<std::endl;
    // }
    if(root==nullptr){
        //std::cout<<"root is empty"<<std::endl;
        return BoardOptimalMove();
    }
    if(depth==0||root->board.isFinished()){
        // If depth is 0 or if the game has already finished, we cannot search further
        // return the score of this board with any move coordinate since we will not use it
        return BoardOptimalMove(root->board.getBoardScore(), BoardCoordinate{0,0});
    }

    //std::cout<<"depth: "<<depth<<std::endl;
    int estimatedScore=(root->board.getCurPlayer()==Cell::X)?-10e6:10e6; //1 million
    BoardOptimalMove bestMove;
    for(int i=0;i<BOARD_SIZE;++i){
        for(int j=0;j<BOARD_SIZE;++j){
            if(root->subTree[i][j].root==nullptr){
                Board newBoard=root->board;
                if(newBoard.play(BoardCoordinate{i,j})){
                    root->subTree[i][j].root=new BoardNode(newBoard);
                }
            }
            BoardOptimalMove childMove=root->subTree[i][j].getOptimalMoveAlphaBeta(depth-1, alpha, beta);
            
            if(childMove.score==ILLEGAL)
                continue;
            //maximize socre for x, minimize score for o
            //std::cout<<"childmove score: "<<childMove.score<<std::endl;
            if((root->board.getCurPlayer()==Cell::X&&childMove.score>estimatedScore)||(root->board.getCurPlayer()==Cell::O&&childMove.score<estimatedScore)){
                estimatedScore=childMove.score;
                bestMove=BoardOptimalMove(estimatedScore,BoardCoordinate{i,j});
            }
            if(root->board.getCurPlayer()==X){
                if(bestMove.score>beta){
                    //exit both i and j loops here
                    goto ret;
                }
                alpha=std::max(bestMove.score,alpha);
            }
            else{
                if(bestMove.score<alpha){
                    //exit both i and j loops here
                    goto ret;
                }
                beta=std::min(bestMove.score,beta);
            }
        }
    }
    ret: return bestMove;
}
