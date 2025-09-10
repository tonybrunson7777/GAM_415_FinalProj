// Fill out your copyright notice in the Description page of Project Settings.


#include "CubeDMIMod.h"
#include "GAM_415_FinalProjCharacter.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ACubeDMIMod::ACubeDMIMod()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create subObject called boxComp
	boxComp = CreateDefaultSubobject<UBoxComponent>("Box Component");

	// Create subObject called cubeMesh
	cubeMesh = CreateDefaultSubobject<UStaticMeshComponent>("Cube Mesh");

	// Set RootComponent to boxComp
	RootComponent = boxComp;

	// Attach cubeMesh to boxComp
	cubeMesh->SetupAttachment(boxComp);
}

// Called when the game starts or when spawned
void ACubeDMIMod::BeginPlay()
{
	Super::BeginPlay();

	// Call overlap event
	boxComp->OnComponentBeginOverlap.AddDynamic(this, &ACubeDMIMod::OnOverlapBegin);

	// Check if baseMat is valid
	if (baseMat)
	{
		dmiMat = UMaterialInstanceDynamic::Create(baseMat, this);
	}

	// Check if cubeMesh is valid
	if (cubeMesh)
	{
		cubeMesh->SetMaterial(0, dmiMat);
	}
}

// Called every frame
void ACubeDMIMod::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACubeDMIMod::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Cast to player character
	AGAM_415_FinalProjCharacter* overlappedActor = Cast<AGAM_415_FinalProjCharacter>(OtherActor);

	// Check if overlappedActor is valid
	if (overlappedActor)
	{
		// Set local variables to a range between 0 and 1
		float ranNumX = UKismetMathLibrary::RandomFloatInRange(0.f, 1.f);
		float ranNumY = UKismetMathLibrary::RandomFloatInRange(0.f, 1.f);
		float ranNumZ = UKismetMathLibrary::RandomFloatInRange(0.f, 1.f);

		// Set a 4 Vector to the random values
		FVector4 randColor = FVector4(ranNumX, ranNumY, ranNumZ, 1.f);

		// Check if dmiMat is valid
		if (dmiMat)
		{
			// Change random color
			dmiMat->SetVectorParameterValue("Color", randColor);
			// Change random darkness
			dmiMat->SetScalarParameterValue("Darkness", ranNumX);
			// Change random opacity
			dmiMat->SetScalarParameterValue("Opacity", ranNumY);
		}
	}
}

