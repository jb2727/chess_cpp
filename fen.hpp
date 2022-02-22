#include <vector>
#include <string>

using namespace std;


struct CastleStatus
    {
    bool whiteKingSide;
    bool whiteQueenSide;
    bool blackKingSide;
    bool blackQueenSide;
    };

class Fen{
    public:
    Fen();
    char GetTurnIndicator();
    CastleStatus * GetCastling();
    EnPassantCoord * GetEnPassantSquare();
    int GetConseqNoPawnMoves();
    int GetMoveNumber();
    vector<string> ExtractBoardTemplate();
    private:

};