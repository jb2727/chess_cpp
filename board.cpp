#include <array>
#include <vector>
#include <string>
#include "piece.hpp"
#include "fen.hpp"
#include "definitions.hpp"
#include "coord.hpp"

using namespace std;



class Board
{

    public:
    Board()
    {

    }
    void movePiece(BoardCoord startPos, BoardCoord endPos){
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
                
                switch(boardTemplate.at(x).at(y)){
                
                /* White Pieces */    
                    case WHITE_KING_SYMBOL:
                        Piece* newPiece = new King(piece_ns::white);
                        break;
                    case WHITE_QUEEN_SYMBOL: 
                        Piece* newPiece = new Queen(piece_ns::white);
                        break;
                    case WHITE_ROOK_SYMBOL: 
                        Piece* newPiece = new Rook(piece_ns::white);
                        break;
                    case WHITE_BISHOP_SYMBOL: 
                        Piece* newPiece = new Bishop(piece_ns::white);
                        break;
                    case WHITE_KNIGHT_SYMBOL: 
                        Piece* newPiece = new Knight(piece_ns::white);
                        break;
                    case WHITE_PAWN_SYMBOL: 
                        Piece* newPiece = new Black(piece_ns::white);
                        break;

                /* Black Pieces*/
                    case BLACK_KING_SYMBOL: 
                        Piece* newPiece = new King(piece_ns::black);
                        break;
                    case BLACK_QUEEN_SYMBOL: 
                        Piece* newPiece = new Queen(piece_ns::black);
                        break;
                    case BLACK_ROOK_SYMBOL: 
                        Piece* newPiece = new Rook(piece_ns::black);
                        break;
                    case BLACK_BISHOP_SYMBOL: 
                        Piece* newPiece = new Bishop(piece_ns::black);
                        break;
                    case BLACK_KNIGHT_SYMBOL: 
                        Piece* newPiece = new Knight(piece_ns::black);
                        break;
                    case BLACK_PAWN_SYMBOL: 
                        Piece* newPiece = new Pawn(piece_ns::black);
                        break;
                    default:
                        //throw custom error relating to corrupted boardmap 
                        break;
                this->boardMap.at(x).at(y) = newPiece;
                }
            }
        }
    }



/**
    string* SplitStringtoList2()
    {

    }
**/
    private:
    array<array<Piece* , 8>, 8> boardMap;
    
};