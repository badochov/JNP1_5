#ifndef JNP1_5_FUNCTION_MAXIMA_H
#define JNP1_5_FUNCTION_MAXIMA_H

#include <functional>

template<typename A, typename V>
class FunctionMaxima {
private:
    class PointType {
    public:
        PointType() = delete;

        A const &arg() const {
            return _arg;
        }

        V const &value() const {
            return _value;
        }

        bool operator<(const PointType &rhs) {
            return std::less(_arg, rhs.arg());
        }

    private:
        friend FunctionMaxima;

        PointType(A arg, V value) : A(arg), V(value) {}

        A _arg;
        V _value;
    };

public:

    static bool maximum_comparator(const PointType &pt1, const PointType &pt2) {
        return std::greater(pt1.value(), pt2.value()) && std::less(pt1.arg(), pt2.arg());
    }

    using point_type = PointType;

};


#endif //JNP1_5_FUNCTION_MAXIMA_H
