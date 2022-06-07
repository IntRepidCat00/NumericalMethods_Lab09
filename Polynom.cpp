#include "Polynom.h"

void Polynom::printTable()
{
    std::string divideLine(80, '_');
    std::cout << "=== " << name << " ===" << std::endl;
    std::cout << divideLine << std::endl;
    std::cout << "| X | ";
    for(int i{0}; i < size; i++)
    {
        std::cout << XVect[i] << " | ";
    }
    std::cout << std::endl << "| Y | ";
    for(int i{0}; i < size; i++)
    {
        std::cout << YVect[i] << " | ";
    }
    std::cout << std::endl;
    std::cout << divideLine << std::endl;
}

void Polynom::printExtendedMatrix()
{
    std::string divideLine(80, '-');
    std::cout << divideLine << std::endl;
    for(int i{0}; i < power; i++)
    {
        for(int j{0}; j < power; j++)
        {
            std::cout << PMatr[i][j] << " ";
        }
        std::cout << "| " << CVect[i] << std::endl;
    }
    std::cout << divideLine << std::endl;
}

void Polynom::swapRows(int row1, int row2)
{
    double temp[power+1];

    for(int i{0}; i < power; i++)
    {
        temp[i] = PMatr[row1][i];
    }
    temp[power] = CVect[row1];
    for(int i{0}; i < power; i++)
    {
        PMatr[row1][i] = PMatr[row2][i];
    }
    CVect[row1] = CVect[row2];
    for(int i{0}; i < power; i++)
    {
        PMatr[row2][i] = temp[i];
    }
    CVect[row2] = temp[power];
}

void Polynom::addRow(int rowToAdd, int rowAdded, double mult)
{
    for(int i{0}; i < power; i++)
    {
        PMatr[rowToAdd][i] += PMatr[rowAdded][i] * mult;
    }
    CVect[rowToAdd] += CVect[rowAdded] * mult;
}

void Polynom::GaussianMethod()
{
    std::cout << "************************* Gaussian Method **************************************"
              << std::endl;
    printExtendedMatrix();
    double biggest{0};
    int mainRow{0};
    for(int i{0}; i < power-1; i++)
    {
        biggest = PMatr[i][i];
        mainRow = i;
        for(int j{i}; j < power; j++)
        {
            if(biggest < fabs(PMatr[j][i]))
            {
                biggest = fabs(PMatr[j][i]);
                mainRow = j;
            }
        }
        if(mainRow != i)
        {
            swapRows(mainRow, i);
        }
        double mult{0};
        for(int j{i+1}; j < power; j++)
        {
            if(PMatr[i][i] != 0)
            {
                mult = PMatr[j][i] / PMatr[i][i];
                addRow(j, i, -mult);
            }
        }
        printExtendedMatrix();
    }

    AVect[power-1] = CVect[power-1]/PMatr[power-1][power-1];

    for(int i{1}; i < power; i++)
    {
        double sub{0};
        for(int j{0}; j < power; j++)
        {
            sub+= AVect[power-1-j]*PMatr[power-1-i][power-1-j];
        }
        AVect[power-1-i] = (CVect[power-1-i]-sub)/PMatr[power-1-i][power-1-i];
    }


    std::cout << std::endl;
    for(int i{0}; i < power; i++)
    {
        std::cout << "a[" << i+1 << "] = " << AVect[i] << std::endl;
    }
}

void Polynom::calcPolynom()
{
    std::string divideLine(80, '_');
    std::cout << divideLine << std::endl;
    std::cout << "The least squares method" << std::endl;
    CVect = new double[power];
    PMatr = new double*[power];
    for(int i{0}; i < power; i++)
    {
        PMatr[i] = new double[power];
    }
    for(int i{0}; i < power; i++)
    {
        for(int j{0}; j < power; j++)
        {
            double P{0};
            for(int k{0}; k < size; k++)
            {
                P+=pow(XVect[k], (j+i));
            }
            PMatr[i][j] = P;
        }
        double C{0};
        for(int j{0}; j < size; j++)
        {
            C+=YVect[j]*pow(XVect[j], i);
        }
        CVect[i] = C;
    }
    printExtendedMatrix();
    GaussianMethod();
    std::cout << "Polynom was calculated" << std::endl;
}

void Polynom::printPolynom()
{
    std::cout << name << " = ";
    for(int i{0}; i < power; i++)
    {
        if(AVect[i] > 0)
        {
            std::cout << " + " << AVect[i] << "*x^(" << i << ")";
        } else if(AVect[i] < 0)
        {
            std::cout << " - " << AVect[i]*(-1) << "*x^(" << i << ")";
        } else
        {
            std::cout << AVect[i] << "*x^(" << i << ")";
        }
    }
    std::cout << std::endl;
}

void Polynom::polyInPoint(double point)
{
    double res{0};
    for(int i{0}; i < power; i++)
    {
        res += AVect[i] * pow(point, i);
    }
    std::cout << "Polynom in point " << point << " is " << res << std::endl;
}