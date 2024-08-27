#ifndef FILE_SYSTEM_H
#define FILE_SYSTEM_H

#include <fstream>
#include <ostream>
#include <iostream>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

class WriteFileSystem
{
private:
    fs::path myPath;
    void CreateOrOpenExistingFile();

public:
    WriteFileSystem();
    WriteFileSystem(fs::path defaultPath);
    void AppendToEndOfFile(std::string data);
};

class ReadFileSystem
{
private:
    fs::path myPath;

public:
    ReadFileSystem();
    ReadFileSystem(fs::path defaultPath);
    void OpenFile();
    void CloseFile();
    std::string ReadLine();
    std::string ReadWholeFile();
};

#endif