// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GAM_415_FinalProjProjectile.generated.h"

class USphereComponent;
class UProjectileMovementComponent;

UCLASS(config=Game)
class AGAM_415_FinalProjProjectile : public AActor
{
	GENERATED_BODY()

	/** Sphere collision component */
	UPROPERTY(VisibleDefaultsOnly, Category=Projectile)
	USphereComponent* CollisionComp;

	/** Projectile movement component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	UProjectileMovementComponent* ProjectileMovement;

	// COMMENT HERE
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* ballMesh;

	// umaterial for the base material; blueprint read write so that I can assign material in editor to avoid null ptr
	UPROPERTY(EditAnywhere)
	class UMaterialInterface* baseMat;

	// COMMENT HERE
	UPROPERTY()
	FLinearColor randColor;

	// COMMENT HERE
	UPROPERTY(EditAnywhere)
	UMaterialInterface* projMat;

	// COMMENT HERE
	UPROPERTY()
	UMaterialInstanceDynamic* dmiMat;


public:
	AGAM_415_FinalProjProjectile();

protected:
	virtual void BeginPlay();

public:

	/** called when projectile hits something */
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	

	/** Returns CollisionComp subobject **/
	USphereComponent* GetCollisionComp() const { return CollisionComp; }
	/** Returns ProjectileMovement subobject **/
	UProjectileMovementComponent* GetProjectileMovement() const { return ProjectileMovement; }
};

