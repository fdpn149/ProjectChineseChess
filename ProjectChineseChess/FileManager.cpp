#include "FileManager.h"
#include "Viewer.h"
namespace ProjectChineseChess
{
	void FileManager::setLocation()
	{
		date = DateTime::UtcNow;
		date = date->AddHours(8);
		date = date->AddYears(-1911);
		location = "log_" + date->Year.ToString("D3") + date->Month.ToString("D2") + date->Day.ToString("D2") +
			date->Hour.ToString("D2") + date->Minute.ToString("D2") + date->Second.ToString("D2") + ".txt";
		swriter = gcnew StreamWriter(location);
	}

	FileManager::FileManager()
	{
		isFirst = true;
	}

	FileManager::~FileManager()
	{
		swriter->Close();
		sreader->Close();
	}

	void FileManager::WriteLog(int player, PictureBox^ piece, Point^ fromPos, Point^ toPos)
	{
		try
		{
			if (isFirst)
			{
				setLocation();
				isFirst = false;
			}
			else
				swriter = File::AppendText(location);
			Point^ fromBoardPos = Board::ToBoardCoord(fromPos);
			Point^ toBoardPos = Board::ToBoardCoord(toPos);
			swriter->WriteLine("Player: " + player + ", Action: "
				+ piece->Name[0].ToUpper(piece->Name[0]) + piece->Name->Substring(1, piece->Name->Length - 3) + " (" + fromBoardPos->X + ", " + fromBoardPos->Y + ") -> ("
				+ toBoardPos->X + ", " + toBoardPos->Y + ")");
			swriter->Close();
		}
		catch (...)
		{
			Viewer v;
			v.ShowMessage("檔案無法寫入");
		}
	}

	bool FileManager::SetFile()
	{
		try
		{
			System::Windows::Forms::OpenFileDialog^ fileDialog = gcnew  System::Windows::Forms::OpenFileDialog();
			fileDialog->Filter = "Text File Only|*.txt";

			if (fileDialog->ShowDialog().Equals(System::Windows::Forms::DialogResult::OK))
			{
				sreader = gcnew StreamReader(fileDialog->FileName);
				location = fileDialog->FileName;
				isFirst = false;
				return true;
			}
		}
		catch (...)
		{
			Viewer v;
			v.ShowMessage("檔案無法開啟");
		}
		return false;
	}

	bool FileManager::ReadLine(Board^ b)
	{
		String^ nowStr;
		nowStr = sreader->ReadLine();
		if (nowStr == nullptr)
		{
			sreader->Close();
			return false;
		}

		firstPiece = b->board[nowStr[nowStr->Length - 15] - '0', nowStr[nowStr->Length - 12] - '0'];
		secondPiece = b->board[nowStr[nowStr->Length - 5] - '0', nowStr[nowStr->Length - 2] - '0'];
		secondPosition->X = nowStr[nowStr->Length - 5] - '0';
		secondPosition->Y = nowStr[nowStr->Length - 2] - '0';
		secondPosition = Board::ToFormCoord(secondPosition);

		return true;
	}
	PictureBox^ FileManager::GetFirstPiece()
	{
		return firstPiece;
	}
	PictureBox^ FileManager::GetSecondPiece()
	{
		return secondPiece;
	}
	Point^ FileManager::GetSecondPosition()
	{
		return secondPosition;
	}
}