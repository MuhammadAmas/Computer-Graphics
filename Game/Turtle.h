/*
 * File:   Turtle.h
 * Author: humera
 *
 * Created on August 8, 2011, 9:34 AM
 */
#include <gl/glut.h>
#include "Canvas.h"
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
using namespace std;

#ifndef TURTLE_H
#define	TURTLE_H

#pragma once

class Turtle
{
private:
    Point2 CP;
    float CD;

public:

    Turtle(Point2 p, float angle)
    {
        CP.set(p.getX(), p.getY());
        CD = angle;
    }
    void moveTo(Point2 p) { CP.set(p.getX(), p.getY()); }

    void lineTo(Point2 newp)
    {
        glBegin(GL_LINES);
        glVertex2f((GLfloat)CP.getX(), (GLfloat)CP.getY());
        glVertex2f((GLfloat)newp.getX(), (GLfloat)newp.getY()); // draw the line
        glEnd();

        CP.set(newp.getX(), newp.getY()); // update the CP
    }

    void turnTo(float angle) { CD = angle; }
    void turn(float angle) { CD += angle; } //Use a negative argument to make a right turn.

    void forward(float dist, bool isVisible)
    {
        const float RadPerDeg = 0.017453393; //radians per degree
        float x = CP.getX() + dist * cos(RadPerDeg * CD);
        float y = CP.getY() + dist * sin(RadPerDeg * CD);
        if (isVisible)
            lineTo(Point2(x, y));
        else
            moveTo(Point2(x, y));
    }

    /*void drawPath(string S, map m,int iteration){
        map <char,string> :: iterator itr;
        itr = m.begin();
        int atomPos = 0;
        for(int i=0;i<iteration;i++){
            for(int j=0;j< S.length; j++){

            }
        }
    }*/
    void drawPath(char c) {
        std::cout << c;

        if (c == 'F') {
            forward(5, true);
        }
        else if (c == '+') {
            turn((-60));

        }
        else if (c == '-') {
            turn(60);
        }

    }

};

#endif	/* TURTLE_H */