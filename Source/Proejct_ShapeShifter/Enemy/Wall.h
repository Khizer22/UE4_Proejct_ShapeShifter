// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../Player/MainCharacter.h"
#include "Wall.generated.h"

UCLASS()
class PROEJCT_SHAPESHIFTER_API AWall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWall();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TArray<UStaticMesh*> WallMeshBrush;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UStaticMeshComponent* WallMesh;

	//Paramters
	//Speed of wal;
	UPROPERTY()
		float wallSpeed = 1.5f;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	EShapeType WallType;	
};
