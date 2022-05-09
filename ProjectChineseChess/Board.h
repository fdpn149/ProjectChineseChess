#pragma once

using System::Windows::Forms::PictureBox;

namespace ProjectChineseChess {
	//´Ñ½L
	ref class Board
	{
	public:
		array<PictureBox^, 2>^ board = gcnew array<PictureBox^, 2>(9, 10);
		Board();
	};

}