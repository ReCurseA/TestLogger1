
#include "Logger.h"

#include <iostream>
#include <map>

Logger::Logger() {
    OutputStreams.clear();
}

Logger::~Logger() {
    for (auto it = OutputStreams.begin(); it != OutputStreams.end(); it++){
        it->second.close();
    }
}

void Logger::LogToFile(const char *FileName, std::vector<double> &values, bool isBinary) {

}

void Logger::AddOutputStream(const char *FileName, bool isBinary) {
    if(!IsStreamExist(FileName))
    {
        std::ofstream out;
        if (isBinary)
        {
            std::ofstream out(FileName, std::ios::out | std::ios::binary);
        }
        else
        {
            std::ofstream out(FileName, std::ios::app);
        }

        OutputStreams.insert(std::make_pair<std::string, std::fstream> (FileName, out));
    }
    else
    {
        std::cout << "Output stream for file " << std::string(FileName)
    }
}

bool Logger::IsStreamExist(const char *FileName) {
    return (OutputStreams.lower_bound(FileName) != OutputStreams.end());
}