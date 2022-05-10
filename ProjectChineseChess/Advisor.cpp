#include "Advisor.h"
#include "GameManager.h"

namespace ProjectChineseChess
{
	void Advisor::CanMove(Board^ board, PictureBox^ piece)
	{
		Point^ pos = board->ToBoardCoord(piece->Location);
		
		//如果是黑方，不能移動到黑方棋子上
		if (this->color == Color::BLACK)
		{
			for (int X = pos->X - 1; X <= pos->X + 1; X += 2)		//----------------------
			{														//左上、右上、左下、右下
				for (int Y = pos->Y - 1; Y <= pos->Y + 1; Y += 2)	//----------------------
				{
					if (X >= 3 && X <= 5 && Y >= 0 && Y <= 2)	//是否超出範圍
					{
						if (board->board[X, Y] == nullptr)
						{
							PictureBox^ greenDot = gcnew PictureBox();  //建立一個綠點
							Point^ formPoint = board->ToFormCoord(Point(X, Y));  //綠點在視窗上的位置
							greenDot->Location = *formPoint;  //設定綠點的位置
							GameManager::green->push_back(greenDot);  //將綠點存起來
						}
						else if(PieceColor(board->board[X, Y]) == Color::RED)
							GameManager::red->push_back(board->board[X, Y]);
					}
				}
			}
		}
		else
		{
			for (int X = pos->X - 1; X <= pos->X + 1; X += 2)		//----------------------
			{														//左上、右上、左下、右下
				for (int Y = pos->Y - 1; Y <= pos->Y + 1; Y += 2)	//----------------------
				{
					if (X >= 3 && X <= 5 && Y >= 7 && Y <= 9)	//是否超出範圍
					{
						if (board->board[X, Y] == nullptr)
						{
							PictureBox^ greenDot = gcnew PictureBox();  //建立一個綠點
							Point^ formPoint = board->ToFormCoord(Point(X, Y));  //綠點在視窗上的位置
							greenDot->Location = *formPoint;  //設定綠點的位置
							GameManager::green->push_back(greenDot);  //將綠點存起來
						}
						else if (PieceColor(board->board[X, Y]) == Color::RED)
							GameManager::red->push_back(board->board[X, Y]);
					}
				}
			}
		}
	}
}