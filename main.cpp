#include <iostream>
#include <fstream>
#include <math.h>
#include <time.h>

int main(int argc, char* argv[]) {
    if(argc != 3)
    {
        std::cout << "Please specify Poisson distribution expectation and size of the sample!";
        return -1;
    }
    double expectation;
    int size;
    try
    {
        expectation = std::stod(argv[1]);
        size = std::stoi(argv[2]);
        if((std::string(argv[2]).find_first_not_of("0123456789") != -1) || (expectation <= 0))
            throw std::invalid_argument ("");
    }
    catch (std::invalid_argument&) {
        std::cout << "Please specify Poisson distribution expectation and size of the sample!";
        return -2;
    }
    catch (std::out_of_range&) {
        std::cout << "Please specify expectation of double type and size of the sample of integer type!";
        return -3;
    }

    std::ofstream output("Poisson distribution sample.txt");
    if(output.is_open()) {
        srand(time(0));
        for (int i = 0; i < size; i++)
        {
            double p = exp(-1 * expectation);
            int x = 0;
            double r = (double) rand() / RAND_MAX - p;
            while (r >= 0)
            {
                x += 1;
                p = p * expectation / x;
                r -= p;
            }
            output << x << std::endl;
        }
        output.flush();
        output.close();
        return 0;
    }
    else
    {
        std::cout << "Couldn't open output file!";
        return -4;
    }
}
