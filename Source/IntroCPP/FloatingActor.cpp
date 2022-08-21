// Fill out your copyright notice in the Description page of Project Settings.


#include "FloatingActor.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/StaticMesh.h"
#include  "Materials/Material.h"

// Sets default values
AFloatingActor::AFloatingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualMesh"));
	VisualMesh->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> VisualCube(TEXT("/Game/Geometry/Meshes/1M_Cube"));
	static ConstructorHelpers::FObjectFinder<UMaterial> VisualCubeMaterial(TEXT("/Game/Geometry/material1"));

	if (VisualCube.Succeeded()) {
		VisualMesh->SetStaticMesh(VisualCube.Object);
		VisualMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}

	if (VisualCubeMaterial.Succeeded()) {
		VisualMesh->SetMaterial(0, VisualCubeMaterial.Object);
	}

}

// Called when the game starts or when spawned
void AFloatingActor::BeginPlay()
{
	Super::BeginPlay();

	GLog->Log("Is Working!");
	
}

// Called every frame
void AFloatingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	FVector NewLocation = GetActorLocation();
	FRotator NewRotation = GetActorRotation();

	float runningtime = GetGameTimeSinceCreation();
	float deltaheight = (FMath::Sin(runningtime + DeltaTime) - FMath::Sin(runningtime));

	NewLocation.Z += deltaheight * 60.0f;

	float deltaRotation = DeltaTime * 20.0f;

	NewRotation.Yaw += deltaRotation;

	SetActorLocationAndRotation(NewLocation, NewRotation);

}

