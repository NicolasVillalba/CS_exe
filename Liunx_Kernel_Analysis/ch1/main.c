int g(int x)
{
    return x + 210;
}

int f(int x)
{
    return g(x);
}

int main()
{
    return f(210) + 210;
}
