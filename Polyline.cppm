export module Polyline;

import Point;

export template <typename T>
class Polyline
{
private:
	Point<T>* vertices;
	int size;
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
	Point <T>& operator[](int index)
	{
		return vertices[index];
	}
	const Point<T>& operator[](int index) const
	{
		return vertices[index];
	}

	~Polyline()
	{
		delete[] vertices;
	}
};