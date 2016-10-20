#pragma once
// credits to reactiioN @ uc

template< class T, std::size_t DIM >
class Vector
{
private:
	std::array< T, DIM >    m_RowVec;

public:
	Vector(void)
	{
		static_assert(DIM >= 2, "Vector required dim min of 2");
		m_RowVec.fill(static_cast<T>(0));
	}
	explicit Vector(std::array< float, DIM > values) :
		m_RowVec(values)
	{

	}
	template < typename... Args >
	Vector(Args ... args)
	{
		m_RowVec = std::array< float, DIM > { std::forward< float >(args)... };
	}
	Vector(const Vector< T, DIM > &vec)
	{
		for (std::size_t i = 0; i < dim(); i++) {
			at(i) = vec.at(i);
		}
	}
	auto operator + (const Vector< T, DIM > &vec) -> Vector< T, DIM >
	{
		Vector< T, DIM > vecBuffer;
		for (std::size_t i = 0; i < dim(); i++) {
			vecBuffer(i) = at(i) + vec(i);
		}
		return vecBuffer;
	}
	auto operator + (const T &value) -> Vector< T, DIM >
	{
		Vector< T, DIM > vecBuffer;
		for (std::size_t i = 0; i < dim(); i++) {
			vecBuffer(i) = at(i) + value;
		}
		return vecBuffer;
	}
	auto operator += (const Vector< T, DIM > &vec) -> Vector< T, DIM >&
	{
		for (std::size_t i = 0; i < dim(); i++) {
			at(i) += vec(i);
		}
		return *this;
	}
	auto operator += (const T &value) -> Vector< T, DIM >&
	{
		for (std::size_t i = 0; i < dim(); i++) {
			at(i) += value;
		}
		return *this;
	}
	auto operator - (const Vector< T, DIM > &vec) const -> Vector< T, DIM >
	{
		Vector< T, DIM > vecBuffer;
		for (std::size_t i = 0; i < dim(); i++) {
			vecBuffer(i) = at(i) - vec(i);
		}
		return vecBuffer;
	}
	auto operator - (const T &value) const -> Vector< T, DIM >
	{
		Vector< T, DIM > vecBuffer;
		for (std::size_t i = 0; i < dim(); i++) {
			vecBuffer(i) = at(i) - value;
		}
		return vecBuffer;
	}
	auto operator -= (const Vector< T, DIM > &vec) -> Vector< T, DIM >&
	{
		for (std::size_t i = 0; i < dim(); i++) {
			at(i) -= vec(i);
		}
		return *this;
	}
	auto operator -= (const T &value) -> Vector< T, DIM >&
	{
		for (std::size_t i = 0; i < dim(); i++) {
			at(i) -= value;
		}
		return *this;
	}
	auto operator * (const Vector< T, DIM > &vec) -> Vector< T, DIM >
	{
		Vector< T, DIM > vecBuffer;
		for (std::size_t i = 0; i < dim(); i++) {
			vecBuffer(i) = at(i) * vec(i);
		}
		return vecBuffer;
	}
	auto operator * (const T &value) -> Vector< T, DIM >
	{
		Vector< T, DIM > vecBuffer;
		for (std::size_t i = 0; i < dim(); i++) {
			vecBuffer(i) = at(i) * value;
		}
		return vecBuffer;
	}
	auto operator *= (const Vector< T, DIM > &vec) -> Vector< T, DIM >&
	{
		for (std::size_t i = 0; i < dim(); i++) {
			at(i) *= vec(i);
		}
		return *this;
	}
	auto operator *= (const T &value) -> Vector< T, DIM >&
	{
		for (std::size_t i = 0; i < dim(); i++) {
			at(i) *= value;
		}
		return *this;
	}
	auto operator / (const Vector< T, DIM > &vec) -> Vector< T, DIM >
	{
		Vector< T, DIM > vecBuffer;
		for (std::size_t i = 0; i < dim(); i++) {
			vecBuffer(i) = at(i) / vec(i);
		}
		return vecBuffer;
	}
	auto operator / (const T &value) -> Vector< T, DIM >
	{
		Vector< T, DIM > vecBuffer;
		for (std::size_t i = 0; i < dim(); i++) {
			vecBuffer(i) = at(i) / value;
		}
		return vecBuffer;
	}
	auto operator /= (const Vector< T, DIM > &vec) -> Vector< T, DIM >&
	{
		for (std::size_t i = 0; i < dim(); i++) {
			at(i) /= vec(i);
		}
		return *this;
	}
	auto operator /= (const T &value) -> Vector< T, DIM >&
	{
		for (std::size_t i = 0; i < dim(); i++) {
			at(i) /= value;
		}
		return *this;
	}
	auto operator = (const Vector< T, DIM > &vec) -> Vector< T, DIM >&
	{
		for (std::size_t i = 0; i < dim(); i++) {
			at(i) = vec.at(i);
		}
		return *this;
	}
	auto operator = (const T &value) -> Vector< T, DIM >&
	{
		for (std::size_t i = 0; i < dim(); i++) {
			at(i) = value;
		}
		return *this;
	}
	auto operator == (const Vector< T, DIM > &vec) -> bool
	{
		for (std::size_t i = 0; i < dim(); i++) {
			if (at(i) != vec(i)) {
				return false;
			}
		}
		return true;
	}
	auto operator == (const T &value) -> bool
	{
		for (std::size_t i = 0; i < dim(); i++) {
			if (at(i) != value) {
				return false;
			}
		}
		return true;
	}
	auto operator != (const Vector< T, DIM > &vec) -> bool
	{
		return !((*this) == vec);
	}
	auto operator != (const T &value) -> bool
	{
		return !((*this) == value);
	}
	auto operator [] (std::size_t iIndex) -> T&
	{
		return m_RowVec[iIndex];
	}
	auto operator [] (std::size_t iIndex) const -> const T&
	{
		return m_RowVec[iIndex];
	}
		auto operator () (std::size_t iIndex) -> T&
	{
		return m_RowVec.at(iIndex);
	}
	auto operator () (std::size_t iIndex) const -> const T&
	{
		return m_RowVec.at(iIndex);
	}
		auto dim(void) const -> std::size_t
	{
		return m_RowVec.size();
	}
	auto clear(void) -> void
	{
		for (std::size_t i = 0; i < dim(); i++) {
			at(i) = static_cast<T>(0);
		}
	}
	auto empty(void) -> bool
	{
		for (std::size_t i = 0; i < dim(); i++) {
			if (at(i) != 0.f) {
				return false;
			}
		}
		return true;
	}
	auto size(void) const -> std::size_t
	{
		return dim() * sizeof(T);
	}
	auto GetLength2D(bool bSqr = false) const -> float
	{
		auto flSqr = static_cast<float>(at(0) * at(0) + at(1) * at(1));
		if (bSqr) {
			return flSqr;
		}
		return std::sqrtf(flSqr);
	}
	auto GetLength3D(bool bSqr = false) const -> float
	{
		static_assert(DIM >= 3, "Vector::GetLegnth3D required min dim of 3");

		auto flSqr = static_cast<float>(at(0) * at(0) + at(1) * at(1) + at(2) * at(2));
		if (bSqr) {
			return flSqr;
		}
		return std::sqrtf(flSqr);
	}
	auto GetLength(bool bSqr = false) const -> float
	{
		auto flSqr = 0.f;
		for (std::size_t i = 0; i < dim(); i++) {
			flSqr += at(i) * at(i);
		}
		if (flSqr) {
			return flSqr;
		}
		return std::sqrtf(flSqr);
	}
	auto DotProduct(const Vector< T, DIM > &vec) -> float
	{
		static_assert(DIM >= 3, "Vector::DotProduct required min dim of 3");
		return static_cast<float>(at(0) * vec(0) + at(1) * vec(1) + at(2) * vec(2));
	}
	auto Normalize(void) -> void
	{
		auto length = GetLength();
		*this *= 1.f / length;
	}
	auto NormalizeInPlace(void) -> void
	{
		auto inversed_radius = 1.f / (GetLength() + FLT_EPSILON);
		*this *= inversed_radius;
	}
	auto at(std::size_t iIndex) -> T&
	{
		return m_RowVec.at(iIndex);
	}
	auto at(std::size_t iIndex) const -> const T&
	{
		return m_RowVec.at(iIndex);
	}
};

using Vec4 = Vector<float, 4>;
using Vec3 = Vector<float, 3>;
using Vec2 = Vector<float, 2>;