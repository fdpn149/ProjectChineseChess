#include "GameManager.h"
#include "Viewer.h"
#include "Advisor.h"
#include "Cannon.h"
#include "Chariot.h"
#include "Elephant.h"
#include "General.h"
#include "Horse.h"
#include "Soldier.h"
namespace ProjectChineseChess
{
	void GameManager::pieceInit()
	{
		//�إߦU�شѤl������
		Chariot^ chariotB1 = gcnew Chariot(Color::BLACK, 1), ^ chariotB2 = gcnew Chariot(Color::BLACK, 2);
		Horse^ horseB1 = gcnew Horse(Color::BLACK, 1), ^ horseB2 = gcnew Horse(Color::BLACK, 2);
		Elephant^ elephantB1 = gcnew Elephant(Color::BLACK, 1), ^ elephantB2 = gcnew Elephant(Color::BLACK, 2);
		Advisor^ advisorB1 = gcnew Advisor(Color::BLACK, 1), ^ advisorB2 = gcnew Advisor(Color::BLACK, 2);
		Cannon^ cannonB1 = gcnew Cannon(Color::BLACK, 1), ^ cannonB2 = gcnew Cannon(Color::BLACK, 2);
		Soldier^ soldierB1 = gcnew Soldier(Color::BLACK, 1), ^ soldierB2 = gcnew Soldier(Color::BLACK, 2), ^ soldierB3 = gcnew Soldier(Color::BLACK, 3);
		Soldier^ soldierB4 = gcnew Soldier(Color::BLACK, 4), ^ soldierB5 = gcnew Soldier(Color::BLACK, 5);
		General^ generalB1 = gcnew General(Color::BLACK, 1), ^ generalR1 = gcnew General(Color::RED, 1);
		Chariot^ chariotR1 = gcnew Chariot(Color::RED, 1), ^ chariotR2 = gcnew Chariot(Color::RED, 2);
		Horse^ horseR1 = gcnew Horse(Color::RED, 1), ^ horseR2 = gcnew Horse(Color::RED, 2);
		Elephant^ elephantR1 = gcnew Elephant(Color::RED, 1), ^ elephantR2 = gcnew Elephant(Color::RED, 2);
		Advisor^ advisorR1 = gcnew Advisor(Color::RED, 1), ^ advisorR2 = gcnew Advisor(Color::RED, 2);
		Cannon^ cannonR1 = gcnew Cannon(Color::RED, 1), ^ cannonR2 = gcnew Cannon(Color::RED, 2);
		Soldier^ soldierR1 = gcnew Soldier(Color::RED, 1), ^ soldierR2 = gcnew Soldier(Color::RED, 2), ^ soldierR3 = gcnew Soldier(Color::RED, 3);
		Soldier^ soldierR4 = gcnew Soldier(Color::RED, 4), ^ soldierR5 = gcnew Soldier(Color::RED, 5);
		//�N�U�شѤl������[�ion_board
		on_board["chariotB1"] = chariotB1; on_board["chariotB2"] = chariotB2; on_board["horseB1"] = horseB1; on_board["horseB2"] = horseB2;
		on_board["elephantB1"] = elephantB1; on_board["elephantB2"] = elephantB2; on_board["advisorB1"] = advisorB1; on_board["advisorB2"] = advisorB2;
		on_board["cannonB1"] = cannonB1; on_board["cannonB2"] = cannonB2; on_board["soldierB1"] = soldierB1; on_board["soldierB2"] = soldierB2;
		on_board["soldierB3"] = soldierB3; on_board["soldierB4"] = soldierB4; on_board["soldierB5"] = soldierB5; on_board["generalB1"] = generalB1;
		on_board["chariotR1"] = chariotR1; on_board["chariotR2"] = chariotR2; on_board["horseR1"] = horseR1; on_board["horseR2"] = horseR2;
		on_board["elephantR1"] = elephantR1; on_board["elephantR2"] = elephantR2; on_board["advisorR1"] = advisorR1; on_board["advisorR2"] = advisorR2;
		on_board["cannonR1"] = cannonR1; on_board["cannonR2"] = cannonR2; on_board["soldierR1"] = soldierR1; on_board["soldierR2"] = soldierR2;
		on_board["soldierR3"] = soldierR3; on_board["soldierR4"] = soldierR4; on_board["soldierR5"] = soldierR5; on_board["generalR1"] = generalR1;
	}

	void GameManager::changeState(PictureBox^ nowPiece)
	{
		if (state != State::PIECE_CLICKED)
		{
			//�p�G�I���Ѥl��{�b���쪺�C�⤣�@��
			if ((current_player == 0 && on_board[nowPiece->Name]->PieceColor(nowPiece) == Color::BLACK) ||
				(current_player == 1 && on_board[nowPiece->Name]->PieceColor(nowPiece) == Color::RED))
			{
				state = State::NONE;
				return;
			}
		}

		//�Y�P�@�Ѥl�Q�I��U
		if (state == State::PIECE_CLICKED && lastPiece->Name == nowPiece->Name)
			state = State::NONE;
		//�Y�I�������P���Ѥl
		else if (state == State::PIECE_CLICKED)
		{
			//�M��ĤG���I���Ѥl�O�_�O����
			for (int i = 0; i < red->size(); i++)
			{
				if (red->at(i) == nowPiece)  //�p�G�����
				{
					state = State::MOVE_PIECE;
					return;
				}
			}
			//�S���
			state = State::NONE;
		}
		//�Y�u�I�F�@���Ѥl
		else
			state = State::PIECE_CLICKED;
	}

	GameManager::GameManager()
	{
		viewer = gcnew Viewer();
		board = gcnew Board();
		pieceInit();
		current_player = 0;
	}

	void GameManager::PieceClick(PictureBox^ piece)
	{
		changeState(piece);  //��窱�A
		//�Y�n���ʴѤl
		if (state == State::MOVE_PIECE)
		{
			on_board[lastPiece->Name]->OnMove(board, lastPiece->Location, piece->Location);  //���ʴѤl
			viewer->RemovePiece(piece);
			viewer->SetPiece(lastPiece, piece->Location);
			viewer->PieceUnclick(lastPiece);  //�N�Ѥl�C���^��
			viewer->RemoveGreens();  //��������I
			viewer->RemoveReds();  //���������I
			state = State::NONE;  //�N���A��^��S
			current_player = !current_player;
		}
		//�Y�u�I�@���Ѥl
		else if (state == State::PIECE_CLICKED)
		{
			viewer->PieceClick(piece);  //���Ѥl�ܦ�
			on_board[piece->Name]->Move(board,piece);  //�M��i�H�������|
			viewer->ShowGreens();  //��ܺ���I
			viewer->ShowReds();  //��ܬ����I
			
		}
		//�Y�P�@�Ѥl�Q�I��U
		else
		{
			if(lastPiece != nullptr)
				viewer->PieceUnclick(lastPiece);  //�N�W�ӴѤl���C���^��
			viewer->PieceUnclick(piece);  //�N�Ѥl�C���^��
			viewer->RemoveGreens();  //��������I
			viewer->RemoveReds();  //���������I
		}
		lastPiece = piece;  //�W�@�ӳQ�I���Ѥl�]���{�b���Ѥl
	}

	void GameManager::FormClick()
	{
		//�Y���Ѥl�w�Q�I
		if (state == State::PIECE_CLICKED)
			viewer->PieceUnclick(lastPiece);  //�N�Ѥl�C���^��
		viewer->RemoveGreens();  //��������I
		viewer->RemoveReds();  //���������I
		state = State::NONE;  //�N���A��^��
	}

	void GameManager::GreenClick(PictureBox^ piece)
	{
		on_board[lastPiece->Name]->OnMove(board, lastPiece->Location, piece->Location);  //���ʴѤl
		viewer->SetPiece(lastPiece, piece->Location);
		viewer->PieceUnclick(lastPiece);  //�N�Ѥl�C���^��
		viewer->RemoveGreens();  //��������I
		viewer->RemoveReds();  //���������I
		state = State::NONE;  //�N���A��^��S
		current_player = !current_player;
	}
}