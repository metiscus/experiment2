#pragma once

#include <cstdint>
#include <cfloat>

#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtc/quaternion.hpp"
#include "glm/gtx/quaternion.hpp"
#include "glm/gtx/euler_angles.hpp"
#include "glm/gtx/norm.hpp"
#include "glm/gtc/matrix_transform.hpp"

typedef glm::vec2 Vector2;
typedef glm::vec3 Vector3;
typedef glm::vec4 Vector4;
typedef glm::quat Quaternion;
typedef glm::mat3 Matrix3;
typedef glm::mat4 Matrix4;

using glm::cross;
using glm::dot;
using glm::distance;
using glm::length;
using glm::normalize;
