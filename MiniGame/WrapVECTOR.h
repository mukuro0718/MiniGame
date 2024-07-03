//======================================================
// @brief WrapVECTORクラス
// Dxlibで定義されているVECTORクラスをラッピング
// 継承して使用
//======================================================
#pragma once

class WrapVECTOR
{
public:
	/*コンストラクタ*/
	WrapVECTOR(const float _x, const float _y, const float _z);
	WrapVECTOR(const float _in);
	WrapVECTOR(const VECTOR _in);
	WrapVECTOR(const std::vector<float> _in);

	virtual ~WrapVECTOR(){}//デストラクタ

	/*メンバ変数の操作*/
	WrapVECTOR Add(const std::vector<float> _in);					//vector<float>を追加して返す
	void Convert(const std::vector<float> _in);						//vector<float>をVECTORに変換
	void Set(const float _x, const float _y, const float _z);		//値のsetter
	void Set(const WrapVECTOR& _in);
	float Size();													//ベクトルのサイズを返す
	WrapVECTOR Norm();												//正規化したベクトルを返す
	WrapVECTOR Scale(const float _in);								//引数でスケーリングした値を返す
	WrapVECTOR Cross(const WrapVECTOR& _in);						//引数との外積の結果を返す
	WrapVECTOR Rotate(const WrapVECTOR& _in);						//ベクトルの回転
	
	/*角度をラジアンに変換*/
	float DegToRad(const float _deg);
	void DegToRad(const WrapVECTOR& _deg);

	/*ラジアンを角度に変換*/
	float RadToDeg(const float _rad);
	void RadToDeg(const WrapVECTOR& _rad);


	/*線形補完*/
	float EaseInOutQuint(const float _start, const float _end, const float _percent);
	void  EaseInOutQuint(const WrapVECTOR& _start, const WrapVECTOR& _end, const WrapVECTOR& _percent);
	
	/*operator*/
	bool operator!=(const WrapVECTOR& _in);
	WrapVECTOR operator+(const WrapVECTOR& _in);
	WrapVECTOR operator-(const WrapVECTOR& _in);
	WrapVECTOR operator+=(const WrapVECTOR& _in);
	WrapVECTOR operator-=(const WrapVECTOR& _in);
	WrapVECTOR operator*=(const WrapVECTOR& _in);

	/*メンバ変数*/
	VECTOR value;//値
};

