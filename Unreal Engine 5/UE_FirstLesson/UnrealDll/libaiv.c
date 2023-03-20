struct Delegate
{
    int (*callme)(int, int);
};

struct MulticastDelegate
{
    int (*callme[100])(int, int);
};

__declspec(dllexport) const char *aiv_get_string()
{
    return "AIV Hello World";
}

__declspec(dllexport) int aiv_adder(const int a, const int b)
{
    return a + b;
}

int aiv_caller(const int n, int (*callme)(int, int))
{
    int total = 0;

    for(int i = 0; i < n; i++)
        total += callme(i, i * 2);

    return total;
}

int test(int a, int b)
{
    return 100;
}

void hello()
{
    aiv_caller(10, aiv_adder);
    aiv_caller(10, test);
}