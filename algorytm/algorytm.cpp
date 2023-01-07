// algorytm.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <cmath>
#include <complex>
#include <random>
#include <time.h>
#include "matrix.h"
#include <vector>
#include <cstdlib>
using namespace std::complex_literals;
using namespace std;

complex<double>** multiplication(int i, int j, int k, int r1, int r2, int c1, int c2, complex<double> mult[2][2], complex<double> first[2][2], complex<double> second[2][2]) {

    complex<double>** tab = new complex<double>* [r1];

    printf("multiply of the matrix=\n");
    for (i = 0; i < 2; i++)
    {
        tab[i] = new complex<double>[2];
    }
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
        {
            tab[i][j] = 0;
            for (k = 0; k < c1; k++)
            {
                tab[i][j] += first[i][k] * second[k][j];
            }
        }
    }
    //for printing result    
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            cout << tab[i][j] << " ";
        }
        printf("\n");
    }
    return tab;


}

int main()
{
    double pH = 3.141592/4;
    const double e = 2.71828;
    int tmp = 3;
   /* complex<double> h[2][2] = { {1 / sqrt(2), 1 / sqrt(2)}, {1 / sqrt(2), -1 / sqrt(2)} };
    complex<double> p[2][2] = { {1, 0}, {0, exp(pH * 1i) } };
    complex<double> mult[2][2] = { {0, 0}, {0, 0} };
    complex<double> slope[2][2] = { {0}, {1} };
    complex<double>** res;
    complex<double>** res2;*/
    Matrix h(2, 2, std::vector<std::vector<std::complex<double>>>{ {1 / sqrt(2), 1 / sqrt(2)}, { 1 / sqrt(2), -1 / sqrt(2) } });
    Matrix p(2, 2, std::vector<std::vector<std::complex<double>>>{ {1, 0}, { 0, exp(pH * 1i) } });
    Matrix mult(2, 2, std::vector<std::vector<std::complex<double>>>{ {0, 0}, {0, 0} });
    Matrix slope(2, 1, std::vector<std::vector<std::complex<double>>>{ {1}, {0} });
    Matrix slope2(2, 1, std::vector<std::vector<std::complex<double>>>{ {1}, {0} });
    Matrix cp(4, 4, std::vector<std::vector<std::complex<double>>>{ {1,0,0,0}, { 0,1,0,0 }, { 0,0,1,0 }, { 0,0,0,exp(pH * 1i) } });
    Matrix tp(4, 1);
    Matrix qnot(2, 2, std::vector<std::vector<std::complex<double>>>{ {0, 1}, {1, 0} });
    //tp = slope.tensorProduct(slope2);
    //cout << tp;
    Matrix res(2, 1);
    Matrix res2(2, 1);

    //res = h * slope ;
    //cout << res;
    //res2 = p * res;
    //cout << res2;
    //res = h * res2;
    //cout << res;

    //slope = h * slope;
    //cout << slope;
    //slope2 = qnot * slope2;
    //cout << slope2;
    //tp = slope2.tensorProduct(slope);
    //cout << tp;
    //cout << cp;
    //cout << p;
    //tp = cp * tp;
    //cout << tp;

    slope = h * slope;
    cout << slope;
    slope2 = qnot * slope2;
    cout << slope2;
    slope2 = p * slope2;
    cout << slope2;
    tp = slope2.tensorProduct(slope);
    cout << tp;
    slope = p * slope;
    slope2 = p * (-1 *slope2);
    cout << slope2;
    tp = slope2.tensorProduct(slope);
    cout << tp;
    cout << log(tp[3][0] / tp[1][0].real()).imag() << endl;
    char b[32];
    for (int i = 0; i < tp.size_y(); i++){
        cout << "probability for state "<< _itoa(i,b,2) << ": " << pow(abs(tp[i][0]), 2)<< endl;
        
    }


    const int nrolls = 10000; // number of experiments
    std::default_random_engine generator;
    std::bernoulli_distribution distribution(pow(abs(tp[1][0]),2));
    int count = 0;  // count number of trues

    srand(time(NULL));
    generator.seed(rand());

    for (int i = 0; i < nrolls; ++i) if (distribution(generator)) ++count;
    cout << count << endl;
    cout << (double)count / nrolls << endl;
            return 0;
    

}
