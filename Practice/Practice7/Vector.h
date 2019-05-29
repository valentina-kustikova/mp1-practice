#pragma once
class Vector
{
private:
    int dim;      
    double *x; 
public:
    Vector(); //�� ���������
    Vector(int _dim); //� ����������
    Vector(const Vector& v); //�����������
    ~Vector();//����������

    
    Vector& operator= (const Vector & v);
    Vector operator+ (const Vector& v);
    Vector operator- (const Vector& v);
    double operator* (const Vector& v);
    Vector operator+ (double dig);
    Vector operator- (double dig);
    Vector operator* (double dig);
    Vector& operator+= (const Vector & v);
    Vector& operator-= (const Vector & v);
    Vector& operator*= (const Vector & v);
    Vector& operator+= (double dig);
    Vector& operator-= (double dig);
    Vector& operator*= (double dig);
    double& operator[] (int idx);
    const double& operator[] (int idx) const;

    void Length();
    void Fill();
    void Print();

} ;

void Menu();
double Digital();