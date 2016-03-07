#include <core/vector2.h>
#include <core/vector3.h>
#include <core/vector4.h>
#include <cmath>
#include <cstdio>

#define TestAssert(cond)                                \
    if((!(cond))){                                      \
        fprintf(stderr, "[%s:%d]:\tTest: '%s' failed!\n", __FILE__, __LINE__, #cond); \
        ++ret;                                          \
    }                                                   \

int ret = 0;
int main(int argc, char** argv)
{
    const float SmallError = 0.001f;
    
    // Test Vector2d
    {
        const Vector2 x_axis_2d (1,0);
        const Vector2 y_axis_2d (0,1);
        TestAssert(fabs(x_axis_2d.Dot(y_axis_2d)) < SmallError);
        TestAssert(fabs(y_axis_2d.Dot(x_axis_2d)) < SmallError);
        TestAssert(fabs(fabs(x_axis_2d.Dot(x_axis_2d)) - 1.0f) < SmallError);
        Vector2 tmp_2d = x_axis_2d + y_axis_2d;
        TestAssert(fabs(tmp_2d.Length() - sqrtf(2.0)) < SmallError);
        TestAssert(fabs(x_axis_2d.Dot(tmp_2d) - y_axis_2d.Dot(tmp_2d)) < SmallError);
        tmp_2d = 5.0f * x_axis_2d;
        TestAssert(fabs(tmp_2d.Length2() - 25.0) < SmallError);
        tmp_2d.x = 1;
        tmp_2d.y = 2;
        TestAssert(fabs(tmp_2d[0] - tmp_2d.x) < SmallError);
        TestAssert(fabs(tmp_2d[1] - tmp_2d.y) < SmallError);
    }
    
    {
        // Test Vector3d
        const Vector3 x_axis_3d (1,0,0);
        const Vector3 y_axis_3d (0,1,0);
        const Vector3 z_axis_3d (0,0,1);
        TestAssert(fabs(x_axis_3d.Dot(y_axis_3d)) < SmallError);
        TestAssert(fabs(x_axis_3d.Dot(z_axis_3d)) < SmallError);
        TestAssert(fabs(y_axis_3d.Dot(z_axis_3d)) < SmallError);
        TestAssert(fabs(fabs(x_axis_3d.Dot(x_axis_3d)) - 1.0f) < SmallError);
        TestAssert(fabs(fabs(y_axis_3d.Dot(y_axis_3d)) - 1.0f) < SmallError);
        TestAssert(fabs(fabs(z_axis_3d.Dot(z_axis_3d)) - 1.0f) < SmallError);
        
        Vector3 tmp_3d = x_axis_3d + y_axis_3d + z_axis_3d;
        TestAssert(fabs(tmp_3d.Length() - sqrtf(3.0)) < SmallError);
        TestAssert(fabs(x_axis_3d.Dot(tmp_3d) - y_axis_3d.Dot(tmp_3d)) < SmallError);
        TestAssert(fabs(x_axis_3d.Dot(tmp_3d) - z_axis_3d.Dot(tmp_3d)) < SmallError);
        TestAssert(fabs(y_axis_3d.Dot(tmp_3d) - z_axis_3d.Dot(tmp_3d)) < SmallError);

        tmp_3d = 5.0f*x_axis_3d + 2.0*y_axis_3d + z_axis_3d;
        TestAssert(fabs(tmp_3d.Length2() - 30.0) < SmallError);
        tmp_3d.ToUnit();
        TestAssert(fabs(tmp_3d.Length() - 1.0) < SmallError);
        
        tmp_3d.x = 1;
        tmp_3d.y = 2;
        tmp_3d.z = 3;
        TestAssert(fabs(tmp_3d[0] - tmp_3d.x) < SmallError);
        TestAssert(fabs(tmp_3d[1] - tmp_3d.y) < SmallError);
        TestAssert(fabs(tmp_3d[2] - tmp_3d.z) < SmallError);
        
        tmp_3d.ToUnit();
        TestAssert(tmp_3d.Dot(x_axis_3d) < tmp_3d.Dot(y_axis_3d));
        TestAssert(tmp_3d.Dot(y_axis_3d) < tmp_3d.Dot(z_axis_3d));
    }
    
    {
        // Test Vector4d
        // Test Vector3d
        const Vector4 x_axis_4d (0,1,0,0);
        const Vector4 y_axis_4d (0,0,1,0);
        const Vector4 z_axis_4d (0,0,0,1);
        TestAssert(fabs(x_axis_4d.Dot(y_axis_4d)) < SmallError);
        TestAssert(fabs(x_axis_4d.Dot(z_axis_4d)) < SmallError);
        TestAssert(fabs(y_axis_4d.Dot(z_axis_4d)) < SmallError);
        TestAssert(fabs(fabs(x_axis_4d.Dot(x_axis_4d)) - 1.0f) < SmallError);
        TestAssert(fabs(fabs(y_axis_4d.Dot(y_axis_4d)) - 1.0f) < SmallError);
        TestAssert(fabs(fabs(z_axis_4d.Dot(z_axis_4d)) - 1.0f) < SmallError);
        
        Vector4 tmp_4d = x_axis_4d + y_axis_4d + z_axis_4d;
        TestAssert(fabs(tmp_4d.Length() - sqrtf(3.0)) < SmallError);
        TestAssert(fabs(x_axis_4d.Dot(tmp_4d) - y_axis_4d.Dot(tmp_4d)) < SmallError);
        TestAssert(fabs(x_axis_4d.Dot(tmp_4d) - z_axis_4d.Dot(tmp_4d)) < SmallError);
        TestAssert(fabs(y_axis_4d.Dot(tmp_4d) - z_axis_4d.Dot(tmp_4d)) < SmallError);

        tmp_4d = 5.0f*x_axis_4d + 2.0*y_axis_4d + z_axis_4d;
        TestAssert(fabs(tmp_4d.Length2() - 30.0) < SmallError);
        tmp_4d.ToUnit();
        TestAssert(fabs(tmp_4d.Length() - 1.0) < SmallError);
        
        tmp_4d.x = 1;
        tmp_4d.y = 2;
        tmp_4d.z = 3;
        TestAssert(fabs(tmp_4d[1] - tmp_4d.x) < SmallError);
        TestAssert(fabs(tmp_4d[2] - tmp_4d.y) < SmallError);
        TestAssert(fabs(tmp_4d[3] - tmp_4d.z) < SmallError);
        
        tmp_4d.ToUnit();
        TestAssert(tmp_4d.Dot(x_axis_4d) < tmp_4d.Dot(y_axis_4d));
        TestAssert(tmp_4d.Dot(y_axis_4d) < tmp_4d.Dot(z_axis_4d));
        
        // rotations
        Vector3 y_axis(0, 1, 0);
        Vector3 rotateVec(1, 0, 0);
        Vector4 tmp = Vector4::AngleAxis(M_PI_2, Vector3(0, 0, 1));
        rotateVec = tmp.Rotate(rotateVec);
        TestAssert(fabs(y_axis.Dot(rotateVec) - 1.0) < SmallError);
    }
    return ret;
}
