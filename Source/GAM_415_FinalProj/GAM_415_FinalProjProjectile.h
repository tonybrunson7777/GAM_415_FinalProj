// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GAM_415_FinalProjProjectile.generated.h"

class USphereComponent;
class UProjectileMovementComponent;
class UNiagaraSystem;

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

	// create a static mesh component for the ball
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* ballMesh;

	// create a material interface for the base material
	UPROPERTY(EditAnywhere)
	class UMaterialInterface* baseMat;

	// create a random color variable
	UPROPERTY()
	FLinearColor randColor;

	// create a material interface for the projectile material
	UPROPERTY(EditAnywhere)
	UMaterialInterface* projMat;

	// create a dynamic material instance
	UPROPERTY()
	UMaterialInstanceDynamic* dmiMat;

	// create a niagara system for the projectile impact
	UPROPERTY(EditAnywhere)
	UNiagaraSystem* colorP;

	UPROPERTY(EditAnywhere)
	UNiagaraSystem* muzzleFlash;

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

