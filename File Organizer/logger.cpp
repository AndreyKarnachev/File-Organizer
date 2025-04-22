#include "logger.h"
#include <fstream>
#include <ctime>

using namespace std;

void log_action(const string& from, const string& to) {
    ofstream log("log.txt", ios::app);										//open in append mode and add text to the end and put into log 
    time_t now = time(nullptr);												//show the time for the specific log

    char time_str[26];                                                      //creating an array for this format with the null position
                                                                            //Mon Jan 01 01:01:01 2025
    ctime_s(time_str, sizeof(time_str), &now);

    log << time_str << "Moved: " << from << " to " << to << "\n";
}