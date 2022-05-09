//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <random>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
struct IOPre
{
    static constexpr int TEN = 10, SZ = TEN * TEN * TEN * TEN;
    std::array<char, 4 * SZ> num;
    constexpr IOPre() : num{}
    {
        for (int i = 0; i < SZ; i++)
        {
            int n = i;
            for (int j = 3; j >= 0; j--)
            {
                num[i * 4 + j] = static_cast<char>(n % TEN + '0');
                n /= TEN;
            }
        }
    }
};
struct IO
{
#if !HAVE_DECL_FREAD_UNLOCKED
#define fread_unlocked fread
#endif
#if !HAVE_DECL_FWRITE_UNLOCKED
#define fwrite_unlocked fwrite
#endif
    static constexpr int SZ = 1 << 17, LEN = 32, TEN = 10, HUNDRED = TEN * TEN,
                         THOUSAND = HUNDRED * TEN, TENTHOUSAND = THOUSAND * TEN,
                         MAGIC_MULTIPLY = 205, MAGIC_SHIFT = 11, MASK = 15,
                         TWELVE = 12, SIXTEEN = 16;
    static constexpr IOPre io_pre = {};
    std::array<char, SZ> input_buffer, output_buffer;
    int input_ptr_left, input_ptr_right, output_ptr_right;
    IO()
        : input_buffer{},
          output_buffer{},
          input_ptr_left{},
          input_ptr_right{},
          output_ptr_right{} {}
    IO(const IO &) = delete;
    IO(IO &&) = delete;
    IO &operator=(const IO &) = delete;
    IO &operator=(IO &&) = delete;
    ~IO() { flush(); }
    template <class T>
    struct is_char
    {
        static constexpr bool value = std::is_same_v<T, char>;
    };
    template <class T>
    struct is_bool
    {
        static constexpr bool value = std::is_same_v<T, bool>;
    };
    template <class T>
    struct is_string
    {
        static constexpr bool value =
            std::is_same_v<T, std::string> || std::is_same_v<T, const char *> ||
            std::is_same_v<T, char *> || std::is_same_v<std::decay_t<T>, char *>;
        ;
    };
    template <class T, class D = void>
    struct is_custom
    {
        static constexpr bool value = false;
    };
    template <class T>
    struct is_custom<T, std::void_t<typename T::internal_value_type>>
    {
        static constexpr bool value = true;
    };
    template <class T>
    struct is_default
    {
        static constexpr bool value = is_char<T>::value || is_bool<T>::value ||
                                      is_string<T>::value || std::is_integral_v<T>;
    };
    template <class T, class D = void>
    struct is_iterable
    {
        static constexpr bool value = false;
    };
    template <class T>
    struct is_iterable<
        T, typename std::void_t<decltype(std::begin(std::declval<T>()))>>
    {
        static constexpr bool value = true;
    };
    template <class T, class D = void, class E = void>
    struct is_applyable
    {
        static constexpr bool value = false;
    };
    template <class T>
    struct is_applyable<T, std::void_t<typename std::tuple_size<T>::type>,
                        std::void_t<decltype(std::get<0>(std::declval<T>()))>>
    {
        static constexpr bool value = true;
    };
    template <class T>
    static constexpr bool needs_newline = (is_iterable<T>::value ||
                                           is_applyable<T>::value) &&
                                          (!is_default<T>::value);
    template <typename T, typename U>
    struct any_needs_newline
    {
        static constexpr bool value = false;
    };
    template <typename T>
    struct any_needs_newline<T, std::index_sequence<>>
    {
        static constexpr bool value = false;
    };
    template <typename T, std::size_t I, std::size_t... Is>
    struct any_needs_newline<T, std::index_sequence<I, Is...>>
    {
        static constexpr bool value =
            needs_newline<decltype(std::get<I>(std::declval<T>()))> ||
            any_needs_newline<T, std::index_sequence<Is...>>::value;
    };
    inline void load()
    {
        memcpy(std::begin(input_buffer), std::begin(input_buffer) + input_ptr_left,
               input_ptr_right - input_ptr_left);
        input_ptr_right =
            input_ptr_right - input_ptr_left +
            static_cast<int>(fread_unlocked(
                std::begin(input_buffer) + input_ptr_right - input_ptr_left, 1,
                SZ - input_ptr_right + input_ptr_left, stdin));
        input_ptr_left = 0;
    }
    inline void read_char(char &c)
    {
        if (input_ptr_left + LEN > input_ptr_right)
            load();
        c = input_buffer[input_ptr_left++];
    }
    inline void read_string(std::string &x)
    {
        char c;
        while (read_char(c), c < '!')
            continue;
        x = c;
        while (read_char(c), c >= '!')
            x += c;
    }
    template <class T>
    inline std::enable_if_t<std::is_integral_v<T>, void> read_int(T &x)
    {
        if (input_ptr_left + LEN > input_ptr_right)
            load();
        char c = 0;
        do
            c = input_buffer[input_ptr_left++];
        while (c < '-');
        [[maybe_unused]] bool minus = false;
        if constexpr (std::is_signed<T>::value == true)
            if (c == '-')
                minus = true, c = input_buffer[input_ptr_left++];
        x = 0;
        while (c >= '0')
            x = x * TEN + (c & MASK), c = input_buffer[input_ptr_left++];
        if constexpr (std::is_signed<T>::value == true)
            if (minus)
                x = -x;
    }
    inline void skip_space()
    {
        if (input_ptr_left + LEN > input_ptr_right)
            load();
        while (input_buffer[input_ptr_left] <= ' ')
            input_ptr_left++;
    }
    inline void flush()
    {
        fwrite_unlocked(std::begin(output_buffer), 1, output_ptr_right, stdout);
        output_ptr_right = 0;
    }
    inline void write_char(char c)
    {
        if (output_ptr_right > SZ - LEN)
            flush();
        output_buffer[output_ptr_right++] = c;
    }
    inline void write_bool(bool b)
    {
        if (output_ptr_right > SZ - LEN)
            flush();
        output_buffer[output_ptr_right++] = b ? '1' : '0';
    }
    inline void write_string(const std::string &s)
    {
        for (auto x : s)
            write_char(x);
    }
    inline void write_string(const char *s)
    {
        while (*s)
            write_char(*s++);
    }
    inline void write_string(char *s)
    {
        while (*s)
            write_char(*s++);
    }
    template <typename T>
    inline std::enable_if_t<std::is_integral_v<T>, void> write_int(T x)
    {
        if (output_ptr_right > SZ - LEN)
            flush();
        if (!x)
        {
            output_buffer[output_ptr_right++] = '0';
            return;
        }
        if constexpr (std::is_signed<T>::value == true)
            if (x < 0)
                output_buffer[output_ptr_right++] = '-', x = -x;
        int i = TWELVE;
        std::array<char, SIXTEEN> buf{};
        while (x >= TENTHOUSAND)
        {
            memcpy(std::begin(buf) + i,
                   std::begin(io_pre.num) + (x % TENTHOUSAND) * 4, 4);
            x /= TENTHOUSAND;
            i -= 4;
        }
        if (x < HUNDRED)
        {
            if (x < TEN)
            {
                output_buffer[output_ptr_right++] = static_cast<char>('0' + x);
            }
            else
            {
                std::uint32_t q =
                    (static_cast<std::uint32_t>(x) * MAGIC_MULTIPLY) >> MAGIC_SHIFT;
                std::uint32_t r = static_cast<std::uint32_t>(x) - q * TEN;
                output_buffer[output_ptr_right] = static_cast<char>('0' + q);
                output_buffer[output_ptr_right + 1] = static_cast<char>('0' + r);
                output_ptr_right += 2;
            }
        }
        else
        {
            if (x < THOUSAND)
            {
                memcpy(std::begin(output_buffer) + output_ptr_right,
                       std::begin(io_pre.num) + (x << 2) + 1, 3),
                    output_ptr_right += 3;
            }
            else
            {
                memcpy(std::begin(output_buffer) + output_ptr_right,
                       std::begin(io_pre.num) + (x << 2), 4),
                    output_ptr_right += 4;
            }
        }
        memcpy(std::begin(output_buffer) + output_ptr_right,
               std::begin(buf) + i + 4, TWELVE - i);
        output_ptr_right += TWELVE - i;
    }
    template <typename T_>
    IO &operator<<(T_ &&x)
    {
        using T =
            typename std::remove_cv<typename std::remove_reference<T_>::type>::type;
        static_assert(is_custom<T>::value or is_default<T>::value or
                      is_iterable<T>::value or is_applyable<T>::value);
        if constexpr (is_custom<T>::value)
        {
            write_int(x.get());
        }
        else if constexpr (is_default<T>::value)
        {
            if constexpr (is_bool<T>::value)
            {
                write_bool(x);
            }
            else if constexpr (is_string<T>::value)
            {
                write_string(x);
            }
            else if constexpr (is_char<T>::value)
            {
                write_char(x);
            }
            else if constexpr (std::is_integral_v<T>)
            {
                write_int(x);
            }
        }
        else if constexpr (is_iterable<T>::value)
        {
            using E = decltype(*std::begin(x));
            constexpr char sep = needs_newline<E> ? '\n' : ' ';
            int i = 0;
            for (const auto &y : x)
            {
                if (i++)
                    write_char(sep);
                operator<<(y);
            }
        }
        else if constexpr (is_applyable<T>::value)
        {
            constexpr char sep =
                (any_needs_newline<
                    T, std::make_index_sequence<std::tuple_size_v<T>>>::value)
                    ? '\n'
                    : ' ';
            int i = 0;
            std::apply(
                [this, &sep, &i](auto const &...y)
                {
                    (((i++ ? write_char(sep) : void()), this->operator<<(y)), ...);
                },
                x);
        }
        return *this;
    }
    template <typename T>
    IO &operator>>(T &x)
    {
        static_assert(is_custom<T>::value or is_default<T>::value or
                      is_iterable<T>::value or is_applyable<T>::value);
        static_assert(!is_bool<T>::value);
        if constexpr (is_custom<T>::value)
        {
            typename T::internal_value_type y;
            read_int(y);
            x = y;
        }
        else if constexpr (is_default<T>::value)
        {
            if constexpr (is_string<T>::value)
            {
                read_string(x);
            }
            else if constexpr (is_char<T>::value)
            {
                read_char(x);
            }
            else if constexpr (std::is_integral_v<T>)
            {
                read_int(x);
            }
        }
        else if constexpr (is_iterable<T>::value)
        {
            for (auto &y : x)
                operator>>(y);
        }
        else if constexpr (is_applyable<T>::value)
        {
            std::apply([this](auto &...y)
                       { ((this->operator>>(y)), ...); },
                       x);
        }
        return *this;
    }
    IO *tie(std::nullptr_t) { return this; }
    void sync_with_stdio(bool) {}
};
namespace std
{
    IO io;
}
#define cin io
#define cout io

using namespace __gnu_pbds;
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
                         tree_order_statistics_node_update>;
using namespace std;
#define ll long long
#define Silver_is_better_than_Gold \
    ios_base::sync_with_stdio(0);  \
    cin.tie(0);                    \
    cout.tie(0);
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define pb push_back
#define endl '\n'
#define test cout << " We Droped up Here Boss _________________ " << endl
#define pii pair<int, int>
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define no                    \
    {                         \
        cout << "NO" << endl; \
    }
#define yes                    \
    {                          \
        cout << "YES" << endl; \
    }
const int mod = 1e9 + 7;
#define sz(x) ((int)(x).size())
#define dups(divs) divs.erase(unique(divs.begin(), divs.end()), divs.end());
#define sum(v) accumulate(v.begin(), v.end(), 0ll)
#define T       \
    int XXX;    \
    cin >> XXX; \
    while (XXX--)
#define F first
#define SS second
#define ld long double
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

template <class A>
istream &operator>>(istream &cin, pair<A, A> p)
{
    return cin >> p.first >> p.second;
}

template <class A>
istream &operator>>(istream &cin, vector<A> &p)
{
    for (int i = 0; i < sz(p) - 1; i++)
        cin >> p[i];
    return cin >> p.back();
}

template <class A>
ostream &operator<<(ostream &cout, pair<A, A> const &v)
{
    return cout << v.first << ' ' << v.second << endl;
}

template <class A>
ostream &operator<<(ostream &cout, vector<A> const &v)
{
    for (auto ele : v)
    {
        cout << ele << " ";
    }
    cout << endl;
    return cout;
}

ll fastpow(ll base, ll power, ll M)
{
    if (power == 1)
        return base;
    ll val = fastpow(base, power / 2, M);
    return (power % 2 == 0) ? (val * val) % M : (((val * val) % M) * base) % M;
}

///////////////////////////////////////////////////////////////////////////]
#define int long long
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, s;
    cin >> n >> s;
    vi v(n);
    cin >> v;
    sort(v.begin(), v.end());
    if (accumulate(all(v), 0ll) < s)
    {
        cout << "-1" << endl;
        return 0;
    }
    int st = 0, en = v[0];
    auto do_stuff = [&](int mid)
    {
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans += v[i] - mid;
        return ans >= s;
    };
    int ans = 0;
    while (st <= en)
    {
        int mid = (st + en) / 2;
        if (do_stuff(mid))
        {
            ans = mid, st = mid + 1;
        }
        else
            en = mid - 1;
    }
    cout << ans << endl;
}
