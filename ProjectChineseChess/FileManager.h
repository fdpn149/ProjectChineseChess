#pragma once
#include "Enums.h"
#include "Board.h"
namespace ProjectChineseChess
{
	using namespace System::IO;
	using System::DateTime;
	using System::Drawing::Point;
	using System::Windows::Forms::PictureBox;
	using System::String;
	ref class Board;
	ref class FileManager
	{
		DateTime^ date;
		String^ location;
		StreamWriter^ swriter;
		StreamReader^ sreader;
		PictureBox^ firstPiece;
		PictureBox^ secondPiece;
		Point^ secondPosition = gcnew Point();
		bool isFirst;
		void setLocation();  //�]�w��X�ɮת���m
	public:
		FileManager();
		~FileManager();
		void WriteLog(int player, PictureBox^ piece, Point^ fromPos, Point^ toPos);
		bool SetFile();  //�]�w��J�ɮת���m
		bool ReadLine(Board^ b);
		PictureBox^ GetFirstPiece();
		PictureBox^ GetSecondPiece();
		Point^ GetSecondPosition();
	};

}