// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "STypes.h"
#include "SUsableActor.h"
#include "SInventoryBase.generated.h"




UCLASS()
class SURVIVALGAME_API USInventoryBase : public UObject
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintPure, Category = "Inventory")
		static bool GetStackByIndex(int32 inIndex, TArray<FInventoryStructure> inInventory, FInventoryStructure & outStructure);

	UFUNCTION(BlueprintPure, Category = "Inventory")
		static bool GetStackByID(FString inID, TArray<FInventoryStructure> inInventory, FInventoryStructure & outStructure, int32 & FoundIndex);

	UFUNCTION(BlueprintPure, Category = "Inventory")
		static bool GetItemInfo(TSubclassOf<ASUsableActor> bItemClass, FItemData & bIteminfo);

	UFUNCTION(BlueprintPure, Category = "Inventory|Helper")
		static void GetUniqueID(FString & bUniqueID);

	UFUNCTION(BlueprintPure, Category = "Inventory")
		static bool Initialize(int32 inSlots, TArray<FInventoryStructure> & inInventory);

	UFUNCTION(BlueprintPure, Category = "Inventory")
		static bool GetStackByClass(TSubclassOf<class ASUsableActor> inClass, bool bReturnFullStacks, TArray<FInventoryStructure> inInventory, FInventoryStructure & outStructure, int32 & FoundIndex);

	UFUNCTION(BlueprintPure, Category = "Inventory")
		static bool GetItemCount(TSubclassOf<class ASUsableActor> inClass, TArray<FInventoryStructure> inInventory, int32 & ItemCount);

	UFUNCTION(BlueprintPure, Category = "Inventory")
		static bool GetItemStackCount(TSubclassOf<class ASUsableActor> inClass, TArray<FInventoryStructure> inInventory, int32 & StackCount);

	UFUNCTION(BlueprintPure, Category = "Inventory")
		static int32 StacksFromAmount(TSubclassOf<class ASUsableActor> inClass, int32 inAmount);

	UFUNCTION(BlueprintPure, Category = "Inventory")
		static bool GetFreeInventorySpace(TSubclassOf<class ASUsableActor> inClass, TArray<FInventoryStructure> inInventory, int32 & outCount);

	UFUNCTION(BlueprintPure, Category = "Inventory")
		static bool GetFreeInventorySlots(TArray<FInventoryStructure> inInventory, int32 & outCount);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
		static bool AddToInventory(TSubclassOf<class ASUsableActor> inClass, UPARAM(ref) TArray<FInventoryStructure> & inInventory, int32 Amount, bool AddNewStack);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
		static bool RemoveFromInventory(TSubclassOf<class ASUsableActor> inClass, UPARAM(ref)  TArray<FInventoryStructure>& inInventory, int32 Amount);

	UFUNCTION(BluePrintCallable, Category = "Inventory")
		static bool RemoveFromStack(int32 inIndex, UPARAM(ref) TArray<FInventoryStructure> & inInventory, int32 Amount, bool RemoveWholeStack = false);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
		static bool SwapInventoryPosition(UPARAM(ref) TArray<FInventoryStructure> & inInventory, int32 inIndexA, int32 inIndexB);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
		static bool SplitStack(UPARAM(ref) TArray<FInventoryStructure> & inInventory, int32 inIndex, int32 inSplit);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
		static bool MergeStacks(UPARAM(ref) TArray<FInventoryStructure> & inInventory, int32 inIndexA, int32 inIndexB);

};
