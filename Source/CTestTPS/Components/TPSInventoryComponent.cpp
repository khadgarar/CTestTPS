// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/TPSInventoryComponent.h"

// Sets default values for this component's properties
UTPSInventoryComponent::UTPSInventoryComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

}


bool UTPSInventoryComponent::TryToAddItem(const FInventoryData& Data)
{
	if (Data.Score < 0) return false;

	if (!Inventory.Contains(Data.Type))
	{ 
		Inventory.Add(Data.Type, 0);
	}

	const auto NextScore = Inventory[Data.Type] + Data.Score;
	if (NextScore > InventotyLimits[Data.Type]) return false;

	Inventory[Data.Type] = NextScore;

	return true;
}



int32 UTPSInventoryComponent::GetInventoryItemByType(EInventoryItemType Type) const
{
	return Inventory.Contains(Type) ? Inventory[Type] : 0;
}

void UTPSInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	const auto InvEnum = StaticEnum<EInventoryItemType>();
	for (int32 i = 0; i < InvEnum->NumEnums() - 1; ++i)
	{
		const EInventoryItemType EnumElem = static_cast<EInventoryItemType>(i);
		const FString EnumElemName = UEnum::GetValueAsString(EnumElem);
		const bool LimitCheckCond = InventotyLimits.Contains(EnumElem) && InventotyLimits[EnumElem] >= 0;
		checkf(LimitCheckCond, TEXT("Limit for %s missing or less then zero"), *EnumElemName);
	}
}

