// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CTestTPS/TPSTypes.h"
#include "TPSInventoryItem.generated.h"

class USphereComponent;

UCLASS()
class CTESTTPS_API ATPSInventoryItem : public AActor
{
	GENERATED_BODY()
	
public:	
	ATPSInventoryItem();

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
protected:
	UPROPERTY(VisibleAnywhere)
	USphereComponent* CollisionComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FInventoryData InventoryData;
};
