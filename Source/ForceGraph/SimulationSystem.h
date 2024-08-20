#pragma once

#include "CoreMinimal.h"
#include "Node.h"
#include "TimerManager.h"
#include <map>

// class UWorld;

class FSimulationSystem
{
public:
    FSimulationSystem(UWorld* InWorld);
    ~FSimulationSystem();

    void Tick(float DeltaTime);
    void InitializeNodes(int NumNodes, int NumDimensions);
    void ApplyForces();
    FNode* FindClosestNode(const FVector& Point, float MaxRadius);

private:
    TArray<FNode> Nodes;
    UWorld* World;

    int NumDimensions;
    float Alpha;
    float AlphaMin;
    float AlphaDecay;
    float AlphaTarget;
    float VelocityDecay;

    std::map<FString, TFunction<void(float)>> Forces; // Map of forces

    void InitializeNodePositions();
    void UpdateSimulationParameters();

    FTimerHandle TimerHandle;
};