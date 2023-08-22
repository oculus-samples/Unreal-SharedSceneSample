/*
Copyright (c) Meta Platforms, Inc. and affiliates.
All rights reserved.

This source code is licensed under the license found in the
LICENSE file in the root directory of this source tree.
*/

#pragma once

#include "OculusXRAnchorTypes.h"
#include "SharedSceneSampleBPLibrary.generated.h"

//Helper
UCLASS()
class SHAREDSCENESAMPLE_API USharedSceneSampleBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	/* Gets the Oculus Net ID for the specified player controller */
	UFUNCTION(BlueprintCallable, Category = "Oculus|SharedSpatialAnchors")
	static FString GetLocalPlayerOculusNetID();

	UFUNCTION(BlueprintCallable, Category = "Oculus|SharedSpatialAnchors")
	static bool GetDeviceSupportsLocalMultiplayer();
};
