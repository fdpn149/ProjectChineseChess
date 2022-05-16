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
		//建立各種棋子的物件
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
		//將各種棋子的物件加進on_board
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
		//如果是綠色點
		if (nowPiece->Name == "green")
		{
			state = State::MOVE_PIECE;
			return;
		}

		if (state != State::PIECE_CLICKED)
		{
			//如果點的棋子跟現在輪到的顏色不一樣
			if ((current_player == 0 && on_board[nowPiece->Name]->PieceColor(nowPiece) == Color::BLACK) ||
				(current_player == 1 && on_board[nowPiece->Name]->PieceColor(nowPiece) == Color::RED))
			{
				state = State::NONE;
				return;
			}
		}

		//若同一棋子被點兩下
		if (state == State::PIECE_CLICKED && lastPiece->Name == nowPiece->Name)
			state = State::NONE;
		//若點兩顆不同的棋子
		else if (state == State::PIECE_CLICKED)
		{
			//尋找第二顆點的棋子是否是紅色
			for (int i = 0; i < red->size(); i++)
			{
				if (red->at(i) == nowPiece)  //如果有找到
				{
					state = State::MOVE_PIECE;
					return;
				}
			}
			//沒找到
			state = State::NONE;
		}
		//若只點了一顆棋子
		else
			state = State::PIECE_CLICKED;
	}

	bool GameManager::willCheck(Color color)
	{
		vector<PictureBox^>^ greenOrigin = gcnew vector<PictureBox^>;  //儲存原本綠色的vector
		vector<PictureBox^>^ redOrigin = gcnew vector<PictureBox^>;  //儲存原本紅色的vector
		greenOrigin->assign(green->begin(), green->end());  //複製綠色到原本綠色
		redOrigin->assign(red->begin(), red->end());  //複製紅色到原本紅色
		green->clear();  //清除綠色
		red->clear();  //清除紅色

		PictureBox^ fpiece;
		//找每一個棋子
		for each (GenericPair<String^, Chess^> ^ p in on_board)
		{
			//若找到要判斷的顏色
			if (p->second->color == color)
			{
				fpiece = board->FindPiece(p->first);
				if (fpiece != nullptr)
				{
					p->second->Move(board, fpiece);  //尋找可以走的路徑

					//查找紅色vector的元素
					for (int i = 0; i < red->size(); i++)
					{
						//若在紅色vector中有找到"將"或"帥"
						if (red->at(i)->Name[0] == 'g')
						{
							green->clear();  //清除綠色
							red->clear();  //清除紅色
							green->assign(greenOrigin->begin(), greenOrigin->end());  //將綠色vector設回原本的
							red->assign(greenOrigin->begin(), greenOrigin->end());  //將紅色vector設回原本的
							return true;
						}
					}
					green->clear();  //清除綠色
					red->clear();  //清除紅色
				}
			}
		}
		green->assign(greenOrigin->begin(), greenOrigin->end());  //將綠色vector設回原本的
		red->assign(redOrigin->begin(), redOrigin->end());  //將紅色vector設回原本的
		return false;
	}

	bool GameManager::opponentCanMove(Color color)
	{
		PictureBox^ fpiece;
		//找每一個棋子
		for each (GenericPair<String^, Chess^> ^ p in on_board)
		{
			//若找到敵方的顏色
			if (p->second->color != color)
			{
				fpiece = board->FindPiece(p->first);
				if (fpiece != nullptr)
				{
					p->second->Move(board, fpiece);  //尋找可以走的路徑
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
		vector<PictureBox^>^ greenOrigin = gcnew vector<PictureBox^>;  //儲存原本綠色的vector
		vector<PictureBox^>^ redOrigin = gcnew vector<PictureBox^>;  //儲存原本紅色的vector
		greenOrigin->assign(green->begin(), green->end());  //複製綠色到原本綠色
		redOrigin->assign(red->begin(), red->end());  //複製紅色到原本紅色
		green->clear();  //清除綠色
		red->clear();  //清除紅色

		Point^ nowPos = piece->Location;  //棋子現在的位置
		Color opponentColor = Chess::OpponentColor(piece);  //對手的顏色
		//找每一個綠點
		for (int i = 0; i < greenOrigin->size(); i++)
		{
			on_board[piece->Name]->OnMove(board, nowPos, greenOrigin->at(i)->Location);  //將棋子從現在位置移到綠點
			nowPos = greenOrigin->at(i)->Location;  //更改現在位置
			//如果會被對手將軍
			if (willCheck(opponentColor))
			{
				greenOrigin->erase(greenOrigin->begin() + i);  //移除綠點
				i--;
			}
		}
		on_board[piece->Name]->OnMove(board, nowPos, piece->Location);  //將棋子移回原本的位置
		PictureBox^ backupPiece;
		//找每一個紅點
		for (int i = 0; i < redOrigin->size(); i++)
		{
			backupPiece = redOrigin->at(i);  //備份紅點的棋子
			on_board[piece->Name]->OnMove(board, piece->Location, backupPiece->Location);  //將棋子從原本位置移到紅點
			nowPos = Board::ToBoardCoord(backupPiece->Location);
			//如果會被對手將軍
			if (willCheck(opponentColor))
			{
				redOrigin->erase(redOrigin->begin() + i);  //移除紅點
				i--;
			}
			on_board[piece->Name]->OnMove(board, backupPiece->Location, piece->Location);  //將棋子移回去
			board->board[nowPos->X, nowPos->Y] = backupPiece;
		}

		green->assign(greenOrigin->begin(), greenOrigin->end());  //將綠色vector設回原本的
		red->assign(redOrigin->begin(), redOrigin->end());  //將紅色vector設回原本的
	}

	bool GameManager::cross_river(PictureBox^ piece)
	{
		Point^ pos = Board::ToBoardCoord(piece->Location);

		if (Chess::PieceColor(piece) == Color::BLACK)  //如果是黑色
		{
			if (pos->Y >= 5)
				return true;
		}
		else  //如果是紅色
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
		changeState(piece);  //更改狀態
		//若要移動棋子
		if (state == State::MOVE_PIECE)
		{
			on_board[lastPiece->Name]->OnMove(board, lastPiece->Location, piece->Location);  //移動棋子
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
			viewer->PieceUnclick(lastPiece);  //將棋子顏色改回來
			viewer->RemoveGreens();  //移除綠色點
			viewer->RemoveReds();  //移除紅色點
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
					viewer->Label1Show("紅方將軍");
				else
					viewer->Label1Show("黑方將軍");
			}
			else if (!will_check && !opponent_can_move)  //欠行
			{
				if (pieceColor == Color::RED)
					viewer->Label1Show("紅方獲勝");
				else
					viewer->Label1Show("黑方獲勝");
				viewer->GameOver();
			}
			else if (will_check && !opponent_can_move)  //獲勝
			{
				if (pieceColor == Color::RED)
					viewer->Label1Show("紅方獲勝");
				else
					viewer->Label1Show("黑方獲勝");
				viewer->GameOver();
			}
			state = State::NONE;  //將狀態改回來
			current_player = !current_player;
		}
		//若只點一顆棋子
		else if (state == State::PIECE_CLICKED)
		{
			viewer->PieceClick(piece);  //讓棋子變色
			on_board[piece->Name]->Move(board, piece);  //尋找可以走的路徑
			findExactlyMove(piece);
			viewer->ShowGreens();  //顯示綠色點
			viewer->ShowReds();  //顯示紅色點
		}
		//若同一棋子被點兩下
		else
		{
			if (lastPiece != nullptr)
				viewer->PieceUnclick(lastPiece);  //將上個棋子的顏色改回來
			viewer->PieceUnclick(piece);  //將棋子顏色改回來
			viewer->RemoveGreens();  //移除綠色點
			viewer->RemoveReds();  //移除紅色點
		}
		lastPiece = piece;  //上一個被點的棋子設成現在的棋子
	}

	void GameManager::FormClick()
	{
		//若有棋子已被點
		if (state == State::PIECE_CLICKED)
			viewer->PieceUnclick(lastPiece);  //將棋子顏色改回來
		viewer->RemoveGreens();  //移除綠色點
		viewer->RemoveReds();  //移除紅色點
		state = State::NONE;  //將狀態改回來
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
			//on_board[lastPiece->Name]->Move(board, lastPiece);  //尋找可以走的路徑
			//for (int i = 0; i < red->size(); i++)
			//{
			//	if (red->at(i)->Name[0] == 'g')
			//	{
			//		check = true;
			//		if (on_board[lastPiece->Name]->color == Color::BLACK)
			//			viewer->Label1Show("黑方將軍");
			//		else
			//			viewer->Label1Show("紅方將軍");
			//		break;
			//	}
			//}
			//viewer->RemoveGreens();  //移除綠色點
			//viewer->RemoveReds();  //移除紅色點
			loading = false;
		}
		else
			throw 0;
	}
}