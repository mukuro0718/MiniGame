#include "Common.h"

/// <summary>
/// コンストラクタ
/// </summary>
WrapVECTOR::WrapVECTOR(const float _x, const float _y, const float _z)
{
	this->value.x = _x;
	this->value.y = _y;
	this->value.z = _z;
}
WrapVECTOR::WrapVECTOR(const float _in)
{
	this->value.x = _in;
	this->value.y = _in;
	this->value.z = _in;
}
WrapVECTOR::WrapVECTOR(const VECTOR _in)
{
	this->value = _in;
}
WrapVECTOR::WrapVECTOR(const std::vector<float> _in)
{
	this->value.x = _in[0];
	this->value.y = _in[1];
	this->value.z = _in[2];
}

/// <summary>
/// vector<float>を追加して返すs
/// </summary>
WrapVECTOR WrapVECTOR::Add(const std::vector<float> _in)
{
	WrapVECTOR out(*this);
	out.value.x += _in[0];
	out.value.y += _in[1];
	out.value.z += _in[2];
	return out;
}

/// <summary>
/// vector<float>をVECTORに変換
/// </summary>
void WrapVECTOR::Convert(const std::vector<float> _in)
{
	this->value.x = _in[0];
	this->value.y = _in[1];
	this->value.z = _in[2];
}

/// <summary>
/// 値のセッター
/// </summary>
void WrapVECTOR::Set(const float _x, const float _y, const float _z)
{
	this->value.x = _x;
	this->value.y = _y;
	this->value.z = _z;
}
void WrapVECTOR::Set(const WrapVECTOR& _in)
{
	*this = _in;
}

float WrapVECTOR::Size()
{
	return VSize(this->value);
}

WrapVECTOR WrapVECTOR::Norm()
{
	WrapVECTOR out(VNorm(this->value));
	return out;
}

WrapVECTOR WrapVECTOR::Scale(const float _in)
{
	WrapVECTOR out(VScale(this->value, _in));
	return out;
}
WrapVECTOR WrapVECTOR::Cross(const WrapVECTOR& _in)
{
	WrapVECTOR out(VCross(this->value, _in.value));
	return out;
}

/// <summary>
/// ベクトルの回転
/// </summary>
WrapVECTOR WrapVECTOR::Rotate(const WrapVECTOR& _in)
{
	/*変数の準備*/
	WrapVECTOR out = *this;

	/*引数の各要素の値が０じゃなければ行列を出す*/
	if (_in.value.x != 0.0f)
	{
		out = VTransform(out.value,MGetRotX(_in.value.x));
	}
	if (_in.value.y != 0.0f)
	{
		out = VTransform(out.value, MGetRotY(_in.value.y));
	}
	if (_in.value.z != 0.0f)
	{
		out = VTransform(out.value, MGetRotZ(_in.value.z));
	}

	return out;
}

/// <summary>
/// 角度をラジアンに変換
/// </summary>
float WrapVECTOR::DegToRad(const float _deg)
{
	return _deg * (DX_PI_F / 180.0f);
}
void WrapVECTOR::DegToRad(const WrapVECTOR& _deg)
{
	this->Set(DegToRad(_deg.value.x), DegToRad(_deg.value.y), DegToRad(_deg.value.z));
}

/// <summary>
/// ラジアンを角度に変換
/// </summary>
float WrapVECTOR::RadToDeg(const float _rad)
{
	return _rad * 180.0f / DX_PI_F;
}
void WrapVECTOR::RadToDeg(const WrapVECTOR& _rad)
{
	this->Set(DegToRad(_rad.value.x), DegToRad(_rad.value.y), DegToRad(_rad.value.z));
}

/// <summary>
/// 線形補完
/// </summary>
float WrapVECTOR::EaseInOutQuint(const float _start, const float _end, const float _percent)
{
	return _start + _percent * (_end - _start);
}
void WrapVECTOR::EaseInOutQuint(const WrapVECTOR& _start, const WrapVECTOR& _end, const WrapVECTOR& _percent)
{
	this->value.x = EaseInOutQuint(_start.value.x, _end.value.x, _percent.value.x);
	this->value.y = EaseInOutQuint(_start.value.y, _end.value.y, _percent.value.x);
	this->value.z = EaseInOutQuint(_start.value.z, _end.value.z, _percent.value.x);
}

/// <summary>
/// オペレーター
/// </summary>
/// <param name="_in"></param>
/// <returns></returns>
WrapVECTOR WrapVECTOR::operator+(const WrapVECTOR& _in)
{
	WrapVECTOR out
	(
		this->value.x + _in.value.x,
		this->value.y + _in.value.y,
		this->value.z + _in.value.z
	);
	return out;
}
WrapVECTOR WrapVECTOR::operator-(const WrapVECTOR& _in)
{
	WrapVECTOR out
	(
		this->value.x - _in.value.x,
		this->value.y - _in.value.y,
		this->value.z - _in.value.z
	);
	return out;
}
WrapVECTOR WrapVECTOR::operator+=(const WrapVECTOR& _in)
{
	this->value.x += _in.value.x;
	this->value.y += _in.value.y;
	this->value.z += _in.value.z;
	return (*this);
}
WrapVECTOR WrapVECTOR::operator-=(const WrapVECTOR& _in)
{
	this->value.x -= _in.value.x;
	this->value.y -= _in.value.y;
	this->value.z -= _in.value.z;
	return (*this);
}
WrapVECTOR WrapVECTOR::operator*=(const WrapVECTOR& _in)
{
	this->value.x *= _in.value.x;
	this->value.y *= _in.value.y;
	this->value.z *= _in.value.z;
	return (*this);
}
bool WrapVECTOR::operator!=(const WrapVECTOR& _in)
{
	if (this->value.x != _in.value.x || 
		this->value.y != _in.value.y || 
		this->value.z != _in.value.z)
	{
		return true;
	}
	return false;
}
