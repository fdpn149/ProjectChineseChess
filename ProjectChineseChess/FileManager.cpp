#include "FileManager.h"
#include "Viewer.h"
#include "Board.h"
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
                + piece->Name[0].ToUpper(piece->Name[0]) + piece->Name->Substring(1,piece->Name->Length-3) + " (" + fromBoardPos->X + ", " + fromBoardPos->Y + ") -> ("
                + toBoardPos->X + ", " + toBoardPos->Y + ")");
            swriter->Close();
        }
        catch (...)
        {
            Viewer v;
            v.ShowMessage("檔案無法寫入");
        }
    }

}