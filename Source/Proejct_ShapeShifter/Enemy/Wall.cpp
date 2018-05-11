// Fill out your copyright notice in the Description page of Project Settings.

#include "Wall.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Classes/Engine/StaticMesh.h"

// Sets default values
AWall::AWall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Set up wall mesh brushes
	//Circle Wall
	static ConstructorHelpers::FObjectFinder<UStaticMesh> WallMesh_Circle(TEXT("StaticMesh'/Game/Meshes/Prototype/mesh_wall_circle.mesh_wall_circle'"));
	if (WallMesh_Circle.Object != nullptr)
		WallMeshBrush.Add(WallMesh_Circle.Object);
	//Square Wall
	static ConstructorHelpers::FObjectFinder<UStaticMesh> WallMesh_Square(TEXT("StaticMesh'/Game/Meshes/Prototype/mesh_wall_square.mesh_wall_square'"));
	if (WallMesh_Square.Object != nullptr)
		WallMeshBrush.Add(WallMesh_Square.Object);

	//Create Wall Static Mesh Component
	WallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WallMesh"));
	WallMesh->SetupAttachment(RootComponent);
	if (WallMeshBrush[0])
		WallMesh->SetStaticMesh(WallMeshBrush[0]);
}

// Called when the game starts or when spawned
void AWall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}