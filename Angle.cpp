//
// Created by Jacob on 5/12/22.
//

#include "Angle.h"

Angle::Angle(double radians) {
    this->radians = radians;
}

double Angle::unbounded_radians() const {
    return this->radians;
}

double Angle::bounded_radians() const {
    return fmod(ROTATION, radians);
}

Angle Angle::operator+(Angle &other) const {
    return Angle(this->unbounded_radians() + other.unbounded_radians());
}

Angle Angle::operator+(Angle &&other) const {
    return Angle(this->unbounded_radians() + other.unbounded_radians());
}

Angle Angle::operator-(Angle &other) const {
    return Angle(this->unbounded_radians() - other.unbounded_radians());
}

Angle Angle::operator-(Angle &&other) const {
    return Angle(this->unbounded_radians() - other.unbounded_radians());
}

Angle& Angle::operator+=(Angle &other) {
    this->radians += other.radians;
    return *this;
}

Angle& Angle::operator+=(Angle &&other) {
    this->radians += other.radians;
    return *this;
}

Angle& Angle::operator-=(Angle &other) {
    this->radians -= other.radians;
    return *this;
}

Angle& Angle::operator-=(Angle &&other) {
    this->radians -= other.radians;
    return *this;
}

bool Angle::same_direction(Angle &other) const {
    return this->bounded_radians() == other.bounded_radians();
}

bool Angle::same_direction(Angle &&other) const {
    return this->bounded_radians() == other.bounded_radians();
}



