#include <array>
#include <vector>
#include <string>
#include "piece.hpp"
#include "fen.hpp"
#include "definitions.hpp"

using namespace std;



class Board
{

    public:
    Board()
    {

    }
    void movePiece(coord startPos, coord endPos){
    //first check if movement is within movement pattern 
    //second, check if there are any pieces inbetween the startingPos and the endingPos 
    //lastly, make array(endPos) point to the Piece and array(startPos)
    //make array(startPos point to NULL 
    }
    void setBoard(Fen input){
    //for x = 0...7: for y = 0...7 -> x
    vector<string> boardTemplate = input.extractBoardTemplate();
        for (int x = 0; x < BOARD_WIDTH; x++){
            for (int y = 0; y < BOARD_LENGTH; y++){
                switch(boardTemplate.at(x).at(y))
                    case 'K':

                    case 'k': 
                    
                    case 'Q': 

                    case 'q': 

                    case 'R': 
                    
                    case 'r': 

                    case 'B': 
                    
                    case 'b': 

                    case 'N': 
                    
                    case 'n': 

                    case 'P': 
                    
                    case 'p': 
                
                
                
                //boardMap.at(x).at(y)

            }
        }
    }



/**
    string* SplitStringtoList2()
    {

    }
**/
    private:
    array<array<Piece, 8>, 8> boardMap;
    
};