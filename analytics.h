#define FUNCTIONS_H
#ifndef ANALYTICS_H

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <vector>
#include <iomanip>

struct GradEmploymentData
{
    int demographicsTotal;      // The estimated total of people awarded degrees in this major during 2005
    std::string educationMajor; // The name of the major for these graduated students
    float meanSalary;           // The average (mean) recorded salary reported for employed people with this degree
    float medianSalary;         // The median recorded salary reported for employed people with this degree
    int demographicsAsian;      // The estimated number of people identifying as Asian that were awarded degrees in this major
    int demographicsMinority;   // The estimated number of people identifying as minority
                                // (e.g., Black, African American, Native American) that were awarded degrees in this major
    int demographicsWhite;      // The estimated number of people identifying as White that were awarded degrees in this major
    int demographicsFemales;    // The estimate number of women awarded degrees in this major
    int demographicsMales;      // The estimate number of men awarded degrees in this major
    int educationBachelor;      // The estimated number of bachelor degrees awarded in this for major
    int educationDoctorate;     // The estimated number of doctoral degrees awarded in this for major
    int educationMasters;       // The estimated number of Masters awarded in this for major
};

/*
void print_list(int *list, const int LENGTH);
void print_sub_vector(std::vector <GradEmploymentData> grad_employment_data, int total, int last);
*/

void print_main_menu();

void print_mean_salaries(std::vector <GradEmploymentData> grad_employment_data);
void print_median_salaries(std::vector <GradEmploymentData> grad_employment_data);
void print_number_of_asians(std::vector <GradEmploymentData> grad_employment_data);
void print_number_of_minorities(std::vector <GradEmploymentData> grad_employment_data);

void binary_search_vector(std::vector <GradEmploymentData> grad_employment_data, std::string to_search, int &steps, bool &found);
bool binary_search_vector(std::vector <GradEmploymentData> grad_employment_data, std::string to_search, int &position);

void insertion_sort_by_education_major_ascending(std::vector <GradEmploymentData> &grad_employment_data, int num_of_majors);

void insertion_sort_by_highest_mean_salary(std::vector <GradEmploymentData> &grad_employment_data, int num_of_majors);
void insertion_sort_by_lowest_mean_salary(std::vector <GradEmploymentData> &grad_employment_data, int num_of_majors);
void insertion_sort_by_highest_median_salary(std::vector <GradEmploymentData> &grad_employment_data, int num_of_majors);
void insertion_sort_by_lowest_median_salary(std::vector <GradEmploymentData> &grad_employment_data, int num_of_majors);
void insertion_sort_by_highest_number_of_asians(std::vector <GradEmploymentData> &grad_employment_data, int num_of_majors);
void insertion_sort_by_lowest_number_of_asians(std::vector <GradEmploymentData> &grad_employment_data, int num_of_majors);
void insertion_sort_by_highest_number_of_minorities(std::vector <GradEmploymentData> &grad_employment_data, int num_of_majors);
void insertion_sort_by_lowest_number_of_minorities(std::vector <GradEmploymentData> &grad_employment_data, int num_of_majors);

void print_vectors(std::vector <GradEmploymentData> grad_employment_data);
void info(std::vector <GradEmploymentData> grad_employment_data, int num_of_majors);

#endif