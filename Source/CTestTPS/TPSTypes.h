#pragma once

#include "CoreMinimal.h"
#include "TPSTypes.generated.h"

UENUM(BlueprintType)
enum class EInventoryItemType : uint8
{
    SPHERE = 0 UMETA(DisplayName = "My Cool Sphere"),
    CUBE UMETA(DisplayName = "MyCool Cube"),
    CYLINDER,
    CONE
};

USTRUCT(BlueprintType)
struct FInventoryData
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EInventoryItemType Type;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = "0"))
        int32 Score;
};
