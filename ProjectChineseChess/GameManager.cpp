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
		if (nowPiece->Name == "green")
		{
			state = State::MOVE_PIECE;
			return;
		}

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
		fmanager = gcnew FileManager();
		pieceInit();
		current_player = 0;
	}

	void GameManager::PieceClick(PictureBox^ piece)
	{
		changeState(piece);  //��窱�A
		//�Y�n���ʴѤl
		if (state == State::MOVE_PIECE)
		{
			check = false;
			viewer->Label1Hide();
			//Color pieceColor = on_board[piece->Name]->PieceColor(piece);  //�Ѥl���C��
			on_board[lastPiece->Name]->OnMove(board, lastPiece->Location, piece->Location);  //���ʴѤl
			if (!loading) fmanager->WriteLog(current_player + 1, lastPiece, lastPiece->Location, piece->Location);
			if (piece->Name != "green")
			{
				viewer->RemovePiece(piece);
				on_board.erase(piece->Name);
			}
			viewer->SetPiece(lastPiece, piece->Location);
			viewer->PieceUnclick(lastPiece);  //�N�Ѥl�C���^��
			viewer->RemoveGreens();  //��������I
			viewer->RemoveReds();  //���������I
			on_board[lastPiece->Name]->Move(board, lastPiece);  //�M��i�H�������|
			for (int i = 0; i < red->size(); i++)
			{
				if (red->at(i)->Name[0] == 'g')
				{
					check = true;
					if (on_board[lastPiece->Name]->color == Color::BLACK)
						viewer->Label1Show("�¤�N�x");
					else
						viewer->Label1Show("����N�x");
					break;
				}
			}
			viewer->RemoveGreens();  //��������I
			viewer->RemoveReds();  //���������I
			//��C�Ӧۤv���Ѥl�i�H�������|
			for each (GenericPair<String^, Chess^> ^ p in on_board)
			{
				bool willCheck = false;  //�O�_�|�Q�N�x
				//�Y�O�v�誺�Ѥl
				if (p->second->color == on_board[lastPiece->Name]->PieceColor(piece))
				{
					p->second->Move(board, board->FindPiece(p->first));  //�M��i�H�������|
					for (int j = 0; j < red->size(); j++)
					{
						if (red->at(j)->Name[0] == 'g')
						{
							willCheck = true;
							check = true;
							if (on_board[lastPiece->Name]->color == Color::BLACK)
								viewer->Label1Show("�¤�N�x");
							else
								viewer->Label1Show("����N�x");
							break;
						}
					}
					green->clear();  //�M�����
					red->clear();  //�M������
				}
				if (willCheck)
					break;
			}
			green->clear();  //�M�����
			red->clear();  //�M������

			state = State::NONE;  //�N���A��^��
			current_player = !current_player;
		}
		//�Y�u�I�@���Ѥl
		else if (state == State::PIECE_CLICKED)
		{
			viewer->PieceClick(piece);  //���Ѥl�ܦ�
			on_board[piece->Name]->Move(board, piece);  //�M��i�H�������|
			Point^ nowPosition = piece->Location;  //�O�s�Ѥl�{�b����m
			vector<PictureBox^>^ greenBak = gcnew vector<PictureBox^>;  //�ƥ��{�b��⪺�}�C
			vector<PictureBox^>^ redBak = gcnew vector<PictureBox^>;  //�ƥ��{�b���⪺�}�C
			greenBak->assign(green->begin(), green->end());  //�ƻs������ƥ�
			redBak->assign(red->begin(), red->end());  //�ƻs��������ƥ�
			green->clear();  //�M�����
			red->clear();  //�M������
			Color pieceColor = on_board[piece->Name]->PieceColor(piece);  //�Ѥl���C��
			for (int i = 0; i < greenBak->size(); i++)
			{
				on_board[piece->Name]->OnMove(board, nowPosition, greenBak->at(i)->Location);  //���ʴѤl�����I
				nowPosition = greenBak->at(i)->Location;  //�]�w�Ѥl�{�b����m

				//��C�ӹ�⪺�Ѥl�i�H�������|
				for each (GenericPair<String^, Chess^> ^ p in on_board)
				{
					bool willCheck = false;
					//�Y�O��⪺�Ѥl
					if (p->second->color != pieceColor)
					{
						p->second->Move(board, board->FindPiece(p->first));  //�M��i�H�������|
						for (int j = 0; j < red->size(); j++)
						{
							if (red->at(j)->Name[0] == 'g')
							{
								willCheck = true;
								greenBak->erase(greenBak->begin() + i);
								i--;
								break;
							}
						}
						green->clear();  //�M�����
						red->clear();  //�M������
					}
					if (willCheck)
						break;
				}
			}
			on_board[piece->Name]->OnMove(board, nowPosition, piece->Location);
			if (check)
			{
				for (int i = 0; i < redBak->size(); i++)
				{
					PictureBox^ bak = redBak->at(i);
					on_board[piece->Name]->OnMove(board, piece->Location, redBak->at(i)->Location);  //���ʴѤl������I

					//��C�ӹ�⪺�Ѥl�i�H�������|
					for each (GenericPair<String^, Chess^> ^ p in on_board)
					{
						bool willCheck = false;  //�O�_�|�Q�N�x
						//�Y�O��⪺�Ѥl
						if (p->second->color != pieceColor)
						{
							PictureBox^ find = board->FindPiece(p->first);
							if (find != nullptr)
							{
								p->second->Move(board, find);  //�M��i�H�������|
								for (int j = 0; j < red->size(); j++)
								{
									if (red->at(j)->Name[0] == 'g')
									{
										willCheck = true;
										redBak->erase(redBak->begin() + i);
										i--;
										break;
									}
								}
							}
							green->clear();  //�M�����
							red->clear();  //�M������
						}
						if (willCheck)
							break;
					}
					on_board[piece->Name]->OnMove(board, bak->Location, piece->Location);  //�N�Ѥl���^�h
					Point^ pos = Board::ToBoardCoord(bak->Location);
					board->board[pos->X, pos->Y] = bak;
				}
			}
			green->assign(greenBak->begin(), greenBak->end());  //�ƻs������ƥ�
			red->assign(redBak->begin(), redBak->end());  //�ƻs��������ƥ�
			viewer->ShowGreens();  //��ܺ���I
			viewer->ShowReds();  //��ܬ����I

		}
		//�Y�P�@�Ѥl�Q�I��U
		else
		{
			if (lastPiece != nullptr)
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

	void GameManager::LoadFile()
	{
		loading = true;
		if (fmanager->SetFile())
		{
			while (fmanager->ReadLine(board))
			{
				PieceClick(fmanager->GetFirstPiece());
				if (fmanager->GetSecondPiece() != nullptr)
					PieceClick(fmanager->GetSecondPiece());
				else
				{
					Point^ secPos = fmanager->GetSecondPosition();
					for (int i = 0; i < green->size(); i++)
					{
						if (green->at(i)->Location == *secPos)
						{
							PieceClick(green->at(i));
							break;
						}
					}
				}
			}
			//on_board[lastPiece->Name]->Move(board, lastPiece);  //�M��i�H�������|
			//for (int i = 0; i < red->size(); i++)
			//{
			//	if (red->at(i)->Name[0] == 'g')
			//	{
			//		check = true;
			//		if (on_board[lastPiece->Name]->color == Color::BLACK)
			//			viewer->Label1Show("�¤�N�x");
			//		else
			//			viewer->Label1Show("����N�x");
			//		break;
			//	}
			//}
			//viewer->RemoveGreens();  //��������I
			//viewer->RemoveReds();  //���������I
			loading = false;
		}
		else
			throw 0;
	}
}