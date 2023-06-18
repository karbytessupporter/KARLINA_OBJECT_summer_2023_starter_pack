/**
 * file: cube_root_approximation.cpp
 * type: C++ (source file)
 * date: 18_JUNE_2023
 * author: karbytes
 * license: PUBLIC_DOMAIN
 */

/* preprocessing directives */
#include <iostream> // standard input (std::cin), standard output (std::cout)
#include <fstream> // file input, file output
#define MAXIMUM_X 100 // constant which represents maximum absolute value of the program input value
#define E 0.00000001 // constant which represents the degree of accuracy of the square root approximation 

/* function prototypes */
long double difference(long double n, long double b);
long double compute_cube_root_of_nonnegative_integer(float x, std::ostream & output);

/**
 * Return the absolute value of (n - (b *  b * b)).
 */
long double difference(long double n, long double b)
{
    if (n > (b * b * b)) return (n - (b * b * b));
    return ((b * b * b) - n);
}

/**
 * Compute the approximate cube root of a real number, x, using the Bisection Method.
 * 
 * The cube root of x is x raised to the power of (1/3).
 * 
 * Assume that x is a float type value and that output is an output stream object.
 * 
 * This function returns a value whose data type is long double (which is a floating-point number).
 */
long double compute_cube_root_of_nonnegative_integer(float x, std::ostream & output)
{
    int i = 0;
    long double A = 0.0, B = 0.0, C = 0.0, epsilon = 0.0;
    C = ((x < (-1 * MAXIMUM_X)) || (x > MAXIMUM_X)) ? 0 : x; // If x is out of range, then set x to 0.
    output << "\n\nC = " << C << ". // real number to take the cube root of";
    output << "\nB = " << B << ". // variable for storing the approximate cube root of x";
    output << "\nA = " << Y << ". // number to add to C before dividing the sum of A and C by 2 for each while loop iteration, i";
    output << "\nepsilon = " << epsilon << ". // variable for storing the difference between the input value and B raised to the power of 3.";
    while (true)
    {
        output << "\n\ni := " << i << ".";
        output << "\nC := " << C << ".";
        output << "\nA := " << A << ".";
        B = (A + C) / 2;
        epsilon = difference(C, B);
        output << "\nB := (A + C) / 2 = " << B << ".";
        output << "\nepsilon = difference(C , B) = " << epsilon << ".";
        if (epsilon <= E) return B;
        if ((B * B * B) > x) C = B;
        else A = B;
        i += 1;
    }
}

/* program entry point */
int main()
{
    // Declare a float type variable and set its initial value to zero.
    float x = 0.0;

    // Declare a double type variable and set its initial value to zero.
    long double S = 0.0;

    // Declare a variable for storing the program user's answer of whether or not to continue inputting values.
    int input_additional_values = 1;

    // Declare a file output stream object.
    std::ofstream file;

    // Set the number of digits of floating-point numbers which are printed to the command line terminal to 100 digits.
    std::cout.precision(100);

    // Set the number of digits of floating-point numbers which are printed to the file output stream to 100 digits.
    file.precision(100);

    /**
     * If cube_root_approximation_output.txt does not already exist in the same directory as cube_root_approximation.cpp, 
     * create a new file named cube_root_approximation_output.txt.
     * 
     * Open the plain-text file named cube_root_approximation_output.txt 
     * and set that file to be overwritten with program data.
     */
    file.open("cube_root_approximation_output.txt");

    // Print an opening message to the command line terminal.
    std::cout << "\n\n--------------------------------";
    std::cout << "\nStart Of Program";
    std::cout << "\n--------------------------------";

    // Print an opening message to the file output stream.
    file << "--------------------------------";
    file << "\nStart Of Program";
    file << "\n--------------------------------";

    // Prompt the user to enter an x value as many times as the user chooses to.
    while (input_additional_values != 0)
    {
        // Print "Enter a real number (represented using only base-ten digits with an optional radix and with an optional negative sign), x, which is no larger than {MAXIMUM_X}: " to the command line terminal.
        std::cout << "\n\nEnter a real number (represented using only base-ten digits with an optional radix and with an optional negative sign), x, which is no larger than " << MAXIMUM_X << ": ";

        // Scan the command line terminal for the most recent keyboard input value.
        std::cin >> x;

        // Print "The value which was entered for x is {x}." to the command line terminal.
        std::cout << "\nThe value which was entered for x is " << x << ".";

        // Print "The value which was entered for x is {x}." to the file output stream.
        file << "\n\nThe value which was entered for x is " << x << ".";

        // Print a horizontal line to the command line terminal.
        std::cout << "\n\n--------------------------------";

        // Print a horizontal line to the command line terminal.
        file << "\n\n--------------------------------";

        // Print "Computing the approximate cube root of x:" to the command line terminal.
        std::cout << "\n\nComputing the approximate cube root of x:";

        // Print "Computing the approximate cube root of x:" to the file output stream.
        file << "\n\nComputing the approximate cube root of x:";

        // Compute the approximate cube root of x using the Bijection Method, print the computational steps to the command line terminal, and store the function result in S.
        S = compute_cube_root_of_real_number(x, std::cout);

        // Compute the approximate square root of x using Heron's Method and print the computational steps to the file output stream.
        compute_cube_root_of_real_number(x, file);

        // Print a horizontal line to the command line terminal.
        std::cout << "\n\n--------------------------------";

        // Print a horizontal line to the command line terminal.
        file << "\n\n--------------------------------";

        // Print "S = approximate_cube_root({x}) = {S}." to the command line terminal.
        std::cout << "\n\nS = approximate_cube_root(" << x << ") = " << S << ".";

        // Print "S = approximate_cube_root({x}) = {S}." to the file output stream.
        file << "\n\nS = approximate_cube_root(" << x << ") = " << S << ".";

        // Print "(S * S * S) = " << {(S * S * S)} << ". // the approximate value of x" to the command line terminal.
        std::cout << "\n\n(S * S * S) = " << (S * S * S) << ". // the approximate absolute value of x";

        // Print "(S * S * S) = " << {(S * S * S)} << ". // the approximate value of x" to the command line terminal.
        std::cout << "\n\n(S * S * S) = " << (S * S * S) << ". // the approximate absolute value of x";

        // Ask the user whether or not to continue inputing values.
        std::cout << "\n\nWould you like to continue inputing program values? (Enter 1 if YES. Enter 0 if NO): ";

        // Scan the command line terminal for the most recent user input entered via keyboard to store in the variable named input_additional_values.
        std::cin >> input_additional_values;

        // Print a horizontal line to the command line terminal.
        std::cout << "\n\n--------------------------------";

        // Print a horizontal line to the command line terminal.
        file << "\n\n--------------------------------";
    }

    // Print a closing message to the command line terminal.
    std::cout << "\nEnd Of Program";
    std::cout << "\n--------------------------------\n\n";

    // Print a closing message to the file output stream.
    file << "\nEnd Of Program";
    file << "\n--------------------------------";

    // Close the file output stream.
    file.close();

    // Exit the program.
    return 0;
}