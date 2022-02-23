#include "fen.hpp"
#include <string>
#include <vector>
#include <array>
#include "coord.hpp"
#include <memory>

using namespace std;


#define WHITE_TURN_INDICATOR "w"
#define BLACK_TURN_INDICATOR "b"

#define WHITE_KINGSIDE_CASTLE_INDICATOR "K"
#define WHITE_QUEENSIDE_CASTLE_INDICATOR "Q"
#define BLACK_KINGSIDE_CASTLE_INDICATOR "k"
#define BLACK_QUEENSIDE_CASTLE_INDICATOR "q"
#define NO_CASTLE_INDICATOR "-"
#define NO_ENPASSANT_INDICATOR "-"

//NOTE: THIS ENTIRE CLASS NEEDS SOME SERIOUS REFACTORING, IT IS NOT CONSISTENT, AND EACH MEMBER FUNCTION IS DOING WAY TOO MUCH

Fen::Fen(string rawFenPattern)
{
    
    this->rawFenPattern;
    this->castling.reset(new CastleStatus());
    setFenConfigurations();
}
//getters
char Fen::GetTurnIndicator()
{   
    return turnIndicator;
}
//WARNING - BE VERY CAREFUL WITH THE IMPLICATIONS OF THESE TWO FUNCTIONS
//getting the pointer to the object and unqiue_ptr<T>.reset(ptr)'ing it in another object *might* lead to undefined behaviour when referencing the pointer in this object, make sure this does not happen!
CastleStatus * Fen::GetCastling()
{
    return castling.get();
}
EnPassantCoord * Fen::GetEnPassantSquare()
{
    return enPassantSquare.get();
}
int Fen::GetConseqNoPawnMoves()
{
    return conseqNoPawnMoves;
}
int Fen::GetMoveNumber()
{
    return moveNumber;
}

vector<string> Fen::ExtractBoardTemplate()
{
    //raw fen pattern = rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1
    string rawFenPattern = this->rawFenPattern;
    vector<string> splitFen;
    string segment;
    
    //first, remove the game state fen indicators (found at and after the first space in an accurate fen)
    rawFenPattern.erase(rawFenPattern.find(' '), string::npos); //npos = until end of string. aka -1
    //raw fen pattern = rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR
    int delimitPos = rawFenPattern.find('/');
    while (delimitPos != string::npos)
    {
        
        segment = rawFenPattern.substr(0,delimitPos); //get rnbqkbnr
        rawFenPattern.erase(0, delimitPos+1); //remove rnbqkbnr/
        splitFen.push_back(segment);
        delimitPos = rawFenPattern.find('/');
    }
    splitFen.push_back(rawFenPattern); //add remaining string to list
    return splitFen;
}

void Fen::setFenConfigurations()
{
    string rawFenPattern = this->rawFenPattern;
    rawFenPattern.erase(0,rawFenPattern.find(' '));
    string turnIndicator = rawFenPattern.substr(0, rawFenPattern.find(' '));
    //validate turnIndicator 
    if ((turnIndicator.compare(WHITE_TURN_INDICATOR) != 0) &&
        (turnIndicator.compare(BLACK_TURN_INDICATOR) != 0))
    {
        throw "placeholder error turn indicator wrong";
    }
    this->turnIndicator = turnIndicator[0]; //the previous code ensures that this is a 1 len string, therefore getting the 0th index is the same as converting it to char
    //validate castling 
    //rules of castling string
    //must be in order K, Q, k, q 
    //if - then nothing else
    //no repeats 

    //extract castle indicators 
    rawFenPattern.erase(0,rawFenPattern.find(' '));
    string castleIndicators = rawFenPattern.substr(0, rawFenPattern.find(' '));
    
    array<string, 4> castleIndicatorOrder = {WHITE_KINGSIDE_CASTLE_INDICATOR,WHITE_QUEENSIDE_CASTLE_INDICATOR,BLACK_KINGSIDE_CASTLE_INDICATOR, BLACK_QUEENSIDE_CASTLE_INDICATOR}; //note, should this be a char instead? 
    int orderIndicatorIndex = 0;
    //this feels like extremely ugly code, would probably be better in a bool class member function
    if (castleIndicators.compare(NO_CASTLE_INDICATOR) != 0)
    {
        for (int i = 0; i<castleIndicators.size(); i++)
        {   
            if (orderIndicatorIndex >= castleIndicatorOrder.size())
                {
                    throw "placeholder error castle indicators contained invalid or out of order symbols";
                }
            while( castleIndicators.find(castleIndicatorOrder[orderIndicatorIndex++], i) == string::npos )
            {
                if (orderIndicatorIndex >= castleIndicatorOrder.size())
                {
                    throw "placeholder error castle indicators contained invalid or out of order symbols";
                }
            }
            if (castleIndicatorOrder[orderIndicatorIndex-1].compare(WHITE_KINGSIDE_CASTLE_INDICATOR) == 0)
            {
                castling->whiteKingSide = true;
            }
            else if (castleIndicatorOrder[orderIndicatorIndex-1].compare(WHITE_QUEENSIDE_CASTLE_INDICATOR) == 0)
            {
                castling->whiteQueenSide = true;
            }
            else if (castleIndicatorOrder[orderIndicatorIndex-1].compare(BLACK_KINGSIDE_CASTLE_INDICATOR) == 0)
            {
                castling->blackKingSide = true;
            }
            else if (castleIndicatorOrder[orderIndicatorIndex-1].compare(BLACK_QUEENSIDE_CASTLE_INDICATOR) == 0)
            {
                castling->blackQueenSide = true;
            }
        }
    }
    //set up enPassantSquare
    rawFenPattern.erase(0,rawFenPattern.find(' '));
    string enPassantPattern = rawFenPattern.substr(0, rawFenPattern.find(' '));
    this->enPassantSquare.reset(new EnPassantCoord(enPassantPattern[0], enPassantPattern[1]));

    //set conseqNoPawnMoves
    rawFenPattern.erase(0,rawFenPattern.find(' '));
    string conseqNoPawnMoves = rawFenPattern.substr(0, rawFenPattern.find(' '));
    this->conseqNoPawnMoves = stoi(conseqNoPawnMoves);

    //set move Number
    rawFenPattern.erase(0,rawFenPattern.find(' '));
    string moveNumber = rawFenPattern.substr(0, rawFenPattern.find(' '));
    this->moveNumber = stoi(moveNumber);

}
