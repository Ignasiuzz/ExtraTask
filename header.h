#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cctype>
#include <iomanip>
#include <algorithm>

struct Data{
    int number;
    std::set<int> lines;
};

int main();
void ReadFile(std::string filename, std::map<std::string, Data>& map);
void ReadLink(std::string filename, std::map<int, std::string>& map);
std::vector<std::string> cleanline(std::string& line);
std::vector<std::string> getLink(std::string& line);
void Output(std::map<std::string, Data>& map);
void CrossReferenceTable(std::map<std::string, Data>& map);
void printLink(std::map<int, std::string>& map);

#endif