/*!*************************************************************************************************************************************************************************************************************************************************************
\file       pa.hpp
\par        Author:          Najih
\par        Email:           n.hajasheikallaudin
\par        Course:          RSE1202    
\par        Section:         RSE
\par        Tutorial:        Assignment 4
\par        File created on: 01/02/2024
\brief      Recieve file containing country name and population and sort to specific requirements

\par        File information:
            This file is contains 8 function definitions to called by main in q-driver.
            Functions:
            - std::vector<CountryInfo> fill_vector_from_istream(std::istream& is);                                      // to identify all the countries names and population found in the file
            - size_t max_name_length(std::vector<CountryInfo> const& countries);                                        // to find the lenght of the longest country name
            - void sort(std::vector<CountryInfo>& rv, Ptr_Cmp_Func cmp);                                                // to sort the data in ascending lexicographic order
            - bool cmp_name_less(CountryInfo const& left, CountryInfo const& right);                                    // return true if the country name referenced by left is lexicographically less than the country name referenced by right
            - bool cmp_name_greater(CountryInfo const& left, CountryInfo const& right);                                 // return true if the country name referenced by left is lexicographically greater than the country name referenced by right
            - bool cmp_pop_less(CountryInfo const& left, CountryInfo const& right);                                     // return true if the population of object referenced by left is numerically less than population of object referenced by right
            - bool cmp_pop_greater(CountryInfo const& left, CountryInfo const& right);                                  // return true if the population of object referenced by left is numerically greater than population of object referenced by right
            - void write_to_ostream(std::vector<CountryInfo> const& v, std::ostream& os, size_t fw);                    // to write all the date stored in the vector CountryInfo in a specified fomat

***************************************************************************************************************************************************************************************************************************************************************/
#ifndef PA_HPP
#define PA_HPP

#include <iostream>                                                                                                     // necessary includes of header files except <algorithm> and C-only headers such as <cstring>, ...
#include <iomanip>
#include <string>
#include <vector>
#include <cctype>

namespace hlp2 {
                        
    struct CountryInfo {                                                                                                // structure to encapsulate a country's name and its population ...
        std::string name;                                                                                               // country's name - *exactly* as in input file
        long int pop;                                                                                                   // country's population
    };

    // other declarations ...
    using Ptr_Cmp_Func = bool (*)(CountryInfo const&, CountryInfo const&);

    std::vector<CountryInfo> fill_vector_from_istream(std::istream& is);

    size_t max_name_length(std::vector<CountryInfo> const& countries);
    void sort(std::vector<CountryInfo>& rv, Ptr_Cmp_Func cmp);
    
    bool cmp_name_less(CountryInfo const& left, CountryInfo const& right);
    bool cmp_name_greater(CountryInfo const& left, CountryInfo const& right);
    bool cmp_pop_less(CountryInfo const& left, CountryInfo const& right);
    bool cmp_pop_greater(CountryInfo const& left, CountryInfo const& right);

    void write_to_ostream(std::vector<CountryInfo> const& v, std::ostream& os, size_t fw);

}                                                                                                                       // end namespace hlp2
#endif
