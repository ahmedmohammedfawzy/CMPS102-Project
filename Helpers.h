#pragma once
#include "DEFS.h"

inline bool isInsideTriangle(Point A, Point B, Point C, Point P) {
    // Vectors: v0 = C - A, v1 = B - A, v2 = P - A
    float v0x = C.x - A.x, v0y = C.y - A.y;
    float v1x = B.x - A.x, v1y = B.y - A.y;
    float v2x = P.x - A.x, v2y = P.y - A.y;

    // Dot products
    float dot00 = v0x * v0x + v0y * v0y; // v0 · v0
    float dot01 = v0x * v1x + v0y * v1y; // v0 · v1
    float dot02 = v0x * v2x + v0y * v2y; // v0 · v2
    float dot11 = v1x * v1x + v1y * v1y; // v1 · v1
    float dot12 = v1x * v2x + v1y * v2y; // v1 · v2

    // Barycentric coordinates (u, v)
    float invDenom = 1.0f / (dot00 * dot11 - dot01 * dot01);
    float u = (dot11 * dot02 - dot01 * dot12) * invDenom;
    float v = (dot00 * dot12 - dot01 * dot02) * invDenom;

    // Check if inside
    return (u >= 0) && (v >= 0) && (u + v <= 1);
}