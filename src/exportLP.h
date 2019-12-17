#include <fstream>

#include "QuineMcCluskey.h"

#include "print.h"


template <typename type>
void export_LP(const minterms_t<type>& minterms, const terms_t<type>& primeimplicants, const chart_t<type>& mintermschart, const chart_t<type>& primeimplicantschart, std::ofstream& os, const char* name, int mode)
{
    using big = typename type::big;

    const big pisize = static_cast<big>(primeimplicants.size());
    const big mtsize = static_cast<big>(minterms.size());
    bool first;

    bool binaries = (mode == 0);
    bool integers = (mode == 1);
    bool reals = !(binaries || integers);

    // \problem: AES =0
    os << "\\problem: " << name << std::endl;
    os << std::endl;

    // Minimize
    // 4x1 + 5x2 + 3x3

    os << "Minimize" << std::endl;
    for (big ipi = 0; ipi < pisize; ipi++)
    {
        if (ipi > 0) os << " + ";
        os << 'x' << (ipi+1);
    }
    os << std::endl;
    os << std::endl;

    // Subject To
    // x1 + x2 + 2x3 <= 20
    // 15x1 + 6x2 –5x3 <= 50
    // x1 + 3x2 + 5x3 <= 30

    os << "Subject To" << std::endl;
    for (big imt = 0; imt < mtsize; imt++)
    {
        auto& mtpi = mintermschart[imt];
        first = true;
        for (big ipi : mtpi)
        {
        if (!first) os << " + ";
        os << 'x' << (ipi+1);
        first = false;
        }
        os << " >= 1" << std::endl;
    }
    os << std::endl;

    if (not binaries)
    {

    // Bounds
    // x3 <= 5.5

    os << "Bounds" << std::endl;
    for (big ipi = 0; ipi < pisize; ipi++)
    {
        os << "0 <= " << 'x' << (ipi+1) << " <= 1" << std::endl;
    }
    os << std::endl;

    }

    if (not reals)
    {

    // x3

    if (binaries) os << "Binaries" << std::endl;
    if (integers) os << "Generals" << std::endl;
    first = true;
    for (big ipi = 0; ipi < pisize; ipi++)
    {
        if (!first) os << ' ';
        os << 'x' << (ipi+1);
        first = false;
    }
    os << std::endl;
    os << std::endl;

    }

    // \Values
    // \x1=... x2=... ...

    os << "\\ Values" << std::endl;
    os << "\\ ";
    first = true;
    for (big ipi = 0; ipi < pisize; ipi++)
    {
        if (!first) os << ' ';
        os << 'x' << (ipi+1) << '=';
        print_bin_star<type>(os, primeimplicants[ipi].first, primeimplicants[ipi].second);
        first = false;
    }
    os << std::endl;
    os << std::endl;

    os << "End" << std::endl;
}

