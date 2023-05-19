#include <iostream>
using namespace std;

int count(long long n)
{
    int count = 0;
    while (n > 0)
    {
        n = n / 10;
        count++;
    }
    return count;
}

string conversion_1(int n)
{
    switch (n)
    {
    case 0:
        return "Zero";

    case 1:
        return "One";

    case 2:
        return "two";

    case 3:
        return "three";

    case 4:
        return "four";

    case 5:
        return "five";

    case 6:
        return "six";

    case 7:
        return "seven";

    case 8:
        return "eight";

    case 9:
        return "nine";

    case 10:
        return "ten";

    case 11:
        return "eleven";

    case 12:
        return "twelve";

    case 13:
        return "thirteen";

    case 14:
        return "fourteen";

    case 15:
        return "fifteen";

    case 16:
        return "sixteen";

    case 17:
        return "seventeen";

    case 18:
        return "eighteen";

    case 19:
        return "nineteen";

    case 20:
        return "twenty";

    case 30:
        return "thirty";

    case 40:
        return "fourty";

    case 50:
        return "fifty";

    case 60:
        return "sixty";

    case 70:
        return "seventy";

    case 80:
        return "eighty";

    case 90:
        return "ninty";

    case 100:
        return "hundred";
    }
}

string conversion_2(int n)
{
    if (n <= 20)
    {
        return conversion_1(n);
    }
    else if (n > 20 && n < 30)
    {
        return conversion_1(20) + " " + conversion_1(n - 20);
    }
    else if (n > 30 && n < 40)
    {
        return conversion_1(30) + " " + conversion_1(n - 30);
    }
    else if (n > 40 && n < 50)
    {
        return conversion_1(40) + " " + conversion_1(n - 40);
    }
    else if (n > 50 && n < 60)
    {
        return conversion_1(50) + " " + conversion_1(n - 50);
    }
    else if (n > 60 && n < 70)
    {
        return conversion_1(60) + " " + conversion_1(n - 60);
    }
    else if (n > 70 && n < 80)
    {
        return conversion_1(70) + " " + conversion_1(n - 70);
    }
    else if (n > 80 && n < 90)
    {
        return conversion_1(80) + " " + conversion_1(n - 80);
    }
    else if (n > 90 && n < 100)
    {
        return conversion_1(90) + " " + conversion_1(n - 90);
    }
    else
    {
        return conversion_1(n);
    }
}

string for_hundreds(int n, int m)
{
    if (n == 0)
    {
        return "and " + conversion_2(m);
    }
    else if (m == 0)
    {
        return conversion_1(n) + " hundred ";
    }
    else
    {
        return conversion_1(n) + " hundred and " + conversion_2(m);
    }
}

string for_thousands(int n)
{
    if (n % 1000 == 0 && (count(n) == 4 || count(n) == 5))
    {
        return conversion_2(n / 1000) + " thousand ";
    }

    else if (n % 1000 != 0 && (count(n) == 4 || count(n) == 5))
    {
        return conversion_2(n / 1000) + " thousand " + for_hundreds((n % 1000) / 100, (n % 1000) % 100);
    }

    else
    {
        return "and " + conversion_2(n);
    }
}

string for_lacs(int n)
{
    if (n % 100000 != 0 && (count(n) == 6 || count(n) == 7))
    {
        return conversion_2(n / 100000) + " lac " + for_thousands(n % 100000);
    }
    else if (n % 100000 == 0 && (count(n) == 6 || count(n) == 7))
    {
        return conversion_2(n / 100000) + " lac ";
    }
    else
    {
        return for_thousands(n);
    }
}

string for_crores(int n)
{
    if (n % 10000000 == 0 && (count(n) == 8 || count(n) == 9))
    {
        return conversion_2(n / 10000000) + " crore ";
    }
    else if (n % 10000000 != 0 && (count(n) == 8 || count(n) == 9))
    {
        return conversion_2(n / 10000000) + " crore " + for_lacs(n % 10000000);
    }
    else
    {
        return for_lacs(n);
    }
}

string for_arab(long long n)
{
    if (n % 1000000000 != 0 && (count(n) == 10 || count(n) == 11))
    {
        return conversion_2(n / 1000000000) + " arab " + for_crores(n % 1000000000);
    }
    else if (n % 1000000000 == 0)
    {
        return conversion_2(n / 1000000000) + " arab ";
    }
    else
    {
        return for_crores(n);
    }
}

int main()
{
    long long n;
    cout<<" -----------------------------------------------"<<endl;
    cout << "|++++++++++ Convert a Number to Words ++++++++++|" << endl;
    cout<<" -----------------------------------------------"<<endl;
    cout<< "Enter number to convert: ";
    cin >> n;
    cout<<endl<<"---------------------------------------"<<endl;

    if (count(n) == 10 || count(n) == 11)
    {
        cout << n << " ------> " << for_arab(n);
    }
    else if (count(n) == 8 || count(n) == 9)
    {
        cout << n << " ------> " << for_crores(n);
    }
    else if (count(n) == 6 || count(n) == 7)
    {
        cout << n << " ------> " << for_lacs(n);
    }
    else if (count(n) == 4 || count(n) == 5)
    {
        cout << n << " ------> " << for_thousands(n);
    }
    else if (count(n) == 3)
    {
        cout << n << " ------> " << for_hundreds(n / 100, n % 100);
    }
    else if(n>=0 && n<3)
    {
        cout << n << " ------> " << conversion_2(n);
    }
    else
    {
        cout<<"Can not convert !!! ";
    }
    cout<<"\n--"<<endl;
    return 0;
}
