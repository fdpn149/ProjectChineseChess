#include "Board.h"
#include "GameForm.h"
namespace ProjectChineseChess
{
    Board::Board()
    {
        //儲存棋子的位置
        board[0, 0] = GameForm::gameform->chariotB1;    board[0, 8] = GameForm::gameform->chariotB2;
        board[1, 0] = GameForm::gameform->horseB1;      board[7, 0] = GameForm::gameform->horseB2;
        board[2, 0] = GameForm::gameform->elephantB1;   board[6, 0] = GameForm::gameform->elephantB2;
        board[3, 0] = GameForm::gameform->advisorB1;    board[5, 0] = GameForm::gameform->advisorB2;
        board[4, 0] = GameForm::gameform->generalB;     board[4, 9] = GameForm::gameform->generalR;
        board[1, 2] = GameForm::gameform->cannonB1;     board[7, 2] = GameForm::gameform->cannonB2;
        board[0, 3] = GameForm::gameform->soldierB1;    board[8, 3] = GameForm::gameform->soldierB5;
        board[2, 3] = GameForm::gameform->soldierB2;    board[6, 3] = GameForm::gameform->soldierB4;
        board[4, 3] = GameForm::gameform->soldierB3;    board[4, 6] = GameForm::gameform->soldierR3;
        board[2, 6] = GameForm::gameform->soldierR2;    board[6, 6] = GameForm::gameform->soldierR4;
        board[0, 6] = GameForm::gameform->soldierR1;    board[8, 6] = GameForm::gameform->soldierR5;
        board[1, 7] = GameForm::gameform->cannonR1;     board[7, 7] = GameForm::gameform->cannonR2;
        board[0, 9] = GameForm::gameform->chariotR1;    board[8, 9] = GameForm::gameform->chariotR2;
        board[1, 9] = GameForm::gameform->horseR1;      board[7, 9] = GameForm::gameform->horseR2;
        board[2, 9] = GameForm::gameform->elephantR1;   board[6, 9] = GameForm::gameform->elephantR2;
        board[3, 9] = GameForm::gameform->advisorR1;    board[5, 9] = GameForm::gameform->advisorR2;
    }
    Point^ Board::ToBoardCoord(Point^ formCoord)
    {
        Point^ point = gcnew Point();
        point->X = (formCoord->X + 35) / 75 - 1;
        point->Y = (formCoord->Y + 35) / 75 - 1;
        return point;
    }
}