/*!*************************************************************************************************************************************************************************************************************************************************************
\file       pa.cpp
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
#include "pa.hpp"
namespace hlp2 {
//#############################################################################################################################################################################################################################################################                        
//=============================================================================================================================================================================================================================================================
//|                                                                              READ FILE SECTION                                                                                                                                                            |
//=============================================================================================================================================================================================================================================================
    std::vector<CountryInfo> fill_vector_from_istream(std::istream& input) {                                            // to identify all the countries names and population found in the file
        
        std::vector<CountryInfo> countries;
        std::string line, country_name, population_num, temp;

        while (std::getline(input >> std::ws, line)) {                                                                  // taking in line without white spaces infront till '\n' is found
            //std::cout<< line << std::endl;
            size_t i=0;
            while(!(line[i]>='0' &&line[i]<='9')){ country_name +=line[i++]; }                                          // storing non-numbered chracters till numbered chracters are found
            
            size_t last_spaces = country_name.size()-1;                                                                 
            while (last_spaces != std::string::npos && std::isspace(country_name[last_spaces])) { --last_spaces; }      // finding the last non-space character
            country_name.erase(last_spaces + 1);                                                                        // removing all excess white space charcters from country_name string 

            population_num = line.substr(i);                                                                            // removing all charcters infront of numbered chracters 
            for (char ch : population_num) {
                if (ch != ',') { temp += ch; }                                                                          // removing ',' if found from the population string
            }
            long int population = std::stol(temp);                                                                      // convert temp string to a long int population 

            CountryInfo countryinfo{ country_name, population };                                                        // storing data into struct CountryInfo
            countries.push_back(countryinfo);                                                                           // and pushing that data into the countries vector struct 
            country_name.clear(); temp.clear();                                                                         // reseting country_name and temp for each new line  
        }
        return countries;
    }
//=============================================================================================================================================================================================================================================================
//|                                                                           MAX NAME LENGTH SECTION                                                                                                                                                         |
//=============================================================================================================================================================================================================================================================
    size_t max_name_length(std::vector<CountryInfo> const& countries) {                                                 // to find the lenght of the longest country name
        size_t max_length = 0;
        for(CountryInfo country: countries) {            
            size_t length = country.name.size();
            if (length > max_length) { max_length = length; }                                                           // finding the largest length if length is larger than max_length then set length as max_length                
        } 
        return max_length;
    }
//=============================================================================================================================================================================================================================================================
//|                                                                                SORTING SECTION                                                                                                                                                            |
//=============================================================================================================================================================================================================================================================
    void sort(std::vector<CountryInfo>& rv, Ptr_Cmp_Func cmp) {                                                         // to sort the data in ascending lexicographic order
        size_t size = rv.size();
        for (size_t i = 0; i < size - 1; ++i) {
            for (size_t j = 0; j < size - i - 1; ++j) {
                if (cmp(rv[j], rv[j + 1])) {                                                                            // Swap if the comparison function returns true
                    std::swap(rv[j], rv[j + 1]);
                }
            }
        }
    }
    bool cmp_name_less(CountryInfo const& left, CountryInfo const& right)    { return left.name > right.name; }         // return true if the country name referenced by left is lexicographically less than the country name referenced by right
    bool cmp_name_greater(CountryInfo const& left, CountryInfo const& right) { return left.name < right.name; }         // return true if the country name referenced by left is lexicographically greater than the country name referenced by right
    bool cmp_pop_less(CountryInfo const& left, CountryInfo const& right)     { return left.pop > right.pop; }           // return true if the population of object referenced by left is numerically less than population of object referenced by right
    bool cmp_pop_greater(CountryInfo const& left, CountryInfo const& right)  { return left.pop < right.pop; }           // return true if the population of object referenced by left is numerically greater than population of object referenced by right
//=============================================================================================================================================================================================================================================================
//|                                                                              WRITE FILE SECTION                                                                                                                                                           |
//=============================================================================================================================================================================================================================================================
    void write_to_ostream(std::vector<CountryInfo> const& v, std::ostream& os, size_t fw) {                             // to write all the date stored in the vector CountryInfo in a specified fomat
        for(const auto& country : v){ os<< std::setw(fw) << std::left << country.name << country.pop << std::endl; }
    }
//##############################################################################################################################################################################################################################################################
}
