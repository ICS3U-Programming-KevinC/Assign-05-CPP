// Copyright (c) 2022 Kevin Csiffary All rights reserved.
//
// Created by: Kevin Csiffary
// Date: Dec. 11, 2022
// This program calculates the area of a triangle with Heron's formula
// and also calculates the interior angles with cosine law

// include cmath for square root powers and cosine
#include <cmath>
#include <iostream>

// calculates the area of the triangle
float CalcArea(float sideA, float sideB, float sideC) {
    // declare variables required by this function
    // variable called s to conserve space but it represents half the perimeter
    float s;
    float area;

    s = (sideA + sideB + sideC) / 2;
    area = sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
    return area;
}

// calculates one angle using cosine law
float CalcAngle(float sideA, float sideB, float sideC) {
    // declare variable required by this function
    float angleA;

    angleA = acos(
        (pow(sideB, 2) + pow(sideC, 2) - pow(sideA, 2)) / (2 * sideB * sideC));
    return angleA * (180 / M_PI);
}

int main() {
    // declare variables for...
    // the units
    std::string units;

    // the three sides as strings
    std::string userSideAStr;
    std::string userSideBStr;
    std::string userSideCStr;

    // the three sides as floats
    float userSideA;
    float userSideB;
    float userSideC;

    // the area
    float finalArea;

    // the three angles
    float firstAngle;
    float secondAngle;
    float thirdAngle;

    // gets user input for units
    std::cout << "Please enter the units you are using: ";
    std::cin >> units;

    // gets user input for side lengths
    std::cout << "Please enter the first side of your triangle: ";
    std::cin >> userSideAStr;
    std::cout << "Please enter the second side of your triangle: ";
    std::cin >> userSideBStr;
    std::cout << "Please enter the third side of your triangle: ";
    std::cin >> userSideCStr;

    try {
        // cast the user inputs into floats
        userSideA = std::stof(userSideAStr);
        userSideB = std::stof(userSideBStr);
        userSideC = std::stof(userSideCStr);

        // check if any side lengths are zero
        if ((userSideA == 0) | (userSideB == 0) | (userSideC == 0)) {
            std::cout << "You can not have a side length of zero.\n";
            main();  // restart program after error

        // check if any side lengths are negative
        } else if ((userSideA < 0) | (userSideB < 0) | (userSideC < 0)) {
            std::cout << "You can not have a negative side length.\n";
            main();  // restart program after error

        // check if the triangle is real
        // by ensuring the two smaller sides are greater than the largest side
        } else if (
            ((userSideA + userSideB) < userSideC)
            | ((userSideB + userSideC) < userSideA)
            | ((userSideA + userSideC) < userSideB)) {
        std::cout << "Invalid triangle!"
        << "The two smaller sides should add to more than the longest side\n";
            main();  // restart program after error
        } else {
            // call CalcArea to get the area of the triangle
            finalArea = CalcArea(userSideA, userSideB, userSideC);

            // call CalcAngle 3 times to get all interior angles
            firstAngle = CalcAngle(userSideA, userSideB, userSideC);
            secondAngle = CalcAngle(userSideB, userSideC, userSideA);
            thirdAngle = CalcAngle(userSideC, userSideA, userSideB);

            // display the area of the triangle
            std::cout << "The area of your triangle is "
            << finalArea << units << "²\n";

            // display the interior angles of the triangle
            std::cout
            << "The corresponding (opposite) angles to your sides are:\n";
            std::cout << "first side  | " << firstAngle << "­°\n";
            std::cout << "second side | " << firstAngle << "­°\n";
            std::cout << "third side  | " << firstAngle << "­°\n";
        }
    } catch (std::invalid_argument) {
        std::cout << "Please enter a valid side length.\n";
        main();  // restart program after error
    }
}
