#include "textfile.h"
#include <iterator>

TextFile::TextFile()
{
    
}

TextFile::~TextFile()
{
    if(file_.is_open())
    {
        file_.close();
    }
}

bool TextFile::Open(const std::string& path, bool binary)
{
    Close();

    if(binary)
    {
        file_.open(path.c_str(), std::fstream::in | std::fstream::out | std::fstream::binary);
    }
    else
    {
        file_.open(path.c_str(), std::fstream::in | std::fstream::out);
    }

    return file_.is_open();
}

void TextFile::Close()
{
    if(file_.is_open())
    {
        file_.close();
        file_.clear();
    }
}

bool TextFile::IsOpen() const
{
    file_.is_open();
}

bool TextFile::Read(std::vector<char>& data)
{
    if(file_.is_open())
    {
        std::copy(
            std::istream_iterator<char>(file_),
            std::istream_iterator<char>(),
            std::back_inserter(data));
        return true;
    }
    return false;
}

bool TextFile::Write(std::vector<char> data)
{
    if(file_.is_open())
    {
        file_.write(&data[0], data.size());
        return true;
    }
    return false;
}

bool TextFile::Read(std::vector<std::string>& data)
{
    std::string line;
    while(file_.is_open() && !file_.eof())
    {
        std::getline(file_, line);
        data.push_back(line);
    }
    return true;
}
