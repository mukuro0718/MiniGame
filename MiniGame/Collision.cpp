#include "Common.h"

/// <summary>
/// コンストラクタ
/// </summary>
Collision::Collision()
{

}
/// <summary>
/// デストラクタ
/// </summary>
Collision::~Collision()
{

}

/// <summary>
/// 球と球の当たり判定
/// </summary>
HitResult Collision::SphereAndSphereCollision(const Object& _in1, const Object& _in2)
{
	/*返す値*/
	HitResult out;

	/*中心ベクトルを出す*/
	WrapVECTOR center1 = _in1.GetHitPosition();
	WrapVECTOR center2 = _in2.GetHitPosition();

	/*半径を出す*/
	float radius1 = _in1.GetRadius();
	float radius2 = _in2.GetRadius();

	/*中心間のベクトルを出す*/
	WrapVECTOR betweenCenterVec = center2 - center1;

	/*中心間のベクトルのサイズを出す*/
	float betweenCenterVecSize = betweenCenterVec.Size();

	/*引数radiusの合計を出す*/
	float sumRadius = radius1 + radius2;

	/*centerPos間のベクトルのサイズがradiusの合計よりも小さければ当たっている*/
	if (betweenCenterVecSize < sumRadius)
	{
		//めり込み量を出す
		float pushBackValue = sumRadius - betweenCenterVecSize;
		//押し戻す方向を出す
		WrapVECTOR pushBackVec = center1 - center2;
		//正規化
		WrapVECTOR pushBackVecNorm = pushBackVec.Norm();
		//めり込み量でスケーリング
		out.fixVec = pushBackVec.Scale(pushBackValue);
		out.isHit = true;
	}


	return out;
}
