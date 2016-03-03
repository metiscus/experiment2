#pragma once

#include <cstdint>
#include <string>
#include <vector>

class Image
{
public:
    Image();
    ~Image();
    
    bool LoadFile(const std::string& filename);
    uint32_t GetWidth() const;
    uint32_t GetHeight() const;
    uint32_t GetChannels() const;
    const std::vector<uint8_t>& GetData() const;
    void CopyData(std::vector<uint8_t>& data) const;
    
private:
    uint32_t width_;
    uint32_t height_;
    uint32_t channels_;
    
    std::vector<uint8_t> data_;
};
