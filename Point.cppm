export module Point;

export template <typename T>
struct Point
{
    T x;
    T y;

    Point() = default;

    Point(T x_value, T y_value)
        : x(x_value), y(y_value)
    {
    }
};