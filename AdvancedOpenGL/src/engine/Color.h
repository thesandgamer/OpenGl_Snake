#ifndef COLOR_H
#define COLOR_H

#include <cstdint>
#include <GL/glew.h>
#include "maths/Vector3.h"
#include "maths/Vector4.h"

class Color
{
public:
    Color();
    Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255);
    Color(uint32_t i);
    virtual ~Color();

    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
    GLfloat* glArray;

    void setColor(uint8_t p_r, uint8_t p_g, uint8_t p_b, uint8_t p_a = 255);

    friend Color operator *(Color value, float scale)
    {
        return Color::multiply(value, scale);
    }	

    Vector3 toVector3();
    Vector4 toVector4();
    GLfloat* toGlArray();

    static Color lerp(Color value1, Color value2, float amount);
    static Color multiply(Color value, float scale);

    static Color black;
    static Color white;
    static Color red;
    static Color green;
    static Color blue;
    static Color yellow;
    static Color lightYellow;
    static Color lightBlue;
    static Color lightPink;
    static Color lightGreen;
};

#endif