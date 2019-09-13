#include "mat.h"

int main()
{
    int s1x, s1y, s4x, s4y;
    cout << "enter size of m1 & m2 & m3" << endl;
    cin  >> s1x >> s1y;

    cout << "enter size of m4" << endl;
    cin  >> s4x >> s4y;

    mat m1(s1x,s1y), m2(s1x, s1y), m3(s1x, s1y), m4(s4x, s4y);

    cout << "enter numbers" << endl;
    cout << "m2" << endl;
    cin >> m2;
    cout << "check yourself" << endl;
    cout <<  m2 << endl;

    cout << "m3" << endl;
    cin >> m3;
    cout << "check yourself" << endl;
    cout <<  m3 << endl;

    cout << "m4" << endl;
    cin >> m4;
    cout << "check yourself" << endl;
    cout <<  m4 << endl;

    try
    {
        m1 = m2 + m3;
        cout << "m1 = m2 + m3" << endl;
        cout << m1 << endl;
    }
    catch (const char* exc)
    {
        cout << exc << endl;
    }

    try
    {
        m1 = m3 + m4;
        cout << "m1 = m3 + m4" << endl;
        cout << m1 << endl;
    }
    catch (const char* exc)
    {
        cout << "exception: " << exc << endl;
    }

    cout << "m1, m2, m3, m4:" << endl;
    cout << m1 << endl << m2 << endl << m3 << endl << m4 << endl;

    try
    {
        m1 = m2 - m3;
        cout << "m1 = m2 - m3" << endl;
        cout << m1 << endl;
    }
    catch (const char* exc)
    {
        cout << exc << endl;
    }

    try
    {
        m1 = m2 * m3;
        cout << "m1 = m2 * m3" << endl;
        cout << m1 << endl;
    }
    catch (const char* exc)
    {
        cout << exc << endl;
    }
    try
    {
        m1 = m3 * m4;
        cout << "m1 = m3 * m4" << endl;
        cout << m1 << endl;
    }
    catch (const char* exc)
    {
        cout << exc << endl;
    }

    m1 = m2 + 40.0;
    cout << "m1 = m2 + 40.0" << endl;
    cout << m1 << endl;

    m1 = m2 - 50.0;
    cout << "m1 = m2 - 50.0" << endl;
    cout << m1 << endl;

    m1 = m2 * 10.0;
    cout << "m1 = m2 * 10.0" << endl;
    cout << m1 << endl;

    m1 += 40.0;
    cout << "m1 += 40.0" << endl;
    cout << m1 << endl;

    m1 -= 50.0;
    cout << "m1 -= 50.0" << endl;
    cout << m1 << endl;

    m1 *= 10.0;
    cout << "m1 *= 10.0" << endl;
    cout << m1 << endl;

    try
    {
        cout << "m2[1] = " << *m2[1] << endl;
        *m2[1] = 5.0;
        cout << "DO m2[1] = 5; RESULT m2[1]= " << *m2[1] << endl;
    }

    catch (const char* exc)
    {
        cout << exc << endl;
    }

    system ("pause");
    return 0;
}