#include "organizer.h"
#include "logger.h"
#include <filesystem>
#include <map>
#include <string>

using namespace std;
namespace fs = std::filesystem;

void organize_files(const string& folder_path) {
    map<string, string> extension_map = {
        {".jpg", "Images"}, {".png", "Images"},
        {".txt", "Documents"}, {".pdf", "Documents"},
        {".doc", "Documents"}, {".docx", "Documents"},                                  // Word
        {".xls", "Documents"}, {".xlsx", "Documents"},                                  // Excel
        {".ppt", "Documents"}, {".pptx", "Documents"},                                  // PowerPoint
        {".mp3", "Music"}, {".mp4", "Videos"},
        {".zip", "Archives"}
    };
                                                                                        //auto for ffs::entry   
    for (const auto& entry : fs::directory_iterator(folder_path)) {                     //fs::directory_iterator used to loop  trough the files in a folder 
        if (!entry.is_regular_file()) continue;                                         //skip  unwanted things like directories 
        
		auto ext = entry.path().extension().string();                                   //get the file extension
		string category = extension_map.count(ext) ? extension_map[ext] : "Left out";   //get the category of the file based on the extension 
		
		fs::path new_dir = fs::path(folder_path) / category;                            //create a new folder path based on the specific category
        fs::create_directories(new_dir);

        fs::path target = new_dir / entry.path().filename();                            //move to  the correct folder //both this and next line   
        fs::rename(entry.path(), target);

        log_action(entry.path().string(), target.string());                             //convert both into strings with .string()
    }

    cout << "Files successfully organized, next time do it yourself :)!\n";

}