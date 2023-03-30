// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/TPSInventoryItem.h"
#include "Gameframework/Pawn.h"
#include "Components/SphereComponent.h"
#include "CTestTPS/Components/TPSInventoryComponent.h"

ATPSInventoryItem::ATPSInventoryItem()
{
	PrimaryActorTick.bCanEverTick = false;

	CollisionComponent = CreateDefaultSubobject<USphereComponent>("SphereComponent");
	check(CollisionComponent);
	CollisionComponent->InitSphereRadius(30.0f);
	CollisionComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	CollisionComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	SetRootComponent(CollisionComponent);
}

void ATPSInventoryItem::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	if (const auto Pawn = Cast<APawn>(OtherActor))
	{
		if(const auto InvComp = Pawn->FindComponentByClass<UTPSInventoryComponent>())
		{ 
			if(InvComp->TryToAddItem(InventoryData))
			{ 
				Destroy();
			}
			
		}
	}
}
