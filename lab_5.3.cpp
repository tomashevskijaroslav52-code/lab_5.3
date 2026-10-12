#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double z(const double x);
double term(const double x, const int k, double a);
double series_sum(const double x, const double eps);

int main()
{
    double p_piv, p_kin;
    int n;

    cout << "p_piv = "; cin >> p_piv;
    cout << "p_kin = "; cin >> p_kin;
    cout << "n     = "; cin >> n;

    double dp = (p_kin - p_piv) / n;

    cout << endl;
    cout << "----------------------------------------" << endl;
    cout << "|" << setw(12) << "p"
        << " |" << setw(20) << "Result" << " |" << endl;
    cout << "----------------------------------------" << endl;

    double p = p_piv;
    for (int i = 0; i <= n; i++)
    {

        double val1 = z(p * p);
        double val2 = z(2 * p + p * p);
        double result = val1 + 2 * val2 + 1;

        cout << "|" << setw(12) << setprecision(4) << fixed << p
            << " |" << setw(20) << setprecision(5) << fixed << result << " |" << endl;

        p += dp;
    }
    cout << "----------------------------------------" << endl;

    return 0;
}

double term(const double x, const int k, double a)
{
    double R = (4 * x * x) / (2 * k * (2 * k + 1));
    return a * R;
}

double series_sum(const double x, const double eps = 0.00001)
{
    int k = 1;
    double a = 2 * x;
    double s = a;

    while (abs(a) >= eps)
    {
        a = term(x, k, a);
        s += a;
        k++;
    }
    return s;
}

double z(const double x)
{
    if (abs(x) >= 1)
    {
        return (cos(2 * x) + 1) / (cos(x) + sin(x) * sin(x));
    }
    else
    {
        return series_sum(x);
    }
}
