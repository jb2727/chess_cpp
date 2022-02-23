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
    static const string DEFAULT_FEN;
    Fen(string rawFenPattern);
    char GetTurnIndicator();
    CastleStatus * GetCastling();
    EnPassantCoord * GetEnPassantSquare();
    int GetConseqNoPawnMoves();
    int GetMoveNumber();
    vector<string> ExtractBoardTemplate();
    private:

};