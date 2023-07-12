#pragma once

namespace complex_numbers {

class Complex {
public:
    Complex(double real, double imag);

    auto real() const -> double;
    auto imag() const -> double;

    auto abs() const -> double;
    auto conj() const -> Complex;
    auto exp() const -> Complex;

private:
    double real_;
    double imag_;
};

auto operator+(Complex const& lhs, Complex const& rhs) -> Complex;
auto operator-(Complex const& lhs, Complex const& rhs) -> Complex;
auto operator*(Complex const& lhs, Complex const& rhs) -> Complex;
auto operator/(Complex const& lhs, Complex const& rhs) -> Complex;

} // namespace complex_numbers
