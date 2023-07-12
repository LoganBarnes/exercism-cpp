#include "complex_numbers.h"

#include <cmath>

namespace complex_numbers {

Complex::Complex(double real, double imag) : real_(real), imag_(imag) {}

auto Complex::real() const -> double {
    return real_;
}

auto Complex::imag() const -> double {
    return imag_;
}

auto Complex::abs() const -> double {
    return std::sqrt(real_ * real_ + imag_ * imag_);
}

auto Complex::conj() const -> Complex {
    return Complex{real_, -imag_};
}

auto Complex::exp() const -> Complex {
    auto const exp_real = std::exp(real_);
    return Complex{exp_real * std::cos(imag_), exp_real * std::sin(imag_)};
}

auto operator+(Complex const& lhs, Complex const& rhs) -> Complex {
    return Complex{lhs.real() + rhs.real(), lhs.imag() + rhs.imag()};
}

auto operator-(Complex const& lhs, Complex const& rhs) -> Complex {
    return Complex{lhs.real() - rhs.real(), lhs.imag() - rhs.imag()};
}

auto operator*(Complex const& lhs, Complex const& rhs) -> Complex {
    return Complex{
        lhs.real() * rhs.real() - lhs.imag() * rhs.imag(),
        lhs.real() * rhs.imag() + lhs.imag() * rhs.real()};
}

auto operator/(Complex const& lhs, Complex const& rhs) -> Complex {
    auto const denominator = rhs.real() * rhs.real() + rhs.imag() * rhs.imag();
    return Complex{
        (lhs.real() * rhs.real() + lhs.imag() * rhs.imag()) / denominator,
        (lhs.imag() * rhs.real() - lhs.real() * rhs.imag()) / denominator};
}

} // namespace complex_numbers
