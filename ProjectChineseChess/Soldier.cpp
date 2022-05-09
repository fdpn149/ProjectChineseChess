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
        
        //�p�G�O"�L"
        if (this->player == Player::RED)
        {
            if (crossedRiver)  //�p�G�w�g�L�e
            {

            }
            else  //�p�G�|���L�e
            {

            }
        }
        //�p�G�O"��"
        else
        {
            if (crossedRiver)  //�p�G�w�g�L�e
            {

            }
            else  //�p�G�|���L�e
            {

            }
        }
    }
}