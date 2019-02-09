#include <iostream>
#include <string>
#include <fstream>
#include <cmath> 

class ZlyTrojkat
{
public:
	ZlyTrojkat() {}
	friend std::ostream& operator << (std::ostream& out, ZlyTrojkat & zt);

};

class Punkt
{
private:
	
	double x;
	double y;

public:

	Punkt() {};

	Punkt(double x, double y)
	{
		this->x = x;
		this->y = y;
	};

	bool operator == (Punkt p)
	{
		if ((x == p.x) && (y == p.y))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	double gety()
	{
		return y;
	}

	double getx()
	{
		return x;
	}

	friend bool czyWspolliniowe(Punkt a, Punkt b, Punkt c);
	friend std::ostream& operator << (std::ostream & out, Punkt & p);

};

bool czyWspolliniowe(Punkt a, Punkt b, Punkt c)
{
	double z = (a.x * (b.y - c.y)) + (b.x * (c.y - a.y)) + (c.x * (a.y - b.y));

	if ((a == b) || (b == c) || (a == c))
	{
		return true;
	}
	else if (z==0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

class Trojkat
{
private:

	Punkt pT[3];

public:

	Trojkat() {};

	Trojkat(Punkt x, Punkt y, Punkt z)
	{
		if (czyWspolliniowe(x, y, z) == true)
		{
			throw ZlyTrojkat();
		}
		else
		{
			this->pT[0] = x;
			this->pT[1] = y;
			this->pT[2] = z;
		}
	}

	double PoleTrojkata()
	{
		double pole;
		//0.5 *[x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)]
		double x1 = pT[0].getx();
		double x2 = pT[1].getx();
		double x3 = pT[2].getx();
		double y1 = pT[0].gety();
		double y2 = pT[1].gety();
		double y3 = pT[2].gety();
		pole = ((x1 * (y2 - y3)) + (x2 * (y3 - y1)) + (x3 * (y1 - y2)));
		pole = abs(pole / 2);
		return pole;
	}

};






std::ostream& operator << (std::ostream & out, Punkt & p)
{
	out << "(" << p.x << "," << p.y << ")" << std::endl;

	return out;
}

std::ostream& operator << (std::ostream & out, ZlyTrojkat & zt)
{
	out << "Nastapil wyjatek - punkty sa wspoliniowe!" << std::endl;
	return out;

}

int main()
{

	Punkt a(1, 3);
	Punkt b(4, 5);
	Punkt c(2, 12);

	std::cout << a;
	std::cout << b;
	std::cout << c;

	try
	{
		Trojkat t1(a, b, c);
		std::cout << "Pole tego trojkata wynosi... : " << t1.PoleTrojkata() << std::endl;

	}


	catch (ZlyTrojkat zt)
	{
		std::cout << zt;
	}


	system("PAUSE");


}
