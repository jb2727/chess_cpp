#include <array>
#include "piece.hpp"
#include "fen.hpp"

using namespace std;

class Board
{

    public:
    Board()
    {

    }
    void createBoard(Fen input){


    }
    
    private:
    array<array<Piece, 8>, 8> boardMap;
    
};