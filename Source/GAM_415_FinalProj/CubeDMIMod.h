// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "CubeDMIMod.generated.h"

UCLASS()
class GAM_415_FINALPROJ_API ACubeDMIMod : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACubeDMIMod();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Setup UBoxComponent called boxComp
	UPROPERTY(EditAnywhere)
	UBoxComponent* boxComp;

	// Setup UStaticMeshComponent called cubeMesh
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* cubeMesh;

	// Setup base material to create dynamic material instance from (DMI1_MAT)
	UPROPERTY(EditAnywhere)
	UMaterialInterface* baseMat;
	
	// Setup dynamic material instance (dmiMat)
	UPROPERTY()
	UMaterialInstanceDynamic* dmiMat;

	// Setup overlap event function
	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
