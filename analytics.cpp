#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <stdio.h>
#include "analytics.h"

/*
void print_list(int *list, const int LENGTH)
{
    for (int i = 0; i < 10; i++)
    {
        std::cout << *(list + i);
        if (i - 1 < LENGTH)
        {
            std::cout << ' ';
        }
    }
}

void print_sub_vector(std::vector <GradEmploymentData> grad_employment_data, int total, int last)
{
    for(int i = 0; i < last; i++)
    {
        grad_employment_data[total].educationMajor;
        grad_employment_data[total].meanSalary;
        grad_employment_data[total].medianSalary;
        grad_employment_data[total].demographicsAsian;
        grad_employment_data[total].demographicsMinority;
        grad_employment_data[total].demographicsWhite;
        grad_employment_data[total].demographicsFemales;
        grad_employment_data[total].demographicsMales;
        grad_employment_data[total].educationBachelor;
        grad_employment_data[total].educationDoctorate;
        grad_employment_data[total].educationMasters;
        if (i < last - 1)
        {
            std::cout << "\n\n";
        }
    }
}
*/

/**
 * display menu from user will select from a list of options
*/
void print_main_menu()
{
    std::cout << "2015 National Survey of Recent College Graduate"
        <<"\n1. Top 10 Majors with the Highest Mean Salary"
        << "\n2. Top 10 Majors with the Lowest Mean Salary"
        << "\n3. Top 10 Majors with the Highest Median Salary"
        << "\n4. Top 10 Majors with the Lowest Median Salary"
        << "\n5. What are the Top 5 Majors with the Highest Number of Asians"
        << "\n6. What are the Top 5 Majors with the Lowest Number of Asians"
        << "\n7. What are the Top 5 Majors with the Highest Number of Minorities"
        << "\n8. What are the Top 5 Majors with the Lowest Number of Minorities"
        << "\n9. Show number of Majors on file"
        << "\n10. Show Grand Total Demographic of all Majors"
        << "\n11. Display Information for a Specific Major"
        << "\n12. Exit"
        << "\n\nSelect a Menu Item: ";
}

/**
 * displays mean salary data for employee type
 * 
 * @param grad_employment_data used to store mean salary data for employee type, which is then printed onto the screen
*/
void print_mean_salaries(std::vector <GradEmploymentData> grad_employment_data)
{
    std::cout.width(35);
    std::cout << std::left << "Education Major" << std::setw(11) << "Mean Salary"
        << "\n------------------------------------------------\n";
    for(int i = 0; i < 10; i++)
    {
        std::cout.width(35);
        std::cout << std::left << grad_employment_data[i].educationMajor
            << std::left << '$'
            << std::setw(11) << std::right << std::fixed << std::showpoint << std::setprecision(2) << grad_employment_data[i].meanSalary
            << '\n';
    }
}

/**
 * displays median salary data for employee type
 * 
 * @param grad_employment_data used to store median salary data for employee type, which is then printed onto the screen
*/
void print_median_salaries(std::vector <GradEmploymentData> grad_employment_data)
{
    std::cout.width(35);
    std::cout << std::left << "Education Major" << std::setw(11) << "Median Salary"
        << "\n--------------------------------------------------\n";
    for(int i = 0; i < 10; i++)
    {
        std::cout.width(35);
        std::cout << std::left << grad_employment_data[i].educationMajor
            << std::setw(0) << '$'
            << std::setw(11) << std::right << std::fixed << std::showpoint << std::setprecision(2) << grad_employment_data[i].medianSalary
            << '\n';
    }
}

/**
 * displays number of Asians data for employee type
 * 
 * @param grad_employment_data used to store number of Asians data for employee type, which is then printed onto the screen
*/
void print_number_of_asians(std::vector <GradEmploymentData> grad_employment_data)
{
    std::cout.width(35);
    std::cout << std::left << "Education Major" << std::setw(11) << "Asians Demographic"
        << "\n-----------------------------------------------------\n";
    for(int i = 0; i < 5; i++)
    {
        std::cout.width(35);
        std::cout << std::setw(35) << grad_employment_data[i].educationMajor << std::setw(10) << grad_employment_data[i].demographicsAsian
            << '\n';
    }
}

/**
 * displays number of minorities data for employee type
 * 
 * @param grad_employment_data used to store number of minorities data for employee type, which is then printed onto the screen
*/
void print_number_of_minorities(std::vector <GradEmploymentData> grad_employment_data)
{
    std::cout.width(35);
    std::cout << std::left << "Education Major" << std::setw(11) << "Minorities Demographic"
        << "\n--------------------------------------------------------\n";
    for(int i = 0; i < 5; i++)
    {
        std::cout.width(35);
        std::cout << std::setw(35) << grad_employment_data[i].educationMajor << std::setw(10) << grad_employment_data[i].demographicsMinority
            << '\n';
    }
}

/*
void print_highest_lowest_number_of_minorities(std::vector <GradEmploymentData> grad_employment_data)
{
    std::cout.width(35);
    std::cout << std::left << "Education Major"  << std::setw(11) << "Minorities Demographic"
        << "\n------------------------------------------------\n";
    for(int i = 0; i < 5; i++)
    {
        std::cout << grad_employment_data[i].demographicsMinority
            << '\n';
    }
}
*/

/**
 * searches data for a string, to_search, that had been typed
 * 
 * @param grad_employment_data 
 * @param to_search 
 * @param position 
 * @return ?
*/
bool binary_search_vector(std::vector <GradEmploymentData> grad_employment_data, std::string to_search, int &position)
{
    int low = 0, middle = 0, high = (grad_employment_data.size() - 1);
    while (low <= high)
    {
        // std::cout << to_search << '\n';
        // std::cout << grad_employment_data[middle].educationMajor;
        /*
        std::cout << "\nlow:" << low << " high: " << high << " middle: " << middle
        << '\n';
        */
        middle = (low + high) / 2;
        if (grad_employment_data[middle].educationMajor > to_search)
        {
            high = middle - 1; // search in lower half
        }
        else if (grad_employment_data[middle].educationMajor < to_search)
        {
            low = middle + 1; // search in upper half
        }
        else
        {
            position = middle;
            return true;
        }
    }
    return false;
}

/*
void binary_search_vector(std::vector <GradEmploymentData> grad_employment_data, std::string to_search, int &steps, bool &found)
{
    int low = 0, middle = 0, high = (grad_employment_data.size() - 1);
    while (low <= high && found == false)
    {
        // std::cout << "\nlow:" << low << " high: " << high << " middle: " << middle
        // << '\n';
        middle = (low + high) / 2;
        if (grad_employment_data[middle].educationMajor > to_search)
        {
            high = middle - 1; // search in lower half
        }
        else if (grad_employment_data[middle].educationMajor < to_search)
        {
            low = middle + 1; // search in upper half
        }
        else
        {
            found = true;
        }
        steps++;
    }
}
*/

/*
void binary_search_vector(std::vector <GradEmploymentData> grad_employment_data, std::string to_search, int steps)
{
    int mid = grad_employment_data.size() / 2, low = 0, high = grad_employment_data.size() - 1;
    if (to_search == grad_employment_data[mid].educationMajor)
    {

    }
    else if (x > grad_employment_data[mid]) // to_search is on the right side
    {
       low = mid + 1;
    }
    else
    {
       high = mid - 1; // to_search is on the left side
    }
}
*/

/**
 * does something
 * 
 * @param a
 * @return a
*/
void insertion_sort_by_education_major_ascending(std::vector <GradEmploymentData> &grad_employment_data, int num_of_majors)
{
    std::string key; // key = education major
    float meanSal, medSal;
    int i, j, demoTot, demoAsian, demoMin, demoWhite, demoFemales, demoMales, edBach, edDoct, edMast;
    for (i = 1; i < num_of_majors; i++)
    {
        key = grad_employment_data[i].educationMajor; // key for sort (education major)
        demoTot = grad_employment_data[i].demographicsTotal;
        meanSal = grad_employment_data[i].meanSalary;
        medSal = grad_employment_data[i].medianSalary;
        demoAsian = grad_employment_data[i].demographicsAsian;
        demoMin = grad_employment_data[i].demographicsMinority;
        demoWhite = grad_employment_data[i].demographicsWhite;
        demoFemales = grad_employment_data[i].demographicsFemales;
        demoMales = grad_employment_data[i].demographicsMales;
        edBach = grad_employment_data[i].educationBachelor;
        edDoct = grad_employment_data[i].educationDoctorate;
        edMast = grad_employment_data[i].educationMasters;
        j = i - 1;

        while (j >= 0 && (grad_employment_data[j].educationMajor > key))
        {
            grad_employment_data[j + 1].demographicsTotal = grad_employment_data[j].demographicsTotal;
            grad_employment_data[j + 1].educationMajor = grad_employment_data[j].educationMajor;
            grad_employment_data[j + 1].meanSalary = grad_employment_data[j].meanSalary;
            grad_employment_data[j + 1].medianSalary = grad_employment_data[j].medianSalary;
            grad_employment_data[j + 1].demographicsAsian = grad_employment_data[j].demographicsAsian;
            grad_employment_data[j + 1].demographicsMinority = grad_employment_data[j].demographicsMinority;
            grad_employment_data[j + 1].demographicsWhite = grad_employment_data[j].demographicsWhite;
            grad_employment_data[j + 1].demographicsFemales = grad_employment_data[j].demographicsFemales;
            grad_employment_data[j + 1].demographicsMales = grad_employment_data[j].demographicsMales;
            grad_employment_data[j + 1].educationBachelor = grad_employment_data[j].educationBachelor;
            grad_employment_data[j + 1].educationDoctorate = grad_employment_data[j].educationDoctorate;
            grad_employment_data[j + 1].educationMasters = grad_employment_data[j].educationMasters;
            j = j - 1;
        }
        grad_employment_data[j + 1].educationMajor = key; // key for sort (education major)
        grad_employment_data[j + 1].demographicsTotal = demoTot;
        grad_employment_data[j + 1].meanSalary = meanSal;
        grad_employment_data[j + 1].medianSalary = medSal;
        grad_employment_data[j + 1].demographicsAsian = demoAsian;
        grad_employment_data[j + 1].demographicsMinority = demoMin;
        grad_employment_data[j + 1].demographicsWhite = demoWhite;
        grad_employment_data[j + 1].demographicsFemales = demoFemales;
        grad_employment_data[j + 1].demographicsMales = demoMales;
        grad_employment_data[j + 1].educationBachelor = edBach;
        grad_employment_data[j + 1].educationDoctorate = edDoct;
        grad_employment_data[j + 1].educationMasters = edMast;
    }
}

/**
 * does something
 * 
 * @param a
 * @return a
*/
void insertion_sort_by_highest_mean_salary(std::vector <GradEmploymentData> &grad_employment_data, int num_of_majors)
{
    std::string educMaj;
    float key, medSal; // key = mean salary
    int i, j, demoTot, demoAsian, demoMin, demoWhite, demoFemales, demoMales, edBach, edDoct, edMast;
    for (i = 1; i < num_of_majors; i++)
    {
        key = grad_employment_data[i].meanSalary; // key for sort (mean salary)
        demoTot = grad_employment_data[i].demographicsTotal;
        educMaj = grad_employment_data[i].educationMajor;
        medSal = grad_employment_data[i].medianSalary;
        demoAsian = grad_employment_data[i].demographicsAsian;
        demoMin = grad_employment_data[i].demographicsMinority;
        demoWhite = grad_employment_data[i].demographicsWhite;
        demoFemales = grad_employment_data[i].demographicsFemales;
        demoMales = grad_employment_data[i].demographicsMales;
        edBach = grad_employment_data[i].educationBachelor;
        edDoct = grad_employment_data[i].educationDoctorate;
        edMast = grad_employment_data[i].educationMasters;
        j = i - 1;

        while (j >= 0 && (grad_employment_data[j].meanSalary < key))
        {
            grad_employment_data[j + 1].demographicsTotal = grad_employment_data[j].demographicsTotal;
            grad_employment_data[j + 1].educationMajor = grad_employment_data[j].educationMajor;
            grad_employment_data[j + 1].meanSalary = grad_employment_data[j].meanSalary;
            grad_employment_data[j + 1].medianSalary = grad_employment_data[j].medianSalary;
            grad_employment_data[j + 1].demographicsAsian = grad_employment_data[j].demographicsAsian;
            grad_employment_data[j + 1].demographicsMinority = grad_employment_data[j].demographicsMinority;
            grad_employment_data[j + 1].demographicsWhite = grad_employment_data[j].demographicsWhite;
            grad_employment_data[j + 1].demographicsFemales = grad_employment_data[j].demographicsFemales;
            grad_employment_data[j + 1].demographicsMales = grad_employment_data[j].demographicsMales;
            grad_employment_data[j + 1].educationBachelor = grad_employment_data[j].educationBachelor;
            grad_employment_data[j + 1].educationDoctorate = grad_employment_data[j].educationDoctorate;
            grad_employment_data[j + 1].educationMasters = grad_employment_data[j].educationMasters;
            j = j - 1;
        }
        grad_employment_data[j + 1].meanSalary = key; // key for sort (mean salary)
        grad_employment_data[j + 1].demographicsTotal = demoTot;
        grad_employment_data[j + 1].educationMajor = educMaj;
        grad_employment_data[j + 1].medianSalary = medSal;
        grad_employment_data[j + 1].demographicsAsian = demoAsian;
        grad_employment_data[j + 1].demographicsMinority = demoMin;
        grad_employment_data[j + 1].demographicsWhite = demoWhite;
        grad_employment_data[j + 1].demographicsFemales = demoFemales;
        grad_employment_data[j + 1].demographicsMales = demoMales;
        grad_employment_data[j + 1].educationBachelor = edBach;
        grad_employment_data[j + 1].educationDoctorate = edDoct;
        grad_employment_data[j + 1].educationMasters = edMast;
    }
}

/**
 * does something
 * 
 * @param a
 * @return a
*/
void insertion_sort_by_lowest_mean_salary(std::vector <GradEmploymentData> &grad_employment_data, int num_of_majors)
{
    std::string educMaj;
    float key, medSal; // key = mean salary
    int i, j, demoTot, demoAsian, demoMin, demoWhite, demoFemales, demoMales, edBach, edDoct, edMast;
    for (i = 1; i < num_of_majors; i++)
    {
        key = grad_employment_data[i].meanSalary; // key for sort (mean salary)
        demoTot = grad_employment_data[i].demographicsTotal;
        educMaj = grad_employment_data[i].educationMajor;
        medSal = grad_employment_data[i].medianSalary;
        demoAsian = grad_employment_data[i].demographicsAsian;
        demoMin = grad_employment_data[i].demographicsMinority;
        demoWhite = grad_employment_data[i].demographicsWhite;
        demoFemales = grad_employment_data[i].demographicsFemales;
        demoMales = grad_employment_data[i].demographicsMales;
        edBach = grad_employment_data[i].educationBachelor;
        edDoct = grad_employment_data[i].educationDoctorate;
        edMast = grad_employment_data[i].educationMasters;
        j = i - 1;

        while (j >= 0 && (grad_employment_data[j].meanSalary > key))
        {
            grad_employment_data[j + 1].demographicsTotal = grad_employment_data[j].demographicsTotal;
            grad_employment_data[j + 1].educationMajor = grad_employment_data[j].educationMajor;
            grad_employment_data[j + 1].meanSalary = grad_employment_data[j].meanSalary;
            grad_employment_data[j + 1].medianSalary = grad_employment_data[j].medianSalary;
            grad_employment_data[j + 1].demographicsAsian = grad_employment_data[j].demographicsAsian;
            grad_employment_data[j + 1].demographicsMinority = grad_employment_data[j].demographicsMinority;
            grad_employment_data[j + 1].demographicsWhite = grad_employment_data[j].demographicsWhite;
            grad_employment_data[j + 1].demographicsFemales = grad_employment_data[j].demographicsFemales;
            grad_employment_data[j + 1].demographicsMales = grad_employment_data[j].demographicsMales;
            grad_employment_data[j + 1].educationBachelor = grad_employment_data[j].educationBachelor;
            grad_employment_data[j + 1].educationDoctorate = grad_employment_data[j].educationDoctorate;
            grad_employment_data[j + 1].educationMasters = grad_employment_data[j].educationMasters;
            j = j - 1;
        }
        grad_employment_data[j + 1].meanSalary = key; // key for sort (mean salary)
        grad_employment_data[j + 1].demographicsTotal = demoTot;
        grad_employment_data[j + 1].educationMajor = educMaj;
        grad_employment_data[j + 1].medianSalary = medSal;
        grad_employment_data[j + 1].demographicsAsian = demoAsian;
        grad_employment_data[j + 1].demographicsMinority = demoMin;
        grad_employment_data[j + 1].demographicsWhite = demoWhite;
        grad_employment_data[j + 1].demographicsFemales = demoFemales;
        grad_employment_data[j + 1].demographicsMales = demoMales;
        grad_employment_data[j + 1].educationBachelor = edBach;
        grad_employment_data[j + 1].educationDoctorate = edDoct;
        grad_employment_data[j + 1].educationMasters = edMast;
    }
}

/**
 * does something
 * 
 * @param a
 * @return a
*/
void insertion_sort_by_highest_median_salary(std::vector <GradEmploymentData> &grad_employment_data, int num_of_majors)
{
    std::string educMaj;
    float meanSal, key; // key = median salary
    int i, j, demoTot, demoAsian, demoMin, demoWhite, demoFemales, demoMales, edBach, edDoct, edMast;
    for (i = 1; i < num_of_majors; i++)
    {
        key = grad_employment_data[i].medianSalary; // key for sort (median salary)
        demoTot = grad_employment_data[i].demographicsTotal;
        educMaj = grad_employment_data[i].educationMajor;
        meanSal = grad_employment_data[i].meanSalary;
        demoAsian = grad_employment_data[i].demographicsAsian;
        demoMin = grad_employment_data[i].demographicsMinority;
        demoWhite = grad_employment_data[i].demographicsWhite;
        demoFemales = grad_employment_data[i].demographicsFemales;
        demoMales = grad_employment_data[i].demographicsMales;
        edBach = grad_employment_data[i].educationBachelor;
        edDoct = grad_employment_data[i].educationDoctorate;
        edMast = grad_employment_data[i].educationMasters;
        j = i - 1;

        while (j >= 0 && (grad_employment_data[j].medianSalary < key))
        {
            grad_employment_data[j + 1].demographicsTotal = grad_employment_data[j].demographicsTotal;
            grad_employment_data[j + 1].educationMajor = grad_employment_data[j].educationMajor;
            grad_employment_data[j + 1].meanSalary = grad_employment_data[j].meanSalary;
            grad_employment_data[j + 1].medianSalary = grad_employment_data[j].medianSalary;
            grad_employment_data[j + 1].demographicsAsian = grad_employment_data[j].demographicsAsian;
            grad_employment_data[j + 1].demographicsMinority = grad_employment_data[j].demographicsMinority;
            grad_employment_data[j + 1].demographicsWhite = grad_employment_data[j].demographicsWhite;
            grad_employment_data[j + 1].demographicsFemales = grad_employment_data[j].demographicsFemales;
            grad_employment_data[j + 1].demographicsMales = grad_employment_data[j].demographicsMales;
            grad_employment_data[j + 1].educationBachelor = grad_employment_data[j].educationBachelor;
            grad_employment_data[j + 1].educationDoctorate = grad_employment_data[j].educationDoctorate;
            grad_employment_data[j + 1].educationMasters = grad_employment_data[j].educationMasters;
            j = j - 1;
        }
        grad_employment_data[j + 1].medianSalary = key; // key for sort (median salary)
        grad_employment_data[j + 1].demographicsTotal = demoTot;
        grad_employment_data[j + 1].educationMajor = educMaj;
        grad_employment_data[j + 1].meanSalary = meanSal;
        grad_employment_data[j + 1].demographicsAsian = demoAsian;
        grad_employment_data[j + 1].demographicsMinority = demoMin;
        grad_employment_data[j + 1].demographicsWhite = demoWhite;
        grad_employment_data[j + 1].demographicsFemales = demoFemales;
        grad_employment_data[j + 1].demographicsMales = demoMales;
        grad_employment_data[j + 1].educationBachelor = edBach;
        grad_employment_data[j + 1].educationDoctorate = edDoct;
        grad_employment_data[j + 1].educationMasters = edMast;
    }
}

/**
 * does something
 * 
 * @param a
 * @return a
*/
void insertion_sort_by_lowest_median_salary(std::vector <GradEmploymentData> &grad_employment_data, int num_of_majors)
{
    std::string educMaj;
    float meanSal, key; // key = median salary
    int i, j, demoTot, demoAsian, demoMin, demoWhite, demoFemales, demoMales, edBach, edDoct, edMast;
    for (i = 1; i < num_of_majors; i++)
    {
        key = grad_employment_data[i].medianSalary; // key for sort (median salary)
        demoTot = grad_employment_data[i].demographicsTotal;
        educMaj = grad_employment_data[i].educationMajor;
        meanSal = grad_employment_data[i].meanSalary;
        demoAsian = grad_employment_data[i].demographicsAsian;
        demoMin = grad_employment_data[i].demographicsMinority;
        demoWhite = grad_employment_data[i].demographicsWhite;
        demoFemales = grad_employment_data[i].demographicsFemales;
        demoMales = grad_employment_data[i].demographicsMales;
        edBach = grad_employment_data[i].educationBachelor;
        edDoct = grad_employment_data[i].educationDoctorate;
        edMast = grad_employment_data[i].educationMasters;
        j = i - 1;

        while (j >= 0 && (grad_employment_data[j].medianSalary > key))
        {
            grad_employment_data[j + 1].demographicsTotal = grad_employment_data[j].demographicsTotal;
            grad_employment_data[j + 1].educationMajor = grad_employment_data[j].educationMajor;
            grad_employment_data[j + 1].meanSalary = grad_employment_data[j].meanSalary;
            grad_employment_data[j + 1].medianSalary = grad_employment_data[j].medianSalary;
            grad_employment_data[j + 1].demographicsAsian = grad_employment_data[j].demographicsAsian;
            grad_employment_data[j + 1].demographicsMinority = grad_employment_data[j].demographicsMinority;
            grad_employment_data[j + 1].demographicsWhite = grad_employment_data[j].demographicsWhite;
            grad_employment_data[j + 1].demographicsFemales = grad_employment_data[j].demographicsFemales;
            grad_employment_data[j + 1].demographicsMales = grad_employment_data[j].demographicsMales;
            grad_employment_data[j + 1].educationBachelor = grad_employment_data[j].educationBachelor;
            grad_employment_data[j + 1].educationDoctorate = grad_employment_data[j].educationDoctorate;
            grad_employment_data[j + 1].educationMasters = grad_employment_data[j].educationMasters;
            j = j - 1;
        }
        grad_employment_data[j + 1].medianSalary = key; // key for sort (median salary)
        grad_employment_data[j + 1].demographicsTotal = demoTot;
        grad_employment_data[j + 1].educationMajor = educMaj;
        grad_employment_data[j + 1].meanSalary = meanSal;
        grad_employment_data[j + 1].demographicsAsian = demoAsian;
        grad_employment_data[j + 1].demographicsMinority = demoMin;
        grad_employment_data[j + 1].demographicsWhite = demoWhite;
        grad_employment_data[j + 1].demographicsFemales = demoFemales;
        grad_employment_data[j + 1].demographicsMales = demoMales;
        grad_employment_data[j + 1].educationBachelor = edBach;
        grad_employment_data[j + 1].educationDoctorate = edDoct;
        grad_employment_data[j + 1].educationMasters = edMast;
    }
}

/**
 * does something
 * 
 * @param a
 * @return a
*/
void insertion_sort_by_highest_number_of_asians(std::vector <GradEmploymentData> &grad_employment_data, int num_of_majors)
{
    std::string educMaj;
    float meanSal, medSal;
    int i, j, demoTot, key, demoMin, demoWhite, demoFemales, demoMales, edBach, edDoct, edMast; // key = asian demographic
    for (i = 1; i < num_of_majors; i++)
    {
        key = grad_employment_data[i].demographicsAsian; // key for sort (asian demographic)
        demoTot = grad_employment_data[i].demographicsTotal;
        educMaj = grad_employment_data[i].educationMajor;
        meanSal = grad_employment_data[i].meanSalary;
        medSal = grad_employment_data[i].medianSalary;
        demoMin = grad_employment_data[i].demographicsMinority;
        demoWhite = grad_employment_data[i].demographicsWhite;
        demoFemales = grad_employment_data[i].demographicsFemales;
        demoMales = grad_employment_data[i].demographicsMales;
        edBach = grad_employment_data[i].educationBachelor;
        edDoct = grad_employment_data[i].educationDoctorate;
        edMast = grad_employment_data[i].educationMasters;
        j = i - 1;

        while (j >= 0 && (grad_employment_data[j].demographicsAsian < key))
        {
            grad_employment_data[j + 1].demographicsTotal = grad_employment_data[j].demographicsTotal;
            grad_employment_data[j + 1].educationMajor = grad_employment_data[j].educationMajor;
            grad_employment_data[j + 1].meanSalary = grad_employment_data[j].meanSalary;
            grad_employment_data[j + 1].medianSalary = grad_employment_data[j].medianSalary;
            grad_employment_data[j + 1].demographicsAsian = grad_employment_data[j].demographicsAsian;
            grad_employment_data[j + 1].demographicsMinority = grad_employment_data[j].demographicsMinority;
            grad_employment_data[j + 1].demographicsWhite = grad_employment_data[j].demographicsWhite;
            grad_employment_data[j + 1].demographicsFemales = grad_employment_data[j].demographicsFemales;
            grad_employment_data[j + 1].demographicsMales = grad_employment_data[j].demographicsMales;
            grad_employment_data[j + 1].educationBachelor = grad_employment_data[j].educationBachelor;
            grad_employment_data[j + 1].educationDoctorate = grad_employment_data[j].educationDoctorate;
            grad_employment_data[j + 1].educationMasters = grad_employment_data[j].educationMasters;
            j = j - 1;
        }
        grad_employment_data[j + 1].demographicsAsian = key; // key for sort (asian demographic)
        grad_employment_data[j + 1].demographicsTotal = demoTot;
        grad_employment_data[j + 1].educationMajor = educMaj;
        grad_employment_data[j + 1].meanSalary = meanSal;
        grad_employment_data[j + 1].medianSalary = medSal;
        grad_employment_data[j + 1].demographicsMinority = demoMin;
        grad_employment_data[j + 1].demographicsWhite = demoWhite;
        grad_employment_data[j + 1].demographicsFemales = demoFemales;
        grad_employment_data[j + 1].demographicsMales = demoMales;
        grad_employment_data[j + 1].educationBachelor = edBach;
        grad_employment_data[j + 1].educationDoctorate = edDoct;
        grad_employment_data[j + 1].educationMasters = edMast;
    }
}

/**
 * does something
 * 
 * @param a
 * @return a
*/
void insertion_sort_by_lowest_number_of_asians(std::vector <GradEmploymentData> &grad_employment_data, int num_of_majors)
{
    std::string educMaj;
    float meanSal, medSal;
    int i, j, demoTot, key, demoMin, demoWhite, demoFemales, demoMales, edBach, edDoct, edMast; // key = asian demographic
    for (i = 1; i < num_of_majors; i++)
    {
        key = grad_employment_data[i].demographicsAsian; // key for sort (asian demographic)
        demoTot = grad_employment_data[i].demographicsTotal;
        educMaj = grad_employment_data[i].educationMajor;
        meanSal = grad_employment_data[i].meanSalary;
        medSal = grad_employment_data[i].medianSalary;
        demoMin = grad_employment_data[i].demographicsMinority;
        demoWhite = grad_employment_data[i].demographicsWhite;
        demoFemales = grad_employment_data[i].demographicsFemales;
        demoMales = grad_employment_data[i].demographicsMales;
        edBach = grad_employment_data[i].educationBachelor;
        edDoct = grad_employment_data[i].educationDoctorate;
        edMast = grad_employment_data[i].educationMasters;
        j = i - 1;

        while (j >= 0 && (grad_employment_data[j].demographicsAsian > key))
        {
            grad_employment_data[j + 1].demographicsTotal = grad_employment_data[j].demographicsTotal;
            grad_employment_data[j + 1].educationMajor = grad_employment_data[j].educationMajor;
            grad_employment_data[j + 1].meanSalary = grad_employment_data[j].meanSalary;
            grad_employment_data[j + 1].medianSalary = grad_employment_data[j].medianSalary;
            grad_employment_data[j + 1].demographicsAsian = grad_employment_data[j].demographicsAsian;
            grad_employment_data[j + 1].demographicsMinority = grad_employment_data[j].demographicsMinority;
            grad_employment_data[j + 1].demographicsWhite = grad_employment_data[j].demographicsWhite;
            grad_employment_data[j + 1].demographicsFemales = grad_employment_data[j].demographicsFemales;
            grad_employment_data[j + 1].demographicsMales = grad_employment_data[j].demographicsMales;
            grad_employment_data[j + 1].educationBachelor = grad_employment_data[j].educationBachelor;
            grad_employment_data[j + 1].educationDoctorate = grad_employment_data[j].educationDoctorate;
            grad_employment_data[j + 1].educationMasters = grad_employment_data[j].educationMasters;
            j = j - 1;
        }
        grad_employment_data[j + 1].demographicsAsian = key; // key for sort (asian demographic)
        grad_employment_data[j + 1].demographicsTotal = demoTot;
        grad_employment_data[j + 1].educationMajor = educMaj;
        grad_employment_data[j + 1].meanSalary = meanSal;
        grad_employment_data[j + 1].medianSalary = medSal;
        grad_employment_data[j + 1].demographicsMinority = demoMin;
        grad_employment_data[j + 1].demographicsWhite = demoWhite;
        grad_employment_data[j + 1].demographicsFemales = demoFemales;
        grad_employment_data[j + 1].demographicsMales = demoMales;
        grad_employment_data[j + 1].educationBachelor = edBach;
        grad_employment_data[j + 1].educationDoctorate = edDoct;
        grad_employment_data[j + 1].educationMasters = edMast;
    }
}

/**
 * does something
 * 
 * @param a
 * @return a
*/
void insertion_sort_by_highest_number_of_minorities(std::vector <GradEmploymentData> &grad_employment_data, int num_of_majors)
{
    std::string educMaj;
    float meanSal, medSal;
    int i, j, demoTot, demoAsian, key, demoWhite, demoFemales, demoMales, edBach, edDoct, edMast; // key = minority demographic
    for (i = 1; i < num_of_majors; i++)
    {
        key = grad_employment_data[i].demographicsMinority; // key for sort (minority demographic)
        demoTot = grad_employment_data[i].demographicsTotal;
        educMaj = grad_employment_data[i].educationMajor;
        meanSal = grad_employment_data[i].meanSalary;
        medSal = grad_employment_data[i].medianSalary;
        demoAsian = grad_employment_data[i].demographicsAsian;
        demoWhite = grad_employment_data[i].demographicsWhite;
        demoFemales = grad_employment_data[i].demographicsFemales;
        demoMales = grad_employment_data[i].demographicsMales;
        edBach = grad_employment_data[i].educationBachelor;
        edDoct = grad_employment_data[i].educationDoctorate;
        edMast = grad_employment_data[i].educationMasters;
        j = i - 1;

        while (j >= 0 && (grad_employment_data[j].demographicsMinority < key))
        {
            grad_employment_data[j + 1].demographicsTotal = grad_employment_data[j].demographicsTotal;
            grad_employment_data[j + 1].educationMajor = grad_employment_data[j].educationMajor;
            grad_employment_data[j + 1].meanSalary = grad_employment_data[j].meanSalary;
            grad_employment_data[j + 1].medianSalary = grad_employment_data[j].medianSalary;
            grad_employment_data[j + 1].demographicsAsian = grad_employment_data[j].demographicsAsian;
            grad_employment_data[j + 1].demographicsMinority = grad_employment_data[j].demographicsMinority;
            grad_employment_data[j + 1].demographicsWhite = grad_employment_data[j].demographicsWhite;
            grad_employment_data[j + 1].demographicsFemales = grad_employment_data[j].demographicsFemales;
            grad_employment_data[j + 1].demographicsMales = grad_employment_data[j].demographicsMales;
            grad_employment_data[j + 1].educationBachelor = grad_employment_data[j].educationBachelor;
            grad_employment_data[j + 1].educationDoctorate = grad_employment_data[j].educationDoctorate;
            grad_employment_data[j + 1].educationMasters = grad_employment_data[j].educationMasters;
            j = j - 1;
        }
        grad_employment_data[j + 1].demographicsMinority = key; // key for sort (minority demographic)
        grad_employment_data[j + 1].demographicsTotal = demoTot;
        grad_employment_data[j + 1].educationMajor = educMaj;
        grad_employment_data[j + 1].meanSalary = meanSal;
        grad_employment_data[j + 1].medianSalary = medSal;
        grad_employment_data[j + 1].demographicsAsian = demoAsian;
        grad_employment_data[j + 1].demographicsWhite = demoWhite;
        grad_employment_data[j + 1].demographicsFemales = demoFemales;
        grad_employment_data[j + 1].demographicsMales = demoMales;
        grad_employment_data[j + 1].educationBachelor = edBach;
        grad_employment_data[j + 1].educationDoctorate = edDoct;
        grad_employment_data[j + 1].educationMasters = edMast;
    }
}

/**
 * does something
 * 
 * @param a
 * @return a
*/
void insertion_sort_by_lowest_number_of_minorities(std::vector <GradEmploymentData> &grad_employment_data, int num_of_majors)
{
    std::string educMaj;
    float meanSal, medSal;
    int i, j, demoTot, demoAsian, key, demoWhite, demoFemales, demoMales, edBach, edDoct, edMast; // key = minority demographic
    for (i = 1; i < num_of_majors; i++)
    {
        key = grad_employment_data[i].demographicsMinority; // key for sort (minority demographic)
        demoTot = grad_employment_data[i].demographicsTotal;
        educMaj = grad_employment_data[i].educationMajor;
        meanSal = grad_employment_data[i].meanSalary;
        medSal = grad_employment_data[i].medianSalary;
        demoAsian = grad_employment_data[i].demographicsAsian;
        demoWhite = grad_employment_data[i].demographicsWhite;
        demoFemales = grad_employment_data[i].demographicsFemales;
        demoMales = grad_employment_data[i].demographicsMales;
        edBach = grad_employment_data[i].educationBachelor;
        edDoct = grad_employment_data[i].educationDoctorate;
        edMast = grad_employment_data[i].educationMasters;
        j = i - 1;

        while (j >= 0 && (grad_employment_data[j].demographicsMinority > key))
        {
            grad_employment_data[j + 1].demographicsTotal = grad_employment_data[j].demographicsTotal;
            grad_employment_data[j + 1].educationMajor = grad_employment_data[j].educationMajor;
            grad_employment_data[j + 1].meanSalary = grad_employment_data[j].meanSalary;
            grad_employment_data[j + 1].medianSalary = grad_employment_data[j].medianSalary;
            grad_employment_data[j + 1].demographicsAsian = grad_employment_data[j].demographicsAsian;
            grad_employment_data[j + 1].demographicsMinority = grad_employment_data[j].demographicsMinority;
            grad_employment_data[j + 1].demographicsWhite = grad_employment_data[j].demographicsWhite;
            grad_employment_data[j + 1].demographicsFemales = grad_employment_data[j].demographicsFemales;
            grad_employment_data[j + 1].demographicsMales = grad_employment_data[j].demographicsMales;
            grad_employment_data[j + 1].educationBachelor = grad_employment_data[j].educationBachelor;
            grad_employment_data[j + 1].educationDoctorate = grad_employment_data[j].educationDoctorate;
            grad_employment_data[j + 1].educationMasters = grad_employment_data[j].educationMasters;
            j = j - 1;
        }
        grad_employment_data[j + 1].demographicsMinority = key; // key for sort (minority demographic)
        grad_employment_data[j + 1].demographicsTotal = demoTot;
        grad_employment_data[j + 1].educationMajor = educMaj;
        grad_employment_data[j + 1].meanSalary = meanSal;
        grad_employment_data[j + 1].medianSalary = medSal;
        grad_employment_data[j + 1].demographicsAsian = demoAsian;
        grad_employment_data[j + 1].demographicsWhite = demoWhite;
        grad_employment_data[j + 1].demographicsFemales = demoFemales;
        grad_employment_data[j + 1].demographicsMales = demoMales;
        grad_employment_data[j + 1].educationBachelor = edBach;
        grad_employment_data[j + 1].educationDoctorate = edDoct;
        grad_employment_data[j + 1].educationMasters = edMast;
    }
}

/**
 * does something
 * 
 * @param a
 * @return a
*/
void print_vectors(std::vector <GradEmploymentData> grad_employment_data)
{
    for(unsigned int i = 0; i < grad_employment_data.size() - 1; i++)
    {
        std::cout << grad_employment_data[i].educationMajor
            << '\n' << grad_employment_data[i].demographicsTotal
            << '\n' << grad_employment_data[i].meanSalary
            << '\n' << grad_employment_data[i].medianSalary
            << '\n' << grad_employment_data[i].demographicsAsian
            << '\n' << grad_employment_data[i].demographicsMinority
            << '\n' << grad_employment_data[i].demographicsWhite
            << '\n' << grad_employment_data[i].demographicsFemales
            << '\n' << grad_employment_data[i].demographicsMales
            << '\n' << grad_employment_data[i].educationBachelor
            << '\n' << grad_employment_data[i].educationDoctorate
            << '\n' << grad_employment_data[i].educationMasters;
    }
}

/**
 * Searches for and displays info about major.
 * 
 * @param grad_employment_data 
 * @param num_of_majors 
*/
void info(std::vector <GradEmploymentData> grad_employment_data, int num_of_majors)
{
    int position = 0;
    bool found = false;
    std::string major = "\0";
    std::cout << '\n';
    
    for(int i = 0; i < num_of_majors; i++)
    {
        std::cout << i + 1 << ". " << grad_employment_data[i].educationMajor
            << '\n';
    }
    std::cout << "\nWhich major do you want more information about?"
        << "\n(Enter '0' to go back to Main Menu)"
        << "\n\nEnter a major: ";
    std::cin.ignore();
    getline(std::cin, major);
    while(major != "0")
    {
        // *** Nested Function ***
        // Searches for and determines if major exists.
        found = binary_search_vector(grad_employment_data, major, position);
        if(found)
        {
            std::cout.width(35);
            std::cout << std::left << "HERE" << std::setw(5) << "THERE" << '\n';
            std::cout.width(35);
            std::cout << std::left << "HEREHERE" << std::setw(5) << "THERETHERE" << '\n';
            std::cout.width(35);
            std::cout << std::left << "HERE" << std::setw(5) << "THERE" << '\n';
            std::cout.width(35);
            std::cout << std::left << "WHATISGOINGON" << std::setw(5) << "THE6456RE" << '\n';
            std::cout.width(35);
            std::cout << std::left << "HERE" << std::setw(5) << "THERE" << '\n';
            std::cout.width(35);
            std::cout << std::left << "HERE" << std::setw(5) << "WH2323O" << '\n';

            std::cout << '\n' << std::left << grad_employment_data[position].educationMajor
            << "\n---------------------------------------------"
                << "\n\n";
            std::cout.width(35);
            std::cout << std::left << "Total Demographic" << std::setw(10) << std::right << grad_employment_data[position].demographicsTotal<< "\n" ;
            std::cout.width(35);
            std::cout << std::left << "Mean Salary"  << std::setw(0) << std::left << '$' << std::setw(9) << std::right
                << std::fixed << std::showpoint << std::setprecision(2) << grad_employment_data[position].meanSalary << '\n';
            std::cout.width(35);
            std::cout << std::left << "Median Salary"  << std::setw(0) << std::left << '$' << std::setw(9) << std::right
                << std::fixed << std::showpoint << std::setprecision(2) << grad_employment_data[position].medianSalary<< "\n" ;
            std::cout.width(35);
            std::cout << std::left << "Total Asian Demographic" << std::setw(10) << std::right << grad_employment_data[position].demographicsAsian<< "\n" ;
            std::cout.width(35);
            std::cout << std::left << "Total Minority Demographic" << std::setw(10) << std::right << grad_employment_data[position].demographicsMinority<< "\n" ;
            std::cout.width(35);
            std::cout << std::left << "Total White Demographic" << std::setw(10) << std::right << grad_employment_data[position].demographicsWhite<< "\n" ;
            std::cout.width(35);
            std::cout << std::left << "Total Female Demographic" << std::setw(10) << std::right << grad_employment_data[position].demographicsFemales<< "\n" ;
            std::cout.width(35);
            std::cout << std::left << "Total Male Demographic" << std::setw(10) << std::right << grad_employment_data[position].demographicsMales<< "\n" ;
            std::cout.width(35);
            std::cout << std::left << "Bachelors" << std::setw(10) << std::right << grad_employment_data[position].educationBachelor<< "\n" ;
            std::cout.width(35);
            std::cout << std::left << "Doctorates" << std::setw(10) << std::right << grad_employment_data[position].educationDoctorate<< "\n" ;
            std::cout.width(35);
            std::cout << std::left << "Masters" << std::setw(10) << std::right << grad_employment_data[position].educationMasters<< "\n" ;
        }
            /*
            std::cout.width(35);
            std::cout << std::left << "Education Major" << std::setw(11) << "Minorities Demographic"
                << "\n--------------------------------------------------------\n";
            for(int i = 0; i < 5; i++)
            {
                std::cout.width(35);
                std::cout << std::setw(35) << grad_employment_data[i].educationMajor << std::setw(10) << grad_employment_data[i].demographicsMinority
                    << '\n';
            }
            */
        else
        {
            std::cout << "Major '" << major << "' was not found."
                << '\n';
        }
        if(major != "0")
        {
            std::cout << "\nWhich major do you want more information about?"
                << "\n(Enter '0' to go back to Main Menu)"
                << "\n\nEnter a major: ";
            getline(std::cin, major);
        }
    }
    std::cout << "\nYou went back to Main Menu."
        << '\n';
}