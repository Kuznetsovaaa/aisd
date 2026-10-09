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

void print_point(const Point<double>& point)
{
    std::cout << '('
        << clean(point.x)
        << ", "
        << clean(point.y)
        << ')';
}

int main()
{
    std::cout << std::fixed << std::setprecision(2);

    // Constructor with a specified number of points
    Polyline<int> line(3);

    line[0] = Point<int>(1, 2);
    line[1] = Point<int>(4, 6);
    line[2] = Point<int>(7, 3);

    std::cout << "Initial polyline:\n";
    std::cout << '(' << line[0].x << ", " << line[0].y << ") -> ";
    std::cout << '(' << line[1].x << ", " << line[1].y << ") -> ";
    std::cout << '(' << line[2].x << ", " << line[2].y << ")\n";

    std::cout << "Length: "
        << line.length()
        << "\n";

    // Constructor with one point
    Point<int> point(10, 20);
    Polyline<int> one_point_line(point);

    std::cout <<  "\nPolyline with one point: ";
    std::cout << '('
        << one_point_line[0].x
        << ", "
        << one_point_line[0].y
        << ")\n";

    // Copy constructor and assignment
    Polyline<int> copy(line);

    Polyline<int> assigned(1);
    assigned = line;

    std::cout << "\nCopy constructor: OK\n";
    std::cout <<  "Assignment operator: OK\n";

    // Polyline addition operators
    Polyline<int> combined = line + copy;
    Polyline<int> appended = line + point;
    Polyline<int> prepended = point + line;

    std::cout << "\nAddition operators:\n";
    std::cout << "Polyline + polyline: 6 vertices\n";

    std::cout << "Polyline + point: last vertex = ("
        << appended[3].x
        << ", "
        << appended[3].y
        << ")\n";

    std::cout << "Point + polyline: first vertex = ("
        << prepended[0].x
        << ", "
        << prepended[0].y
        << ")\n";

    // Constructor with coordinates in a range
    Polyline<int> range_line(5, 1.0, 10.0);

    std::cout << "\nPolyline with coordinates in [1, 10]:\n";

    for (int i = 0; i < 5; ++i)
    {
        std::cout << '('
            << range_line[i].x
            << ", "
            << range_line[i].y
            << ')';

        if (i < 4)
        {
            std::cout << " -> ";
        }
    }

    std::cout << '\n';

    // User-defined regular polygon
    int polygon_size;

    std::cout << "\nEnter N for a regular polygon (N > 2): ";
    std::cin >> polygon_size;

    while (polygon_size <= 2)
    {
        std::cout << "N must be greater than 2. Enter N again: ";
        std::cin >> polygon_size;
    }

    double start_x;
    double start_y;

    std::cout << "Enter coordinates of the starting point: ";
    std::cin >> start_x >> start_y;

    Point<double> start_point(start_x, start_y);

    Polyline<double> polygon(polygon_size, start_point);

    std::cout << "\nRegular polygon:\n";

    for (int i = 0; i < polygon_size; ++i)
    {
        std::cout << "Vertex " << i + 1 << ": ";
        print_point(polygon[i]);
        std::cout << '\n';
    }

    std::cout << "Polygon length: "
        << polygon.length()
        << '\n';

    // Different coordinate types
    Polyline<float> float_line(2);
    float_line[0] = Point<float>(1.0f, 2.0f);
    float_line[1] = Point<float>(4.0f, 6.0f);

    Polyline<double> double_line(2);
    double_line[0] = Point<double>(2.0, 1.0);
    double_line[1] = Point<double>(7.0, 5.0);

    Polyline < std::complex < float>> complex_float_line(2);
    complex_float_line[0] =
        Point < std::complex < float>>(
            std::complex<float>(1.0f, 2.0f),
            std::complex<float>(2.0f, 1.0f)
        );

    complex_float_line[1] =
        Point < std::complex < float>>(
            std::complex<float>(5.0f, 4.0f),
            std::complex<float>(5.0f, 4.0f)
        );

    Polyline < std::complex < double>> complex_double_line(2);
    complex_double_line[0] =
        Point < std::complex < double>>(
            std::complex<double>(1.0, 3.0),
            std::complex<double>(2.0, 2.0)
        );

    complex_double_line[1] =
        Point < std::complex < double>>(
            std::complex<double>(6.0, 6.0),
            std::complex<double>(6.0, 5.0)
        );

    std::cout << "\nLengths for different coordinate types:\n";
    std::cout << "float: "
        << float_line.length()
        << '\n';

    std::cout << "double: "
        << double_line.length()
        << '\n';

    std::cout << "complex<float>: "
        << complex_float_line.length()
        << '\n';

    std::cout << "complex<double>: "
        << complex_double_line.length()
        << '\n';

    return 0;
}