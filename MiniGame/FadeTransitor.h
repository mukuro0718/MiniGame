#pragma once
#include "Transitor.h"
class FadeTransitor :
    public Transitor
{
public:
	FadeTransitor(){}
	~FadeTransitor(){}
	virtual void Update() override;
	virtual void Draw() override;
};
