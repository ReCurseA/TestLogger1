#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <random>

#include "Logger.h"

const std::string currentDateTime() {
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}

void WriteInfoInBinaryFile(std::string &FileName, std::vector<double> &info){
    std::ofstream out(FileName, std::ios::app | std::ios::binary);
    if (out.is_open())
    {
        for (int j = 0; j < info.size(); j++) {
            double wr = info[j];
            out.write((char *) &wr, sizeof(double));
            /*std::string currentTime = currentDateTime();
            out.write((char *) &currentTime, sizeof(currentTime.size()));*/
        }
    }
    else
    {
        std::cout << "File isn't open" << std::endl;
    }
    out.close();
}

void GenerateRandomInfo(std::vector<double> & info, int size)
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator (seed);
    std::normal_distribution<double> distribution(0.0,1.0);

    for (int j = 0; j < size; j++)
    {
        double randNum = distribution(generator);
        info.push_back(randNum);
    }
}

int main() {
    std::vector<double> info;

    GenerateRandomInfo(info, 5);

    std::string FileName = "C:\\Users\\reuno\\CLionProjects\\RandomTests\\DifferentInfo.bin";

    WriteInfoInBinaryFile(FileName, info);

    return 0;
}
