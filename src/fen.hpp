#ifndef FEN_HPP
#define FEN_HPP

#include <vector>
#include <string>
#include <memory>
#include "coord.hpp"

using namespace std;


struct CastleStatus
    {
    bool whiteKingSide = false;
    bool whiteQueenSide = false;
    bool blackKingSide = false;
    bool blackQueenSide = false;
    };

class Fen{

    public:
    //const static string ;
    //static const string DEFAULT_FEN;
    Fen(string rawFenPattern);
    char GetTurnIndicator();
    CastleStatus * GetCastling();
    EnPassantCoord * GetEnPassantSquare();
    int GetConseqNoPawnMoves();
    int GetMoveNumber();
    vector<string> ExtractBoardTemplate();
    private:
    void setFenConfigurations();
    string rawFenPattern;
    char turnIndicator;
    unique_ptr<CastleStatus> castling;
    unique_ptr<EnPassantCoord> enPassantSquare; 
    int conseqNoPawnMoves;
    int moveNumber;

};

#endif
