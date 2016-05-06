
#include "STypes.generated.h"
#pragma once



UENUM()
enum class EInventorySlot : uint8
{
	/* For currently equipped items/weapons */
	Hands,

	/* For primary weapons on spine bone */
	Primary,

	/* Storage for small items like flashlight on right pelvis (right hip) */
	Secondary,

	/* Storage for melee weapon on spine bone*/
	Tertiary,

	/* Storage for throwable or utility object on left pelvis (left hip) */
	Utility
	
};


UENUM()
enum class EBotBehaviorType : uint8
{
	/* Does not move, remains in place until a player is spotted */
	Passive,

	/* Patrols a region until a player is spotted */
	Patrolling,
};


USTRUCT()
struct FTakeHitInfo
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	float ActualDamage;

	UPROPERTY()
	UClass* DamageTypeClass;

	UPROPERTY()
	TWeakObjectPtr<class ASBaseCharacter> PawnInstigator;

	UPROPERTY()
	TWeakObjectPtr<class AActor> DamageCauser;

	UPROPERTY()
	uint8 DamageEventClassID;

	UPROPERTY()
	bool bKilled;

private:

	UPROPERTY()
	uint8 EnsureReplicationByte;

	UPROPERTY()
	FDamageEvent GeneralDamageEvent;

	UPROPERTY()
	FPointDamageEvent PointDamageEvent;

	UPROPERTY()
	FRadialDamageEvent RadialDamageEvent;

public:
	FTakeHitInfo()
		: ActualDamage(0),
		DamageTypeClass(nullptr),
		PawnInstigator(nullptr),
		DamageCauser(nullptr),
		DamageEventClassID(0),
		bKilled(false),
		EnsureReplicationByte(0)
	{}

	FDamageEvent& GetDamageEvent()
	{
		switch (DamageEventClassID)
		{
		case FPointDamageEvent::ClassID:
			if (PointDamageEvent.DamageTypeClass == nullptr)
			{
				PointDamageEvent.DamageTypeClass = DamageTypeClass ? DamageTypeClass : UDamageType::StaticClass();
			}
			return PointDamageEvent;

		case FRadialDamageEvent::ClassID:
				if (RadialDamageEvent.DamageTypeClass == nullptr)
				{
					RadialDamageEvent.DamageTypeClass = DamageTypeClass ? DamageTypeClass : UDamageType::StaticClass();
				}
				return RadialDamageEvent;

		default:
			if (GeneralDamageEvent.DamageTypeClass == nullptr)
			{
				GeneralDamageEvent.DamageTypeClass = DamageTypeClass ? DamageTypeClass : UDamageType::StaticClass();
			}
			return GeneralDamageEvent;
		}
	}


	void SetDamageEvent(const FDamageEvent& DamageEvent)
	{
		DamageEventClassID = DamageEvent.GetTypeID();
		switch (DamageEventClassID)
		{
		case FPointDamageEvent::ClassID:
			PointDamageEvent = *((FPointDamageEvent const*)(&DamageEvent));
			break;
		case FRadialDamageEvent::ClassID:
			RadialDamageEvent = *((FRadialDamageEvent const*)(&DamageEvent));
			break;
		default:
			GeneralDamageEvent = DamageEvent;
		}
	}


	void EnsureReplication()
	{
		EnsureReplicationByte++;
	}
};

USTRUCT(BlueprintType)
struct FItemData
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemStructure")
		UTexture2D* bItemImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemStructure")
		FString bItemName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemStructure")
		FText bItemDescription;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemStructure")
		int32 bItemStackSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemStructure")
		bool bHotbarPlaceable;

	//Constructor
	FItemData()
	{

	}
};


USTRUCT(BlueprintType)
struct FInventoryStructure
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryStructure")
		int32 bCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryStructure")
		TSubclassOf<class ASUsableActor> bClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryStructure")
		FString bID;

	//Constructor
	FInventoryStructure()
	{
		bClass = NULL;
		bCount = -1;
		bID = "";

	}

	FInventoryStructure(TSubclassOf<class ASUsableActor> inClass, int32 inCount, FString inID) {
		bClass = inClass;
		bCount = inCount;
		bID = inID;
	}
};