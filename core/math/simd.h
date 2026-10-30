/**
 * @file simd.h
 *
 * Portable 4-lane single precision SIMD wrapper plus runtime CPU feature
 * detection for AVX/AVX2 dispatch.
 *
 * Compile-time baselines:
 *  - x86_64: SSE2 (the build system passes -msse2 / /arch:SSE2).
 *  - x86_32: SSE2 only; SSE4.1 instructions are emulated.
 *  - Everything else (ARM included): GODOT_SIMD_F32X4 stays undefined and
 *    callers keep their original scalar code.
 *
 * Every operation here is specified to produce bit-identical results to the
 * scalar expression documented next to it, so callers can replace scalar
 * code without changing outputs. In particular there is no FMA, no
 * reciprocal approximation, and min/max follow the `a < b ? a : b` form.
 *
 * AVX/AVX2/FMA code must live in .cpp files, in functions tagged with
 * GODOT_SIMD_TARGET_AVX2 (or _AVX2_FMA), and must only be called after
 * checking CPUFeatures at runtime.
 */
