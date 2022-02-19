#include "fen.hpp"
#include <string>
#include <vector>

using namespace std;

class Fen
{
    public:
    Fen()
    {

    }

    vector<string> extractBoardTemplate()
    {
        //raw fen pattern = rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1
        string rawFenPattern = this->rawFenPattern;
        vector<string> splitFen;
        string segment;
        
        //first, remove the game state fen indicators (found at and after the first space in an accurate fen)
        rawFenPattern.erase(rawFenPattern.find(' '), string::npos); //apperantly npos means "until the end of the string... time will tell if this works"
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

    private:
    string rawFenPattern;
};
