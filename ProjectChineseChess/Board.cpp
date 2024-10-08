#include "Board.h"
#include "GameForm.h"
namespace ProjectChineseChess
{
    Board::Board()
    {
        //�x�s�Ѥl����m
        board[0, 0] = GameForm::gameform->chariotB1;    board[8, 0] = GameForm::gameform->chariotB2;
        board[1, 0] = GameForm::gameform->horseB1;      board[7, 0] = GameForm::gameform->horseB2;
        board[2, 0] = GameForm::gameform->elephantB1;   board[6, 0] = GameForm::gameform->elephantB2;
        board[3, 0] = GameForm::gameform->advisorB1;    board[5, 0] = GameForm::gameform->advisorB2;
        board[4, 0] = GameForm::gameform->generalB1;    board[4, 9] = GameForm::gameform->generalR1;
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
        point->X = (formCoord->X - 40) / 75;
        point->Y = (formCoord->Y - 40) / 75;
        return point;
    }
    Point^ Board::ToFormCoord(Point^ boardCoord)
    {
        Point^ point = gcnew Point();
        point->X = boardCoord->X * 75 + 40;
        point->Y = boardCoord->Y * 75 + 40;
        return point;
    }
    PictureBox^ Board::FindPiece(String^ name)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (board[i, j] != nullptr && board[i, j]->Name == name)
                    return board[i, j];
            }
        }
        return nullptr;
    }
}