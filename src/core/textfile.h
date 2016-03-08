#pragma once
#include <cstdint>
#include <fstream>
#include <vector>

#include "ifile.h"

class TextFile : public IFile
{
public:
    TextFile();
    ~TextFile();
    virtual bool Open(const std::string& path, bool binary = true);
    virtual void Close();
    virtual bool IsOpen() const;
    
    virtual bool Read(std::vector<char>& data);
    virtual bool Write(std::vector<char> data);

private:
    std::fstream file_;
};
