#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
using namespace std;
void get_region()
{
    for (int i = 0; i < 100; i++)
    {
        double a = (double)rand() / RAND_MAX;
        if (a < 0.15)
            cout << "北" << endl;
        else if (a < 0.3)
            cout << "中" << endl;
        else if (a < 0.45)
            cout << "南" << endl;
        else
            cout << "全台" << endl;
    }
}
#define size 12
int open_hour[size] = {
    730, 830, 900, 930, 1000, 1030, 1100, 1115, 1130, 1200, 1215, 1230};
int close_hour[size] = {
    1800, 1900, 1930, 2100, 2000, 2030, 2100, 2130, 2200, 2300, 2330, 2400};
FILE *fp; //need file to paste on excel;
void get_business_hour()
{
    fp = fopen("business_hour.txt", "w");
    for (int i = 0; i < 100; i++)
    {
        int a = round(((double)rand() / RAND_MAX) * (size - 1));
        // cout << open_hour[a] << "\t\t";
        fprintf(fp, "%d\t", open_hour[a]);
        a = round(((double)rand() / RAND_MAX) * (size - 1));
        // cout << close_hour[a] << endl;
        fprintf(fp, "%d\n", close_hour[a]);
    }
}

int main()
{
    srand(7);
    get_region();
    get_business_hour();
}