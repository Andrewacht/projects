/* 
 * File:   main.cpp
 * Author: andre van der Wacht TI2A
 * Language: C++
 *
 * Created on 19 februari 2019, 14:35
 */

#include <cstdlib>
#include <iostream>

using namespace std;

void RGBtoCMY(float R, float G, float B) {
    float C = 1 - (R/255);
    float M = 1 - (G/255);
    float Y = 1 - (B/255);
    
    cout << "R: " << R << " ----> C: " << C << endl;
    cout << "G: " << G << " ----> M: " << M << endl;
    cout << "B: " << B << " ----> Y: " << Y << endl;
}

void CMYtoRGB(float C, float M, float Y) {
    float c = 1 - C;
    float m = 1 - M;
    float y = 1 - Y;
    
    int R = c * 255;
    int G = m * 255;
    int B = y * 255;
    
    cout << "C: " << C << " ----> R: " << R << endl;
    cout << "M: " << M << " ----> G: " << G << endl;
    cout << "Y: " << Y << " ----> B: " << B << endl;
}

void RGBtoHSL(float R, float G, float B) {
    float r = R/255;
    float g = G/255;
    float b = B/255;
    float min;
    float max;
    float L;
    float S;
    float H;
    
    if (r < g && r < b){
        min = r;
    }
    
    if (b < r && b < g){
        min = b;
    }
    
    if (g < r && g < b){
        min = g;
    }
    
    if (r > g && r > b){
        max = r;
        
        H = ((g-b)/(max-min))*60;
    }
    
    if (b > r && b > g){
        max = b;
        
        H = (4.0 + ((r-g)/(max-min)))*60;
    }
    
    if (g > r && g > b){
        max = g;
        
        H = (2.0 + ((b-r)/(max-min)))*60;
    }
    
    L = (min+max)/2;
    
    if (L < 0.5){
        S = (max-min)/(max+min);
    }
    
    if (L > 0.5){
        S = (max-min)/(2.0-max-min);
    }
    
    cout << "R: " << R << " ----> H: " << H << " degrees" << endl;
    cout << "G: " << G << " ----> S: " << S << endl;
    cout << "B: " << B << " ----> L: " << L << endl;
}

void HSLtoRGB(float H, float S, float L) {
    int R;
    int G;
    int B;
    float h;
    float temp1;
    float temp2;
    float r;
    float g;
    float b;
    
    if (L < 0.5){
        temp1 = L*(1.0+S);
    }
    
    if (L >= 0.5){
        temp1 = L+S-(L*S);
    }
    temp2 = (2*L)-temp1;
    h = H/360;
    
    r = h + 0.333;
    g = h;
    b = h - 0.333;
    
    if (r > 1){
        r -= 1;
    }
    
    if (g > 1){
        g -= 1;
    }
    
    if (b > 1){
        b -= 1;
    }
    
    if (r < 0){
        r += 1;
    }
    
    if (g < 0){
        g += 1;
    }
    
    if (b < 0){
        b += 1;
    }
    
    if ( 6*r < 1){
        r = temp2 + (temp1 - temp2) * 6 * r;
    }
    
    else if (2*r < 1){
        r = temp1;
    }
    
    else if (3*r < 2){
        r = temp2 + (temp1 - temp2) * (0.666 - r) * 6;
    }
    
    else {
        r = temp2;
    }
    
    if ( 6*g < 1){
        g = temp2 + (temp1 - temp2) * 6 * g;
    }
    
    else if (2*g < 1){
        g = temp1;
    }
    
    else if (3*r < 2){
        g = temp2 + (temp1 - temp2) * (0.666 - g) * 6;
    }
    
    else {
        g = temp2;
    }
    
    if ( 6*b < 1){
        b = temp2 + (temp1 - temp2) * 6 * b;
    }
    
    else if (2*b < 1){
        b = temp1;
    }
    
    else if (3*b < 2){
        b = temp2 + (temp1 - temp2) * (0.666 - b) * 6;
    }
    
    else {
        b = temp2;
    }
    
    R = r * 255;
    G = g * 255;
    B = b * 255;
    
    cout << "H: " << H << " degrees" << " ----> R: " << R << endl;
    cout << "S: " << S << " ----> G: " << G << endl;
    cout << "L: " << L << " ----> B: " << B << endl;
}

int main() {
    CMYtoRGB(0.8627, 0.8117, 0.0784);
    RGBtoCMY(35, 48, 235);
    HSLtoRGB(219, 0.34, 0.23);
    RGBtoHSL(240, 155, 70);
    return 0;
}