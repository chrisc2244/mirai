#include "CSV_Table.h"

CSV_Table::CSV_Table() : m_Width(0), m_Height(0) { } 

std::vector<std::vector<std::string>>& CSV_Table::getTable()
{
    return m_Table;
}

const void CSV_Table::consoleDump() const
{
    for (int i = 0; i < m_Table.size(); i++)
    {
        for (int j = 0; j < m_Table[i].size(); j++)
        {
            std::cout << m_Table[i][j] << " ";
        }
        std::cout << "\n";
    }
    return void();
}

std::vector<std::string> CSV_Table::getLine(const uint32_t line_index)
{
    if (line_index < m_Table.size())
        return m_Table[line_index];
    
    throw std::invalid_argument("Error @ CSV_Table.getLine(): Index is out of bounds");

    // Return empty vector if error encountered
    return std::vector<std::string>();
}

std::string CSV_Table::getElement(const uint32_t row, const uint32_t column)
{
    if (row < m_Table.size() && column < m_Table[row].size())
        return m_Table[row][column];
    throw std::invalid_argument("Error @ CSV_Table.getElement() : Index is out of bounds");
    
    // Return empty string if error encountered
    return "";
}

int CSV_Table::getElementInt(const uint32_t row, const uint32_t column)
{
    int num = 0;
    try
    {
        num = std::stoi(getElement(row, column));
    }
    catch (...)
    {
        std::exception_ptr eptr = std::current_exception();
        std::rethrow_exception(eptr);
    }
    return num;
}

float CSV_Table::getElementFloat(const uint32_t row, const uint32_t column)
{
    float num = 0.f;
    try
    {
        num = std::stof(getElement(row, column));
    }
    catch (...)
    {
        std::exception_ptr eptr = std::current_exception();
        std::rethrow_exception(eptr);
    }
    return num;
}

double CSV_Table::getElementDouble(const uint32_t row, const uint32_t column)
{
    double num = 0;
    try
    {
        num = std::stod(getElement(row, column));
    }
    catch (...)
    {
        std::exception_ptr eptr = std::current_exception();
        std::rethrow_exception(eptr);
    }
    return num;
}

const size_t CSV_Table::sizeRows() const
{
    return m_Table.size();
}

const size_t CSV_Table::sizeColumns() const
{
    if (sizeRows() >= 1)
        return m_Table[0].size();
    return 0;
}
