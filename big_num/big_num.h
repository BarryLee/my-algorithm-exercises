#include <string>
#include <ostream>

const int MAXD = 10000;

struct Big_num {
    Big_num(int);
    Big_num(const std::string&, int);
    Big_num(long, int);

    Big_num& add(const Big_num&);
    //Big_num& sub(const Big_num&);
    Big_num& mul(const Big_num&);
    //Big_num& div(long);
    std::ostream& display(std::ostream&) const;

    //Big_num& operator=(const Big_num&);
    Big_num& operator+=(const Big_num&);
    //Big_num& operator-=(const Big_num&);
    Big_num& operator*=(const Big_num&);

    friend Big_num operator+(const Big_num&, const Big_num&);
    //friend Big_num operator-(const Big_num&, const Big_num&);
    friend Big_num operator*(const Big_num&, const Big_num&);
    friend std::ostream& operator<<(std::ostream&, const Big_num&);
#ifdef NDEBUG
private:
#endif
    void init(int _base);
    int a[MAXD];
    int base;
    int length;
    int digit_per_slot;
    int sign;
};
