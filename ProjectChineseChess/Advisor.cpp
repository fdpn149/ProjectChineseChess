#include "Advisor.h"
#include "GameManager.h"

namespace ProjectChineseChess
{
	bool Advisor::inRange(Direction direct, Point^ pos)
	{
		switch (direct)
		{
		case ProjectChineseChess::Direction::LEFTUP:
			if (color == Color::RED)  //紅方
			{
				if (pos->X - 1 >= 3 && pos->Y - 1 >= 7)
					return true;
				else
					return false;
			}
			else  //黑方
			{
				if (pos->X - 1 >= 3 && pos->Y - 1 >= 0)
					return true;
				else
					return false;
			}
			break;
		case ProjectChineseChess::Direction::RIGHTUP:
			if (color == Color::RED)  //紅方
			{
				if (pos->X + 1 <= 5 && pos->Y - 1 >= 7)
					return true;
				else
					return false;
			}
			else  //黑方
			{
				if (pos->X + 1 <= 5 && pos->Y - 1 >= 0)
					return true;
				else
					return false;
			}
			break;
		case ProjectChineseChess::Direction::LEFTDOWN:
			if (color == Color::RED)  //紅方
			{
				if (pos->X - 1 >= 3 && pos->Y + 1 <= 9)
					return true;
				else
					return false;
			}
			else  //黑方
			{
				if (pos->X - 1 >= 3 && pos->Y + 1 <= 2)
					return true;
				else
					return false;
			}
			break;
		case ProjectChineseChess::Direction::RIGHTDOWN:
			if (color == Color::RED)  //紅方
			{
				if (pos->X + 1 <= 5 && pos->Y + 1 <= 9)
					return true;
				else
					return false;
			}
			else  //黑方
			{
				if (pos->X + 1 <= 5 && pos->Y + 1 <= 2)
					return true;
				else
					return false;
			}
			break;
		}
		return false;
	}
	void Advisor::pushGreenAndRed(Board^ board, int X, int Y)
	{
		if (board->board[X, Y] == nullptr)
		{
			PictureBox^ greenDot = gcnew PictureBox();  //建立一個綠點
			Point^ formPoint = Board::ToFormCoord(Point(X, Y));  //綠點在視窗上的位置
			greenDot->Location = *formPoint;  //設定綠點的位置
			GameManager::green->push_back(greenDot);  //將綠點存起來
		}
		else if (PieceColor(board->board[X, Y]) != color)
			GameManager::red->push_back(board->board[X, Y]);
	}


	void Advisor::Move(Board^ board, PictureBox^ piece)
	{
		Point^ pos = Board::ToBoardCoord(piece->Location);
		
		//左上
		int X = pos->X - 1; int Y = pos->Y - 1;
		if (inRange(Direction::LEFTUP, pos))
		{
			pushGreenAndRed(board, X, Y);
		}

		//右上
		X = pos->X + 1; Y = pos->Y - 1;
		if (inRange(Direction::RIGHTUP, pos))
		{
			pushGreenAndRed(board, X, Y);
		}

		//左下
		X = pos->X - 1; Y = pos->Y + 1;
		if (inRange(Direction::LEFTDOWN, pos))
		{
			pushGreenAndRed(board, X, Y);
		}

		//右下
		X = pos->X + 1; Y = pos->Y + 1;
		if (inRange(Direction::RIGHTDOWN, pos))
		{
			pushGreenAndRed(board, X, Y);
		}


		////如果是黑方，不能移動到黑方棋子上
		//if (this->color == Color::BLACK)
		//{
		//	for (int X = pos->X - 1; X <= pos->X + 1; X += 2)		//----------------------
		//	{														//左上、右上、左下、右下
		//		for (int Y = pos->Y - 1; Y <= pos->Y + 1; Y += 2)	//----------------------
		//		{
		//			if (X >= 3 && X <= 5 && Y >= 0 && Y <= 2)	//是否超出範圍
		//			{
		//				if (board->board[X, Y] == nullptr)
		//				{
		//					PictureBox^ greenDot = gcnew PictureBox();  //建立一個綠點
		//					Point^ formPoint = board->ToFormCoord(Point(X, Y));  //綠點在視窗上的位置
		//					greenDot->Location = *formPoint;  //設定綠點的位置
		//					GameManager::green->push_back(greenDot);  //將綠點存起來
		//				}
		//				else if(PieceColor(board->board[X, Y]) == Color::RED)
		//					GameManager::red->push_back(board->board[X, Y]);
		//			}
		//		}
		//	}
		//}
		//else
		//{
		//	for (int X = pos->X - 1; X <= pos->X + 1; X += 2)		//----------------------
		//	{														//左上、右上、左下、右下
		//		for (int Y = pos->Y - 1; Y <= pos->Y + 1; Y += 2)	//----------------------
		//		{
		//			if (X >= 3 && X <= 5 && Y >= 7 && Y <= 9)	//是否超出範圍
		//			{
		//				if (board->board[X, Y] == nullptr)
		//				{
		//					PictureBox^ greenDot = gcnew PictureBox();  //建立一個綠點
		//					Point^ formPoint = board->ToFormCoord(Point(X, Y));  //綠點在視窗上的位置
		//					greenDot->Location = *formPoint;  //設定綠點的位置
		//					GameManager::green->push_back(greenDot);  //將綠點存起來
		//				}
		//				else if (PieceColor(board->board[X, Y]) == Color::RED)
		//					GameManager::red->push_back(board->board[X, Y]);
		//			}
		//		}
		//	}
		//}
	}
}