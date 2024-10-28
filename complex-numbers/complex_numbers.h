#pragma once

namespace complex_numbers {

class Complex {
public:
    Complex(double real);
    Complex(double real, double imag);

    [[nodiscard]] auto real() const -> double;
    [[nodiscard]] auto imag() const -> double;

    [[nodiscard]] auto abs() const -> double;
    [[nodiscard]] auto conj() const -> Complex;
    [[nodiscard]] auto exp() const -> Complex;

private:
    double real_;
    double imag_;

    // https://rules.sonarsource.com/cpp/RSPEC-2807/
    friend auto operator+(Complex const& lhs, Complex const& rhs) -> Complex;
    friend auto operator-(Complex const& lhs, Complex const& rhs) -> Complex;
    friend auto operator*(Complex const& lhs, Complex const& rhs) -> Complex;
    friend auto operator/(Complex const& lhs, Complex const& rhs) -> Complex;
};

} // namespace complex_numbers
