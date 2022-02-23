#include "board.hpp"
#include "fen.hpp"
#include <memory>
#include "definitions.hpp"

int main()
{
    unique_ptr<Fen> startingPosition(new Fen(DEFAULT_FEN)); 
    Board board(startingPosition.get());
    return 0;  
}