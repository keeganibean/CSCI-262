/*
 * mondrian.cpp
 *
 * Author: <your name here>
 *
 * Generate recursive pictures inspired by the art of Piet Mondrian.
 */

#include <cstdlib>
#include <ctime>

#include "mondrian.h"

using namespace std;

void Mondrian::_paint_recursive(Picture &picture, int left, int top, int right, int bottom) {
    // base case 1 - in case we made a zero width or height rectangle
    if (right-left<=0 || bottom-top<=0)
        return;
    // base case 2 - rectangle is now "small enough"
    // Fill with a color (or not)
    if (((right-left)*(bottom-top))<35000)
    {
        _color_fill(picture, left, top, right, bottom);
        _draw_horizontal_line(picture, top, left, right);
        _draw_horizontal_line(picture, bottom, left, right);
        _draw_vertical_line(picture, left, top, bottom);
        _draw_vertical_line(picture, right, top, bottom);
    }

    else
    {
        if ((right-left)>=(bottom-top))
        {
            int split = rand()%(right-left);
            _paint_recursive(picture, split+left, top, right, bottom);
            _paint_recursive(picture, left, top, split+left, bottom);
        }
        else
        {
            int split = rand()%(bottom-top);
            _paint_recursive(picture, left, split+top, right, bottom);
            _paint_recursive(picture, left, top, right, split+top);
        }
    }
    // otherwise, split the rectangle in two at random, paint the two
    // rectangles recursively
}

void Mondrian::_color_fill(Picture &picture, int left, int top, int right, int bottom) {
    int r, g, b;
    string dist = "rybcwwwww";
    // Choose a color at random from a palette;
    // for traditional Mondrian colors, a good palette is:
    // red: r = 255, g = 0, b = 0
    // blue: r = 0, g = 0, b = 128
    // yellow: r = 255, g = 215, b = 0
    // white: r = 255, g = 255, b = 255
    // black: r = 0, g = 0, b = 0
    char color;
    color = dist[rand()%8];
    if (color=='w')
    {
        r = 255; g = 255; b = 255;
    }
    if (color=='r')
    {
        r = 255; g = 0; b = 0;
    }
    if (color=='b')
    {
        r = 0; g = 0; b = 255;
    }
    if (color=='y')
    {
        r = 255; g = 255; b = 0;
    }
    if (color=='c')
    {
        r = 0; g = 220; b = 220;
    }

    for (int x = left; x <= right; x++) {
        for (int y = top; y <= bottom; y++) {
            picture.set(x, y, r, g, b);
        }
    }
}

// These are done for you to save time in lab
void Mondrian::_draw_horizontal_line(Picture &picture, int y, int left, int right) {
    for (int x = left; x <= right; x++) {
        picture.set(x, y, 0, 0, 0);
    }
}

void Mondrian::_draw_vertical_line(Picture &picture, int x, int top, int bottom) {
    for (int y = top; y <= bottom; y++) {
        picture.set(x, y, 0, 0, 0);
    }
}

void Mondrian::paint(string output_filename, int width, int height) {
    // get a new random seed each time
    srand(time(nullptr));

    // create a white picture
    Picture picture(width, height, 255, 255, 255);

    // put a frame around it
    _draw_horizontal_line(picture, 0, 0, width - 1);
    _draw_horizontal_line(picture, height - 1, 0, width - 1);
    _draw_vertical_line(picture, 0, 0, height - 1);
    _draw_vertical_line(picture, width - 1, 0, height - 1);

    // invoke our computer artist!
    _paint_recursive(picture, 1, 1, width - 2, height - 2);

    // save result
    picture.save(output_filename);
}
