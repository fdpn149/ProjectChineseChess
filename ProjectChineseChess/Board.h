#pragma once

using System::Windows::Forms::PictureBox;
using System::Drawing::Point;

namespace ProjectChineseChess {
	//�ѽL
	ref class Board
	{
	public:
		array<PictureBox^, 2>^ board = gcnew array<PictureBox^, 2>(9, 10);
		Board();
		Point^ ToBoardCoord(Point^ formCoord);
	};
}