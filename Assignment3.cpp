#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

/*
Taylor Evans

This program will produce a sales analysis of the sales
personnel for a company. It will produce a report with the salespersons' names,
their sales amounts, the average sales amount, and the name of the 
salesperson who sold the most. 
*/

int main()
{
    int numSalesPerson;
    const int MAX_SALES_PERSON = 100;
    string salesPersonName[MAX_SALES_PERSON];
    string highestSalesPersonName;
    double salesAmounts[MAX_SALES_PERSON];
    double averageSales = 0.0;
    double highestSales = 0.0;
    double totalSales = 0.0;

    ofstream report("salesReport");
    if (!report.is_open())
    {
        cout << "File did not open. Will terminate the application now.";
        system("pause");
        exit(-1);
    }

    for (numSalesPerson = 0; numSalesPerson < MAX_SALES_PERSON; numSalesPerson++)
    {
        cout << "Please enter the salesperson's name (or CTRL Z to end): ";
        getline(cin, salesPersonName[numSalesPerson]);

        if (cin.eof())
            break;

        if (salesPersonName[numSalesPerson].empty())
        {
            cout << "Please enter the salesperson's name (or CTRL Z to end): ";
            getline(cin, salesPersonName[numSalesPerson]);
        }

        cout << "Enter sales amount: ";
        cin >> salesAmounts[numSalesPerson];

        while (cin.fail())
        {
            cin.clear();
            cin.ignore(80, '\n');
            cout << "Invalid input. Re-enter sales amount: ";
            cin >> salesAmounts[numSalesPerson];
        }

        cin.ignore(80, '\n');

        totalSales += salesAmounts[numSalesPerson];

        if (highestSales < salesAmounts[numSalesPerson])
        {
            highestSales = salesAmounts[numSalesPerson];
            highestSalesPersonName = salesPersonName[numSalesPerson];
        }
    }

    averageSales = totalSales / numSalesPerson;
    
    if (numSalesPerson > 0)
    {
        report << left << setw(20) << "Sales Analysis Report" << endl;
        report << setw(20) << "Salesperson" << right << setw(20) << "Sales Amount" << endl;

        for (int ctr = 0; ctr < numSalesPerson; ctr++)
        {
            report << setw(20) << left << salesPersonName[ctr] << right << setw(20) << salesAmounts[ctr];

            if (salesAmounts[ctr] < averageSales)
            {
                report << " *** below average ***";
            }

            report << endl;

            if (salesAmounts[ctr] > highestSales)
            {
                highestSales = salesAmounts[ctr];
                highestSalesPersonName = salesPersonName[ctr];
            }
        }

        report << endl << "Average Sales Amount" << right << setw(20) << averageSales << endl;
        report << left << highestSalesPersonName << " sold the most!" << endl;
    }

    report.close();

    system("type salesReport");  
	system("pause");
}

/* 
Please enter the salesperson's name (or CTRL Z to end): Taylor E
Enter sales amount: 666.66
Please enter the salesperson's name (or CTRL Z to end): Rikki W
Enter sales amount: 777.77
Please enter the salesperson's name (or CTRL Z to end): Evan A
Enter sales amount: 555.55
Please enter the salesperson's name (or CTRL Z to end): ^Z
Sales Analysis Report
Salesperson                 Sales Amount
Taylor E                          666.66
Rikki W                           777.77
Evan A                            555.55 *** below average ***

Average Sales Amount              666.66
Rikki W sold the most!
Press any key to continue . . .
*/

/*
Sales Analysis Report
Salesperson                 Sales Amount
Taylor E                          666.66
Rikki W                           777.77
Evan A                            555.55 *** below average ***

Average Sales Amount              666.66
Rikki W sold the most!
*/
