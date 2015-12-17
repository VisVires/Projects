/*
Author: William George
Date Created: 7/28/15
Date Last Modified: 7/29/15
Purpose: Uses Durnin and Womersley 4-site skin fold body fat measurement
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

double calcBodyFat(const vector<double>& pinches, const int age, const char sex);
bool male(const char mf);
double calcDensityM(const int age, double logSum);
double calcDensityF(const int age, double logSum);
double siriEquation(double density);


int main()
{
    double bicep = 0;
    double tricep = 0;
    double subscap = 0;
    double suprailiac = 0;
    int age;
    char sex;
    vector<double> pinches;

    cout <<"Please enter your age: ";
    cin >>age;

    cout <<"Enter sex: (M or F) ";
    cin >> sex;

    cout <<"Please enter the Bicep Measurement: ";
    cin >> bicep;
    pinches.push_back(bicep);

    cout << "Please enter the Tricep Measurement: ";
    cin >> tricep;
    pinches.push_back(tricep);

    cout <<"Please enter the Subscapular Measurement: ";
    cin >> subscap;
    pinches.push_back(subscap);

    cout <<"Please enter the Suprailiac Measurement: ";
    cin >> suprailiac;
    pinches.push_back(suprailiac);

    double bodyfat = calcBodyFat(pinches, age, sex);
    cout << "You are "<< std::setprecision(2)<< std::fixed<< bodyfat << "% body fat" << endl;

return 0;
}

double calcBodyFat(const vector<double>& pinches, const int age, const char sex)
{
    double sumOfSkin = 0.0;
    double logSum;
    double density;
    double bodyFat;
    for (vector<int>::size_type i = 0; i != pinches.size(); ++i)
    {
        sumOfSkin += (double)pinches[i];
    }

    logSum = log10(sumOfSkin);
    cout << logSum << endl;

    male(sex) ? density = calcDensityM(age, logSum): density = calcDensityF(age, logSum);

    bodyFat = siriEquation(density);

    return bodyFat;
}

bool male(const char mf)
{
    if (mf == 'm' || mf == 'M')
        return true;
    return false;

}

double calcDensityM(const int age, double logSum)
{
    double density;
    if (age < 17)
    {
        density = (1.1533 - (.0643 * logSum));
    }
    else if (age <= 19)
    {
        density = (1.1620 - (.0630 * logSum));
    }
    else if (age <= 29)
    {
         density = (1.1631 - (.0632 * logSum));
    }
    else if (age <= 39)
    {
         density = (1.1422 - (.0544 * logSum));
    }
    else if (age <= 49)
    {
         density = (1.1620 - (.0700 * logSum));
    }
    else if (age > 50)
    {
         density = (1.1715 - (.0779 * logSum));
    }
    return density;
}

double calcDensityF(const int age, double logSum)
{
    double density;
    if (age < 17)
    {
        density = (1.1369 - (.0598 * logSum));
    }
    else if (age <= 19)
    {
        density = (1.1549 - (.0678 * logSum));
    }
    else if (age <= 29)
    {
         density = (1.1599 - (.0717 * logSum));
    }
    else if (age <= 39)
    {
         density = (1.1423 - (.0632 * logSum));
    }
    else if (age <= 49)
    {
         density = (1.1333 - (.0612 * logSum));
    }
    else if (age > 50)
    {
         density = (1.1339 - (.0645 * logSum));
    }
    return density;
}

double siriEquation(double density)
{
    return (495/density) - 450;
}
