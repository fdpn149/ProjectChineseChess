#pragma once
#include "Enums.h"
namespace ProjectChineseChess
{
	using namespace System::IO;
	using System::DateTime;
	using System::Drawing::Point;
	using System::Windows::Forms::PictureBox;
	using System::String;
	ref class FileManager
	{
		DateTime^ date;
		String^ location;
		StreamWriter^ swriter;
		StreamReader^ sreader;
		bool isFirst;
		void setLocation();
	public:
		FileManager();
		~FileManager();
		void WriteLog(int player, PictureBox^ piece, Point^ fromPos, Point^ toPos);
	};

}