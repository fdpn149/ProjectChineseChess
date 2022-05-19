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

		pushGreenAndRed(board, pos->X, pos->Y + direction);
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
			greenDot->Name = "green";
			GameManager::green->push_back(greenDot);  //將綠點存起來
		}
		else if (PieceColor(board->board[pos->X + direct, pos->Y]) != color)  //若旁邊一格是對手的棋子
		{
			GameManager::red->push_back(board->board[pos->X + direct, pos->Y]);  //將前面的棋子存起來
		}
	}

	Soldier::Soldier(Color color, int id) : Chess(color, id)
	{
		crossedRiver = false;
	}

	void Soldier::Move(Board^ board, PictureBox^ piece)
	{
		Point^ pos = Board::ToBoardCoord(piece->Location);

		checkFront(board, pos);  //檢查前面
		if (crossedRiver)  //如果已經過河
		{
			if (!KingsFaceToFace(board, piece))  //王見王判斷
				return;
			checkSide(board, pos, 1);  //檢查右邊
			checkSide(board, pos, -1);  //檢查左邊
		}
	}
}