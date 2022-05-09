#include "Board.h"
#include "GameForm.h"
namespace ProjectChineseChess
{
    Board::Board()
    {
        board[0, 0] = GameForm::gameform->chariotB1; board[0, 8] = GameForm::gameform->chariotB2;
        board[0, 1] = GameForm::gameform->horseB1; board[0, 7] = GameForm::gameform->horseB2;
        board[0, 2] = GameForm::gameform->elephantB1; board[0, 6] = GameForm::gameform->elephantB2;
        board[0, 3] = GameForm::gameform->advisorB1; board[0, 5] = GameForm::gameform->advisorB2;
        board[0, 4] = GameForm::gameform->generalB; board[9, 4] = GameForm::gameform->generalR;
        board[2, 1] = GameForm::gameform->cannonB1; board[2, 7] = GameForm::gameform->cannonB2;
        board[3, 0] = GameForm::gameform->soldierB1; board[3, 8] = GameForm::gameform->soldierB5;
        board[3, 2] = GameForm::gameform->soldierB2; board[3, 6] = GameForm::gameform->soldierB4;
        board[3, 4] = GameForm::gameform->soldierB3; board[6, 4] = GameForm::gameform->soldierR3;
        board[6, 2] = GameForm::gameform->soldierR2; board[6, 6] = GameForm::gameform->soldierR4;
        board[6, 0] = GameForm::gameform->soldierR1; board[6, 8] = GameForm::gameform->soldierR5;
        board[7, 1] = GameForm::gameform->cannonR1; board[7, 7] = GameForm::gameform->cannonR2;
        board[9, 0] = GameForm::gameform->chariotR1; board[9, 8] = GameForm::gameform->chariotR2;
        board[9, 1] = GameForm::gameform->horseR1; board[9, 7] = GameForm::gameform->horseR2;
        board[9, 2] = GameForm::gameform->elephantR1; board[9, 6] = GameForm::gameform->elephantR2;
        board[9, 3] = GameForm::gameform->advisorR1; board[9, 5] = GameForm::gameform->advisorR2;
    }
}