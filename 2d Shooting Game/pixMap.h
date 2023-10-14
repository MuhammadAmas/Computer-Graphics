
#include <malloc.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <string>
#include <assert.h>
#include <gl/glut.h>
using namespace std;

using std::fstream;
using std::ios;
using std::string;
using std::cout;
using std::endl;

// ********** mRGBA class **********
typedef unsigned char uchar;


class mRGBA { // the name RGBA is already used by Windows

public:

    unsigned char r, g, b, a;
    mRGBA() { r = g = b = 0; a = 255; }
    mRGBA(mRGBA& p) { r = p.r; g = p.g; b = p.b; a = p.a; }
    mRGBA(unsigned char rr, unsigned char gg, unsigned char bb, unsigned char aa)
    {
        r = rr; g = gg; b = bb; a = aa;
    }

    void set(unsigned char rr, unsigned char gg, unsigned char bb, unsigned char aa)
    {
        r = rr; g = gg; b = bb; a = aa;
    }

};

/********** RGBPixmap class ************/
#pragma once
class RGBApixmap
{
private:
    mRGBA* pixel;  // array of pixels


public:

    int nRows, nCols;                       // dimensions of pixel map
    RGBApixmap() { nRows = nCols = 0; pixel = 0; }

    RGBApixmap(int rows, int cols)
    {
        nRows = rows;
        nCols = cols;
        pixel = new mRGBA[rows * cols];
    }
    void freeIt()
    {
        delete[]pixel;
        nRows = nCols = 0;
    }

    // *** draw this pixel map at current position

    void mDraw()
    {
        if (nRows == 0 || nCols == 0)
            return;

        // tell OpenGL: don't align pixels with 4-byte boundaries in memory
        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
        glDrawPixels(nCols, nRows, GL_RGBA, GL_UNSIGNED_BYTE, pixel);

    }

    mRGBA* getPixmap(void) const
    {
        return this->pixel;
    }


    // *** read a rectangule of pixels into this pixmap

    int mRead(int x, int y, int wid, int ht)
    {
        nRows = ht;
        nCols = wid;
        pixel = new mRGBA[nRows * nCols];
        if (!pixel) return -1;
        // tell OpenGL: don't align pixels with 4-byte boundaries in memory
        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
        glReadPixels(x, y, nCols, nRows, GL_RGBA, GL_UNSIGNED_BYTE, pixel);
        return 0;
    }


    // *** setPixel 

    void setPixel(int x, int y, mRGBA color) {

        if (x >= 0 && x < nCols && y >= 0 && y < nRows)

            pixel[nCols * y + x] = color;

    }

    // *** get pixel
    mRGBA getPixel(int x, int y)
    {

        mRGBA bad(255, 255, 255, 255);

        assert(x >= 0 && x < nCols);

        assert(y >= 0 && y < nRows);

        return pixel[nCols * y + x];

    }

    void makeBMP(int w, int h)
    {
        nRows = h;
        nCols = w;
        pixel = new mRGBA[nRows * nCols];
    }

    void setTexture(GLuint textureID)
    {

        //  glBindTexture(GL_TEXTURE_2D, textureID);
        //
        //   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
        //   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
        //
        //  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        //  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        //  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, this->nCols, this->nRows, 0, GL_RGBA,
        //	           GL_UNSIGNED_BYTE, this->pixel);

        glBindTexture(GL_TEXTURE_2D, textureID);
        gluBuild2DMipmaps(GL_TEXTURE_2D, 4, this->nCols, this->nRows, GL_RGBA, GL_UNSIGNED_BYTE, this->getPixmap());

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST) ;
        //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST) ;

        glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

    }


    // *** read BMP file into this pixel map (see RGBpixmap.cpp)
    int readBMPFile(string fname, float para);
    void blend(RGBApixmap, RGBApixmap);
    void  setOpacity(float opacity);
    void  makeAvgImg(RGBApixmap S, RGBApixmap D);
    void  makeAvg2Img(RGBApixmap A, RGBApixmap B, RGBApixmap C);
    void  makeCompositeImg(RGBApixmap A, RGBApixmap B, RGBApixmap C, float f);

    void setChromaKey(mRGBA c);

    void setChromaKey(int r, int g, int b);

    bool copyFromScreen(int left, int bottom, int width, int height);

    void drawToScreen(int left, int bottom);

    void copyFromScreenToScreen(int left, int bottom, int width, int height, int newLeft, int newBottom);


    void blendOnScreen(int left, int bottom);
    void rotateImage(float angle);
    // these 2 are used in texture example
    void makeCheckerboard(int);

    mRGBA* BMPWithAlpha();

}; // class RGBApixmap



typedef unsigned short ushort;
typedef unsigned long  ulong;

fstream inf;        // global in this file for convenience



/* *** Helper function getShort()

 * BMP format uses little-endian integer types

 * get and construct inmemory a 2-byte integer stored

 * in little-endian form

 */

ushort getShort() {

    char ic;

    ushort ip;

    inf.get(ic);

    ip = ic;              // 1st byte is little one

    inf.get(ic);

    ip |= ((ushort)ic << 8);       // or in high order byte

    return ip;

}



/* *** Helper function getLong()

 * BMP format uses little-endian integer types

 * get and construct inmemory a 4-byte integer stored

 * in little-endian form

 */

ulong getLong() {
    ulong ip = 0;
    char  ic = 0;
    unsigned char uc = ic;

    inf.get(ic); uc = ic; ip = uc;
    inf.get(ic); uc = ic; ip |= ((ulong)uc << 8);
    inf.get(ic); uc = ic; ip |= ((ulong)uc << 16);
    inf.get(ic); uc = ic; ip |= ((ulong)uc << 24);
    return ip;
}



float fx(float x, float a0, float a1) {

    float y, t;

    t = x / a1;

    y = a0 * exp(-(t * t));

    return y;

}





int getAlpha(int row, int col, int nRows, int nCols, float (*p)(float, float, float), float a1)
{
    int   rowCenter, colCenter, alpha;
    float dx, dy, dist = 0.0;
    rowCenter = (float)nRows / 2.0;
    colCenter = (float)nCols / 2.0;
    dx = row - rowCenter;
    dy = col - colCenter;
    dist = sqrt(dx * dx + dy * dy);
    alpha = (int)(*p)(dist, 255.0, a1);
    return alpha;

}


// *** Read into memory an mRGB image from an uncompressed BMP file

// return 0 on fail, 1 for Ok

int RGBApixmap::readBMPFile(string fname, float para)
{
    int k, row, col, numPadBytes, nBytesInRow;
    char ch1, ch2;

    inf.open(fname.c_str(), ios::in | ios::binary); // read binary chars
    if (!inf) {
        cout << "can't open file: " << fname << endl;
        return 0;
    }
    inf.get(ch1); inf.get(ch2); // type: always 'BM'
    ulong  fileSize = getLong();
    ushort reserved1 = getShort(); // always 0
    ushort reserved2 = getShort(); // always 0
    ulong  offBits = getLong();  // offset to image-unreliable
    ulong  headerSize = getLong();  // always 40
    ulong  numCols = getLong();  // number of columns in image
    ulong  numRows = getLong();  // number of rows in image

    // cout <<ch1<<ch2<<numRows<<"x"<<numCols<<cout.flush()<<endl;

    ushort planes = getShort(); // always 1
    ushort bitsPerPixel = getShort(); // 8 or 24; allow only 24 here
    ulong  compression = getLong();            // must be 0 for uncompressed
    ulong  imageSize = getLong();  // total bytes in image
    ulong  xPels = getLong();     // always 0
    ulong  yPels = getLong();     // always 0
    ulong  numLUTentries = getLong();           // 256 for 8 bit, otherwise 0
    ulong  impColors = getLong();  // always 0
    if (bitsPerPixel != 24) {
        cout << "not a 24-bit pixel image, or is compressed!\n";
        inf.close();
        return 0; // failed
    }

    // add bytes at end of each row so total# is a multiple of 4
    // round up 3*numCols to next mult. of 4
    nBytesInRow = ((3 * numCols + 3) / 4) * 4;
    numPadBytes = nBytesInRow - 3 * numCols; // need this many
    nRows = numRows; // set class's data members
    nCols = numCols;

    pixel = new mRGBA[nRows * nCols]; // make space for array
    if (!pixel) return 0; // out of memory!

    long count = 0;
    char dum;
    for (row = 0; row < nRows; row++) {
        for (col = 0; col < nCols; col++) {
            char r, g, b;
            inf.get(b); inf.get(g); inf.get(r); // read bytes
            pixel[count].r = r; // place them in colors
            pixel[count].g = g; // place them in colors
            pixel[count].b = b; // place them in colors
            //int alpha = getAlpha(row,col,nRows,nCols,fx,para); // calculate alpha value
            pixel[count++].a = (uchar)255; // set Alpha value to opaque
        }
        for (k = 0; k < numPadBytes; k++) // skip pad bytes at row's end
            inf >> dum;
    }
    inf.close();
    return 1;
} // end of readBMPFile




void RGBApixmap::setOpacity(float opacity)
{

    long count = 0;
    int i, j, c;

    //this->nRows = this->nCols = D.nRows;
    //this->pixel = (mRGBA*) malloc(4 * this->nRows * this->nCols);

    for (i = 0; i < this->nRows; i++)
        for (j = 0; j < this->nCols; j++)
        {

            //this->pixel[count].r = 255;
            //this->pixel[count].g = 128;
            //this->pixel[count++].b = 2555;
            this->pixel[count++].a = 128;
        }

}

void RGBApixmap::makeAvgImg(RGBApixmap S, RGBApixmap D)
{
    long count = 0;
    int i, j, c;

    float a;

    this->nRows = this->nCols = D.nRows;
    this->pixel = (mRGBA*)malloc(4 * this->nRows * this->nCols);

    for (i = 0; i < this->nRows; i++)
        for (j = 0; j < this->nCols; j++)
        {
            a = (float)S.pixel[count].a / 255;
            cout << a << endl;

            D.pixel[count].r = (unsigned char)((a * S.pixel[count].r) + ((1 - a) * D.pixel[count].r));
            D.pixel[count].g = (unsigned char)((a * S.pixel[count].g) + ((1 - a) * D.pixel[count].g));

            D.pixel[count++].b = (unsigned char)((a * S.pixel[count].b) + ((1 - a) * D.pixel[count].b));

        }
}

void RGBApixmap::blend(RGBApixmap S, RGBApixmap D)
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    makeAvgImg(S, D);
    D.mDraw();


}

void RGBApixmap::setChromaKey(int r, int g, int b)
{

    long count = 0;

    for (int row = 0; row < this->nCols; row++)
        for (int col = 0; col < this->nRows; col++)
        {
            mRGBA p = pixel[count];

            if (p.r == r && p.g == g && p.b == b)
                pixel[count++].a = 0;
            else
                pixel[count++].a = 255;

        }


}



void RGBApixmap::setChromaKey(mRGBA c)
{


    long count = 0;
    int i, j;

    for (i = 0; i < this->nRows; i++)
        for (j = 0; j < this->nCols; j++)
        {
            mRGBA p = this->pixel[count];
            if (p.r == c.r && p.g == c.g && p.b == c.b)
            {
                cout << " i m in" << endl;
                this->pixel[count++].a = 0;
                cout << p.r << p.g << p.b << endl;



            }
            else
            {
                this->pixel[count++].a = 255;
                //cout<<" i m out" << endl;
            }
        }

}
void RGBApixmap::makeAvg2Img(RGBApixmap A, RGBApixmap B, RGBApixmap C)
{
    long count = 0;
    int i, j, c;

    this->nRows = this->nCols = A.nRows;
    this->pixel = (mRGBA*)malloc(4 * this->nRows * this->nCols);

    for (i = 0; i < this->nRows; i++)
        for (j = 0; j < this->nCols; j++)
        {

            this->pixel[count].r = (A.pixel[count].r + B.pixel[count].r) / 2;
            this->pixel[count].g = (A.pixel[count].g + B.pixel[count].g) / 2;
            this->pixel[count++].b = (A.pixel[count].b + B.pixel[count].b) / 2;

        }
}


void RGBApixmap::makeCompositeImg(RGBApixmap A, RGBApixmap B, RGBApixmap C, float f)
{
    long count = 0;
    int i, j, c;

    this->nRows = this->nCols = A.nRows;
    this->pixel = (mRGBA*)malloc(4 * this->nRows * this->nCols);

    for (i = 0; i < this->nRows; i++)
        for (j = 0; j < this->nCols; j++)
        {

            this->pixel[count].r = (unsigned char)(((1 - f) * (float)A.pixel[count].r) + (f * (float)B.pixel[count].r));
            this->pixel[count].g = (unsigned char)(((1 - f) * (float)A.pixel[count].g) + (f * (float)B.pixel[count].g));
            this->pixel[count++].b = (unsigned char)(((1 - f) * (float)A.pixel[count].b) + (f * (float)B.pixel[count].b));

        }
}

bool RGBApixmap::copyFromScreen(int left, int bottom,
    int width, int height)
{

    RGBApixmap scrImage(height, width);
    if (scrImage.getPixmap() == NULL) { // memory allocation failed
        //     cerr << "RGBApixmap::copyFromScreen() -> allocation m�moire �chou�e." << endl;
        return false;
    }

    // tell OpenGL NOT to try to align pixels to 4 byte boundaries in memory
    glPixelStorei(GL_PACK_ALIGNMENT, 1);
    //glPixelStorei(GL_UNPACK_ALIGNMENT,1);
   //glReadBuffer( GL_FRONT );
    glReadPixels(left, bottom, width, height, GL_RGBA, GL_UNSIGNED_BYTE, this->getPixmap());
    //glCopyPixels(left,bottom,width,height,GL_COLOR);

    return true;
}

void RGBApixmap::drawToScreen(int left, int bottom)
{
    if ((nRows == 0) ||
        (nCols == 0)) {
        return;
    }

    // set the current raster-position
    glRasterPos2i(left, bottom);

    // tell OpenGL NOT to try to align pixels to 4 byte boundaries in memory
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    glDrawPixels(nCols, nRows, GL_RGBA, GL_UNSIGNED_BYTE, this->getPixmap());

}


void RGBApixmap::copyFromScreenToScreen(int left, int bottom,
    int width, int height,
    int newLeft, int newBottom)
{
    // set the current raster-position
    glRasterPos2i(newLeft, newBottom);
    glCopyPixels(left, bottom, width, height, GL_COLOR);
}


void RGBApixmap::blendOnScreen(int left, int bottom)
{
    // result = (alpha * source) + ((1 - alpha) * destination)
    glEnable(GL_BLEND);

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);   //defines blending factors
    //glColor4f(0.0f, 1.0f, 0.0f, 1.00f);                  //defines the alpha value = 0.75f
    this->drawToScreen(left, bottom);     //draw the second picture i.e. this

    glDisable(GL_BLEND);
}