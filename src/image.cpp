#include "image.h"

#define STB_IMAGE_IMPLEMENTATION
#include "image.inl"

Image::Image()
    : width_(0)
    , height_(0)
    , channels_(0)
{
}

Image::~Image()
{
    
}

bool Image::LoadFile(const std::string& filename)
{
    //TODO
    return false;
}

uint32_t Image::GetWidth() const
{
    return width_;
}

uint32_t Image::GetHeight() const
{
    return height_;
}

uint32_t Image::GetChannels() const
{
    return channels_;
}

const std::vector<uint8_t>& Image::GetData() const
{
    return data_;
}

void Image::CopyData(std::vector<uint8_t>& data) const
{
    data = data_;
}
