#pragma once
//*************************************Point2 ***************************//
#include <gl/glut.h>
class Point2
{
public:
    Point2() { x = y = 0.0f; } // constructor 1
    Point2(float xx, float yy) { x = xx; y = yy; } // constructor 2
    void set(float xx, float yy) { x = xx; y = yy; }
    float getX() { return x; }
    float getY() { return y; }
    void draw(void)
    {
        glPointSize(4.0);

        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
        glEnable(GL_POINT_SMOOTH);

        glBegin(GL_POINTS); // draw this point
        glVertex2f((GLfloat)x, (GLfloat)y);
        glEnd();

        glDisable(GL_POINT_SMOOTH);

    }// end draw
private:
    float x, y;
}; // end class Point2


//*************************************IntRect ***************************//

class IntRect
{
public:
    IntRect() { l = 0; r = 100; b = 0; t = 100; } // constructors
    IntRect(int left, int right, int bottom, int top)
    {
        l = left; r = right; b = bottom; t = top;
    } // constructors
    void set(int left, int right, int bottom, int top)
    {
        l = left; r = right; b = bottom; t = top;
    }
    int getl() { return l; }
    int getr() { return r; }
    int getb() { return b; }
    int gett() { return t; }
    void draw(void); // draw this rectangle using OpenGL
private:
    int l, r, b, t;
}; //end class IntRect:

void IntRect::draw(void)
{
    glBegin(GL_LINE_LOOP);
    glVertex2i(l, b);
    glVertex2i(r, b);
    glVertex2i(r, t);
    glVertex2i(l, t);
    glEnd();
}// end IntRect::draw


//*************************************RealRect ***************************//

class RealRect
{
public:
    RealRect() { l = 0; r = 100; b = 0; t = 100; } // constructors
    RealRect(float left, float right, float bottom, float top)
    {
        l = left; r = right; b = bottom; t = top;
    } // constructors
    void set(float left, float right, float bottom, float top)
    {
        l = left; r = right; b = bottom; t = top;
    }
    float getl() { return l; }
    float getr() { return r; }
    float getb() { return b; }
    float gett() { return t; }
    void draw(void); // draw this rectangle using OpenGL
private:
    float l, r, b, t;
}; //end class RealRect:
void RealRect::draw(void)
{
    glLineWidth(4.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(l, b);
    glVertex2f(r, b);
    glVertex2f(r, t);
    glVertex2f(l, t);
    glEnd();

    glLineWidth(1.0);
}// end RealRect





//********************************PolyLine ***************************//