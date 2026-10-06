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

    std::cout << int_point.x << ' ' << int_point.y << '\n';
    std::cout << float_point.x << ' ' << float_point.y << '\n';
    std::cout << double_point.x << ' ' << double_point.y << '\n';

    Polyline<int> first(3);

    first[0] = { 1, 2 };
    first[1] = { 3, 4 };
    first[2] = { 5, 6 };

    Polyline<int> second(first);

    Polyline<int> third(3);
    third = first;

    std::cout << second[0].x << ' ' << second[0].y << '\n';
    std::cout << third[2].x << ' ' << third[2].y << '\n';

    Point<int> point{ 10, 20 };

    Polyline<int> combined = first + second;
    Polyline<int> appended = first + point;
    Polyline<int> prepended = point + first;

    std::cout << combined[0].x << ' ' << combined[0].y << '\n';
    std::cout << combined[3].x << ' ' << combined[3].y << '\n';

    std::cout << appended[3].x << ' ' << appended[3].y << '\n';

    std::cout << prepended[0].x << ' ' << prepended[0].y << '\n';
    std::cout << prepended[1].x << ' ' << prepended[1].y << '\n';

    Polyline<int> length_line(3);

    length_line[0] = { 0, 0 };
    length_line[1] = { 3, 4 };
    length_line[2] = { 6, 4 };

    std::cout << length_line.length() << '\n';

    Point<double> triangle_start{ 1.0, 0.0 };

    Polyline<double> triangle(3, triangle_start);

    std::cout << "Triangle vertices:\n";

    for (int i = 0; i < 3; ++i)
    {
        std::cout << triangle[i].x << ' '
            << triangle[i].y << '\n';
    }

    Point<double> square_start{ 1.0, 0.0 };

    Polyline<double> square(4, square_start);

    std::cout << "Square vertices:\n";

    for (int i = 0; i < 4; ++i)
    {
        std::cout << square[i].x << ' '
            << square[i].y << '\n';
    }

    Point<int> int_start{ 1, 0 };
    Polyline<int> int_polygon(4, int_start);

    Point<float> float_start{ 1.0f, 0.0f };
    Polyline<float> float_polygon(4, float_start);

    Point<double> double_start{ 1.0, 0.0 };
    Polyline<double> double_polygon(4, double_start);
    Polyline<float> float_line(2);

    float_line[0] = { 0.0f, 0.0f };
    float_line[1] = { 3.0f, 4.0f };

    std::cout << float_line.length() << '\n';

    Polyline<double> double_line(2);

    double_line[0] = { 0.0, 0.0 };
    double_line[1] = { 3.0, 4.0 };

    std::cout << double_line.length() << '\n';

    Polyline < std::complex < float>> complex_float_line(2);

    complex_float_line[0] = {
        std::complex<float>{0.0f, 0.0f},
        std::complex<float>{0.0f, 0.0f}
    };

    complex_float_line[1] = {
        std::complex<float>{3.0f, 0.0f},
        std::complex<float>{4.0f, 0.0f}
    };

    std::cout<< complex_float_line.length() << '\n';

    Polyline < std::complex < double>> complex_double_line(2);

    complex_double_line[0] = {
        std::complex<double>{0.0, 0.0},
        std::complex<double>{0.0, 0.0}
    };

    complex_double_line[1] = {
        std::complex<double>{3.0, 0.0},
        std::complex<double>{4.0, 0.0}
    };

    std::cout << complex_double_line.length() << '\n';
    return 0;
}