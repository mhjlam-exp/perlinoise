#pragma once
#include <vector>
#include <string>

class ppm
{
public:
    // storage for RGB values
    std::vector<unsigned char> r;
    std::vector<unsigned char> g;
    std::vector<unsigned char> b;
	
    unsigned int height;
    unsigned int width;
    unsigned int max_col_val;
    unsigned int size; // total number of pixels

    ppm();
    ppm(const std::string& fname); // fill with data stored in file
    ppm(const unsigned int _width, const unsigned int _height); // create empty/black image
    void read(const std::string& fname); // read image from file
    void write(const std::string& fname); // write image to file
};
