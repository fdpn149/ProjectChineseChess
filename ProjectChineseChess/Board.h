#pragma once

using System::Windows::Forms::PictureBox;
using System::Drawing::Point;
using System::String;

namespace ProjectChineseChess {
	//´Ñ½L
	ref class Board
	{
	public:
		array<PictureBox^, 2>^ board = gcnew array<PictureBox^, 2>(9, 10);
		Board();
		static Point^ ToBoardCoord(Point^ formCoord);
		static Point^ ToFormCoord(Point^ boardCoord);
		PictureBox^ FindPiece(String^ name);
	};
}