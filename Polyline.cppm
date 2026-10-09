export module Polyline;

import Point;
import Geometry;

export template <typename T>
class Polyline
{
private:
    Point<T>* vertices;
    int size;

    static double square_root(double value)
    {
        if (value == 0.0)
        {
            return 0.0;
        }

        double result = value;

        for (int i = 0; i < 20; ++i)
        {
            result = (result + value / result) / 2.0;
        }

        return result;
    }

    static double coordinate_square(const T& value)
    {
        if constexpr (requires { value.real(); value.imag(); })
        {
            double real_part = static_cast<double>(value.real());
            double imaginary_part = static_cast<double>(value.imag());

            return real_part * real_part
                + imaginary_part * imaginary_part;
        }
        else
        {
            double number = static_cast<double>(value);

            return number * number;
        }
    }

public:
    // Empty polyline
    Polyline()
        : vertices(nullptr), size(0)
    {
    }

    // Polyline with a specified number of points
    Polyline(int vertex_count)
        : vertices(nullptr), size(0)
    {
        if (vertex_count <= 0)
        {
            return;
        }

        vertices = new Point<T>[vertex_count];
        size = vertex_count;
    }

    // Polyline consisting of one point
    Polyline(const Point<T>& point)
        : vertices(new Point<T>[1]), size(1)
    {
        vertices[0] = point;
    }

    // Regular polygon with a specified starting point
    Polyline(int vertex_count, const Point<T>& start_point)
        : vertices(nullptr), size(0)
    {
        if (vertex_count <= 2)
        {
            return;
        }

        vertices = new Point<T>[vertex_count];
        size = vertex_count;

        const double pi = 3.14159265358979323846;
        const double angle_step = 2.0 * pi / vertex_count;

        vertices[0] = start_point;

        double start_x = static_cast<double>(start_point.x);
        double start_y = static_cast<double>(start_point.y);

        for (int i = 1; i < vertex_count; ++i)
        {
            double angle = angle_step * i;

            double cosine_value = cosine(angle);
            double sine_value = sine(angle);

            vertices[i].x = static_cast<T>(
                start_x * cosine_value - start_y * sine_value
                );

            vertices[i].y = static_cast<T>(
                start_x * sine_value + start_y * cosine_value
                );
        }
    }

    // Polyline with coordinates in the specified range
    Polyline(int vertex_count, double minimum, double maximum)
        : vertices(nullptr), size(0)
    {
        if (vertex_count <= 0)
        {
            return;
        }

        vertices = new Point<T>[vertex_count];
        size = vertex_count;

        if (vertex_count == 1)
        {
            double value = (minimum + maximum) / 2.0;

            vertices[0].x = static_cast<T>(value);
            vertices[0].y = static_cast<T>(value);

            return;
        }

        for (int i = 0; i < vertex_count; ++i)
        {
            double ratio =
                static_cast<double>(i)
                / static_cast<double>(vertex_count - 1);

            double value =
                minimum + (maximum - minimum) * ratio;

            vertices[i].x = static_cast<T>(value);
            vertices[i].y = static_cast<T>(value);
        }
    }

    // Copy constructor
    Polyline(const Polyline& other)
        : vertices(nullptr), size(other.size)
    {
        if (size > 0)
        {
            vertices = new Point<T>[size];

            for (int i = 0; i < size; ++i)
            {
                vertices[i] = other.vertices[i];
            }
        }
    }

    // Copy assignment operator
    Polyline& operator=(const Polyline& other)
    {
        if (this != &other)
        {
            Point<T>* new_vertices = nullptr;

            if (other.size > 0)
            {
                new_vertices = new Point<T>[other.size];

                for (int i = 0; i < other.size; ++i)
                {
                    new_vertices[i] = other.vertices[i];
                }
            }

            delete[] vertices;

            vertices = new_vertices;
            size = other.size;
        }

        return *this;
    }

    // Read/write access to a vertex
    Point<T>& operator[](int index)
    {
        return vertices[index];
    }

    // Read-only access to a vertex
    const Point<T>& operator[](int index) const
    {
        return vertices[index];
    }

    // Concatenation of two polylines
    Polyline operator+(const Polyline& other) const
    {
        Polyline result(size + other.size);

        for (int i = 0; i < size; ++i)
        {
            result[i] = vertices[i];
        }

        for (int i = 0; i < other.size; ++i)
        {
            result[size + i] = other.vertices[i];
        }

        return result;
    }

    // Adding a point to the end
    Polyline operator+(const Point<T>& point) const
    {
        Polyline result(size + 1);

        for (int i = 0; i < size; ++i)
        {
            result[i] = vertices[i];
        }

        result[size] = point;

        return result;
    }

    // Adding a point to the beginning
    friend Polyline operator+(const Point<T>& point, const Polyline& line)
    {
        Polyline result(line.size + 1);

        result[0] = point;

        for (int i = 0; i < line.size; ++i)
        {
            result[i + 1] = line.vertices[i];
        }

        return result;
    }

    // Calculate the length of the polyline
    double length() const
    {
        double result = 0.0;

        for (int i = 1; i < size; ++i)
        {
            T dx = vertices[i].x - vertices[i - 1].x;
            T dy = vertices[i].y - vertices[i - 1].y;

            double distance_squared =
                coordinate_square(dx)
                + coordinate_square(dy);

            result += square_root(distance_squared);
        }

        return result;
    }

    ~Polyline()
    {
        delete[] vertices;
    }
};