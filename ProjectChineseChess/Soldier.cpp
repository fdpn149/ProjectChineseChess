#include "Soldier.h"
#include "GameManager.h"
namespace ProjectChineseChess
{
	void Soldier::checkFront(Board^ board, Point^ pos)
	{
		if (pos->Y - 1 < 0 || pos->Y + 1 >= 10)  //判斷往前一步是否出界
			return;

		int direction;  //棋子該走的方向
		if (color == Color::BLACK)
			direction = 1;
		else
			direction = -1;

		if (board->board[pos->X, pos->Y + direction] == nullptr)  //若前面一格沒有東西
		{
			PictureBox^ greenDot = gcnew PictureBox();  //建立一個綠點
			Point^ formPoint = Board::ToFormCoord(Point(pos->X, pos->Y + direction));  //綠點在視窗上的位置
			greenDot->Location = *formPoint;  //設定綠點的位置
			GameManager::green->push_back(greenDot);  //將綠點存起來
		}
		else if (PieceColor(board->board[pos->X, pos->Y + direction]) != color)  //若前面一格是對手的棋子
		{
			GameManager::red->push_back(board->board[pos->X, pos->Y + direction]);  //將前面的棋子存起來
		}
	}

	void Soldier::checkSide(Board^ board, Point^ pos, int direct)
	{
		if (pos->X + direct < 0 || pos->X + direct >= 9)  //判斷向旁邊一步是否出界
			return;

		if (board->board[pos->X + direct, pos->Y] == nullptr)  //若旁邊一格沒有東西
		{
			PictureBox^ greenDot = gcnew PictureBox();  //建立一個綠點
			Point^ formPoint = Board::ToFormCoord(Point(pos->X + direct, pos->Y));  //綠點在視窗上的位置
			greenDot->Location = *formPoint;  //設定綠點的位置
			GameManager::green->push_back(greenDot);  //將綠點存起來
		}
		else if (PieceColor(board->board[pos->X + direct, pos->Y]) != color)  //若旁邊一格是對手的棋子
		{
			GameManager::red->push_back(board->board[pos->X + direct, pos->Y]);  //將前面的棋子存起來
		}
	}

	void Soldier::checkCrossRiver(Point^ pos)
	{
		if (color == Color::BLACK)  //如果是黑色
		{
			if (pos->Y >= 5)
				crossedRiver = true;
		}
		else  //如果是紅色
		{
			if (pos->Y <= 4)
				crossedRiver = true;
		}
	}

	Soldier::Soldier(Color color, int id) : Chess(color, id)
	{
		crossedRiver = false;
	}

	void Soldier::Move(Board^ board, PictureBox^ piece)
	{
		Point^ pos = Board::ToBoardCoord(piece->Location);

		if (crossedRiver == false)  //如果還沒過河
			checkCrossRiver(pos);  //檢查是否過河

		checkFront(board, pos);  //檢查前面
		if (crossedRiver)  //如果已經過河
		{
			checkSide(board, pos, 1);  //檢查右邊
			checkSide(board, pos, -1);  //檢查左邊
		}
	}
}