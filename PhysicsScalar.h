#ifndef JANK_ENGINE_PHYSICSSCALAR_H
#define JANK_ENGINE_PHYSICSSCALAR_H

#include "glut.h"
#include "Unit.h"

template<Unit units>
class PhysicsScalar {
public:
    GLdouble val;

    constexpr explicit PhysicsScalar(GLdouble val) : val(val) {}

    constexpr PhysicsScalar& operator+=(PhysicsScalar other) {
        val += other.val;
        return *this;
    }
    constexpr PhysicsScalar& operator-=(PhysicsScalar other) {
        val -= other.val;
        return *this;
    }
    constexpr friend PhysicsScalar operator+(PhysicsScalar first, PhysicsScalar second) {
        return PhysicsScalar(first.val + second.val);
    }
    constexpr friend PhysicsScalar operator-(PhysicsScalar first, PhysicsScalar second) {
        return PhysicsScalar(first.val - second.val);
    }
    constexpr PhysicsScalar operator-() {
        return PhysicsScalar(-val);
    }
    constexpr friend PhysicsScalar operator*(PhysicsScalar scalar, GLdouble n) {
        return PhysicsScalar(scalar.val * n);
    }
    constexpr friend PhysicsScalar operator*(GLdouble n, PhysicsScalar scalar) {
        return PhysicsScalar(n * scalar.val);
    }
    constexpr friend PhysicsScalar operator/(PhysicsScalar scalar, GLdouble n) {
        return PhysicsScalar(scalar.val / n);
    }
    constexpr friend auto operator/(GLdouble n, PhysicsScalar scalar) {
        return PhysicsScalar<units.inverse()>(n / scalar.val);
    }

    constexpr friend auto operator<=>(PhysicsScalar first, PhysicsScalar second) {
        return first.val <=> second.val;
    }
    constexpr friend bool operator==(PhysicsScalar first, PhysicsScalar second) {
        return first.val == second.val;
    }

    friend std::ostream& operator<<(std::ostream& ost, const PhysicsScalar& scalar) {
        ost << scalar.val << ' ' << units;
        return ost;
    }
};

template<Unit firstUnits, Unit secondUnits>
constexpr PhysicsScalar<firstUnits*secondUnits> operator*(PhysicsScalar<firstUnits> first, PhysicsScalar<secondUnits> second) {
    return PhysicsScalar<firstUnits*secondUnits>{first.val*second.val};
}
template<Unit firstUnits, Unit secondUnits>
constexpr PhysicsScalar<firstUnits/secondUnits> operator/(PhysicsScalar<firstUnits> first, PhysicsScalar<secondUnits> second) {
    return PhysicsScalar<firstUnits*secondUnits>{first.val/second.val};
}

template<Unit U>
[[maybe_unused]] std::size_t hash_value(PhysicsScalar<U> scalar) {
    return boost::hash_value(scalar.val);
}

constexpr PhysicsScalar<METERS> ONE_METER(1);
constexpr PhysicsScalar<SECONDS> ONE_SECOND(1);
constexpr PhysicsScalar<KILOGRAMS> ONE_KILOGRAM(1);

#endif //JANK_ENGINE_PHYSICSSCALAR_H
