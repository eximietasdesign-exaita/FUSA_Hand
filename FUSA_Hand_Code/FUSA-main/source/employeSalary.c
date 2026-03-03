/**
 * @file employee_salary.c
 *
 * @brief Computes employee salary based on age and grade using conditional logic.
 *
 * This file contains logic to calculate an employee's salary by:
 * - Starting with a fixed base salary.
 * - Adjusting the salary based on the employee’s age group and grade level.
 */

// Base salary before adjustments
#define SALARY 11000

/**
 * @brief Calculates and adjusts an employee's salary based on age and grade.
 *
 * This function assigns a base salary and modifies it according to the employee's
 * age and grade as per predefined rules:
 *
 * - Age 18–35:
 *     - Grade 1: +10000
 *     - Grade 2: +20000
 *     - Grade 3: +30000
 *     - Other grades: salary = 1000
 *     - Invalid grades: +0
 *
 * - Age 36–62:
 *     - Grade 4: +40000
 *     - Grade 5: +50000
 *     - Grade 6: +60000
 *     - Grade 7: +70000
 *     - Other grades: salary = 1000
 *     - Invalid grades: +0
 *
 * - Invalid age: +0
 *
 * @param f_newemploye_age   Age of the new employee.
 * @param f_newemploye_grade Grade level of the new employee.
 *
 * @return int Adjusted salary based on age and grade rules.
 */
int employeeSalaryRange(int f_newemploye_age, int f_newemploye_grade) 
{
    int l_salary = SALARY; // Initialize with base salary

    // Check age range and adjust salary based on grade
    if(f_newemploye_age >= 18 && f_newemploye_age <= 35) 
    {
        if(f_newemploye_grade >= 0 && f_newemploye_grade <= 3) 
        {
            switch (f_newemploye_grade)
            {
                case 1:
                    l_salary += 10000;
                    break;
                case 2:
                    l_salary += 20000;
                    break;
                case 3:
                    l_salary += 30000;
                    break;
                default:
                    l_salary = 1000;
                    break;
            }
        }
        else 
        {
            l_salary += 0;
        }
    }
    else if(f_newemploye_age >= 36 && f_newemploye_age <= 62) 
    {
        if(f_newemploye_grade >= 4 && f_newemploye_grade <= 10) 
        {
            switch (f_newemploye_grade)
            {
                case 4:
                    l_salary += 40000;
                    break;
                case 5:
                    l_salary += 50000;    
                    break;
                case 6:
                    l_salary += 60000;
                    break;
                case 7:
                    l_salary += 70000;
                    break;
                default:
                    l_salary = 1000; 
                    break;
            }
        } 
        else 
        {
            l_salary += 0;
        }
    }   
    else 
    {
        l_salary += 0;
    }

    return l_salary;
}
