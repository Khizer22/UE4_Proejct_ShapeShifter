// Fill out your copyright notice in the Description page of Project Settings.

#include "MainCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/Controller.h"
#include "UObject/ConstructorHelpers.h"
#include "Classes/Engine/StaticMesh.h"

// Sets default values
AMainCharacter::AMainCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller
	CameraBoom->SocketOffset = FVector(0, 0, 60);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bDoCollisionTest = false;
	CameraBoom->bEnableCameraLag = true;

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm
	FollowCamera->FieldOfView = 90;	

	//**************TEMPORARY FOR PROTOTYPE***************//
	//Square Player
	static ConstructorHelpers::FObjectFinder<UStaticMesh> PlayerCubeMesh(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
	if (PlayerCubeMesh.Object != nullptr)
		PlayerMeshBrush.Add(PlayerCubeMesh.Object);
	//Sphere Player
	static ConstructorHelpers::FObjectFinder<UStaticMesh> PlayerSphereMesh(TEXT("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));
	if (PlayerSphereMesh.Object != nullptr)
		PlayerMeshBrush.Add(PlayerSphereMesh.Object);

	//Create Static Mesh Component
	PlayerMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlayerMesh"));
	PlayerMeshComponent->SetupAttachment(RootComponent);
	if (PlayerMeshBrush[0])
		PlayerMeshComponent->SetStaticMesh(PlayerMeshBrush[0]);
}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	//Dont turn the player with the mouse
	bUseControllerRotationYaw = false;


}

// Called every frame
void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//Enum
void AMainCharacter::ChangeShapeNext() 
{
	myShape = EShapeType::SPHERE;
	//change later
	if (PlayerMeshComponent && PlayerMeshBrush[1])
		PlayerMeshComponent->SetStaticMesh(PlayerMeshBrush[1]);
}

void AMainCharacter::ChangeShapePrevious()
{
	myShape = EShapeType::CUBE;
	//change later
	if (PlayerMeshComponent && PlayerMeshBrush[0])
		PlayerMeshComponent->SetStaticMesh(PlayerMeshBrush[0]);
}

// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Set up gameplay key bindings
	check(PlayerInputComponent);
	//Jump
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AMainCharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AMainCharacter::StopJumping);
	//Movement
	//PlayerInputComponent->BindAxis("MoveForward", this, &AMainCharacter::MoveForward);
	//PlayerInputComponent->BindAxis("MoveRight", this, &AMainCharacter::MoveRight);
	//Mouse turning
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	//Change Shape
	PlayerInputComponent->BindAction("ShapeShiftNext", IE_Pressed, this, &AMainCharacter::ChangeShapeNext);
	PlayerInputComponent->BindAction("ShapeShiftPrevious", IE_Pressed, this, &AMainCharacter::ChangeShapePrevious);
}

//Inputs
void AMainCharacter::MoveForward(float Value) 
{
	// find out which way is forward
	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);
	// get forward vector
	const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

	if ((Controller != NULL) && (Value != 0.0f))
	{

		AddMovementInput(Direction, Value);
	}
}
void AMainCharacter::MoveRight(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}

