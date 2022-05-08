#pragma once

enum class State
{
	MOVE_PIECE, PIECE_CLICKED, NONE
};

enum class Piece
{
	CHARIOT_B1,HORSE_B1,ELEPHANT_B1, ADVISOR_B1,
	GENERAL_B, ADVISOR_B2, ELEPHANT_B2, HORSE_B2,
	CHARIOT_B2, CANNON_B1, CANNON_B2, SOLDIER_B1,
	SOLDIER_B2, SOLDIER_B3, SOLDIER_B4, SOLDIER_B5,
	CHARIOT_R1, HORSE_R1, ELEPHANT_R1, ADVISOR_R1,
	GENERAL_R, ADVISOR_R2, ELEPHANT_R2, HORSE_R2,
	CHARIOT_R2, CANNON_R1, CANNON_R2, SOLDIER_R1,
	SOLDIER_R2, SOLDIER_R3, SOLDIER_R4, SOLDIER_R5,
};

enum class Player
{
	RED, BLACK
};