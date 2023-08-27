/*
    Created: August 29, 2022
    August 31, 2022
        Tested
    September 21, 2022
        Modified output alignment and added output headers.
        Added "Press enter to continue..." prompt.
        Switched binary search from looking for list number of major to major name.
        Combined binary search into info function.
    August 25, 2023
        modified directives in analytics.h file
    August 26, 2023
        add function header functions prototypes

    Gathers education major information from a file into an array.
    Sorts the information in ascending or descending order.
    Displays the information in ascending or descending order.
    Displays the information about majors.
*/

#include "analytics.h"

int main()
{	
    // bool found = false;
    const int MENU_ITEMS = 12;
    std::vector <GradEmploymentData> grad_employment_data;
    std::ifstream input_file("graduates2015.csv");
    std::string line = "\0", remainder = "0", to_search = "\0", temp = "\0";
    char confirm = '\0';
    int selection = 0, struct_number = 0, num_of_majors = 0, total_demographics = 0;

    if (!input_file)
    {
        std::cout << "Error opening file. No file was opened.";
        getchar();
        exit(1);
    }
    getline(input_file, line, '\n');
    while(input_file.peek() != EOF)
    {
        GradEmploymentData temp = {0, "\0", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        grad_employment_data.push_back(temp);
        num_of_majors++;
        getline(input_file, line, ',');
        grad_employment_data[struct_number].demographicsTotal = stoi(line);
        getline(input_file, line, ',');
        // removes apostrophes from major name
        if (line[0] == '"')
        {
            getline(input_file, remainder, ','); // search after internal comma of major name
            line = line + remainder;
            for(unsigned int i = 0; i < line.length(); i++) // "hat" char = 5
            {
                line[i] = line[i + 1]; // shift all letters one left, deleting start apostrophe
                if (i == (line.length() - 1))
                {
                    line.resize(line.length() - 2); // resizing to remove end apostrophe
                }
            }
        }
        grad_employment_data[struct_number].educationMajor = line;
        getline(input_file, line, ',');
        grad_employment_data[struct_number].meanSalary = stof(line);
        getline(input_file, line, ',');
        grad_employment_data[struct_number].medianSalary = stof(line);
        getline(input_file, line, ',');
        grad_employment_data[struct_number].demographicsAsian = stoi(line);
        getline(input_file, line, ',');
        grad_employment_data[struct_number].demographicsMinority = stoi(line);
        getline(input_file, line, ',');
        grad_employment_data[struct_number].demographicsWhite = stoi(line);
        getline(input_file, line, ',');
        grad_employment_data[struct_number].demographicsFemales = stoi(line);
        getline(input_file, line, ',');
        grad_employment_data[struct_number].demographicsMales = stoi(line);
        getline(input_file, line, ',');
        grad_employment_data[struct_number].educationBachelor = stoi(line);
        getline(input_file, line, ',');
        grad_employment_data[struct_number].educationDoctorate = stoi(line);
        getline(input_file, line, '\n');
        grad_employment_data[struct_number].educationMasters = stoi(line);
        struct_number++;
    }
    while(selection != MENU_ITEMS)
    {
        //print_vectors(grad_employment_data);
        print_main_menu();
        while (selection < 1 || selection > MENU_ITEMS)
        {
            std::cin >> selection;
            if(selection < 1 || selection > MENU_ITEMS)
            {
                std::cout << "\nInvalid Option."
                << "\nSelect a Menu Item: ";
            }
            else
            {
                std::cout << "You chose Menu Item '" << selection << "'. Enter 'y' to confirm, 'n' to cancel request: ";
                while (tolower(confirm) != 'y' && tolower(confirm) != 'n')
                {
                    confirm = tolower(getchar());
                }
                if (confirm == tolower('y'))
                {
                    switch (selection)
                    {
                        case 1:
                            std::cout << '\n';
                            insertion_sort_by_highest_mean_salary(grad_employment_data, num_of_majors);
                            print_mean_salaries(grad_employment_data);
                            std::cin.ignore();
                            std::cout << "\nPress enter to continue...";
                            std::cin.ignore();
                            std::cout << '\n';
                            break;
                        case 2:
                            std::cout << '\n';
                            insertion_sort_by_lowest_mean_salary(grad_employment_data, num_of_majors);
                            print_mean_salaries(grad_employment_data);
                            std::cin.ignore();
                            std::cout << "\nPress enter to continue...";
                            std::cin.ignore();
                            std::cout << '\n';
                            break;
                        case 3:
                            std::cout << '\n';
                            insertion_sort_by_highest_median_salary(grad_employment_data, num_of_majors);
                            print_median_salaries(grad_employment_data);
                            std::cin.ignore();
                            std::cout << "\nPress enter to continue...";
                            std::cin.ignore();
                            std::cout << '\n';
                            break;
                        case 4:
                            std::cout << '\n';
                            insertion_sort_by_lowest_median_salary(grad_employment_data, num_of_majors);
                            print_median_salaries(grad_employment_data);
                            std::cin.ignore();
                            std::cout << "\nPress enter to continue...";
                            std::cin.ignore();
                            std::cout << '\n';
                            break;
                        case 5:
                            std::cout << '\n';
                            insertion_sort_by_highest_number_of_asians(grad_employment_data, num_of_majors);
                            print_number_of_asians(grad_employment_data);
                            std::cin.ignore();
                            std::cout << "\nPress enter to continue...";
                            std::cin.ignore();
                            std::cout << '\n';
                            break;
                        case 6:
                            std::cout << '\n';
                            insertion_sort_by_lowest_number_of_asians(grad_employment_data, num_of_majors);
                            print_number_of_asians(grad_employment_data);
                            std::cin.ignore();
                            std::cout << "\nPress enter to continue...";
                            std::cin.ignore();
                            std::cout << '\n';
                            break;
                        case 7:
                            std::cout << '\n';
                            insertion_sort_by_highest_number_of_minorities(grad_employment_data, num_of_majors);
                            print_number_of_minorities(grad_employment_data);
                            std::cin.ignore();
                            std::cout << "\nPress enter to continue...";
                            std::cin.ignore();
                            std::cout << '\n';
                            break;
                        case 8:
                            std::cout << '\n';
                            insertion_sort_by_lowest_number_of_minorities(grad_employment_data, num_of_majors);
                            print_number_of_minorities(grad_employment_data);
                            std::cin.ignore();
                            std::cout << "\nPress enter to continue...";
                            std::cin.ignore();
                            std::cout << '\n';
                            break;
                        case 9:
                            std::cout << "\nTotal Number of Majors on File: " << num_of_majors
                                << '\n';
                            std::cin.ignore();
                            std::cout << "\nPress enter to continue...";
                            std::cin.ignore();
                            break;
                        case 10:
                            std::cout << "\nDemographic Grand Total: ";
                            for(unsigned int i = 0; i < grad_employment_data.size(); i++)
                            {
                                total_demographics += grad_employment_data[i].demographicsTotal;
                            }
                            std::cout << total_demographics
                                << '\n';
                            std::cin.ignore();
                            std::cout << "\nPress enter to continue...";
                            std::cin.ignore();
                            std::cout << '\n';
                            break;
                        case 11:
                            insertion_sort_by_education_major_ascending(grad_employment_data, num_of_majors);
                            info(grad_employment_data, num_of_majors);
                            break;
                        case 12:
                            std::cout << "You have exited the program."
                                << '\n';
                            break;
                    }
                }
                else
                {
                    selection = 0; // resets selection if user does not confirm
                }
                if(selection != MENU_ITEMS && tolower(confirm) == 'y')
                {
                    print_main_menu();
                    selection = 0; // resets selection
                    confirm = '\0'; // resets confirmation
                    //print_vectors(grad_employment_data);
                }
                if (tolower(confirm) == 'n')
                {
                    std::cout << "Select a Menu Item: ";
                    confirm = '\0';
                }
            }
        }
    }
	input_file.close();

    return 0;
}

/*
    insertion_sort_by_education_major_ascending(grad_employment_data, num_of_majors);
    for(int i = 0; i < num_of_majors; i++)
    {
        std::cout << i + 1 << ". " << grad_employment_data[i].educationMajor
            << '\n';
    }
    std::cout << "\nEnter Major to Binary Search for: ";
    std::cin >> selection;
    if((unsigned int) selection >= 1 && (unsigned int) selection <= grad_employment_data.size())
    {
        to_search = grad_employment_data[selection - 1].educationMajor;
    }
    // print_vectors(grad_employment_data);
    binary_search_vector(grad_employment_data, to_search);
    if(found == true)
    {
        std::cout << "Your search '" << to_search << "' was found!"
            << "\nSteps that it took to binary search for '" << to_search << "': " << steps << '.'
            << '\n';
    }
    else
    {
        std::cout << "Your search was not found!"
            << '\n';
    }
    to_search = "\0"; // resets to_search for binary search
    steps = 0; // resets steps for binary search
    found = false; // resets found for binary search
    std::cin.ignore();
    std::cout << "\nPress enter to continue...";
    std::cin.ignore();
    std::cout << '\n';
    break;
*/