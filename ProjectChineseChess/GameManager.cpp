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
		Chariot^ chariotB1 = gcnew Chariot(Player::BLACK, 1), ^ chariotB2 = gcnew Chariot(Player::BLACK, 2);
		Horse^ horseB1 = gcnew Horse(Player::BLACK, 1), ^ horseB2 = gcnew Horse(Player::BLACK, 2);
		Elephant^ elephantB1 = gcnew Elephant(Player::BLACK, 1), ^ elephantB2 = gcnew Elephant(Player::BLACK, 2);
		Advisor^ advisorB1 = gcnew Advisor(Player::BLACK, 1), ^ advisorB2 = gcnew Advisor(Player::BLACK, 2);
		Cannon^ cannonB1 = gcnew Cannon(Player::BLACK, 1), ^ cannonB2 = gcnew Cannon(Player::BLACK, 2);
		Soldier^ soldierB1 = gcnew Soldier(Player::BLACK, 1), ^ soldierB2 = gcnew Soldier(Player::BLACK, 2), ^ soldierB3 = gcnew Soldier(Player::BLACK, 3);
		Soldier^ soldierB4 = gcnew Soldier(Player::BLACK, 4), ^ soldierB5 = gcnew Soldier(Player::BLACK, 5);
		General^ generalB1 = gcnew General(Player::BLACK, 1), ^ generalR1 = gcnew General(Player::RED, 1);
		Chariot^ chariotR1 = gcnew Chariot(Player::RED, 1), ^ chariotR2 = gcnew Chariot(Player::RED, 2);
		Horse^ horseR1 = gcnew Horse(Player::RED, 1), ^ horseR2 = gcnew Horse(Player::RED, 2);
		Elephant^ elephantR1 = gcnew Elephant(Player::RED, 1), ^ elephantR2 = gcnew Elephant(Player::RED, 2);
		Advisor^ advisorR1 = gcnew Advisor(Player::RED, 1), ^ advisorR2 = gcnew Advisor(Player::RED, 2);
		Cannon^ cannonR1 = gcnew Cannon(Player::RED, 1), ^ cannonR2 = gcnew Cannon(Player::RED, 2);
		Soldier^ soldierR1 = gcnew Soldier(Player::RED, 1), ^ soldierR2 = gcnew Soldier(Player::RED, 2), ^ soldierR3 = gcnew Soldier(Player::RED, 3);
		Soldier^ soldierR4 = gcnew Soldier(Player::RED, 4), ^ soldierR5 = gcnew Soldier(Player::RED, 5);
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
		//若同一棋子被點兩下
		if (state == State::PIECE_CLICKED && lastClicked->Name == nowPiece->Name)
			state = State::NONE;
		//若點兩顆不同的棋子
		else if (state == State::PIECE_CLICKED)
		{
			state = State::MOVE_PIECE;
		}
		//若只點了一顆棋子
		else
			state = State::PIECE_CLICKED;
	}

	GameManager::GameManager()
	{
		viewer = gcnew Viewer();
		board = gcnew Board();
		pieceInit();
	}

	void GameManager::PieceClick(PictureBox^ piece)
	{
		changeState(piece);  //更改狀態
		//若要移動棋子
		if (state == State::MOVE_PIECE)
		{
			
		}
		//若只點一顆棋子
		else if (state == State::PIECE_CLICKED)
		{
			viewer->PieceClick(piece);  //讓棋子變色
			on_board[piece->Name]->CanMove(board,piece);
		}
		//若同一棋子被點兩下
		else
		{
			viewer->PieceUnclick(piece);  //將棋子顏色改回來
		}
		lastClicked = piece;  //上一個被點的棋子設成現在的棋子
	}

	void GameManager::FormClick()
	{
		//若有棋子已被點
		if (state == State::PIECE_CLICKED)
			viewer->PieceUnclick(lastClicked);  //將棋子顏改回來
		state = State::NONE;  //將狀態改回來
	}
}