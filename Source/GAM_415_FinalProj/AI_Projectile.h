// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AI_Projectile.generated.h"

class USphereComponent;
class UProjectileMovementComponent;

UCLASS()
class GAM_415_FINALPROJ_API AAI_Projectile : public AActor
{
	GENERATED_BODY()

	/** Sphere collision component */
	UPROPERTY(VisibleDefaultsOnly, Category = Projectile)
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
	// Sets default values for this actor's properties
	AAI_Projectile();

protected:
	virtual void BeginPlay();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/** called when projectile hits something */
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	/** Returns CollisionComp subobject **/
	USphereComponent* GetCollisionComp() const { return CollisionComp; }
	/** Returns ProjectileMovement subobject **/
	UProjectileMovementComponent* GetProjectileMovement() const { return ProjectileMovement; }

};
