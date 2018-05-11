// Fill out your copyright notice in the Description page of Project Settings.

#include "WallManager.h"
#include "Wall.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
AWallManager::AWallManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;  //dont need this atm	
}

// Called when the game starts or when spawned
void AWallManager::BeginPlay()
{
	Super::BeginPlay();

	//static ConstructorHelpers::FClassFinder<AWall> WallClassObject(TEXT("/Game/Blueprints/EnemyWalls/BP_Wall"));
	//if (WallClassObject.Class != nullptr)
	//	WallClass = WallClassObject.Class;

	for (int i = 0; i < 5;i++) 
	{
		//if (WallClass)
			//Walls.Add(WallClass);
	}
}

// Called every frame
void AWallManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

