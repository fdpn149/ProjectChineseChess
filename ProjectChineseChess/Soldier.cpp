#include "Soldier.h"
#include "GameManager.h"
namespace ProjectChineseChess
{
    Soldier::Soldier(Player player, int id) : Chess(player, id)
    {
        crossedRiver = false;
    }
    void Soldier::CanMove(Board^ board, PictureBox^ piece)
    {
        Point^ pos = board->ToBoardCoord(piece->Location);
        
        //如果是"兵"
        if (this->player == Player::RED)
        {
            if (crossedRiver)  //如果已經過河
            {

            }
            else  //如果尚未過河
            {

            }
        }
        //如果是"卒"
        else
        {
            if (crossedRiver)  //如果已經過河
            {

            }
            else  //如果尚未過河
            {

            }
        }
    }
}