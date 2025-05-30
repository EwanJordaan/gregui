#ifndef GREGUI_H
#define GREGUI_H

#pragma once

#include <stdexcept>
#include <windows.h>
#include <iostream>

typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef signed short int16_t;
typedef unsigned short uint16_t;
typedef signed int int32_t;
typedef unsigned int uint32_t;
typedef signed long long int64_t;
typedef unsigned long long uint64_t;

typedef float float32_t;
typedef double float64_t;

#ifndef GREG_API
#define GREG_API
#endif

namespace greg {
    struct vector2 {
        float32_t x;
        float32_t y;

        vector2() : x(0), y(0) {}

        vector2(float32_t _x, float32_t _y) : x(_x), y(_y) {}

        //Define operators
        //Addition of two vectors
        vector2 operator+(const vector2 &other) const {
            return vector2(x + other.x, y + other.y);
        };

        //Subtraction of two vectors
        vector2 operator-(const vector2 &other) const {
            return vector2(x - other.x, y - other.y);
        };

        //Multiplication of two vectors
        vector2 operator*(int scalar) const {
            return vector2(x * scalar, y * scalar);
        };

        //Devision of two vectors
        vector2 operator/(int scalar) const {
            //Devision by zero check
            if (scalar == 0) {
                //Throw error
                throw std::runtime_error("Devision by zero");
            }
            return vector2(x / scalar, y / scalar);
        };

        // In-place addition
        vector2& operator+=(const vector2& other) {
            x += other.x;
            y += other.y;
            return *this;
        }

        // In-place subtraction
        vector2& operator-=(const vector2& other) {
            x -= other.x;
            y -= other.y;
            return *this;
        }

        // In-place scalar multiplication
        vector2& operator*=(int scalar) {
            x *= scalar;
            y *= scalar;
            return *this;
        }

        // In-place scalar division
        vector2& operator/=(int scalar) {
            if (scalar == 0) {
                throw std::runtime_error("Division by zero in Vector2!");
            }
            x /= scalar;
            y /= scalar;
            return *this;
        }

        //Equality check
        bool operator==(const vector2 &other) const {
            return x == other.x && y == other.y;
        };

        //Inequality check
        bool operator!=(const vector2 &other) const {
            return x != other.x || y != other.y;
        };

        //Output stream operator
        friend std::ostream& operator<<(std::ostream& os, const vector2& v) {
            os << "(" << v.x << ", " << v.y << ")";
            return os;
        }
    };

    struct vector3 {
        float32_t x;
        float32_t y;
        float32_t z;

        vector3() : x(0), y(0), z(0) {}

        vector3(float32_t _x, float32_t _y, float32_t _z) : x(_x), y(_y), z(_z) {}
    };

    struct vector4{
        float32_t x;
        float32_t y;
        float32_t z;
        float32_t w;

        vector4() : x(0), y(0), z(0), w(0) {}

        vector4(float32_t _x, float32_t _y, float32_t _z, float32_t _w) : x(_x), y(_y), z(_z), w(_w) {}
    };

    struct gregui_window {};


}

#endif //GREGUI_H