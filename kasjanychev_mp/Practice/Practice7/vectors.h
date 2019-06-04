#pragma once

class Vectors
{
private:
	int s;
	double *arr;
public:
	Vectors();
	Vectors(int x);
	Vectors(const Vectors& vct);
	~Vectors();
	Vectors operator+ (const Vectors & temp) const;
	Vectors operator- (const Vectors & temp) const;
	double operator* (const Vectors & temp) const;
	Vectors operator+ (double temp) const;
	Vectors operator- (double temp) const;
	Vectors operator* (double temp) const;
	const Vectors& operator= (const Vectors & temp);
	const double& operator[] (int i) const;
    double& operator[] (int i);
	double Lenght() const;
	Vectors& operator+= (const Vectors & temp);
	Vectors& operator-= (const Vectors & temp);
	Vectors& operator*= (double temp);
	void PrVec() const;
	void ScVec();
};