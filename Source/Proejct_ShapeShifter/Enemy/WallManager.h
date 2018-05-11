// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WallManager.generated.h"

UCLASS()
class PROEJCT_SHAPESHIFTER_API AWallManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWallManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

//	UPROPERTY()
		//TSubclassOf<AWall> WallClass;
	//UPR///OPERTY()
		//TArray<TSubclassOf<AWall*>> Walls;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
