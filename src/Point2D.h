#pragma once



class Point2D
{
public:

	int x,y;

	Point2D(void)
	{
		x = 0;
		y = 0;
	}

	Point2D(int x,int y)
	{
		this->x = x;
		this->y = y;
	}

	Point2D(const Point2D &rhs)
	{
		x = rhs.x;
		y = rhs.y;
	}
	Point2D & operator = (const Point2D& rhs)
	{
		x = rhs.x;
		y = rhs.y;
		return *this;
	}

	virtual ~Point2D(void)
	{
	}
};


