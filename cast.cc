// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: Copyright (C) 2022 - 2025 Steffen A. Mork

#include <cstdio>
#include <cstdlib>
#include <cstdint>

int main()
{
	const union
	{
		float    f;
		uint32_t u;
	}              raw {.u = 0x3f800000};
	const float    float1 = raw.u;
	const float    float2 = (float)raw.u;
	const float    float3 = static_cast<float>(raw.u);
	const float    float4 = *reinterpret_cast<const float *>(&raw.u);

	printf("Raw:              0x%08x\n", raw.u);
	printf("union:            %8.5f\n", raw.f);
	printf("cast:             %8.5f\n", float1);
	printf("C style cast:     %8.5f\n", float2);
	printf("static cast:      %8.5f\n", float3);
	printf("reinterpret cast: %8.5f\n", float4);

	return EXIT_SUCCESS;
}
