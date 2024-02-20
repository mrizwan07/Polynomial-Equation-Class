#include <iostream>
using namespace std;
class Polynomial;
class Term {
	friend Polynomial;
private:
	int exp;
	float coef;
};
class Polynomial {
private:
	Term* termArray;
	int size;
public:
	Polynomial()
	{
		termArray = NULL;
	}
	Polynomial(int size)
	{
		termArray = new Term [size];
		this->size = size;
		for (int i = 0; i < size; i++)
		{
			termArray[i].coef = 0;
			termArray[i].exp = 0;
		}
	}
	~Polynomial()
	{
		delete []termArray;
		termArray = NULL;
	}
	Polynomial(Polynomial& obj)
	{
		size = obj.size;
		termArray = new Term [size];
		for (int i = 0; i < size; i++)
		{
			termArray[i].coef = obj.termArray[i].coef;
			termArray[i].exp = obj.termArray[i].exp;
		}
	}
	void addTerm(float Coefficient, int power)
	{
		for (int i = 0; i < size; i++)
		{
			if (termArray[i].coef == 0 && termArray[i].exp == 0)
			{
				termArray[i].coef = Coefficient;
				termArray[i].exp = power;
			}
		}
	}
	int getDegree()
	{
		return termArray[0].exp;
	}
	float getCoefficient(int power)
	{
		for (int i = 0; i < size; i++)
		{
			if (termArray[i].exp == power)
			{
				return termArray[i].coef;
			}
		}
	}
	int evaluate(int n)
	{
		int temp = 0;
		for (int i = 0; i < size; i++)
		{
			temp = temp + ((termArray[i].coef) * n * (termArray[i].exp));
		}
		return temp;
	}
	Polynomial & operator +(Polynomial & p)
	{
		int count = 0;
		for (int i = 0; i < size; i++)
		{ 
			for (int j= 0; j < p.size; j++)
			{
				if (termArray[i].exp == p.termArray[j].exp)
				{
					count++;
				}
			}
		}
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < p.size; j++)
			{
				if (termArray[i].exp != p.termArray[j].exp)
				{
					count++;
				}
			}
		}
		for (int i = 0; i <p.size; i++)
		{
			for (int j = 0; j <size; j++)
			{
				if (p.termArray[i].exp != termArray[j].exp)
				{
					count++;
				}
			}
		}
		Polynomial* temp = new Polynomial[count];
		int count2 = 0;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < p.size; j++)
			{
				if (termArray[i].exp == p.termArray[j].exp)
				{
					temp->termArray[count].coef=(termArray[i].coef)+(p.termArray[j].coef);
					temp->termArray[count].exp = (termArray[i].exp);
					count2++;
				}
			}
		}
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < p.size; j++)
			{
				if (termArray[i].exp != p.termArray[j].exp)
				{
					temp->termArray[count].coef = (termArray[i].coef) + (p.termArray[j].coef);
					temp->termArray[count].exp = (termArray[i].exp);
					count2++;
				}
			}
		}
		for (int i = 0; i < p.size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (p.termArray[i].exp != termArray[j].exp)
				{
					temp->termArray[count].coef = (termArray[i].coef) + (p.termArray[j].coef);
					temp->termArray[count].exp = (termArray[i].exp);
					count++;
				}
			}
		}
		return *temp;
	}
	Polynomial& operator -(Polynomial& p)
	{
		int count = 0;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < p.size; j++)
			{
				if (termArray[i].exp == p.termArray[j].exp)
				{
					count++;
				}
			}
		}
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < p.size; j++)
			{
				if (termArray[i].exp != p.termArray[j].exp)
				{
					count++;
				}
			}
		}
		for (int i = 0; i < p.size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (p.termArray[i].exp != termArray[j].exp)
				{
					count++;
				}
			}
		}
		Polynomial* temp = new Polynomial[count];
		int count2 = 0;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < p.size; j++)
			{
				if (termArray[i].exp == p.termArray[j].exp)
				{
					temp->termArray[count].coef = (termArray[i].coef) - (p.termArray[j].coef);
					temp->termArray[count].exp = (termArray[i].exp);
					count2++;
				}
			}
		}
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < p.size; j++)
			{
				if (termArray[i].exp != p.termArray[j].exp)
				{
					temp->termArray[count].coef = (termArray[i].coef) - (p.termArray[j].coef);
					temp->termArray[count].exp = (termArray[i].exp);
					count2++;
				}
			}
		}
		for (int i = 0; i < p.size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (p.termArray[i].exp != termArray[j].exp)
				{
					temp->termArray[count].coef = (termArray[i].coef) - (p.termArray[j].coef);
					temp->termArray[count].exp = (termArray[i].exp);
					count++;
				}
			}
		}
		return *temp;
	}
	void Clear()
	{
		for (int i = 0; i < size; i++)
		{
			termArray[i].coef = 0;
			termArray[i].exp = 0;
		}
	}
	bool addToCoefficient(float coefficient, int power)
	{
		for (int i = 0; i < size; i++)
		{
			if (termArray[i].exp == power)
			{
				termArray[i].coef=coefficient;
				return true;
			}
		}
		return false;
	}
	Polynomial& derivative()
	{
		Polynomial* temp = new Polynomial[size];
		for (int i = 0; i < size; i++)
		{
			temp->termArray[i].coef = (termArray[i].coef) * (termArray[i].exp);
			temp->termArray[i].exp = (termArray[i].exp) - 1;
		}
		return *temp;
	}
};

int main()
{
	Polynomial P1(3);
	P1.addTerm(2.0,3);
	P1.addTerm(3.9, 2);
	P1.addTerm(4.1, 1);
	P1.addToCoefficient(1.9,2);
	


	return 0;
}