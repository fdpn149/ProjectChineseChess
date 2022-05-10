#include "Soldier.h"
#include "GameManager.h"
namespace ProjectChineseChess
{
	void Soldier::checkFront(Board^ board, Point^ pos)
	{
		int direction;  //棋子該走的方向
		if (color == Color::BLACK)
			direction = 1;
		else
			direction = -1;
			
		if (board->board[pos->X, pos->Y + direction] == nullptr)  //若前面一格沒有東西
		{
			PictureBox^ greenDot = gcnew PictureBox();  //建立一個綠點
			Point^ formPoint = board->ToFormCoord(Point(pos->X, pos->Y + direction));  //綠點在視窗上的位置
			greenDot->Location = *formPoint;  //設定綠點的位置
			GameManager::green->push_back(greenDot);  //將綠點存起來
		}
		else if (PieceColor(board->board[pos->X, pos->Y + direction]) != color)  //若前面一格是對手的棋子
		{
			GameManager::red->push_back(board->board[pos->X, pos->Y + direction]);  //將前面的棋子存起來
		}
	}

	Soldier::Soldier(Color color, int id) : Chess(color, id)
	{
		crossedRiver = false;
	}

	void Soldier::CanMove(Board^ board, PictureBox^ piece)
	{
		Point^ pos = board->ToBoardCoord(piece->Location);

		//如果是"兵"
		if (this->color == Color::RED)
		{
			if (crossedRiver)  //如果已經過河
			{

			}
			else  //如果尚未過河
			{
				if (pos->Y - 1 > 0)
				{
					checkFront(board, pos);
				}
			}
		}
		//如果是"卒"
		else
		{
			if (crossedRiver)  //如果已經過河
			{

			}
			else  //如果尚未過河
			{
				if (pos->Y + 1 < 10)
				{
					checkFront(board, pos);
				}
			}
		}
	}
}