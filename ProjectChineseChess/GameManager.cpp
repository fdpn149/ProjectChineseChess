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
			check = false;
			viewer->Label1Hide();
			//Color pieceColor = on_board[piece->Name]->PieceColor(piece);  //棋子的顏色
			on_board[lastPiece->Name]->OnMove(board, lastPiece->Location, piece->Location);  //移動棋子
			if (!loading) fmanager->WriteLog(current_player + 1, lastPiece, lastPiece->Location, piece->Location);
			if (piece->Name != "green")
			{
				viewer->RemovePiece(piece);
				on_board.erase(piece->Name);
			}
			viewer->SetPiece(lastPiece, piece->Location);
			viewer->PieceUnclick(lastPiece);  //將棋子顏色改回來
			viewer->RemoveGreens();  //移除綠色點
			viewer->RemoveReds();  //移除紅色點
			on_board[lastPiece->Name]->Move(board, lastPiece);  //尋找可以走的路徑
			for (int i = 0; i < red->size(); i++)
			{
				if (red->at(i)->Name[0] == 'g')
				{
					check = true;
					if (on_board[lastPiece->Name]->color == Color::BLACK)
						viewer->Label1Show("黑方將軍");
					else
						viewer->Label1Show("紅方將軍");
					break;
				}
			}
			viewer->RemoveGreens();  //移除綠色點
			viewer->RemoveReds();  //移除紅色點
			//找每個自己的棋子可以走的路徑
			for each (GenericPair<String^, Chess^> ^ p in on_board)
			{
				bool willCheck = false;  //是否會被將軍
				//若是己方的棋子
				if (p->second->color == on_board[lastPiece->Name]->PieceColor(piece))
				{
					p->second->Move(board, board->FindPiece(p->first));  //尋找可以走的路徑
					for (int j = 0; j < red->size(); j++)
					{
						if (red->at(j)->Name[0] == 'g')
						{
							willCheck = true;
							check = true;
							if (on_board[lastPiece->Name]->color == Color::BLACK)
								viewer->Label1Show("黑方將軍");
							else
								viewer->Label1Show("紅方將軍");
							break;
						}
					}
					green->clear();  //清除綠色
					red->clear();  //清除紅色
				}
				if (willCheck)
					break;
			}
			green->clear();  //清除綠色
			red->clear();  //清除紅色

			state = State::NONE;  //將狀態改回來
			current_player = !current_player;
		}
		//若只點一顆棋子
		else if (state == State::PIECE_CLICKED)
		{
			viewer->PieceClick(piece);  //讓棋子變色
			on_board[piece->Name]->Move(board, piece);  //尋找可以走的路徑
			Point^ nowPosition = piece->Location;  //保存棋子現在的位置
			vector<PictureBox^>^ greenBak = gcnew vector<PictureBox^>;  //備份現在綠色的陣列
			vector<PictureBox^>^ redBak = gcnew vector<PictureBox^>;  //備份現在紅色的陣列
			greenBak->assign(green->begin(), green->end());  //複製綠色到綠色備份
			redBak->assign(red->begin(), red->end());  //複製紅色到紅色備份
			green->clear();  //清除綠色
			red->clear();  //清除紅色
			Color pieceColor = on_board[piece->Name]->PieceColor(piece);  //棋子的顏色
			for (int i = 0; i < greenBak->size(); i++)
			{
				on_board[piece->Name]->OnMove(board, nowPosition, greenBak->at(i)->Location);  //移動棋子到綠色點
				nowPosition = greenBak->at(i)->Location;  //設定棋子現在的位置

				//找每個對手的棋子可以走的路徑
				for each (GenericPair<String^, Chess^> ^ p in on_board)
				{
					bool willCheck = false;
					//若是對手的棋子
					if (p->second->color != pieceColor)
					{
						p->second->Move(board, board->FindPiece(p->first));  //尋找可以走的路徑
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
						green->clear();  //清除綠色
						red->clear();  //清除紅色
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
					on_board[piece->Name]->OnMove(board, piece->Location, redBak->at(i)->Location);  //移動棋子到紅色點

					//找每個對手的棋子可以走的路徑
					for each (GenericPair<String^, Chess^> ^ p in on_board)
					{
						bool willCheck = false;  //是否會被將軍
						//若是對手的棋子
						if (p->second->color != pieceColor)
						{
							PictureBox^ find = board->FindPiece(p->first);
							if (find != nullptr)
							{
								p->second->Move(board, find);  //尋找可以走的路徑
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
							green->clear();  //清除綠色
							red->clear();  //清除紅色
						}
						if (willCheck)
							break;
					}
					on_board[piece->Name]->OnMove(board, bak->Location, piece->Location);  //將棋子移回去
					Point^ pos = Board::ToBoardCoord(bak->Location);
					board->board[pos->X, pos->Y] = bak;
				}
			}
			green->assign(greenBak->begin(), greenBak->end());  //複製綠色到綠色備份
			red->assign(redBak->begin(), redBak->end());  //複製紅色到紅色備份
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