long long gcd(long long n, long long m)
{
    return (m == 0 ? n : gcd(m, n % m));
}
