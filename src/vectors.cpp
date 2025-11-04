#include "vectors.h"

vec2::vec2(float x_, float y_){
    x = x_; y = y_;
}

vec2 vec2::operator* (float scale){
    return vec2(x * scale, y * scale);
}

vec2 vec2::operator*= (float scale){
    return vec2(x *= scale, y *= scale);
}

vec2 vec2::operator* (vec2 vec){
    return vec2(x * vec.x, y * vec.y);
}

vec2 vec2::operator*= (vec2 vec){
    return vec2(x *= vec.x, y *= vec.y);
}

vec2 vec2::operator+ (vec2 vec){
    return vec2(x + vec.x, y + vec.y);
}

vec2 vec2::operator+= (vec2 vec){
    return vec2(x += vec.x, y += vec.y);
}

vec2 vec2::operator- (vec2 vec){
    return vec2(x - vec.x, y - vec.y);
}

vec2 vec2::operator-= (vec2 vec){
    return vec2(x -= vec.x, y -= vec.y);
}

float vec2::mod(){
    return sqrt(x*x + y*y);
}

vec2 vec2::norm(){
    float module = mod();
    return vec2(x / module, y / module);
}

float vec2::dot(vec2 vec){
    return x*vec.x + y*vec.y;
}

float vec2::cross_2d(vec2 vec){
    return x*vec.y - y*vec.x;
}



vec3::vec3(float x_, float y_, float z_){
    x = x_; y = y_; z = z_;
}

vec3::vec3(vec2 &vec){
    x = vec.x; y = vec.y; z = 0;
}

vec3 vec3::operator* (float scale){
    return vec3(x * scale, y * scale, z * scale);
}

vec3 vec3::operator*= (float scale){
    return vec3(x *= scale, y *= scale, z *= scale);
}

vec3 vec3::operator* (vec3 vec){
    return vec3(x * vec.x, y * vec.y, z * vec.z);
}

vec3 vec3::operator*= (vec3 vec){
    return vec3(x *= vec.x, y *= vec.y, z *= vec.z);
}

vec3 vec3::operator+ (vec3 vec){
    return vec3(x + vec.x, y + vec.y, z + vec.z);
}

vec3 vec3::operator+= (vec3 vec){
    return vec3(x += vec.x, y += vec.y, z += vec.z);
}

vec3 vec3::operator- (vec3 vec){
    return vec3(x - vec.x, y - vec.y, z - vec.z);
}

vec3 vec3::operator-= (vec3 vec){
    return vec3(x -= vec.x, y -= vec.y, z -= vec.z);
}

float vec3::mod(){
    return sqrt(x*x + y*y + z*z);
}

vec3 vec3::norm(){
    float module = mod();
    return vec3(x / module, y / module, z / module);
}

float vec3::dot(vec3 vec){
    return x*vec.x + y*vec.y + z*vec.z;
}

vec3 vec3::cross(vec3 vec){
    return vec3(
        y*vec.z - vec.z*y,
        z*vec.x - vec.x*z,
        x*vec.y - vec.y*x
    );
}