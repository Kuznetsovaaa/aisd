import Point;
import Polyline; 

#include <complex>
#include <iostream>

int main()
{
    Point<int> int_point{ 1, 2 };
    Point<float> float_point{ 1.5f, 2.5f };
    Point<double> double_point{ 1.5, 2.5 };

    std::complex<float> complex_float_x{ 1.5f, 2.5f };
    std::complex<float> complex_float_y{ 3.5f, 4.5f };

    Point < std::complex < float>> complex_float_point{
        complex_float_x,
        complex_float_y
    };

    std::complex<double> complex_double_x{ 1.5, 2.5 };
    std::complex<double> complex_double_y{ 3.5, 4.5 };

    Point < std::complex < double>> complex_double_point{
        complex_double_x,
        complex_double_y
    };

    std::cout<< int_point.x << ' ' << int_point.y << '\n';
    std::cout << float_point.x << ' ' << float_point.y << '\n';
    std::cout << double_point.x << ' ' << double_point.y << '\n';

    return 0;
}