
#ifndef TESTLOGGER1_LOGGER_H
#define TESTLOGGER1_LOGGER_H

#include "iostream"
#include <vector>
#include <map>
#include <fstream>

class Logger {
public:
    Logger();
    ~Logger();

    void LogToFile(const char *FileName, std::vector<double> &values, bool isBinary);

private:
    void AddOutputStream(const char *FileName, bool isBinary);

    bool IsStreamExist(const char *FileName);

    std::map<std::string, std::fstream> OutputStreams;
};

#endif //TESTLOGGER1_LOGGER_H
