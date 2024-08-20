#pragma once

#include "CoreMinimal.h"

struct FNode
{
	FVector Position;
	FVector Velocity;
	FVector Force; // Optional: Direct application of force
	bool bIsPositionFixed;
};
