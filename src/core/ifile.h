#pragma once

#include <cstdint>
#include <string>
#include <vector>

class IFile
{
public:
    IFile() = default;
    virtual bool Open(const std::string& path, bool binary = true) = 0;
    virtual void Close()                                    = 0;
    virtual bool IsOpen() const                             = 0;
    
    virtual bool Read(std::vector<char>& data)              = 0;
    virtual bool Write(std::vector<char> data)              = 0;
    virtual bool GetLines(std::vector<std::string>& data)   = 0;
    virtual bool WriteLines(std::vector<std::string>)       = 0;
protected:
    ~IFile() = default;
};
