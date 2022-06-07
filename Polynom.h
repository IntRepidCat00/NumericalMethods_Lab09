#ifndef LAB09_POLYNOM_H
#define LAB09_POLYNOM_H
#include <iostream>
#include <cmath>

class Polynom
{
public:
    Polynom(std::string nm = "", int pow = 1)
        : name{nm}, power{pow+1}
    {
        AVect = new double[pow];
    }
    ~Polynom()
    {
        if(AVect != nullptr)
        {
            delete AVect;
            AVect = nullptr;
        }
        if(PMatr != nullptr)
        {
            for(int i{0}; i < power; i++)
            {
                if(PMatr[i] != nullptr)
                {
                    delete PMatr[i];
                }
            }
            delete [] PMatr;
            PMatr = nullptr;
        }
        if(CVect != nullptr)
        {
            delete CVect;
            CVect = nullptr;
        }
    }
    void setPower(int pow) {power = pow;}
    void setName(std::string nm) {name = nm;}
    std::string getName() {return name;}
    void printTable();
    void calcPolynom();
    void printPolynom();
    void polyInPoint(double point);
private:
    std::string name{""};
    double size{6};
    double XVect[6] {0.05, 0.10, 0.17, 0.25, 0.30, 0.36};
    double YVect[6] {0.54, 0.51, 0.47, 0.45, 0.42, 0.38};
    int power{1};
    double *AVect;
    double **PMatr;
    double *CVect;
    void printExtendedMatrix();
    void swapRows(int row1, int row2);
    void addRow(int rowToAdd, int rowAdded, double mult);
    void GaussianMethod();
};


#endif //LAB09_POLYNOM_H
