#include <cstdio>
#include <vector>
#include <cmath>

constexpr static long SECOND = 1;
constexpr static long MINUTE = 60 * SECOND;
constexpr static long HOUR = 60 * MINUTE;
constexpr static long DAY = 24 * HOUR;
constexpr static long MONTH = 30 * DAY;
constexpr static long YEAR = 365 * DAY;
constexpr static long CENTURY = 100 * YEAR;
constexpr static long LIMIT = 100'000'000;

class Base {
public:
    virtual ~Base() = default;

    virtual long        result(long n) = 0;
    virtual const char* name() = 0;

    long largest_n(long time)
    {
        long n = 1;
        while (result(n) <= time * 1e6) {
            if (n == LIMIT) return -1;
            n++;
        }
        return n - 1;
    }
};

class LgN : public Base {
public:
    ~LgN() override = default;

    long result(long n) override { return std::log10(n); }

    const char* name() override { return "lgn"; }
};

class SqrtN : public Base {
public:
    ~SqrtN() override = default;

    long result(long n) override { return std::sqrtl(n); }

    const char* name() override { return "sqrtn"; }
};

class N : public Base {
public:
    ~N() override = default;

    long result(long n) override { return n; }

    const char* name() override { return "n"; }
};

class NLogN : public Base {
public:
    ~NLogN() override = default;

    long result(long n) override { return n * std::log10(n); }

    const char* name() override { return "nlgn"; }
};

class N2 : public Base {
public:
    ~N2() override = default;

    long result(long n) override { return n * n; }

    const char* name() override { return "n^2"; }
};

class N3 : public Base {
public:
    ~N3() override = default;

    long result(long n) override { return n * n * n; }

    const char* name() override { return "n^3"; }
};

class Pow2 : public Base {
public:
    ~Pow2() override = default;

    long result(long n) override { return std::powl(2, n); }

    const char* name() override { return "2^n"; }
};

class Factorial : public Base {
public:
    ~Factorial() override = default;

    long result(long n) override
    {
        if (n <= 1) return 1;
        return result(n - 1) * n;
    }

    const char* name() override { return "n!"; }
};

int main(int argc, char* argv[])
{
    std::vector<long>                  times{SECOND, MINUTE, HOUR, DAY, MONTH, YEAR, CENTURY};
    std::vector<std::unique_ptr<Base>> fns;
    fns.emplace_back(std::make_unique<LgN>());
    fns.emplace_back(std::make_unique<SqrtN>());
    fns.emplace_back(std::make_unique<N>());
    fns.emplace_back(std::make_unique<NLogN>());
    fns.emplace_back(std::make_unique<N2>());
    fns.emplace_back(std::make_unique<N3>());
    fns.emplace_back(std::make_unique<Pow2>());
    fns.emplace_back(std::make_unique<Factorial>());

#define PRINT_TIME(unit) std::printf("%15s", #unit)
    PRINT_TIME(fn);
    PRINT_TIME(second);
    PRINT_TIME(minute);
    PRINT_TIME(hour);
    PRINT_TIME(day);
    PRINT_TIME(month);
    PRINT_TIME(year);
    PRINT_TIME(century);
#undef PRINT_TIME

    for (auto& fn : fns) {
        std::printf("\n%15s", fn->name());
        for (long time : times) {
            long n = fn->largest_n(time);
            n == -1 ? std::printf("%15s", "inf") : std::printf("%15ld", n);
        }
    }
    std::printf("\n");

    return 0;
}