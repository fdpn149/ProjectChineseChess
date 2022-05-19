#include "Soldier.h"
#include "GameManager.h"
namespace ProjectChineseChess
{
	void Soldier::checkFront(Board^ board, Point^ pos)
	{
		if (pos->Y - 1 < 0 || pos->Y + 1 >= 10)  //�P�_���e�@�B�O�_�X��
			return;

		int direction;  //�Ѥl�Ө�����V
		if (color == Color::BLACK)
			direction = 1;
		else
			direction = -1;

		pushGreenAndRed(board, pos->X, pos->Y + direction);
	}

	void Soldier::checkSide(Board^ board, Point^ pos, int direct)
	{
		if (pos->X + direct < 0 || pos->X + direct >= 9)  //�P�_�V����@�B�O�_�X��
			return;

		if (board->board[pos->X + direct, pos->Y] == nullptr)  //�Y����@��S���F��
		{
			PictureBox^ greenDot = gcnew PictureBox();  //�إߤ@�Ӻ��I
			Point^ formPoint = Board::ToFormCoord(Point(pos->X + direct, pos->Y));  //���I�b�����W����m
			greenDot->Location = *formPoint;  //�]�w���I����m
			greenDot->Name = "green";
			GameManager::green->push_back(greenDot);  //�N���I�s�_��
		}
		else if (PieceColor(board->board[pos->X + direct, pos->Y]) != color)  //�Y����@��O��⪺�Ѥl
		{
			GameManager::red->push_back(board->board[pos->X + direct, pos->Y]);  //�N�e�����Ѥl�s�_��
		}
	}

	Soldier::Soldier(Color color, int id) : Chess(color, id)
	{
		crossedRiver = false;
	}

	void Soldier::Move(Board^ board, PictureBox^ piece)
	{
		Point^ pos = Board::ToBoardCoord(piece->Location);

		checkFront(board, pos);  //�ˬd�e��
		if (crossedRiver)  //�p�G�w�g�L�e
		{
			if (!KingsFaceToFace(board, piece))  //�������P�_
				return;
			checkSide(board, pos, 1);  //�ˬd�k��
			checkSide(board, pos, -1);  //�ˬd����
		}
	}
}