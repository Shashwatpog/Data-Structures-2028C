// This program demonstrates a two-dimensional array.
#include <iostream>
#include <iomanip>
#include<fstream>
#include <string>
using namespace std;
int main()
{
	string filename;
	string line;
	cout << "Enter Name of the File You want to write in" << endl;
	cin >> filename;
	fstream data;
	data.open(filename, ios :: app);
		
	const int NUM_DIVS = 3; // Number of divisions
	const int NUM_QTRS = 4; // Number of quarters
	double sales[NUM_DIVS][NUM_QTRS]; // Array with 3 rows and 4 columns.
	double totalSales = 0; // To hold the total sales.
	int div, qtr; // Loop counters.
	data << "The first lab of CS2028.\n";
	data << "This program will calculate the total sales of\n";
	data << "all the company's divisions.\n";
	data << "Enter the following sales information:\n\n";
	// Nested loops to fill the array with quarterly
	// sales figures for each division.
	for (div = 0; div < NUM_DIVS; div++)
	{
		for (qtr = 0; qtr < NUM_QTRS; qtr++)
		{
			cout<< "Division " << (div + 1);
			cout << ", Quarter " << (qtr + 1) << ": $";
			cin >> sales[div][qtr];
			data << "Division " << (div + 1);
			data << ", Quarter " << (qtr + 1) << ": $"  << sales[div][qtr] << endl;
		}
		data << endl;
		cout << endl; // Print blank line.
	}
	cout << fixed << showpoint << setprecision(2);
	data << "The sales for the company is: $" << endl;
	data << "Div" << "\t" << "Q1" << "\t" << "Q2" << "\t" << "Q3" << "\t" << "Q4"
		<< endl;
	// Nested loops to display the quarterly sales figures for each division.
	for (div = 0; div < NUM_DIVS; div++)
	{
		data << div + 1 << "\t";
		for (qtr = 0; qtr < NUM_QTRS; qtr++)
		{
			totalSales = totalSales + sales[div][qtr];
			data << "$" << sales[div][qtr] << "\t";
		}
		data << endl; // Print blank line.
	}
	data << endl;
	data << "The total sales for the company are: $";
	data << totalSales << endl;
	data << endl;
	data.close();
	return 0;
}
