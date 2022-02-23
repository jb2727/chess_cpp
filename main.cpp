#include "board.hpp"
#include "fen.hpp"
#include <memory>

int main()
{
    Fen startingPosition(Fen::DEFAULT_FEN); 
    Board board(startingPosition);
    return 0;  
}