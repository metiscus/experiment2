#pragma once
#include <cstdint>
#include <memory>
#include <vector>

class Array
{
public:
    enum Type
    {
        UByteArrayType,
        UShortArrayType,
        UIntArrayType,
        ByteArrayType,
        ShortArrayType,
        IntArrayType,
        FloatArrayType,
        Vector2Type,
        Vector3Type,
        Vector4Type
    };
    
    Array(Type type);
    
    Type     GetType() const;
    uint32_t GetDataSize() const;
    uint32_t GetDataType() const;

    virtual uint32_t GetNumElements() const = 0;
    virtual uint32_t GetTotalDataSize() const = 0;
    virtual uint8_t* GetDataPointer() = 0;

protected:
    Type type_;
    uint32_t data_size_;
    uint32_t data_type_;
    
    virtual ~Array() { };
    Array& operator=(Array& rhs) = delete;
};

template <typename T, Array::Type ARRAYTYPE>
class TemplateArray : public Array
{
public:
    TemplateArray()
        : Array(ARRAYTYPE)
    {
        
    }
    
    virtual uint32_t GetNumElements() const
    {
        return data_.size();
    }

    virtual uint32_t GetTotalDataSize() const
    {
        return data_.size() * GetDataSize();
    }
    
    virtual T* GetDataPointer()
    {
        return &data_[0];
    }
    
    void Resize(uint32_t size)
    {
        data_.resize(size);
    }
    
    void Reserve(uint32_t size)
    {
        data_.reserve(size);
    }
private:
    std::vector<T> data_;
};

typedef std::shared_ptr<Array> ArrayPtr;
