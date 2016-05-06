// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SInventoryBase.h"
#include "SBasicInventory.generated.h"

/**
 * 
 */
UCLASS()
class SURVIVALGAME_API USBasicInventory : public USInventoryBase
{
	GENERATED_BODY()

		USBasicInventory();

public:

	int32 Slots = 12;

	TArray<FInventoryStructure> Inventory;
	
	
};
