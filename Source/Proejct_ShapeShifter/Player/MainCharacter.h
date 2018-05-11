// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MainCharacter.generated.h"

UENUM(BlueprintType)		
enum class EShapeType : uint8
{
	//Shape types
	CUBE 	UMETA(DisplayName = "Cube"),
	SPHERE 	UMETA(DisplayName = "Sphere"),
};

UCLASS()
class PROEJCT_SHAPESHIFTER_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMainCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Shapes
	UFUNCTION()
		void ChangeShapeNext();
	UFUNCTION()
		void ChangeShapePrevious();
	//Current Shape
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		EShapeType myShape = EShapeType::CUBE;

	//TEMPORARY PROTOTYPE MESHES
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TArray<UStaticMesh*> PlayerMeshBrush;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UStaticMeshComponent* PlayerMeshComponent;
private:

	//Inputs
	void MoveRight(float value);
	void MoveForward(float value);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Camera Spring
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
		class USpringArmComponent *CameraBoom;
	//Camera
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
		class UCameraComponent *FollowCamera;
	
};
