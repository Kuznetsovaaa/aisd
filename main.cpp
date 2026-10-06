import Point;
import Polyline;

#include <complex>
#include <iomanip>
#include <iostream>

double clean(double value)
{
    if (value > -0.005 && value < 0.005)
    {
        return 0.0;
    }

    return value;
}

int main()
{
    std::cout << std::fixed << std::setprecision(2);

    Polyline<int> line(3);

    line[0] = { 1, 2 };
    line[1] = { 4, 6 };
    line[2] = { 7, 3 };

    std::cout << "Original polyline:\n";
    std::cout << '(' << line[0].x << ", " << line[0].y << ") -> ";
    std::cout<< '(' << line[1].x << ", " << line[1].y << ") -> ";
    std::cout << '(' << line[2].x << ", " << line[2].y << ")\n";

    std::cout << "Length: " << line.length() << "\n";

    Polyline<int> copy(line);

    Polyline<int> assigned(3);
    assigned = line;

    std::cout << "\nCopy and assignment: OK\n";

    Point<int> point{ 10, 20 };

    Polyline<int> combined = line + copy;
    Polyline<int> appended = line + point;
    Polyline<int> prepended = point + line;

    std::cout << "\nAddition operators:\n";

    std::cout << "line + line: 6 vertices\n";

    std::cout << "line + point: last vertex = ("
        << appended[3].x << ", "
        << appended[3].y << ")\n";

    std::cout << "point + line: first vertex = ("
        << prepended[0].x << ", "
        << prepended[0].y << ")\n";

    Point<double> start{ 3.0, 4.0 };
    Polyline<double> polygon(4, start);

    std::cout << "\nRegular 4-gon:\n";

    for (int i = 0; i < 4; ++i)
    {
        std::cout << "Vertex " << i + 1 << ": ("
            << clean(polygon[i].x) << ", "
            << clean(polygon[i].y) << ")\n";
    }

    Polyline<float> float_line(2);
    float_line[0] = { 1.0f, 2.0f };
    float_line[1] = { 4.0f, 6.0f };

    Polyline<double> double_line(2);
    double_line[0] = { 2.0, 1.0 };
    double_line[1] = { 7.0, 5.0 };

    Polyline < std::complex < float>> complex_float_line(2);
    complex_float_line[0] = { {1.0f, 2.0f}, {2.0f, 1.0f} };
    complex_float_line[1] = { {5.0f, 4.0f}, {5.0f, 4.0f} };

    Polyline < std::complex < double>> complex_double_line(2);
    complex_double_line[0] = { {1.0, 3.0}, {2.0, 2.0} };
    complex_double_line[1] = { {6.0, 6.0}, {6.0, 5.0} };

    std::cout << "\nLengths for different coordinate types:\n";
    std::cout << "float: " << float_line.length() << '\n';
    std::cout << "double: " << double_line.length() << '\n';
    std::cout << "complex<float>: " << complex_float_line.length() << '\n';
    std::cout << "complex<double>: " << complex_double_line.length() << '\n';

    return 0;
}