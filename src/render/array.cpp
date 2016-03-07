#include "array.h"
#include <GL/gl.h>

Array::Array(Type type)
    : type_(type)
{
    switch(type)
    {
        case UByteArrayType:
            data_size_ = 1;
            data_type_ = GL_UNSIGNED_BYTE;
            break;
        case UShortArrayType:
            data_size_ = sizeof(short);
            data_type_ = GL_UNSIGNED_SHORT;
            break;
        case UIntArrayType:
            data_size_ = sizeof(unsigned);
            data_type_ = GL_UNSIGNED_INT;
            break;
        case ByteArrayType:
            data_size_ = 1;
            data_type_ = GL_BYTE;
            break;
        case ShortArrayType:
            data_size_ = sizeof(short);
            data_type_ = GL_SHORT;
            break;
        case IntArrayType:
            data_size_ = sizeof(int);
            data_type_ = GL_INT;
            break;
        case FloatArrayType:
            data_size_ = sizeof(float);
            data_type_ = GL_FLOAT;
            break;
        case Vector2Type:
            data_size_ = 2*sizeof(float);
            data_type_ = GL_BYTE;
            break;
        case Vector3Type:
            data_size_ = 3*sizeof(float);
            data_type_ = GL_BYTE;
            break;
        case Vector4Type:
            data_size_ = 4*sizeof(float);
            data_type_ = GL_BYTE;
            break;
    }
}

Array::Type Array::GetType() const
{
    return type_;
}

uint32_t Array::GetDataSize() const
{
    return data_size_;
}

uint32_t Array::GetDataType() const
{
    return data_type_;
}

