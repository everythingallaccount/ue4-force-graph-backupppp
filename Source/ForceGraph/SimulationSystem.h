#pragma once

#include "CoreMinimal.h"
#include "Node.h"
#include "TimerManager.h"
#include <map>

#include "KnowledgeEdge.h"

// class UWorld;

class  FORCEGRAPH_API FSimulationSystem
{
public:
    FSimulationSystem(UWorld* InWorld);
    ~FSimulationSystem();

    void Tick(int iterations);
    void InitializeNodes(int NumNodes, int NumDimensions);
    void ApplyForces();
    FNode* FindClosestNode(const FVector& Point, float MaxRadius);

public:
    TArray<FNode> Nodes;
    TMap<int32, AKnowledgeEdge*> all_links;


    
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