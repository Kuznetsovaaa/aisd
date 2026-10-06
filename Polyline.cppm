export module Polyline;

import Point;

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
    Polyline()
        : vertices(nullptr), size(0)
    {
    }

    Polyline(int vertex_count)
        : vertices(new Point<T>[vertex_count]), size(vertex_count)
    {
    }

    Polyline(const Polyline& other)
        : vertices(new Point<T>[other.size]), size(other.size)
    {
        for (int i = 0; i < size; ++i)
        {
            vertices[i] = other.vertices[i];
        }
    }

    Polyline& operator=(const Polyline& other)
    {
        if (this != &other)
        {
            delete[] vertices;

            size = other.size;
            vertices = new Point<T>[size];

            for (int i = 0; i < size; ++i)
            {
                vertices[i] = other.vertices[i];
            }
        }

        return *this;
    }

    Point<T>& operator[](int index)
    {
        return vertices[index];
    }

    const Point<T>& operator[](int index) const
    {
        return vertices[index];
    }

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

    double length() const
    {
        double result = 0.0;

        for (int i = 1; i < size; ++i)
        {
            T dx = vertices[i].x - vertices[i - 1].x;
            T dy = vertices[i].y - vertices[i - 1].y;

            double distance_squared =
                coordinate_square(dx) + coordinate_square(dy);

            result += square_root(distance_squared);
        }

        return result;
    }

    ~Polyline()
    {
        delete[] vertices;
    }
};