#include "board.hpp"

using namespace std;


    
    Board::Board(Fen * startState)
    {
        setBoard(startState);
    }

    void Board::movePiece(BoardCoord startPos, BoardCoord endPos)
    {
        //get piece at startPos
        Piece * movingPiece = boardMap.at(startPos.X).at(startPos.Y);
        Piece * targetPiece = boardMap.at(endPos.X).at(endPos.Y);
        if (NULL == movingPiece)
        {
            throw "placeholder error, trying to move a piece that doesn't exist";
        }
        //check whether this is an attack or a move, then check if movement is within movement pattern 
        //---
        //note, there's no need to check whether the Piece at the target square is a King or not, because if the rest of the game functions as intended, then the
        //will never be able to successfully capture a King (outside the movement pattern)
        bool validMove = (NULL != targetPiece) ? movingPiece->ValidMovementPattern(startPos, endPos) : targetPiece->ValidAttackPattern(startPos, endPos);
        if (false == validMove){
            throw "placeholder error invalid movement pattern";
        }
        //
        
        //second, check if there are any pieces inbetween the startingPos and the endingPos
        if (!(movingPiece->getType() == piece_ns::knight)) 
        {
            if (piecesInbetween(startPos, endPos))
            {
                throw "placeholder error pieces inbetween coordinates";
            }
        }
        //lastly, make array(endPos) point to the Piece and array(startPos)
        boardMap.at(endPos.X).at(endPos.Y) = boardMap.at(startPos.X).at(startPos.Y);
        //make the original position NULL
        boardMap.at(startPos.X).at(startPos.Y) = NULL;
    }

    void Board::setBoard(Fen * input)
    {

    //replace this with std::fill 
    for (int x = 0; x < BOARD_WIDTH; x++)
    {
        for (int y = 0; y < BOARD_LENGTH; y++)
        {
            this->boardMap.at(x).at(y) = (Piece *)NULL;
        }
    }
    
    //for x = 0...7: for y = 0...7 -> x
        vector<string> boardTemplate = input->ExtractBoardTemplate();
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
                            Piece* newPiece = new Pawn(piece_ns::white);
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
                            std::ostringstream error_message;

                            error_message << "Fen boardMap is corrupted" << std::endl;
                            //note to self: print out entire boardMap for debugging reasons
                            throw std::invalid_argument(error_message.str());
                            break;
                    this->boardMap.at(x).at(y) = newPiece;
                    }
                }
            }
    }

    bool Board::piecesInbetween(BoardCoord startPos, BoardCoord endPos)
    {
        //note, this code does not work for startPos and endPos that are not directly orthagonal or diagonal together. I don't think it needs to be so I'm content with leaving it like this
        while(startPos.getAbsXDiff(endPos)>1 || startPos.getAbsYDiff(endPos)>1)
        {
            if (startPos.X<endPos.X)
            {
                startPos.X++;
            }
            else if (startPos.X>endPos.X)
            {
                endPos.X--;
            }

            if (startPos.Y<endPos.Y)
            {
                startPos.Y++;
            }
            else if (startPos.Y>endPos.Y)
            {
                endPos.Y--;
            }
        if (NULL != this->boardMap.at(startPos.X).at(startPos.Y))
        {
            return true;
        }
        }
        return false;
        //all piecese move in a either a diagonal or orthagonal fashion, only need to examine cases where diffx = 0 or diffx = diffy & diffy = 0 or diffy = diffx
        
    }
    
