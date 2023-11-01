// This program produces a sales report for DLC，Inc.
#include <iostream>
#include<iomanip>
using namespace std;


struct Product {
    int id;
    int units;
    double prices;
    double sales;
};
//Function prototypes
void calcSales(Product[], int);
void showOrder(Product[], int);
void dualSort(Product[], int);
void showTotals(Product[], int);
void swap(double&, double&);
void swap(int&, int&);



int main()
{
    //NUM PRODSis the number of products produced.
    const int NUM_PRODS = 9;

    Product prod_array[NUM_PRODS] = {
                                     {914,842,12.95,0},
                                     {915,416,14.95,0},
                                     {916,127,18.95,0},
                                     {917,514,16.95,0},
                                     {918,437,21.95,0},
                                     {919,269,31.95,0},
                                     {920,97,14.95,0},
                                     {921,492,14.95,0},
                                     {922,212,16.95,0}
    };
    

    // Calculate each product’s sales.
    calcSales(prod_array, NUM_PRODS);

    // Sort the elements in the sales array in descending
    //order and shuffle the ID numbers in the id array to
    // keep themin para11e1.
    dualSort(prod_array, NUM_PRODS);

    // Set the numeric output formatting.
    cout << setprecision(2) << fixed << showpoint;

    // Display the products and sales amounts.
    showOrder(prod_array, NUM_PRODS);

    // Display total units sold and total sales
    showTotals(prod_array, NUM_PRODS);
    return 0;
}

//***************************************************************
// Definition of calcSales. Accepts units，prices，and sales     *
// arrays as arguments. The size of these arrays is passed      *
// into the num parameter. This function calculates each        *
// product’s sales by multiplying its units sold by each unit’s *
// price. The result is stored in the sales array               *
//***************************************************************

void calcSales( Product prod_array[],int num)
{
    for (int index = 0; index < num; index++)
        prod_array[index].sales = prod_array[index].units * prod_array[index].prices;
}

//******************************************************************
// Definition of function dualSort，Accepts id and sales arrays    *
// as arguments，The size of these arrays is passed into size.     *
// This function performs a descending order selection sort on     *
// the sales array. The elements of the id array are exchanged     *
// identica7ly as those of the sales array.size is the number      *
//of elementsin each array.                                        *
//******************************************************************

void dualSort(Product prod_array[], int size)
{
    int start, maxIndex, tempid;
    double maxValue;

    for (start = 0; start < (size - 1); start++)
    {
        maxIndex = start;
        maxValue = prod_array[start].sales;
        tempid = prod_array[start].id;
        for (int index = start + 1; index < size; index++)
        {
            if (prod_array[index].sales > maxValue)
            {
                maxValue = prod_array[index].sales;
                tempid = prod_array[index].id;
                maxIndex = index;
            }
        }
        swap(prod_array[maxIndex].sales, prod_array[start].sales);
        swap(prod_array[maxIndex].id, prod_array[start].id);
    }
}

//*****************************************************
// The swap function swaps doubles a and bin memory.  *
//*****************************************************
void swap(double& a, double& b)
{
    double temp = a;
    a = b;
    b = temp;
}

//**************************************************
// The swap function swaps ints a and b in memory. *
//**************************************************
void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

//***************************************************************
//Definition of showOrder function.Accepts sales and id arrays  *
// as arguments. The size of these arrays is passed into num.   *
// The function first displays a heading, then the sorted list  *
// of product numbers and sales.                                *
//***************************************************************

void showOrder(Product prod_array[], int num)
{
    cout << "ProductNumber\tSales\n";
    cout << "--------------------------\n";
    for (int index = 0; index < num; index++)
    {
        cout << prod_array[index].id << "\t\t$";
        cout << setw(8) << prod_array[index].sales << endl;
    }
    cout << endl;
}

//********************************************************************* 
//Definition of showTotals function. Accepts sales and id arrays      *
//as arguments. The size of these arrays is passed into num.          *
// The function first calculates the total units (of a11              *  
// products) sold and the total sales. It then displays these         * 
// amounts.                                                           *
//********************************************************************* 

void showTotals(Product prod_array[], int num)
{
    int totaUnits = 0;
    double totalSales = 0.0;

    for (int index = 0; index < num; index++)
    {
        totaUnits += prod_array[index].units;
        totalSales += prod_array[index].sales;
    }
    cout << "Total units Sold: " << totaUnits << endl;
    cout << "Total sales: $" << totalSales << endl;
}
