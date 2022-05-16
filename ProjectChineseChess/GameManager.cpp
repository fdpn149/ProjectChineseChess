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
		//�p�G�O����I
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

	bool GameManager::willCheck(Color color)
	{
		vector<PictureBox^>^ greenOrigin = gcnew vector<PictureBox^>;  //�x�s�쥻��⪺vector
		vector<PictureBox^>^ redOrigin = gcnew vector<PictureBox^>;  //�x�s�쥻���⪺vector
		greenOrigin->assign(green->begin(), green->end());  //�ƻs����쥻���
		redOrigin->assign(red->begin(), red->end());  //�ƻs�����쥻����
		green->clear();  //�M�����
		red->clear();  //�M������

		PictureBox^ fpiece;
		//��C�@�ӴѤl
		for each (GenericPair<String^, Chess^> ^ p in on_board)
		{
			//�Y���n�P�_���C��
			if (p->second->color == color)
			{
				fpiece = board->FindPiece(p->first);
				if (fpiece != nullptr)
				{
					p->second->Move(board, fpiece);  //�M��i�H�������|

					//�d�����vector������
					for (int i = 0; i < red->size(); i++)
					{
						//�Y�b����vector�������"�N"��"��"
						if (red->at(i)->Name[0] == 'g')
						{
							green->clear();  //�M�����
							red->clear();  //�M������
							green->assign(greenOrigin->begin(), greenOrigin->end());  //�N���vector�]�^�쥻��
							red->assign(greenOrigin->begin(), greenOrigin->end());  //�N����vector�]�^�쥻��
							return true;
						}
					}
					green->clear();  //�M�����
					red->clear();  //�M������
				}
			}
		}
		green->assign(greenOrigin->begin(), greenOrigin->end());  //�N���vector�]�^�쥻��
		red->assign(redOrigin->begin(), redOrigin->end());  //�N����vector�]�^�쥻��
		return false;
	}

	bool GameManager::opponentCanMove(Color color)
	{
		PictureBox^ fpiece;
		//��C�@�ӴѤl
		for each (GenericPair<String^, Chess^> ^ p in on_board)
		{
			//�Y���Ĥ誺�C��
			if (p->second->color != color)
			{
				fpiece = board->FindPiece(p->first);
				if (fpiece != nullptr)
				{
					p->second->Move(board, fpiece);  //�M��i�H�������|
					findExactlyMove(fpiece);
					if (!green->empty())
					{
						green->clear();
						red->clear();
						return true;
					}
				}
			}
		}
		green->clear();
		red->clear();
		return false;
	}

	void GameManager::findExactlyMove(PictureBox^ piece)
	{
		vector<PictureBox^>^ greenOrigin = gcnew vector<PictureBox^>;  //�x�s�쥻��⪺vector
		vector<PictureBox^>^ redOrigin = gcnew vector<PictureBox^>;  //�x�s�쥻���⪺vector
		greenOrigin->assign(green->begin(), green->end());  //�ƻs����쥻���
		redOrigin->assign(red->begin(), red->end());  //�ƻs�����쥻����
		green->clear();  //�M�����
		red->clear();  //�M������

		Point^ nowPos = piece->Location;  //�Ѥl�{�b����m
		Color opponentColor = Chess::OpponentColor(piece);  //��⪺�C��
		//��C�@�Ӻ��I
		for (int i = 0; i < greenOrigin->size(); i++)
		{
			on_board[piece->Name]->OnMove(board, nowPos, greenOrigin->at(i)->Location);  //�N�Ѥl�q�{�b��m������I
			nowPos = greenOrigin->at(i)->Location;  //���{�b��m
			//�p�G�|�Q���N�x
			if (willCheck(opponentColor))
			{
				greenOrigin->erase(greenOrigin->begin() + i);  //�������I
				i--;
			}
		}
		on_board[piece->Name]->OnMove(board, nowPos, piece->Location);  //�N�Ѥl���^�쥻����m
		PictureBox^ backupPiece;
		//��C�@�Ӭ��I
		for (int i = 0; i < redOrigin->size(); i++)
		{
			backupPiece = redOrigin->at(i);  //�ƥ����I���Ѥl
			on_board[piece->Name]->OnMove(board, piece->Location, backupPiece->Location);  //�N�Ѥl�q�쥻��m������I
			nowPos = Board::ToBoardCoord(backupPiece->Location);
			//�p�G�|�Q���N�x
			if (willCheck(opponentColor))
			{
				redOrigin->erase(redOrigin->begin() + i);  //�������I
				i--;
			}
			on_board[piece->Name]->OnMove(board, backupPiece->Location, piece->Location);  //�N�Ѥl���^�h
			board->board[nowPos->X, nowPos->Y] = backupPiece;
		}

		green->assign(greenOrigin->begin(), greenOrigin->end());  //�N���vector�]�^�쥻��
		red->assign(redOrigin->begin(), redOrigin->end());  //�N����vector�]�^�쥻��
	}

	bool GameManager::cross_river(PictureBox^ piece)
	{
		Point^ pos = Board::ToBoardCoord(piece->Location);

		if (Chess::PieceColor(piece) == Color::BLACK)  //�p�G�O�¦�
		{
			if (pos->Y >= 5)
				return true;
		}
		else  //�p�G�O����
		{
			if (pos->Y <= 4)
				return true;
		}
		return false;
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
			on_board[lastPiece->Name]->OnMove(board, lastPiece->Location, piece->Location);  //���ʴѤl
			check = false;
			viewer->Label1Hide();
			if (!loading)
				fmanager->WriteLog(current_player + 1, lastPiece, lastPiece->Location, piece->Location);
			if (piece->Name != "green")
			{
				viewer->RemovePiece(piece);
				on_board.erase(piece->Name);
			}
			viewer->SetPiece(lastPiece, piece->Location);
			viewer->PieceUnclick(lastPiece);  //�N�Ѥl�C���^��
			viewer->RemoveGreens();  //��������I
			viewer->RemoveReds();  //���������I
			if (lastPiece->Name->Substring(0, 7) == "soldier")
			{
				if (cross_river(lastPiece))
					on_board[lastPiece->Name]->SetCrossRiver();
			}

			Color pieceColor = Chess::PieceColor(lastPiece);
			bool will_check = willCheck(pieceColor);
			bool opponent_can_move = opponentCanMove(pieceColor);
			if (will_check && opponent_can_move)
			{
				check = true;
				if (pieceColor == Color::RED)
					viewer->Label1Show("����N�x");
				else
					viewer->Label1Show("�¤�N�x");
			}
			else if (!will_check && !opponent_can_move)  //���
			{
				if (pieceColor == Color::RED)
					viewer->Label1Show("�������");
				else
					viewer->Label1Show("�¤����");
				viewer->GameOver();
			}
			else if (will_check && !opponent_can_move)  //���
			{
				if (pieceColor == Color::RED)
					viewer->Label1Show("�������");
				else
					viewer->Label1Show("�¤����");
				viewer->GameOver();
			}
			state = State::NONE;  //�N���A��^��
			current_player = !current_player;
		}
		//�Y�u�I�@���Ѥl
		else if (state == State::PIECE_CLICKED)
		{
			viewer->PieceClick(piece);  //���Ѥl�ܦ�
			on_board[piece->Name]->Move(board, piece);  //�M��i�H�������|
			findExactlyMove(piece);
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