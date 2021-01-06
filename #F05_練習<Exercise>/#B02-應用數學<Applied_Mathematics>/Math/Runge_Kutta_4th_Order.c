//
// C program to implement Runge Kutta method
//
//  Version 1.1
//	
//  Created by Waylon.Yuen on 03/01/2021.
//  Last modified by Waylon.Yuen on 04/01/2021.
//  Copyright © 2021年 Oracragron. All rights reserved.
//

//Library
#include<stdio.h>

//Definations
float dydx(float x, float y);
float RungeKutta(float x0, float y0, float x, float h);

// Main program
int main(void) {

    // define -> 改變此數值進行驗證
    float x0 = 0;
    float y = 1;
    float x = 2;
    float h = 0.2;

    // 執行檔中輸入 debug
    // printf("Plz input x0,y,x,h (format)\n");
    // scanf("%f,%f,%f,%f\n", &x0, &y, &x, &h);

    // show answer
    printf("\nThe value of y at x is : %f", RungeKutta(x0, y, x, h));

    return 0;
}


// A sample differential equation "dy/dx = (x - y)/2"
float dydx(float x, float y) {
    return (x - y)/2;
}

// Finds value of y for a given x using step size h 
// and initial value y0 at x0. 
float RungeKutta(float x0, float y0, float x, float h) {

    // define
    float k1, k2, k3, k4, k5;
    int n = (int)((x - x0) / h); // Count number of iterations using step size or step height h
    float y = y0; // Iterate for number of iterations

    // Apply Runge Kutta Formulas to find next value of y
    for (int i = 1; i <= n; i++) {
        k1 = h * dydx(x0, y);
        k2 = h * dydx(x0 + 0.5*h, y + 0.5*k1);
        k3 = h * dydx(x0 + 0.5*h, y + 0.5*k2);
        k4 = h * dydx(x0 + h, y + k3);

        // Update next value of y
        y = y + (1.0/6.0) * (k1 + 2*k2 + 2*k3 + k4);;

        // Update next value of x
        x0 = x0 + h;
    }

    return y;
}
